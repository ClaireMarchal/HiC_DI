/******************************************************************************/
/*                                                                            */
/*    Copyright 2016 Claire Marchal                                           */
/*                                                                            */
/*    This program is free software: you can redistribute it and/or modify    */
/*    it under the terms of the GNU General Public License as published by    */
/*    the Free Software Foundation, either version 3 of the License, or       */
/*    (at your option) any later version.                                     */
/*                                                                            */
/*    This program is distributed in the hope that it will be useful,         */
/*    but WITHOUT ANY WARRANTY; without even the implied warranty of          */
/*    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the            */
/*    GNU General Public License for more details.                            */
/*                                                                            */
/*    You should have received a copy of the GNU General Public License       */
/*    along with this program. If not, see <http://www.gnu.org/licenses/>.    */
/*                                                                            */
/******************************************************************************/

#include "HiC_DI_generator.h"

static void     ft_strdel(char **line)
{
  if (line != NULL)
    {
      free(*line);
      line = NULL;
    }
}

void	ft_generator(char *input, char *output, int *val)
{
  FILE		*fd_i;
  FILE		*fd_o;
  char		*line;
  char		*chr;
  size_t	buffer;
  int		i;
  int		j;
  int		read_pos;
  int		paired_read_pos;
  float		a;
  float		b;
  int		window;

  i = 1;
  a = 0;
  b = 0;
  window = 0;
  read_pos = 0;
  paired_read_pos = 0;
  buffer = 1000;
  line = (char *)malloc(buffer * sizeof(char));
  chr = (char *)malloc(50 * sizeof(char));
  if ((fd_i = fopen(input, "r")) == NULL ||\
      (fd_o = fopen(output, "a")) == NULL ||\
      line == NULL || chr == NULL)
    {
      fprintf(stderr, "\nError: %s\n", strerror(errno));
      return;
    }
  while (i > 0)
  {
    if ((i = getline(&line, &buffer, fd_i)) == -1 && errno != 0)
	{
	  fprintf(stderr, "\nError: %s\n", strerror(errno));
	  return;
	}
    if (i > 0)
	if (ft_filter(line, &read_pos, &paired_read_pos, &chr) == 1)
	  {
	    *val = *val + ft_calc_DI(&window, read_pos,\
			      paired_read_pos, fd_o, &a, &b, chr);
	    j = -1;
	    while (chr[++j])
		chr[j] = 0;
	  }
  }
  ft_strdel(&line);
  ft_strdel(&chr);
  fclose(fd_o);
  return;
}

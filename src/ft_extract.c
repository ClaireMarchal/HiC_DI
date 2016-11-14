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

static int	ft_fill(char *line, int *i)
{
  int	j;
  char	*tmp;

  j = 0;
  tmp = (char *)malloc(50 * sizeof(char));
  if (tmp == NULL)
    return (-1);
  while (line[*i] != '\t')
    {
      tmp[j] = line[*i];
      (*i)++;
      j++;
    }
  tmp[j] = 0;
  j = atoi(tmp);
  ft_strdel(&tmp);
  return (j);
}

static	int	ft_count_occur(char *str, char sep)
{
  int	i;
  int	n;

  n = 0;
  i = 0;
  if (str == NULL)
    return (0);
  while (str[i])
    {
      if (str[i] == sep)
	n++;
      i++;
    }
  return (n);
}

int	ft_extract(char *line, int *read_pos, int *paired_read_pos, char **chr)
{
  int	i;
  int	word;

  if (line == NULL)
    return (0);
  if (ft_count_occur(line, '\t') != 9)
    {
      fprintf(stderr, "Bad line format!\nThis line has been suppressed: %s", line);
      return (0);
    }
  i = 1;
  while (line[i] != '\t')
    {
      ((*chr)[i - 1]) = line[i];
      i++;
    }
  ((*chr)[i - 1]) = 0;
  i++;
  if ((*read_pos = ft_fill(line, &i)) == -1)
    return (0);
  i++;
  word = 2;
  while (line[i] != '\t' || word != 6)
    {
      i++;
      if (line[i] == '\t')
	word++;
    }
  i++;
  if ((*paired_read_pos = ft_fill(line, &i)) == -1)
    return (0);
  return (1);
}

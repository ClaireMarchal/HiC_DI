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

int	ft_calc_DI(int *window, int read, int paired, FILE *fd,\
		   float *a, float *b, char *chr)
{
  float	DI;
  int	test;
  float	e;

  test = 1;
  if (read < (*window + 40000))
    {
      if (paired < read && paired >= (read - 2000000))
	(*a)++;
      else if (paired > read && paired <= (read + 2000000))
	(*b)++;
      else
	test = 0;
    }
  else
    {
      e = (*a + *b) / 2;
      DI = 0;
      if ((*b - *a) != 0 && e != 0)
	DI = ((*b - *a) / (fabs(*b - *a)) *				\
	    (((*a - e) * (*a - e) / e) + ((*b - e) * (*b - e) / e)));
      fprintf(fd, "%s\t%d\t%d\t%f\n", chr, *window, *window + 40000, DI);
      *window = *window + 40000;
      if (paired < read && paired >= (read - 2000000))
        *a = 1;
      else if (paired > read && paired <= (read + 2000000))
        *b = 1;
      else
	test = 0;
    }
  return (test);
}

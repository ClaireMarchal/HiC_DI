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


#ifndef	HIC_DI_GENERATOR_H
#define	HIC_DI_GENERATOR_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <math.h>

//#define max(a,b) (a>b?a:b)
//#define min(a,b) (a>b?b:a)

/*typedef struct  s_list
{
  char          *chr;
  int           start;
  int		end;
  char          *name;
  struct s_list *prev;
  struct s_list *next;
  }               t_list;*/

void    ft_licence(void);
void    ft_help(void);
void	ft_generator(char *input, char *output, int *val);
int	ft_filter(char *line, int *read_pos, int *paired_read_pos, char **chr);
int	ft_extract(char *line, int *read_pos, int *paired_read_pos, char **chr);
int	ft_calc_DI(int *window, int read_pos, int paired_read_pos, FILE *fd,\
		   float *a, float *b, char *chr);
//int     ft_strcmp(const char *s1, const char *s2);
//void    ft_freetab(char **tab);
//char    **ft_strsplit(char *str, char c);
//int     ft_merge(FILE *fd1, FILE *fd_out, char *file2);
//void    ft_dellistbyend(t_list *list);
//t_list  *ft_newchr(char *chr1, char *file2);

#endif

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

void	ft_help(void)
{
  fprintf(stderr, "\
HiC_DI_generator\n\
\n\
This tool calculates the directionality index (DI) as defined by Dixon et al.\n\
(Nature, 2012). Briefly, the DI is calculated for paired reads separated by\n\
maximum 2Mb, in 40kb windows.\n\
It reflects the tendency for a given 40kb windows to be enriched for reads\n\
paired with reads in 2Mb upstream (negative DI) or downstream (positive DI).\n\
It has been designed for HOMER paired-end alignment files and takes as input\n\
a file with each line corresponding to a pair of reads formatted as following:\n\
\n\
\tchr1\t15875\t0\t1.0\t50\tchr1\t167748856\t1\t50\n\
\n\
as in HOMER tag directories files, each line beginning by a tabulation.\n\
The output is a bedGraph file with the DI at 40kb resolution.\n\
\n\
usage: ./HiC_DI_generator input output\n\
\n\
");
}

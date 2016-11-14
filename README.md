# HiC_DI


**************************************************************
Created by Claire Marchal
**************************************************************

HiC_DI_generator

This tool calculates the directionality index (DI) as defined by Dixon et al.
(Nature, 2012). Briefly, the DI is calculated for paired reads separated by
maximum 2Mb, in 40kb windows.
It reflects the tendency for a given 40kb windows to be enriched for reads
paired with reads in 2Mb upstream (negative DI) or downstream (positive DI).
It has been designed for HOMER paired-end alignment files and takes as input
a file with each line corresponding to a pair of reads formatted as following:

  chr1 15875	 0    1.0	    50 chr1   167748856		 1  50

as in HOMER tag directories files, each line beginning by a tabulation.
The output is a bedGraph file with the DI at 40kb resolution.


# Installation

*** download the folder merge_bp:

git clone https://github.com/ClaireMarchal/HiC_DI.git

*** go into the folder:

cd HiC_DI

*** compile program:

make

# How to use

./HiC_DI_generator [path to the input file] [path to the output file]

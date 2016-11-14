
NAME = HiC_DI_generator

CC = gcc

FLAGS = -Werror -Wall -Wextra

SRC = main.c	ft_licence.c	ft_help.c	ft_filter.c\
	ft_generator.c	ft_extract.c	ft_calc_DI.c

all: $(NAME)

$(NAME):	
	@ (cd src && $(CC) $(FLAGS) $(SRC) -o ../$(NAME))

fclean:	
	@ /bin/rm -f $(NAME)

re:	fclean all

.PHONY: all HiC_DI_generator fclean re


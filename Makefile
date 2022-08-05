# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vzayas-s <vzayas-s@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/22 21:56:00 by vzayas-s          #+#    #+#              #
#    Updated: 2022/08/05 16:45:07 by vzayas-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC = push_swap.c 	\
	  movements.c 	\
	  movements2.c \
	  check.c		\
	  free.c 		\
	  print.c		\
	  index.c		\
	  sort_low_nb.c	\
	  sort_all.c	\
	  count.c		\
	  magic_atoi.c	\
	  magic_split.c	\
	  list_utils.c	\
	  init_values.c

OBJ = $(SRC:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror #-fsanitize=address -g3
RM = /bin/rm -rf

RED=\033[0;31m
YELLOW=\033[0;33m
GREEN=\033[0;32m
BLUE=\033[0;34m
END=\033[0m

$(NAME) : $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo "$(BLUE)༺ library created༻$(END)"

$(OBJ) : $(SRC)
	@$(CC) $(CFLAGS) -c $(SRC)

all: $(NAME)

clean:
	@$(RM) $(OBJ) $(BONUS_OBJS)
	@echo "$(RED)༺ Objs deleted༻$(END)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(YELLOW)༺ Executable deleted༻$(END)"

re: fclean all

.PHONY: all clean fclean re bonus
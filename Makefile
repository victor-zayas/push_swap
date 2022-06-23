# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vzayas-s <vzayas-s@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/22 21:56:00 by vzayas-s          #+#    #+#              #
#    Updated: 2022/06/23 12:44:45 by vzayas-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

INCLUDE = libft/libft.a

SRC = push_swap.c

OBJ = $(SRC:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = /bin/rm -rf

GREEN=\033[0;32m
RED=\033[0;31m
BLUE=\033[0;34m
END=\033[0m

$(NAME) : $(OBJ) $(INCLUDE)
	@make -C libft/
	@$(AR) $(NAME) $(OBJ)
	@echo "$(GREEN)༺ library created༻$(END)"

$(OBJ) : $(SRC)
	@$(CC) $(CFLAGS) -c $(SRC)

all: $(NAME)

clean:
	@$(RM) $(OBJ) $(BONUS_OBJS)
	@echo "$(RED)༺ Objs deleted༻$(END)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(RED)༺ Executable deleted༻$(END)"

re: fclean all

.PHONY: all clean fclean re bonus
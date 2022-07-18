# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vzayas-s <vzayas-s@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/24 12:12:22 by vzayas-s          #+#    #+#              #
#    Updated: 2022/04/21 14:24:24 by vzayas-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_isalpha.c			\
	  ft_isdigit.c			\
	  ft_isalnum.c			\
	  ft_isascii.c			\
	  ft_isprint.c			\
	  ft_strlen.c			\
	  ft_strlcpy.c			\
	  ft_strlcat.c			\
	  ft_strncmp.c			\
	  ft_toupper.c			\
	  ft_tolower.c			\
	  ft_strnstr.c			\
	  ft_atoi.c				\
	  ft_strchr.c			\
	  ft_strrchr.c			\
	  ft_memset.c			\
	  ft_bzero.c			\
	  ft_memchr.c			\
	  ft_memcmp.c			\
	  ft_memcpy.c			\
	  ft_memmove.c			\
	  ft_calloc.c			\
	  ft_strdup.c			\
	  ft_substr.c			\
	  ft_strjoin.c			\
	  ft_strtrim.c			\
	  ft_split.c			\
	  ft_itoa.c				\
	  ft_strmapi.c			\
	  ft_striteri.c 		\
	  ft_putchar_fd.c 		\
	  ft_putstr_fd.c 		\
	  ft_putendl_fd.c		\
	  ft_putnbr_fd.c

BONUS =	ft_lstadd_back_bonus.c  \
		ft_lstadd_front_bonus.c \
		ft_lstclear_bonus.c     \
		ft_lstdelone_bonus.c    \
		ft_lstiter_bonus.c      \
		ft_lstlast_bonus.c      \
		ft_lstmap_bonus.c       \
		ft_lstnew_bonus.c       \
		ft_lstsize_bonus.c

INCLUDES = libft.h

OBJ = $(SRC:.c=.o)

BONUS_OBJS = $(BONUS:.c=.o)

CC = gcc
AR = ar rc
CFLAGS = -Wall -Wextra -Werror
RM = /bin/rm -f

all: $(NAME)

$(NAME) : $(OBJ) $(INCLUDES)
	@$(AR) $(NAME) $(OBJ)
	@echo "library created"

bonus: $(BONUS_OBJS) $(OBJ) $(INCLUDES)
	@$(AR) $(NAME) $(BONUS_OBJS) $(OBJ)
	@echo "Bonus Compiled"

$(OBJ) : $(SRC)
	@$(CC) $(CFLAGS) -c $(SRC)
	
$(BONUS_OBJS) : $(BONUS)
	@$(CC) $(CFLAGS) -c $(BONUS)

clean:
	@$(RM) $(OBJ) $(BONUS_OBJS)
	@echo "objs deleted"

fclean: clean
	@$(RM) $(NAME)
	@echo "executable deleted"

re: fclean all

.PHONY: all clean fclean re bonus

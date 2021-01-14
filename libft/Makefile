# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bob <bob@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/04/15 22:00:03 by bob               #+#    #+#              #
#    Updated: 2021/01/11 18:59:55 by bob              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRC = ft_atoi.c ft_bzero.c ft_memalloc.c ft_memcpy.c ft_memdel.c ft_putchar.c \
	  ft_putstr.c ft_strchr.c ft_strdel.c ft_strequ.c ft_strnequ.c ft_strsub.c\
	  print_memory.c ft_putnbr.c ft_xputstr.c ft_putendl_fd.c ft_putstr_fd.c \
	  ft_memdup.c buffer.c indexof.c
HEADER = libft.h buffer.h
OBJ = $(SRC:.c=.o)
ARFLAGS = rc
CFLAGS = -Wall -Wextra -Werror
CC = gcc

# **************************************************************************** #

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(ARFLAGS) $@ $^
	@echo "\033[1;32m ->> libft: library compilled.\n\033[0m"

buffer.o : buffer.c buffer.h
	$(CC) $(CFLAGS) -c $<

%.o: %.c
	$(CC) $(CFLAGS) -c $<

.PHONY: clean fclean re all

clean:
	@$(RM) $(OBJ)
	@echo "\033[0;35m ->> libft: object files deleted.\n\033[0m"

fclean: clean
	@$(RM) $(NAME)
	@echo "\033[0;31m ->> libft: library deleted.\n\033[0m"

re: fclean all

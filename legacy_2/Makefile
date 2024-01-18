# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jho <jho@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/03 08:54:04 by jho               #+#    #+#              #
#    Updated: 2024/01/03 09:07:34 by jho              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=cc
CFLAGS=-Wall -Wextra -Werror
MLXFLAGS=-Lmlx -lmlx -framework OpenGL -framework Appkit
NAME=miniRT
HEADERS=./includes/
MANDATORY_SRCS=$(wildcard sources/*/*.c)
MANDATORY_OBJS=$(MANDATORY_SRCS:%.c=%.o)

%.o : %.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

all: $(NAME)

$(NAME): $(MANDATORY_OBJS) $(HEADERS)
	$(CC) $(CFLAGS) $(MANDATORY_OBJS) $(MLXFLAGS) -o $(NAME)

clean:
	rm -Rf $(MANDATORY_OBJS)

fclean: clean
	rm -Rf $(NAME)

re:
	make fclean
	make all

.PHONY: all, clean, fclean, re
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jho <jho@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/03 08:54:04 by jho               #+#    #+#              #
#    Updated: 2024/01/21 00:47:45 by jho              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=cc
# CFLAGS=-Wall -Wextra -Werror
CFLAGS=
MLXFLAGS=-Lmlx -lmlx -framework OpenGL -framework Appkit
NAME=miniRT
SOURCES=./sources/
HEADERS=./headers/
MANDATORY_SRCS=$(SOURCES)get_next_line/get_next_line.c \
			$(SOURCES)get_next_line/get_next_line_utils.c \
			$(SOURCES)libft/ft_except.c \
			$(SOURCES)libft/ft_strcmp.c \
			$(SOURCES)libft/ft_strlen.c \
			$(SOURCES)libft/ft_substr.c \
			$(SOURCES)libft/ft_token.c \
			$(SOURCES)main/main.c \
			$(SOURCES)mrt/mrt_add_obj.c \
			$(SOURCES)mrt/mrt_color.c \
			$(SOURCES)mrt/mrt_destroy.c \
			$(SOURCES)mrt/mrt_init.c \
			$(SOURCES)mrt/mrt_ray_at.c \
			$(SOURCES)mrt/mrt_ray.c \
			$(SOURCES)mrt/mrt_raytrace.c \
			$(SOURCES)mrt/mrt_sphere.c \
			$(SOURCES)scene/scene_destroy.c \
			$(SOURCES)scene/scene_show.c \
			$(SOURCES)scene/scene_init.c \
			$(SOURCES)vector/vec_add.c \
			$(SOURCES)vector/vec_cross.c \
			$(SOURCES)vector/vec_dot.c \
			$(SOURCES)vector/vec_len.c \
			$(SOURCES)vector/vec_norm.c \
			$(SOURCES)vector/vec_print.c \
			$(SOURCES)vector/vec_scale.c \
			$(SOURCES)vector/vec_sub.c \
			$(SOURCES)vector/vec.c
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

.PHONY: all clean fclean re

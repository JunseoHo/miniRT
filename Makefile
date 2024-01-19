# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jho <jho@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/03 08:54:04 by jho               #+#    #+#              #
#    Updated: 2024/01/19 20:30:59 by jho              ###   ########.fr        #
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
			$(SOURCES)main/main.c \
			$(SOURCES)mrt_load/mrt_load.c \
			$(SOURCES)mrt_load/mrt_parse_amb.c \
			$(SOURCES)mrt_load/mrt_parse_cam.c \
			$(SOURCES)mrt_load/mrt_parse_color.c \
			$(SOURCES)mrt_load/mrt_parse_cylinder.c \
			$(SOURCES)mrt_load/mrt_parse_double.c \
			$(SOURCES)mrt_load/mrt_parse_light.c \
			$(SOURCES)mrt_load/mrt_parse_plane.c \
			$(SOURCES)mrt_load/mrt_parse_sphere.c \
			$(SOURCES)mrt_load/mrt_parse_vector.c \
			$(SOURCES)mrt_load/mrt_parse.c \
			$(SOURCES)mrt_load/mrt_verify.c \
			$(SOURCES)mrt_rt/mrt_rt_render.c \
			$(SOURCES)mrt_rt/mrt_rt.c \
			$(SOURCES)mrt_rt/mrt_scene.c \
			$(SOURCES)mrt_rt/mrt_viewport.c \
			$(SOURCES)mrt_util/mrt_except.c \
			$(SOURCES)mrt_util/mrt_print.c \
			$(SOURCES)mrt_util/mrt_substr.c \
			$(SOURCES)mrt_util/mrt_token.c \
			$(SOURCES)mrt_util/mrt_util.c \
			$(SOURCES)vector/vec_init.c \
			$(SOURCES)vector/vec_operations_1.c \
			$(SOURCES)vector/vec_operations_2.c \
			$(SOURCES)vector/vec_print.c
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

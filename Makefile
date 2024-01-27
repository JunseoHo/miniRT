# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sejkim2 <sejkim2@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/03 08:54:04 by jho               #+#    #+#              #
#    Updated: 2024/01/27 12:47:35 by sejkim2          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=cc
CFLAGS=-Wall -Wextra -Werror
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
			$(SOURCES)libft/ft_isdigit.c \
			$(SOURCES)libft/ft_str_first_chr.c \
			$(SOURCES)libft/ft_str_last_chr.c \
			$(SOURCES)main/main.c \
			$(SOURCES)mrt/mrt_add_obj.c \
			$(SOURCES)mrt/mrt_color.c \
			$(SOURCES)mrt/mrt_cylinder.c \
			$(SOURCES)mrt/mrt_destroy.c \
			$(SOURCES)mrt/mrt_hit_cylinder.c \
			$(SOURCES)mrt/mrt_hit_plane.c \
			$(SOURCES)mrt/mrt_hit_sphere.c \
			$(SOURCES)mrt/mrt_hit.c \
			$(SOURCES)mrt/mrt_init.c \
			$(SOURCES)mrt/mrt_file_parse.c \
			$(SOURCES)mrt/mrt_parse_line.c \
			$(SOURCES)mrt/mrt_parse_amb.c \
			$(SOURCES)mrt/mrt_parse_double.c \
			$(SOURCES)mrt/mrt_verify_integer_or_decimal.c \
			$(SOURCES)mrt/mrt_parse_color.c \
			$(SOURCES)mrt/mrt_parse_cam.c \
			$(SOURCES)mrt/mrt_parse_vector.c \
			$(SOURCES)mrt/mrt_parse_light.c \
			$(SOURCES)mrt/mrt_parse_add_obj.c \
			$(SOURCES)mrt/mrt_parse_sphere.c \
			$(SOURCES)mrt/mrt_parse_plane.c \
			$(SOURCES)mrt/mrt_parse_cylinder.c \
			$(SOURCES)vector/vec_add.c \
			$(SOURCES)vector/vec_color.c \
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

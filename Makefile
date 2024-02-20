# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sejkim2 <sejkim2@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/03 08:54:04 by jho               #+#    #+#              #
#    Updated: 2024/02/20 16:04:36 by sejkim2          ###   ########.fr        #
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
			$(SOURCES)libft/ft_strlcpy.c \
			$(SOURCES)libft/ft_strlen.c \
			$(SOURCES)libft/ft_substr.c \
			$(SOURCES)libft/ft_token.c \
			$(SOURCES)libft/ft_isdigit.c \
			$(SOURCES)libft/ft_strchr.c \
			$(SOURCES)libft/ft_strrchr.c \
			$(SOURCES)main/main.c \
			$(SOURCES)mrt_parser/mrt_add_obj.c \
			$(SOURCES)mrt_parser/mrt_color.c \
			$(SOURCES)mrt_parser/mrt_cylinder.c \
			$(SOURCES)mrt_parser/mrt_destroy.c \
			$(SOURCES)mrt/mrt_hit_cone.c \
			$(SOURCES)mrt/mrt_hit_cylinder.c \
			$(SOURCES)mrt/mrt_hit_plane.c \
			$(SOURCES)mrt/mrt_hit_sphere.c \
			$(SOURCES)mrt/mrt_hit.c \
			$(SOURCES)mrt_parser/mrt_init.c \
			$(SOURCES)mrt_parser/mrt_cone.c \
			$(SOURCES)mrt_parser/mrt_file_parse.c \
			$(SOURCES)mrt_parser/mrt_parse_line.c \
			$(SOURCES)mrt_parser/mrt_parse_amb.c \
			$(SOURCES)mrt_parser/mrt_parse_double.c \
			$(SOURCES)mrt_parser/mrt_verify_integer_or_decimal.c \
			$(SOURCES)mrt_parser/mrt_parse_color.c \
			$(SOURCES)mrt_parser/mrt_parse_cone.c \
			$(SOURCES)mrt_parser/mrt_parse_cam.c \
			$(SOURCES)mrt_parser/mrt_parse_vector.c \
			$(SOURCES)mrt_parser/mrt_parse_light.c \
			$(SOURCES)mrt_parser/mrt_parse_add_obj.c \
			$(SOURCES)mrt_parser/mrt_parse_sphere.c \
			$(SOURCES)mrt_parser/mrt_parse_plane.c \
			$(SOURCES)mrt_parser/mrt_parse_cylinder.c \
			$(SOURCES)mrt_parser/mrt_verify_value_range.c \
			$(SOURCES)mrt/mrt_phong.c \
			$(SOURCES)mrt_parser/mrt_plane.c \
			$(SOURCES)mrt/mrt_ray_at.c \
			$(SOURCES)mrt/mrt_ray.c \
			$(SOURCES)mrt/mrt_raycast.c \
			$(SOURCES)mrt/mrt_raytrace.c \
			$(SOURCES)mrt_parser/mrt_sphere.c \
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

bonus:
	make BONUS=1

clean:
	rm -Rf $(MANDATORY_OBJS)

fclean: clean
	rm -Rf $(NAME)

re:
	make fclean
	make all

.PHONY: all clean bonus fclean re

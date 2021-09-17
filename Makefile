# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: swang <swang@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/02 17:18:13 by swang             #+#    #+#              #
#    Updated: 2021/09/17 15:11:42 by swang            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = gcc

CFLAGS = -Wall -Wextra -Werror

GNL = gnl/get_next_line.c\
	gnl/get_next_line_utils.c

SRC_DIR = src/
SRC_NAME =	main.c\
			init.c\
			map.c\
			check_map.c\
			window.c\
			image.c\
			move.c\
			key_press.c\
			so_long_utils.c\
			ft_split.c

SRCS = $(addprefix $(SRC_DIR), $(SRC_NAME))

OBJS = $(SRCS:.c=.o) $(GNL:.c=.o)

.c.o :
	$(CC) $(CFLAGS) -c $< -o $@

all : $(NAME)
	
$(NAME) : $(OBJS)
		$(CC) $(CFLAGS) -L./mlx -lmlx -framework OpenGL -framework Appkit $(OBJS) -o $(NAME)

clean :
		rm -rf $(OBJS)

fclean :	clean
			rm -rf $(NAME)

re :	fclean all

.PHONY : all clean fclean re
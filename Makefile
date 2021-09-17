# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: swang <swang@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/02 17:18:13 by swang             #+#    #+#              #
#    Updated: 2021/09/18 02:10:18 by swang            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRC_DIR = src/
SRC_NAME =	main.c\
			init.c\
			map.c\
			check_map.c\
			window.c\
			image.c\
			put_element.c\
			move.c\
			key_press.c\
			so_long_utils.c\
			ft_split.c\
			ft_split_utils.c\
			ft_end.c

SRCS = $(addprefix $(SRC_DIR), $(SRC_NAME))

OBJS = $(SRCS:.c=.o)

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
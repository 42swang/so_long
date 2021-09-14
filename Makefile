# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: swang <swang@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/02 17:18:13 by swang             #+#    #+#              #
#    Updated: 2021/09/14 16:38:02 by swang            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = gcc

CFLAGS = -Wall -Wextra -Werror

GNL = gnl/get_next_line.c\
	gnl/get_next_line_utils.c

SRC_DIR = src/
SRC_NAME =	main.c\
			check_map.c\
			open_map.c\
			ft_error.c\
			so_long.c\
			so_long_utils.c\
			init.c\

SRCS = $(addprefix $(SRC_DIR), $(SRC_NAME))

OBJS = $(SRCS:.c=.o) $(GNL:.c=.o)

.c.o :
	$(CC) $(CFLAGS) -c $< -o $@

all : $(NAME)
	
$(NAME) : $(OBJS)
		$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean :
		rm -rf $(OBJS)

fclean :	clean
			rm -rf $(NAME)

re :	fclean all

.PHONY : all clean fclean re
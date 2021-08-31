# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: swang <swang@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/02 17:18:13 by swang             #+#    #+#              #
#    Updated: 2021/08/31 16:12:21 by swang            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

gnl = gnl\get_next_line.c\
	gnl\get_next_line_utils.c\

SRC_DIR = src/

SRC_NAME =	map/check_map.c\
			map/open_map.c\
			ft_error.c\
			so_long.c\
			main.c\

SRCS = $(addprefix $(SRC_DIR), $(SRC_NAME))

OBJS = $(SRCS:.c=.o) $(gnl:.c=.o)

.c.o :
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all : $(NAME)
	
$(NAME) : $(OBJS)
		$(CC) $(CFLAGS) $^ -o $@

clean :
		rm -rf $(OBJS)

fclean :	clean
			rm -rf $(NAME)

re :	fclean
		all

.PHONY : all clean fclean re
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: swang <swang@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/02 17:18:13 by swang             #+#    #+#              #
#    Updated: 2021/09/28 04:05:16 by swang            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
B_NAME = so_long_bonus

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
			ft_itoa.c\
			ft_split.c\
			ft_split_utils.c\
			ft_end.c

BNS_DIR = bonus/
BNS_NAME = main_bonus.c\
			init_bonus.c\
			map_bonus.c\
			check_map_bonus.c\
			window_bonus.c\
			image_bonus.c\
			put_element_bonus.c\
			move_bonus.c\
			key_press_bonus.c\
			so_long_utils_bonus.c\
			ft_itoa_bonus.c\
			ft_split_bonus.c\
			ft_split_utils_bonus.c\
			ft_end_bonus.c

SRCS = $(addprefix $(SRC_DIR), $(SRC_NAME))
BNSS = $(addprefix $(BNS_DIR), $(BNS_NAME))

OBJS = $(SRCS:.c=.o)
B_OBJS = $(BNSS:.c=.o)

.c.o :
	$(CC) $(CFLAGS) -c $< -o $@

all : $(NAME)
	
$(NAME) : $(OBJS)
		make -C ./mlx
		$(CC) $(CFLAGS) -L./mlx -lmlx -framework OpenGL -framework Appkit $(OBJS) -o $(NAME)

bonus : $(B_OBJS)
		make -C ./mlx
		$(CC) $(CFLAGS) -L./mlx -lmlx -framework OpenGL -framework Appkit $(B_OBJS) -o $(B_NAME)
clean :
		make -C ./mlx clean
		rm -rf $(OBJS) $(B_OBJS)

fclean :	clean
			rm -rf $(NAME) $(B_NAME)

re :	fclean all

.PHONY : all clean fclean re bonus
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/20 11:15:57 by pcervill          #+#    #+#              #
#    Updated: 2022/09/20 11:19:16 by pcervill         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Werror -Wextra #-g -fsanitize=address -g3

SRC_DIR = ./src

SRCS = push_swap.c

OBJS = $(addprefix $(SRC_DIR)/, ${SRCS:.c=.o})

NAME = push_swap

LIBFT_PATH = ./libft/

LIBFT = -L$(LIBFT_PATH) $(LIBFT_PATH)libft.a

all:	$(NAME)

$(NAME) :	slibft $(OBJS)
			$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

run:
	./$(NAME) 265

slibft:
		make -C $(LIBFT_PATH)

clean:
		make clean -C $(LIBFT_PATH)
		rm -f $(OBJS)

fclean:	clean
		rm -f $(NAME)
		make fclean -C $(LIBFT_PATH)

re:	fclean all

.PHONY = all clean fclean re

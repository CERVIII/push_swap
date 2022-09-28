# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/20 11:15:57 by pcervill          #+#    #+#              #
#    Updated: 2022/09/28 16:08:25 by pcervill         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Werror -Wextra #-g -fsanitize=address -g3

SRC_DIR = ./src

SRCS = push_swap.c

OBJS = $(addprefix $(SRC_DIR)/, ${SRCS:.c=.o})

NAME = push_swap

LIBFT_PATH = ./libft/

all:		$(NAME)
			@echo " \033[32m[ OK ] | Push_swap ready!\033[0m"

$(NAME):	$(OBJS)
			@echo " \033[33m[ .. ] | Compiling libft..\033[0m"
			make bonus -C $(LIBFT_PATH)
			@echo " \033[32m[ OK ] | Libft ready!\033[0m"
			@echo " \033[33m[ .. ] | Compiling push_swap..\033[0m"
			$(CC) -L $(LIBFT_PATH) -l ft $(CFLAGS) $(OBJS)  -o $(NAME)
			

run:
			./$(NAME) 265

clean:
			make clean -C $(LIBFT_PATH)
			rm -f $(OBJS)

fclean:		clean
			rm -f $(NAME)
			make fclean -C $(LIBFT_PATH)
			@echo " \033[1;31m[ OK ] | Push_swap fclean ready!\033[0m"

re:			fclean all

.PHONY =	all clean fclean re
.SILENT: $(OBJS)
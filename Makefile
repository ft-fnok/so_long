# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nlalleik <nlalleik@students.42wolfsburg.de +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/02 16:09:34 by nlalleik          #+#    #+#              #
#    Updated: 2022/11/13 21:04:00 by nlalleik         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC := 		gcc

CFLAGS 	:=	-Wall -Werror -Wextra

PRINTF 	:=	./printf/libftprintf.a

SRC		:=	so_long.c \

NAME 	= so_long

OBJ		= $(subst .c,.o,$(SRC))

all: $(NAME) 

$(NAME): so_long

so_long: $(PRINTF) 
	$(CC) $(CFLAGS) $(SRC) $(PRINTF) -o $(NAME)

$(NAME): so_long
	@rm -f $(OBJ)

$(PRINTF):
	@make -C ./printf
	@rm -f $(OBJS)
		 
clean: 
	@rm -f $(OBJ)
	@make clean -C ./printf

fclean: clean
	@rm -f $(NAME)
	@rm -f a.out
	@make fclean -C ./printf

re: fclean all

.PHONY:    all    clean    fclean    re bonus
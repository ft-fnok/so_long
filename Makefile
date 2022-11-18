# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nlalleik <nlalleik@student.42wolfsburg.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/02 16:09:34 by nlalleik          #+#    #+#              #
#    Updated: 2022/11/18 12:26:03 by nlalleik         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC := 		gcc

CFLAGS 	:=	-Wall -Werror -Wextra #*-Lmlx -lmlx -framework OpenGL -framework AppKit#

PRINTF 	:=	./printf/libftprintf.a

LIBFT 	:=	./libft/libft.a

SRC		:=	validation-test.c \
			validation-alt.c \
			validation-helpers.c \
			
NAME 	= so_long

OBJS	= $(subst .c,.o,$(SRC))

all: $(NAME) 

#$(NAME): so_long

so_long: $(PRINTF) $(LIBFT)
	$(CC) $(CFLAGS) $(SRC) $(PRINTF) $(LIBFT) -o $(NAME)

$(NAME): $(OBJS) 
#	@rm -f $(OBJS)

$(PRINTF):
	@make -C ./printf
	@rm -f $(OBJS)
	
$(LIBFT):
	@make -C ./libft
	@rm -f $(OBJS)
	
clean: 
	@rm -f $(OBJS)
	@make clean -C ./printf

fclean: clean
	@rm -f $(NAME)
	@rm -f a.out
	@make fclean -C ./printf

re: fclean all

.PHONY:    all    clean    fclean    re bonus
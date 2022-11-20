# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nlalleik <nlalleik@students.42wolfsburg.de +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/02 16:09:34 by nlalleik          #+#    #+#              #
#    Updated: 2022/11/20 22:13:57 by nlalleik         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC := 		gcc

CFLAGS 	:=	-Wall -Werror -Wextra 

LIBS	:=	-Lmlx -lmlx -framework OpenGL -framework AppKit

PRINTF 	:=	./printf/libftprintf.a

LIBFT 	:=	./libft/libft.a

SRC		:=	main.c \
			validation.c \
			validation-helpers.c \
			path-validation.c \
			map_functions.c \
			so_long.c
			
NAME 	= so_long

OBJ		= $(SRC:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
#$(subst .c,.o,$(SRC))

all: prv_libs $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(LIBFT) $(PRINTF) $(LIBS) $(OBJ) -o $(NAME)

#$(NAME): 
	
prv_libs: $(PRINTF) $(LIBFT)
#	$(CC) $(CFLAGS) $(SRC) $(PRINTF) $(LIBFT) -o $(NAME)

#$(NAME): $(OBJ) 

$(PRINTF):
	@make -C ./printf
#	@rm -f $(OBJS)
	
$(LIBFT):
	@make -C ./libft
#	@rm -f $(OBJS)
	
clean: 
	@rm -f $(OBJS)
	@make clean -C ./printf
	@make clean -C ./libft

fclean: clean
	@rm -f $(NAME)
	@rm -f a.out
	@make fclean -C ./printf
	@make fclean -C ./libft

re: fclean all

.PHONY:    all    clean    fclean    re bonus
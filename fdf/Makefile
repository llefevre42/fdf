# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thvocans <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/23 19:03:58 by thvocans          #+#    #+#              #
#    Updated: 2017/06/01 17:23:16 by llefevre         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all libfclean libclean fclean clean re

NAME = fdf

FLAGS = -lmlx -framework OpenGL -framework AppKit

C_FOLDER = ./

H_FOLDER = ./

LIB_FOLD = ./libft/

LIB = libft/libft.a

SRC = fdf parthing_fdf

C_FILE = $(addsuffix .c,$(addprefix $(C_FOLDER),$(SRC)))

O_FILE = $(addsuffix .o,$(SRC))

all: $(NAME)

$(NAME): $(LIB) $(O_FILE)
	@gcc -o $@ $^ $(O_FILE) $(FLAGS) -L$(LIB_FOLD) -I$(LIB_FOLD) -lft
	@echo "\033[32mexecutable OK\033[0m"

./%.o: ./%.c
	@gcc -c  $< -I$(LIB_FOLD) -o $@
	@echo "\033[32m$@\033[0m"

$(LIB):
	@$(MAKE) -C libft

libclean:
	@$(MAKE) -C libft clean

clean: libclean
	@/bin/rm -f $(O_FILE)
	@echo "\033[32mrm .o files\033[0m"

libfclean:
	@$(MAKE) -C libft fclean

fclean: clean libfclean
	@/bin/rm -f $(NAME)
	@echo "\033[32mrm $(NAME)\033[0m"

re: fclean all

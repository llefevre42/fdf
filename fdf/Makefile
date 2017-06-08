# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: llefevre <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/06/07 20:31:18 by llefevre          #+#    #+#              #
#    Updated: 2017/06/07 20:56:41 by llefevre         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all libfclean libclean fclean clean re

NAME = fdf

FLAGS = -lmlx -framework OpenGL -framework AppKit

C_FOLDER = ./

H_FOLDER = ./

LIB_FOLD = ./libft/

LIB = libft/libft.a

SRC = affiche_cub affiche_marge conv_hex fdf full_tab placement print_ligne put_cub put_keycode put_mousse strlen_custom

C_FILE = $(addsuffix .c,$(addprefix $(C_FOLDER),$(SRC)))

O_FILE = $(addsuffix .o,$(SRC))

all: $(NAME)

$(NAME): $(LIB) $(O_FILE)
	@gcc -o $@ $^ $(FLAGS) -L$(LIB_FOLD) -I$(LIB_FOLD) -lft
	@echo "\033[32mexecutable OK\033[0m"
	@echo "\033[32;40moooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo\n\
	o-oooo---ooooooooooooooooooooooooooooooo--oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo----oooooooooo\n\
	o-oooo-------ooooooooooooooooooooooooooo-oo-ooooooooooooooooooo-o-oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo--oooooooooooooo-ooooo\n\
	o-ooooo---------ooooooooooooooooooooooooo-o--oooooooooooooooo-oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo--------oooooooooooooooo-ooo\n\
	oo-ooooo-----------oooooooooooooooooooooo-oo---oooooooooooo-oo--oooooooooooooooooooooooooooooooooooooooooooooooooooooo------------ooooooooooooooooo-oo\n\
	ooo-oooo--------------oooooooooooooooooooo-o----ooooooooo-o-----ooooooooooooooooooooooooooooooooooooooooooooooooooo----------------ooooooooooooooooooo\n\
	ooooo-ooo------------oo-ooooooooooooooooooo------oooo----------oooooooooooooooooooooooooooooooooooooooooooooooo-o-------------------oooooooooooooo-ooo\n\
	ooooooo-oo-----------ooooo-oooooooooooooooo-------------------ooooooooooooooooooooooooooooooooooooooooooooo--ooooo-------------------oooooooooooo-oooo\n\
	ooooooooo-------------ooooooo-ooooooooooooo-----------------------oooooooooooooooooooooooooooooooooooooo-oooooooooo------------------oooooooooo-oooooo\n\
	oooooooooooo-----------oooooooo-ooooooooo-oo-ooooo-----------ooooooo-oooooooooooooooooooooooooooooooo-oooooooooooooo------------------ooooooo-oooooooo\n\
	ooooooooooooooo--------ooooooooooo-oooo-ooooo-ooo---------oooooooooooo-ooooooooooooooooooooooooooo-oooooooooooooooooo------------------ooo--oooooooo-o\n\
	oooooooooooooo-ooo------oooooooooooo---oooooo-oo-------oooooooooooooooo-ooooooooooooooooooooooo-ooooooooooooooooooooo-------------------ooooooooooooo-\n\
	ooooooooooooooo-ooo------ooooooooooooooooooooo-------ooooooooooooooooooo-oooooooooooooooooo--ooooooooooooooooooooooooo-------------------ooooooooooooo\n\
	oooooooooooooooo-ooo--------oooooooo---oooooooooo-oooooooooooooooo---oooo-ooooooooooooooo-ooooooooooooooooooooooooooooo------------------ooooooooooo-o\n\
	oooooooooooooooooo-oo-------ooo--oo-o--ooooooooooooooooooooooooo--oo--ooo-oooooooooooo-ooooooooooooooooooooooooooooooooo------------------ooooooooo-oo\n\
	ooooooooooooooooooooo--------oooooo----oooooooooooooooooooooooo---oo---ooo-oooooooo-ooooooooooooooooooooooooooooooo--oooooo---------------ooooooo-oooo\n\
	oooooooooooooooooooooooo------ooooo----oooooooooooooooooooooooo-------oooo-ooooo-ooooooooooooooooooooooooooo---ooooooooooooo---------------oooo-oooooo\n\
	oooooooooooooooooooooooooooo---oooo---ooooooo--oo---ooooooooooo-------oooooooo-ooooooooooooooooooooooo---oooooooooooooooooooo--------------o-ooooooooo\n\
	oooooooooooooooooooooooooooooooooo--ooooooo--ooooo---ooooooooooo-----oooo---oooooooooooooooooo----ooooooooooooooooooooooooooo------------ooooooooooooo\n\
	oooooooooooooooooooooooooooooooooooo-oooooo------------ooooooooooooooooo-ooooo-ooooooo----oooooooooooooooooooooooooooooooooooo------oooooooooooooooooo\n\
	oooooooooooooooooooooooooooooooooooooo-ooo--------------ooooooooooooooo----ooooo--oooooooooooooooooooooooooooooooooooooo-----ooooooooooooooooooooooooo\n\
	ooooooooooooooooooooooooooooooooooooooo--o---------------ooooooooooooo-------oooo-oooooooooooooooooooooooo-------ooooooooooooooooooooooooooooooooooooo\n\
	oooooooooooooooooooooooooooooooooooooooooo----------------oooooooooo-----------oo--ooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo\n\
	oooooooooooooooooooooooooooooooooooooooooooooo---------------ooo----------------oo-ooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo\n\
	oooooooooooooooooooooooooooooooooooooooooooooooo---------------------------------o-ooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo\n\
	ooooooooooooooooooooooooooooo-ooooooooooooooooo------oo----------------------------ooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo\n\
	oooooooooooooooooooooooooo------------------------ooo----o-----------------------ooo--oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo\n\
	ooooooooooooooooooooooooooo--------------------oooo----ooo--------------------------oo---ooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo\n\
	ooooooooooooooooooooooooooooooooooooooooooooooo------oooo---oooooooooooo---------------ooo--oooooooooooooooooooooooooooooooooooooooooooooooooooooooooo\n\
	oooooooooooooooooooooooooooooooooooooo--------------oooo---oooooooooooooo----o------------oo---ooooooooooooooooooooooooooooooooooooooooooooooooooooooo\n\
	ooooooooooooooooooooooooooooooooo----------------oooooo---ooooooooooooooo----o---------------ooo---o---ooooooooooooooooooooooooooooooooooooooooooooooo\n\
	ooooooooooooooooooooooooooooooo----------oooooooooo-------ooooooooooooooo----oo----o------------ooo-ooo-----------------oooooooooooooooooooooooooooooo\n\
	ooooooooooooooooooooooooooooooooo--ooooooooooo---------ooooooooooooooooo------o----------------------oo--oo-------ooooooooo-oooooooooooooooooooooooooo\n\
	oooooooooooooooooooooooooooooooooooooooooo---------ooooooooooooooooooooo----------------------------------ooo--------------ooooooooooooooooooooooooooo\n\
	ooooooooooooooooooooooooooooooooooooooooo------ooooooooooooooooooooooooo-------------o-----oooo-------o---oooooooooooooooooooooooooooooooooooooooooooo\n\
	oooooooooooooooooooooooooooooooooooooooo-o---oooooooooooooooooooooooooo------oo--oo-ooo----ooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo\033[0m"

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

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/05 11:40:02 by mmanley           #+#    #+#              #
#    Updated: 2018/06/12 15:43:24 by mmanley          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = asm

CFLAGS = -Wall -Wextra -Werror

LIB = libftprintf.a

LIB_PATH = ../printf/

INC = includes

RED = \x1b[31m

GREEN = \x1b[32m

WHITE = \x1b[0m

OBJ_PATH = objs/

FAN = -fsanitize=address -g3

SRCS =	main.c\
		pars/get_info.c\
		pars/check_line.c\
		pars/parsing.c\
		param/param_op.c\
		param/param_label.c\
		param/param_code.c\
		param/param_type.c\
		errors/errors.c\
		errors/debug.c\
		errors/err_parsing.c\
		asm_to_byte/create_file.c\
		asm_to_byte/write_bytes.c\
		options/options.c\
		options/options_file.c

OBJS_BASE = $(SRCS:%.c=%.o)

OBJS = $(addprefix $(OBJ_PATH), $(OBJS_BASE))

all : $(LIB) $(NAME)

$(NAME) : objs $(OBJS)
	@gcc -o $@ $(OBJS) $(LIB_PATH)/$(LIB) -I $(LIB_PATH)/ -I ./$(INC) $(CFLAGS)
	@echo "${WHITE}Asm			${GREEN}DONE${WHITE}"

$(LIB) :
	@make -C $(LIB_PATH)

objs :
	@mkdir -p objs
	@mkdir -p objs/errors
	@mkdir -p objs/pars
	@mkdir -p objs/param
	@mkdir -p objs/options
	@mkdir -p objs/asm_to_byte

$(OBJ_PATH)%.o: %.c $(INC)/asm.h
	@gcc -o $@ -c $< -I $(LIB_PATH)/ -I ./$(INC)

clean :
	@rm -rf $(OBJS) objs
	@cd $(LIB_PATH) && $(MAKE) clean
	@echo "${WHITE}Asm objs		${RED}DEL${WHITE}"

fclean : clean
	@cd $(LIB_PATH) && $(MAKE) fclean
	@rm $(NAME)
	@echo "${WHITE}Asm status		${RED}DEL${WHITE}"

re : fclean all

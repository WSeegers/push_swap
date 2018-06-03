# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/03 20:54:46 by wseegers          #+#    #+#              #
#    Updated: 2018/06/03 22:50:43 by wseegers         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = checker
CC = clang
CFLAGS = -Werror -Wall -Wextra 
INC = -I toolkit-wtc/include -I src
LIB = toolkit-wtc/toolkit-wtc.a

SRC_PATH = src
SRC = checker.c e_exit.c init_stacks.c get_numbers.c has_dup.c
BIN_PATH = bin
BIN := $(SRC:%.c=$(BIN_PATH)/%.o)
DEP := $(BIN:%.o=%.d)

all : make_lib $(NAME) 

make_lib :
	make -C toolkit-wtc

$(NAME) : $(MAIN) $(BIN)
	$(CC) $(CFLAGS) $(INC) -o $@ $^ $(LIB)

$(BIN_PATH)/%.o : $(SRC_PATH)/%.c
	@mkdir -p $(BIN_PATH)
	$(CC) $(CFLAGS) $(INC) -MMD -c $< -o $@

-include $(DEP)

clean :
	rm -rf $(BIN_PATH)

fclean : clean
	rm -f $(NAME)
	make fclean -C toolkit-wtc

re : fclean all

.PHONEY : usage all make_all  clean  fclean  re

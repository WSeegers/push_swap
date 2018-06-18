# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/03 20:54:46 by wseegers          #+#    #+#              #
#    Updated: 2018/06/18 22:44:40 by wseegers         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = checker push_swap
CC = clang
CFLAGS = -Werror -Wall -Wextra 
INC = -I toolkit-wtc/include -I src
LIB = toolkit-wtc/toolkit-wtc.a

SRC_PATH = src
SRC = get_info.c get_numbers.c create_stack.c e_exit.c stack_print.c\
	  stack_pop.c stack_add.c stack_init.c stack_rot.c print_stacks.c\
	  stack_swap.c stack_ops.c check_stacks.c stack_copy.c stack_is_sorted.c\
	  rank_info.c op_print.c stack_find_rank.c state_ops.c\
	  create_state.c next_state.c
BIN_PATH = bin
BIN := $(SRC:%.c=$(BIN_PATH)/%.o)
DEP := $(BIN:%.o=%.d)

all : make_lib $(NAME) 

make_lib :
	make -C toolkit-wtc

$(NAME) : % : $(SRC_PATH)/%.c $(BIN)
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

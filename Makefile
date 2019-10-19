# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nharra <nharra@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/04 12:53:22 by nharra            #+#    #+#              #
#    Updated: 2019/10/19 13:56:27 by nharra           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Werror -Wextra

SRCS_CHECKER =\
	checker.c

SRCS_STACK =\
	check_cmd.c\
	stack_op.c\
	stack_input.c\

SRCS_PUSH_SWAP =\
	find_middle.c\
	half_to_a.c\
	half_to_b.c\
	push_swap.c\
	sort_stack.c\
	check_simple_a.c\
	check_simple_b.c\
	sort_hard_3a.c\
	sort_hard_3b.c\

SOURCES_DIR_CHECKER = checker_dir

SOURCES_DIR_PUSH_SWAP = push_swap_dir

SOURCES_DIR_STACK = stack_dir

SOURCE_CHECKER = $(addprefix $(SOURCES_DIR_CHECKER)/, $(SRCS_CHECKER))

SOURCE_PUSH_SWAP = $(addprefix $(SOURCES_DIR_PUSH_SWAP)/, $(SRCS_PUSH_SWAP))

SOURCE_STACK = $(addprefix $(SOURCES_DIR_STACK)/, $(SRCS_STACK))

OBJECTS_DIR = obj

OBJ_CHECKER = $(SRCS_CHECKER:.c=.o)

OBJ_STACK = $(SRCS_STACK:.c=.o)

OBJ_PUSH_SWAP = $(SRCS_PUSH_SWAP:.c=.o)

OBJECTS_CHECKER = $(addprefix $(OBJECTS_DIR)/, $(OBJ_CHECKER))

OBJECTS_STACK = $(addprefix $(OBJECTS_DIR)/, $(OBJ_STACK))

OBJECTS_PUSH_SWAP = $(addprefix $(OBJECTS_DIR)/, $(OBJ_PUSH_SWAP))

INCLUDE_DIR = includes

vpath %.c $(SOURCES_DIR_CHECKER) $(SOURCES_DIR_STACK) $(SOURCES_DIR_PUSH_SWAP)

INCLUDES = stack.h

NAME_CHECKER = checker

NAME_PUSH_SWAP = push_swap

LIBFT = $(addprefix $(LIBFT_DIR)/, libft.a)

LIBFT_DIR = libft

LIBFT_INCLUDE_DIR = libft/includes

all: $(NAME_CHECKER) $(NAME_PUSH_SWAP)

$(NAME_CHECKER): $(LIBFT_DIR)/libft.a $(OBJECTS_STACK) $(OBJECTS_CHECKER)
	gcc $(FLAGS) -o $(NAME_CHECKER) $(OBJECTS_CHECKER) $(OBJECTS_STACK) -I $(LIBFT_INCLUDE_DIR) -I $(INCLUDE_DIR) -L libft/ -lft

$(NAME_PUSH_SWAP): $(LIBFT_DIR)/libft.a $(OBJECTS_STACK) $(OBJECTS_PUSH_SWAP)
	gcc $(FLAGS) -o $(NAME_PUSH_SWAP) $(OBJECTS_PUSH_SWAP) $(OBJECTS_STACK) -I $(LIBFT_INCLUDE_DIR) -I $(INCLUDE_DIR) -L libft/ -lft

$(OBJECTS_DIR)/%.o: %.c
	gcc -I$(INCLUDE_DIR) -I$(LIBFT_INCLUDE_DIR) -c $< -o $@ $(FLAGS)

$(OBJECTS_STACK): | $(OBJECTS_DIR)

$(OBJECTS_DIR):
	mkdir $(OBJECTS_DIR)

$(LIBFT_DIR)/libft.a:
	make -C $(LIBFT_DIR) all

fclean:
	make -C $(LIBFT_DIR) fclean
	rm -rf $(NAME_CHECKER)
	rm -rf $(NAME_PUSH_SWAP)
	rm -rf $(OBJECTS_DIR)

clean:
	make -C $(LIBFT_DIR) clean
	rm -rf $(OBJECTS_DIR)

re: fclean all

.PHONY: all, clean, fclean, re, make_lib

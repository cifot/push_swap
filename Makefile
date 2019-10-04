# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nharra <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/04 12:53:22 by nharra            #+#    #+#              #
#    Updated: 2019/10/04 12:53:49 by nharra           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Werror -Wextra

SRCS_CHECKER =\
	checker.c

SRCS_STACK =\
	stack.c \
	stack_info.c \
	stack_info_2.c \
	stack_input.c  \
	stack_commands.c \
	stack_array.c \

SRCS_PUSH_SWAP =\
	push_swap.c \
	output.c \
	output_b.c \
	output_b_first.c \
	output_a_first.c \
	output_last.c \
	output_start_check_sort.c \

SOURCES_DIR_CHECKER = srcs_checker

SOURCES_DIR_PUSH_SWAP = srcs_push_swap

SOURCES_DIR_STACK = srcs_stack

SOURCE_CHECKER = $(addprefix $(SOURCES_DIR_CHECKER)/, $(SRCS_CHECKER))

SOURCE_PUSH_SWAP = $(addprefix $(SOURCES_DIR_PUSH_SWAP)/, $(SRCS_PUSH_SWAP))

SOURCE_STACK = $(addprefix $(SOURCES_DIR_STACK)/, $(SRCS_STACK))

OBJECTS_DIR = obj

OBJECTS_DIR_CHECKER = $(addprefix $(OBJECTS_DIR)/, checker)

OBJECTS_DIR_STACK = $(addprefix $(OBJECTS_DIR)/, stack)

OBJECTS_DIR_PUSH_SWAP = $(addprefix $(OBJECTS_DIR)/, push_swap)

OBJ_CHECKER = $(SRCS_CHECKER:.c=.o)

OBJ_STACK = $(SRCS_STACK:.c=.o)

OBJ_PUSH_SWAP = $(SRCS_PUSH_SWAP:.c=.o)

OBJECTS_CHECKER = $(addprefix $(OBJECTS_DIR_CHECKER)/, $(OBJ_CHECKER))

OBJECTS_STACK = $(addprefix $(OBJECTS_DIR_STACK)/, $(OBJ_STACK))

OBJECTS_PUSH_SWAP = $(addprefix $(OBJECTS_DIR_PUSH_SWAP)/, $(OBJ_PUSH_SWAP))

INCLUDE_DIR = includes

INCLUDES = stack.h \
			push_swap.h

NAME_CHECKER = checker

NAME_PUSH_SWAP = push_swap

LIBFT = $(addprefix $(LIBFT_DIR)/, libft.a)

LIBFT_DIR = libft

LIBFT_INCLUDE_DIR = libft/includes

all: $(NAME_PUSH_SWAP) $(NAME_CHECKER)

$(NAME_CHECKER): $(LIBFT_DIR)/libft.a $(OBJECTS_DIR) $(OBJECTS_DIR_STACK) $(OBJECTS_STACK) $(OBJECTS_DIR_CHECKER) $(OBJECTS_CHECKER)
	gcc -o $(NAME_CHECKER) $(OBJECTS_CHECKER) $(OBJECTS_STACK) -I $(LIBFT_INCLUDE_DIR) -I $(INCLUDE_DIR) -L libft/ -lft $(FLAGS)

$(NAME_PUSH_SWAP): $(LIBFT_DIR)/libft.a $(OBJECTS_DIR) $(OBJECTS_DIR_STACK) $(OBJECTS_STACK) $(OBJECTS_DIR_PUSH_SWAP) $(OBJECTS_PUSH_SWAP)
	gcc -o $(NAME_PUSH_SWAP) $(OBJECTS_PUSH_SWAP) $(OBJECTS_STACK) -I $(LIBFT_INCLUDE_DIR) -I $(INCLUDE_DIR) -L libft/ -lft $(FLAGS)

$(OBJECTS_CHECKER): | $(OBJECTS_DIR)

$(OBJECTS_PUSH_SWAP): | $(OBJECTS_DIR)

$(OBJECTS_DIR):
	mkdir $(OBJECTS_DIR)

$(OBJECTS_DIR_CHECKER):
	mkdir $(OBJECTS_DIR_CHECKER)

$(OBJECTS_DIR_STACK):
	mkdir $(OBJECTS_DIR_STACK)

$(OBJECTS_DIR_PUSH_SWAP):
	mkdir $(OBJECTS_DIR_PUSH_SWAP)

$(OBJECTS_DIR_CHECKER)/%.o: $(SOURCES_DIR_CHECKER)/%.c
	gcc  -I$(INCLUDE_DIR) -I$(LIBFT_INCLUDE_DIR) -c $< -o $@ $(FLAGS)

$(OBJECTS_DIR_STACK)/%.o: $(SOURCES_DIR_STACK)/%.c
	gcc  -I$(INCLUDE_DIR) -I$(LIBFT_INCLUDE_DIR) -c $< -o $@ $(FLAGS)

$(OBJECTS_DIR_PUSH_SWAP)/%.o: $(SOURCES_DIR_PUSH_SWAP)/%.c
	gcc  -I$(INCLUDE_DIR) -I$(LIBFT_INCLUDE_DIR) -c $< -o $@ $(FLAGS)

$(LIBFT_DIR)/libft.a:
	make -C $(LIBFT_DIR) all

fclean: clean
	make -C $(LIBFT_DIR) fclean
	rm -rf $(NAME_CHECKER)
	rm -rf $(NAME_PUSH_SWAP)

clean:
	make -C $(LIBFT_DIR) clean
	rm -rf $(OBJECTS_DIR)

re: fclean all

.PHONY: all, clean, fclean, re, make_lib

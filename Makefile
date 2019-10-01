# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nharra <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/15 15:50:31 by nharra            #+#    #+#              #
#    Updated: 2019/10/01 16:42:54 by nharra           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CHECKER = checker

FLAGS = -Wall -Werror -Wextra

SOURCES_CHECKER_DIR = check_dir
SOURCES_CHECKER=\
	checker.c\
	take_ops.c\


SOURCES_UTILS_DIR = utilities
SOURCES_UTILS =\
	ft_atol.c\
	ft_bzero.c\
	ft_strlen.c\
	ft_dlist_del.c\
	ft_dlist_delone.c\
	ft_dlist_find_tag.c\
	ft_dlist_push.c\
	ft_dlist_pushtag.c\
	ft_dlist_simple_del.c\
	ft_dlist_simple_delone.c\
	ft_memalloc.c\
	ft_safe_strcat.c\
	ft_strcat.c\
	ft_strchr.c\
	ft_strcmp.c\
	ft_strcpy.c\
	get_next_line.c\
	op_push.c\
	op_swap.c\
	op_rotate.c\
	op_rev_rotate.c\
	ft_memcpy.c\
	ft_dlist_is_sorted.c\
	ft_memdel.c\
	init_stack.c\

vpath %.c = $(SOURCES_CHECKER_DIR) $(SOURCES_UTILS_DIR)

OBJECTS_DIR = obj
OBJ_CHECKER = $(SOURCES_UTILS:.c=.o) $(SOURCES_CHECKER:.c=.o)
OBJECTS_CHECKER = $(addprefix $(OBJECTS_DIR)/, $(OBJ_CHECKER))

INC_DIR = includes
vpath %.h = $(INC_DIR)

all :$(CHECKER)

$(OBJECTS_DIR):
	mkdir $(OBJECTS_DIR)

$(OBJECTS_DIR)/%.o: %.c
	gcc $(FLAGS) -I $(INC_DIR) -c $< -o $@


$(CHECKER): $(OBJECTS_CHECKER) $(INC_DIR)/utilities.h $(INC_DIR)/checker.h
	gcc $(FLAGS) $(OBJECTS_CHECKER) -o $(CHECKER)

$(OBJECTS_CHECKER): | $(OBJECTS_DIR)

fclean: clean
	rm -f $(CHECKER)

clean:
	rm -rf $(OBJECTS_DIR)

re: fclean all

.PHONY: all, clean, fclean, re

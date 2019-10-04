# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nharra <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/17 12:21:44 by nharra            #+#    #+#              #
#    Updated: 2019/10/04 20:43:36 by nharra           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Werror -Wextra

SOURCES_MEMORY =\
	ft_atol.c\
	ft_atoi.c\
	ft_bzero.c\
	ft_isalnum.c\
	ft_isalpha.c\
	ft_isascii.c\
	ft_isdigit.c\
	ft_isprint.c\
	ft_memccpy.c\
	ft_memchr.c\
	ft_memcmp.c\
	ft_memcpy.c\
	ft_memmove.c\
	ft_memset.c\
	ft_strcat.c\
	ft_strchr.c\
	ft_strcmp.c\
	ft_strcpy.c\
	ft_strdup.c\
	ft_strlcat.c\
	ft_strlen.c\
	ft_strncat.c\
	ft_strncmp.c\
	ft_strncpy.c\
	ft_strnstr.c\
	ft_strrchr.c\
	ft_strstr.c\
	ft_tolower.c\
	ft_toupper.c\
	ft_itoa.c\
	ft_memalloc.c\
	ft_memdel.c\
	ft_putchar.c\
	ft_putchar_fd.c\
	ft_putendl.c\
	ft_putendl_fd.c\
	ft_putnbr.c\
	ft_putnbr_fd.c\
	ft_putstr.c\
	ft_putstr_fd.c\
	ft_strclr.c\
	ft_strdel.c\
	ft_strequ.c\
	ft_striter.c\
	ft_striteri.c\
	ft_strjoin.c\
	ft_strmap.c\
	ft_strmapi.c\
	ft_strnequ.c\
	ft_strnew.c\
	ft_strsplit.c\
	ft_strsub.c\
	ft_strtrim.c\
	ft_safe_strcat.c\
	ull_len_base.c\
	ll_len_base.c\
	ft_ulltostr.c\
	ft_lltostr.c\

SOURCES_DOUBLE_LIST =\
	ft_dlist_del.c\
	ft_dlist_delone.c\
	ft_dlist_find_tag.c\
	ft_dlist_find.c\
	ft_dlist_push.c\
	ft_dlist_simple_del.c\
	ft_dlist_simple_delone.c\
	ft_dlist_del_link.c\
	ft_dlist_delone_link.c\
	ft_dlist_push_link.c\

SOURCES_SINGLE_LIST =\
	ft_lstnew.c\
	ft_lstdelone.c\
	ft_lstdel.c\
	ft_lstadd.c\
	ft_lstiter.c\
	ft_lstmap.c\

SOURCES_FILE=\
	get_next_line.c\

SOURCES_MEMORY_DIR = memory
SOURCES_SINGLE_LIST_DIR = singly_linked_list
SOURCES_DOUBLE_LIST_DIR = double_linked_list
SOURCES_FILE_DIR = file

SOURCE = $(notdir $(SOURCES))

SOURCES = \
	$(addprefix $(SOURCES_MEMORY_DIR)/, $(SOURCES_MEMORY))\
	$(addprefix $(SOURCES_SINGLE_LIST_DIR)/, $(SOURCES_SINGLE_LIST))\
	$(addprefix $(SOURCES_DOUBLE_LIST_DIR)/, $(SOURCES_DOUBLE_LIST))\
	$(addprefix $(SOURCES_FILE_DIR)/, $(SOURCES_FILE))\

OBJECTS_DIR = obj

OBJ = $(SOURCE:.c=.o)

OBJECTS = \
	$(addprefix $(OBJECTS_DIR)/, $(OBJ))

INCLUDE_DIR = includes

INCLUDES = libft.h

NAME = libft.a

vpath %.c $(SOURCES_MEMORY_DIR) $(SOURCES_SINGLE_LIST_DIR) $(SOURCES_DOUBLE_LIST_DIR) $(SOURCES_FILE_DIR)

vpath %.h $(INCLUDE_DIR)

all: $(NAME)

$(OBJECTS_DIR):
	mkdir $(OBJECTS_DIR)

$(OBJECTS_DIR)/%.o: %.c $(INCLUDES)
	gcc $(FLAGS) -I$(INCLUDE_DIR) -c $< -o $@

$(NAME): $(OBJECTS_DIR) $(OBJECTS)
	ar rc $(NAME) $(OBJECTS)
	ranlib $(NAME)

clean:
	rm -rf $(OBJECTS_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re

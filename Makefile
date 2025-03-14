# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chiarakappe <chiarakappe@student.42.fr>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/06 15:51:42 by ckappe            #+#    #+#              #
#    Updated: 2025/03/12 17:56:48 by chiarakappe      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Makefile for push_swap project

# Project name
NAME = push_swap

# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Wextra -Werror -g

# Header files
HEADERS = push_swap.h

# Source files
SRCS = utils/array_prep.c utils/helpers.c utils/map_to_ranks.c \
utils/error_checking.c utils/init_arr.c utils/split.c \
ps_operations/push.c ps_operations/swap.c \
ps_operations/rotate.c ps_operations/revrotate.c \
sorting/chunk_sort.c sorting/bring_to_top.c sorting/rotate_struct.c \
sorting/sort_five.c sorting/sort_three.c sorting/helpers_chunk_sort.c \
main.c

# Object files (replace .c with .o). Compiling source files to object files
OBJS = $(SRCS:.c=.o)

# Delivery files
DELIVERY_FILES = $(NAME)

# Phony targets
.PHONY: all clean fclean re

# Rule for creating object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Default target
all: $(NAME)

# Create the library
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

# Clean up object files
clean:
	rm -f $(OBJS)

# Clean up object files and the library
fclean: clean
	rm -f $(NAME)

# Rebuild the library
re: fclean all

valgrind: re
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(NAME)
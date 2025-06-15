# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jdub <jdub@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/01 00:00:00 by jdub              #+#    #+#              #
#    Updated: 2025/06/15 16:24:06 by jdub             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCDIR = src/
INCDIR = inc/
OBJDIR = obj/

SOURCES = main.c \
          stack_operations.c \
          swap_operations.c \
          push_operations.c \
          rotate_operations.c \
          reverse_rotate_operations.c \
          parsing.c \
          utils.c \
          algorithm.c

SRCS = $(addprefix $(SRCDIR), $(SOURCES))
OBJS = $(addprefix $(OBJDIR), $(SOURCES:.c=.o))

INCLUDES = -I$(INCDIR)

all: $(NAME)

$(NAME): $(OBJDIR) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(OBJDIR)%.o: $(SRCDIR)%.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re 
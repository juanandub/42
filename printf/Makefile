# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpareja- <jpareja-@student.42malaga.c>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/02 12:42:29 by angellop          #+#    #+#              #
#    Updated: 2025/01/03 19:54:55 by jpareja-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
LIBFT = libft.a
LIBFT_DIR = ../libft

MY_SOURCES =  ft_printf.c \ ft_handle_int.c
			 
MY_SOURCES_BONUS = 

CC = cc # compiler
CCFLAGS = -Wall -Wextra -Werror # flags for warnings and errors
RM = rm -rf # command to remove files
AR = ar rcs

# Object files corresponding to the source files
OBJS = $(MY_SOURCES:.c=.o)
BONUS_OBJS = $(MY_SOURCES_BONUS:.c=.o)

%.o : %.c
	$(CC) $(CCFLAGS) -c $< -o $@

all: libft $(NAME)

libft:
	@echo "Compilando libft..."
	$(MAKE) -C $(LIBFT_DIR)

bonus: $(OBJS) $(BONUS_OBJS)
	$(AR) $(NAME) $(OBJS) $(BONUS_OBJS)

# Build the static library
$(NAME) : $(OBJS)
	$(AR) $(NAME) $(OBJS)

test: test.o $(NAME)
	$(CC) $(CCFLAGS) test.c $(NAME) $(LIBFT_DIR)/$(LIBFT) -o test

clean:
	$(RM) $(OBJS) $(BONUS_OBJS)

fclean: clean
	$(RM) $(NAME)

re:	fclean all # Clean and recompile everything

.PHONY: all clean fclean re bonus

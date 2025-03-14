# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpareja- <jpareja-@student.42malaga.c>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/02 12:42:29 by angellop          #+#    #+#              #
#    Updated: 2025/01/07 12:56:39 by jpareja-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
LIBFT = libft.a
LIBFT_DIR = libft

MY_SOURCES =  ft_printf.c ft_handle_int.c ft_putnbr_base.c ft_handle_p.c

CC = cc # compiler
CCFLAGS = -Wall -Wextra -Werror # flags for warnings and errors
RM = rm -rf # command to remove files
AR = ar rcs

# Object files corresponding to the source files
OBJS = $(MY_SOURCES:.c=.o)

%.o : %.c
	$(CC) $(CCFLAGS) -c $< -o $@

all: $(NAME)

libft:
	@echo "Compilando libft..."
	$(MAKE) -C $(LIBFT_DIR)

# Build the static library
$(NAME): libft $(OBJS)
	@echo "Copiando libft.a en libftprintf.a..."
	cp $(LIBFT_DIR)/$(LIBFT) $(NAME)
	@echo "Agregando objetos de ft_printf a libftprintf.a..."
	$(AR) $(NAME) $(OBJS)

test: test.o $(NAME)
	$(CC) $(CCFLAGS) test.c $(NAME) $(LIBFT_DIR)/$(LIBFT) -o test

clean:
	$(RM) $(OBJS) $(BONUS_OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re:	fclean all # Clean and recompile everything

.PHONY: all clean fclean re libft

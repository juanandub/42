# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpareja- <jpareja-@student.42malaga.c>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/02 12:42:29 by angellop          #+#    #+#              #
#    Updated: 2024/12/17 14:00:42 by jpareja-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc # compiler
CCFLAGS = -Wall -Wextra -Werror # flags for warnings and errors
RM = rm -rf # command to remove files

DEPS = $(MY_SOURCES:.c=.d)

MY_SOURCES = ft_isdigit.c \
             ft_isalnum.c \
             ft_isalpha.c \
             ft_isascii.c \
             ft_isprint.c \
             ft_strlen.c \
             ft_memset.c \
             ft_bzero.c \
             ft_memcpy.c \
             ft_memmove.c \
             ft_strlcpy.c \
             ft_strlcat.c \
             ft_toupper.c \
             ft_tolower.c \
             ft_strchr.c \
             ft_strrchr.c \
             ft_strncmp.c \
             ft_memchr.c \
             ft_memcmp.c \
             ft_strnstr.c \
             ft_atoi.c \
             ft_calloc.c \
             ft_strdup.c \
             ft_substr.c \
             ft_strjoin.c \
             ft_split.c \
             ft_itoa.c \

# Object files corresponding to the source files
OBJS = $(MY_SOURCES:.c=.o)

# Build the static library
$(NAME) : $(OBJS)
	@ar crs $(NAME) $(OBJS)

all: $(NAME)

%.d : %.c
	@$(CC) -M $(CCFLAGS) $< > $@;

-include $(DEPS)
# Compile .c files to .o object files
%.o : %.c
	@$(CC) $(CCFLAGS) -c -o $@ $<

clean:
	@$(RM) $(OBJS)

fclean: clean
	@rm -f $(NAME) $(DEPS)

re:	fclean all # Clean and recompile everything

.PHONY: all clean fclean re

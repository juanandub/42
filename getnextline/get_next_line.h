/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpareja- <jpareja-@student.42malaga.c>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 12:57:37 by jpareja-          #+#    #+#             */
/*   Updated: 2025/01/27 13:45:05 by jpareja-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

#include <unistd.h>
#include <fcntl.h>

char	*get_next_line(int fd);
char	*ft_strdup(const char *s);
size_t	ft_strlen(const char *str);


#endif

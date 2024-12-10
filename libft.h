/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpareja- <jpareja-@student.42malaga.c>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 12:57:37 by jpareja-          #+#    #+#             */
/*   Updated: 2024/12/06 11:10:52 by jpareja-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <errno.h>

int		ft_isdigit(int c);
int		ft_isalpha(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
size_t	ft_strlen(const char *str);
void	*ft_memset(void *s, int c, size_t n);
char	*ft_strchr(const char *string, int c);
char	*ft_strchr(const char *string, int c);
char	*ft_strrchr(const char *string, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t count);
void	*ft_memchr(const void *s, int c, size_t n);
size_t	ft_strlcat(char *dest, char *src, size_t size);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
int		ft_atoi(const char *nptr);
size_t	strlcpy(char *dst, const char *src, size_t size);
void	ft_bzero(void *s, size_t n);
size_t	strlcpy(char *dst, const char *src, size_t size);
void	*calloc(size_t nmemb, size_t size);
char	*strnstr(const char *big, const char *little, size_t len);
char	*strdup(const char *s);

#endif
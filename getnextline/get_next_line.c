/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpareja- <jpareja-@student.42malaga.c>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 21:01:40 by jpareja-          #+#    #+#             */
/*   Updated: 2025/02/18 18:34:54 by jpareja-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	find_newline(const char *c)
{
	int	i;

	i = 0;
	if (!c)
		return (-1);
	while (c[i] != '\0')
	{
		if (c[i] == '\n')
		{
			return (i);
		}
		i++;
	}
	return (-1);
}

static char	*ft_strndup(const char *s, size_t n)
{
	size_t	i;
	char	*dup;

	if (!s)
		return (NULL);
	dup = malloc((n + 1) * sizeof(char));
	if (!dup)
		return (NULL);
	i = 0;
	while (i < n && s[i] != '\0')
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

static void	ft_aux(char **stash, char *buffer, int fd)
{
	ssize_t		b_read;
	char		*tmp;

	while (find_newline(*stash) == -1)
	{
		b_read = read(fd, buffer, BUFFER_SIZE);
		if (b_read <= 0)
		{
			if (*stash && b_read == -1)
			{
				free(*stash);
				*stash = NULL;
			}
			return ;
		}
		buffer[b_read] = '\0';
		if (!*stash)
			*stash = ft_strdup(buffer);
		else
		{
			tmp = ft_strjoin(*stash, buffer);
			free(*stash);
			*stash = tmp;
		}
	}
}

static char	*ft_extract_line(char **stash, int index)
{
	char	*line;
	char	*tmp;

	if (!*stash || **stash == '\0')
	{
		free(*stash);
		return (NULL);
	}
	if (index == -1)
	{
		line = ft_strdup(*stash);
		free(*stash);
		*stash = NULL;
		return (line);
	}
	line = ft_strndup(*stash, index + 1);
	tmp = ft_strdup(*stash + 1 + index);
	free(*stash);
	*stash = tmp;
	if (!**stash)
	{
		free(*stash);
		*stash = NULL;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*buffer;
	int			i;

	if (BUFFER_SIZE <= 0 || fd < 0 || read(fd, 0, 0) < 0)
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	ft_aux(&stash, buffer, fd);
	free(buffer);
	if (!stash || *stash == '\0')
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	i = find_newline(stash);
	return (ft_extract_line(&stash, i));
}

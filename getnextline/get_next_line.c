/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpareja- <jpareja-@student.42malaga.c>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 21:01:40 by jpareja-          #+#    #+#             */
/*   Updated: 2025/01/30 18:14:08 by jpareja-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	find_newline(const char *c)
{
	int i = 0;
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

static void	ft_aux(char **stash, char *buffer, int fd)
{
	char		*line;
	ssize_t		b_read;
	char		*tmp;
	
	while (find_newline(stash) == -1)
	{
		b_read = read(fd, buffer, BUFFER_SIZE);
		if (b_read <= 0)
			return (0);
		buffer[b_read]='\0';
		if (!*stash)
			*stash = ft_strdup(buffer);
		else
		{
			tmp = ft_stjoin(*stash, buffer);
			free(*stash);
			*stash = tmp;
		}
	}
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*buffer;
	int			i;
	
	stash = NULL;
	if (BUFFER_SIZE <= 0 || fd < 0 || read(fd, 0, 0) < 0)
		return (NULL);

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	ft_aux(&stash, buffer, fd);
	free(buffer);
	if (!stash || *stash == '\0')
		return (NULL);
	i = find_newline(stash);
	return (0);
}

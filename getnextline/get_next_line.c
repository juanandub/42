/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpareja- <jpareja-@student.42malaga.c>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 21:01:40 by jpareja-          #+#    #+#             */
/*   Updated: 2025/01/27 13:48:52 by jpareja-         ###   ########.fr       */
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

char	*get_next_line(int fd) //
{
	static char	*stash;
	char		*buffer;
	char		*line;
	ssize_t		b_read;
	char		*tmp;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (BUFFER_SIZE <= 0 || fd < 0 || read(fd, 0, 0) < 0)
	{
		free(buffer);
		return (0);
	}
	if (!buffer)
		return (0);
	while (find_newline(stash) == -1)
	{
		b_read = read(fd, buffer, BUFFER_SIZE);
		if (b_read <= 0)
			break;
		buffer[b_read]='\0';
		if (!stash)
			stash = ft_strdup(buffer);
		else
		{
			tmp = ft_stjoin(stash, buffer);
			free(stash);
			stash = tmp;
		}
	}
	return (0);
}
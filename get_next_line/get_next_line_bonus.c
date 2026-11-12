/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkryvono <dkryvono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 15:00:00 by dkryvono          #+#    #+#             */
/*   Updated: 2026/10/26 15:00:00 by dkryvono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_create_stash(char *stash, size_t line_size)
{
	size_t	stash_size;
	char	*temp;

	stash_size = ft_strlen(stash + line_size);
	if (stash_size == 0)
		return (free(stash), NULL);
	temp = malloc(stash_size + 1);
	if (!temp)
		return (free(stash), NULL);
	ft_memcpy(temp, stash + line_size, stash_size);
	temp[stash_size] = '\0';
	free(stash);
	return (temp);
}

static char	*ft_read_stash(int fd, char *stash)
{
	char	*buffer;
	ssize_t	bytes;

	buffer = malloc((size_t)BUFFER_SIZE + 1);
	if (!buffer)
		return (free(stash), NULL);
	while (!ft_set_end(stash))
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes < 0)
			return (free(buffer), free(stash), NULL);
		if (bytes == 0)
			break ;
		buffer[bytes] = '\0';
		stash = ft_strjoin(stash, buffer);
		if (!stash)
			return (free(buffer), NULL);
	}
	free(buffer);
	return (stash);
}

static char	*ft_create_line(char *stash)
{
	char	*line;
	size_t	line_size;

	if (!stash || !stash[0])
		return (NULL);
	line_size = ft_line_count(stash);
	line = malloc(line_size + 1);
	if (!line)
		return (NULL);
	ft_memcpy(line, stash, line_size);
	line[line_size] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*stash[1024];
	char		*line;
	size_t		line_size;

	if (fd < 0 || fd >= 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	stash[fd] = ft_read_stash(fd, stash[fd]);
	if (!stash[fd])
		return (NULL);
	line = ft_create_line(stash[fd]);
	if (!line)
	{
		free(stash[fd]);
		stash[fd] = NULL;
		return (NULL);
	}
	line_size = ft_line_count(stash[fd]);
	stash[fd] = ft_create_stash(stash[fd], line_size);
	return (line);
}

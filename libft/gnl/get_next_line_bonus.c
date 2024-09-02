/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dravaono <dravaono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 14:32:34 by dravaono          #+#    #+#             */
/*   Updated: 2024/07/30 15:59:08 by dravaono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*free_str(char *buf, char *stash)
{
	free(buf);
	free(stash);
	return (0);
}

char	*readline(int fd, char *stash)
{
	char	*buf;
	int		nb_read;
	char	*temp;

	if (!stash)
		stash = ft_strdup("");
	nb_read = 10;
	buf = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buf)
		return (0);
	while (!ft_strchr(stash, '\n') && nb_read != 0)
	{
		nb_read = read(fd, buf, BUFFER_SIZE);
		if (nb_read == -1)
			return (free_str(buf, stash));
		buf[nb_read] = '\0';
		temp = ft_strjoin(stash, buf);
		free(stash);
		stash = temp;
	}
	free(buf);
	return (stash);
}

char	*nextline(char *stash)
{
	int		i;
	int		j;
	char	*newstash;

	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
	{
		free(stash);
		return (0);
	}
	newstash = malloc(sizeof(char) * (ft_strlen(stash)- i + 1));
	i++;
	j = 0;
	while (stash[i])
	{
		newstash[j] = stash[i];
		j++;
		i++;
	}
	free(stash);
	newstash[j] = '\0';
	return (newstash);
}

char	*beforeline(char *stash)
{
	int		i;
	char	*line;

	i = 0;
	if (!stash)
		return (0);
	while (stash[i] && stash[i] != '\n')
		i++;
	line = malloc(sizeof(char) * (i + 2));
	if (!line)
		return (0);
	i = 0;
	while (stash[i] && stash[i] != '\n')
	{
		line[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
	{
		line[i] = '\n';
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*stash[65534];
	char		*line;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (0);
	stash[fd] = readline(fd, stash[fd]);
	if (!stash[fd])
		return (0);
	line = beforeline(stash[fd]);
	stash[fd] = nextline(stash[fd]);
	if (line[0] == '\0')
	{
		free(stash[fd]);
		free(line);
		return (0);
	}
	return (line);
}

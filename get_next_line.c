/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chphan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 16:49:32 by chphan            #+#    #+#             */
/*   Updated: 2024/12/12 16:49:40 by chphan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_save(char *stash)
{
	char	*stash_temp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
	{
		free(stash);
		return (NULL);
	}
	stash_temp = malloc(((ft_strlen(stash) - i) + 1) * sizeof(char));
	if (!stash_temp)
		return (NULL);
	i++;
	while (stash[i])
		stash_temp[j++] = stash[i++];
	stash_temp[j] = '\0';
	free(stash);
	return (stash_temp);
}

char	*get_lineuh(char *stash)
{
	char	*line;
	int		i;

	i = 0;
	if (!stash[0])
		return (NULL);
	while (stash[i] && stash[i] != '\n')
		i++;
	line = malloc((i + 2) * sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
	{
		line[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*read_file(int fd, char *stash)
{
	char	*buff;
	int		byte;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	byte = 1;
	while (im_detected(stash) != 1 && byte != 0)
	{
		byte = read(fd, buff, BUFFER_SIZE);
		if (byte == -1)
		{
			free(buff);
			free(stash);
			return (NULL);
		}
		buff[byte] = '\0';
		stash = ft_strjoin(stash, buff);
	}
	free(buff);
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = read_file(fd, stash);
	if (!stash)
		return (0);
	line = get_lineuh(stash);
	stash = get_save(stash);
	return (line);
}

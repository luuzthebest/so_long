/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvvz <lvvz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 11:06:12 by hounajar          #+#    #+#             */
/*   Updated: 2025/04/12 19:58:36 by lvvz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	size_cal(char *buff)
{
	int	i;

	i = 0;
	while (buff[i] && buff[i] != '\n')
		i++;
	if (buff[i] == '\n')
		i++;
	return (i);
}

char	*extract_line(char *buff)
{
	int		i;
	char	*line;

	if (!buff || !*buff)
		return (NULL);
	line = malloc(size_cal(buff) + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (buff[i] && buff[i] != '\n')
	{
		line[i] = buff[i];
		i++;
	}
	if (buff[i] == '\n')
	{
		line[i] = '\n';
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*update_buff(char *buff)
{
	int		i;
	char	*new_buff;

	i = 0;
	while (buff[i] && buff[i] != '\n')
		i++;
	if (!buff[i])
	{
		free(buff);
		return (NULL);
	}
	i++;
	new_buff = gnl_strdup(&buff[i]);
	free(buff);
	return (new_buff);
}

char	*read_buff(int fd, char *buff)
{
	ssize_t	bytes_read;
	char	*line;

	bytes_read = 1;
	line = malloc((size_t)BUFFER_SIZE + 1);
	if (!line)
		return (NULL);
	while (bytes_read > 0 && !gnl_strchr(buff, '\n'))
	{
		bytes_read = read(fd, line, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(line);
			free(buff);
			return (NULL);
		}
		line[bytes_read] = '\0';
		buff = gnl_strjoin(buff, line);
	}
	free(line);
	return (buff);
}

char	*get_next_line(int fd)
{
	static char	*buff;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buff = read_buff(fd, buff);
	if (!buff)
		return (NULL);
	line = extract_line(buff);
	buff = update_buff(buff);
	return (line);
}

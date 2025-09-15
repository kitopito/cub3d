/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nateshim <nateshim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 21:49:25 by nateshim          #+#    #+#             */
/*   Updated: 2025/09/15 21:49:29 by nateshim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_fgetc(int fd)
{
	static char		buf[BUFFER_SIZE];
	static ssize_t	pos;
	static ssize_t	size;

	if (pos >= size)
	{
		size = read(fd, buf, BUFFER_SIZE);
		pos = 0;
		if (size <= 0)
			return ((char)EOF);
	}
	return ((unsigned char)buf[pos++]);
}

static char	*putc_and_dump(char *str, char c)
{
	static char		buf[BUFFER_SIZE + 1];
	static ssize_t	pos;
	char			*tmp;

	if (c != (char)EOF)
		buf[pos++] = c;
	if (pos == BUFFER_SIZE || c == '\n' || c == (char)EOF)
	{
		buf[pos] = '\0';
		tmp = ft_strjoin(str, buf);
		free(str);
		pos = 0;
		if (tmp == NULL)
			return (NULL);
		str = tmp;
	}
	return (str);
}

char	*get_next_line(int fd)
{
	char	c;
	char	*line;

	line = ft_strjoin("", "");
	if (line == NULL)
		return (NULL);
	while (1)
	{
		c = ft_fgetc(fd);
		line = putc_and_dump(line, c);
		if (line == NULL)
			return (NULL);
		if (c == '\n' || c == (char)EOF)
			break ;
	}
	if (ft_strlen(line) == 0)
	{
		free(line);
		return (NULL);
	}
	return (line);
}

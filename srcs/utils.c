/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywada <ywada@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 19:14:48 by ywada             #+#    #+#             */
/*   Updated: 2025/08/11 19:15:51 by ywada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void free_map(char **map)
{
  int i = 0;

  if (!map)
    return;
  while (map[i])
  {
    free(map[i]);
    i++;
  }
  free(map);
}

static int	count_lines(char *path)
{
	int		fd;
	int		n;
	char	*line;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (-1);
	n = 0;
	line = get_next_line(fd);
	while (line)
	{
		n++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (n);
}

char	**read_all_lines(char *path, int *out_n)
{
	int		fd;
	int		n;
	int		i;
	char	**arr;
	char	*line;

	n = count_lines(path);
	fd = open(path, O_RDONLY);
	if (n <= 0 || fd < 0)
		return (NULL);
	arr = (char **)malloc(sizeof(char *) * n);
	if (!arr)
		return (NULL);
	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		arr[i] = ft_strtrim(line, "\n");
		free(line);
		i++;
		line = get_next_line(fd);
	}
	close(fd);
	*out_n = n;
	return (arr);
}

char	*skip_ws(char *s)
{
	while (*s == ' ' || *s == '\t')
		s++;
	return (s);
}

void	split_free(char **sp)
{
	int	i;

	if (!sp)
		return ;
	i = 0;
	while (sp[i])
	{
		free(sp[i]);
		i++;
	}
	free(sp);
}

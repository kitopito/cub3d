/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywada <ywada@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 19:14:51 by ywada             #+#    #+#             */
/*   Updated: 2025/08/11 19:15:51 by ywada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int count_lines(char *filepath)
{
  int fd = open(filepath, O_RDONLY);
  int count = 0;
  char *line;

  if (fd < 0)
    return (-1);
  line = get_next_line(fd);
  while (line)
  {
    count++;
    free(line);
    line = get_next_line(fd);
  }
  close(fd);
  return count;
}

static void fill_map(t_data *data, char *filepath)
{
  int fd = open(filepath, O_RDONLY);
  int i = 0;
  char *line;

  data->map = (char **)malloc(sizeof(char *) * (data->rows + 1));
  if (!data->map)
    return;
  line = get_next_line(fd);
  while (line)
  {
    data->map[i++] = ft_strtrim(line, "\n");
    free(line);
    line = get_next_line(fd);
  }
  data->map[i] = NULL;
  close(fd);
}

void parse_map(t_data *data, char *filepath)
{
  data->rows = count_lines(filepath);
  if (data->rows <= 0)
  {
    perror("Invalid or empty map file");
    exit(EXIT_FAILURE);
  }
  fill_map(data, filepath);
  data->columns = ft_strlen(data->map[0]);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywada <ywada@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 19:14:44 by ywada             #+#    #+#             */
/*   Updated: 2025/08/11 19:15:51 by ywada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int main(int ac, char **av)
{
  t_data data;
  int i = 0;

  if (ac != 2)
  {
    ft_putstr_fd("Usage: ./cub3D <map_file>\n", 2);
    return (EXIT_FAILURE);
  }
  init_data(&data);
  parse_map(&data, av[1]);

  // マップ表示（テスト用）
  while (data.map[i])
  {
    printf("%s\n", data.map[i]);
    i++;
  }

  free_map(data.map);
  return (EXIT_SUCCESS);
}

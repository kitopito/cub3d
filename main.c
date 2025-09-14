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
	t_config	cfg;
	int			i;

	if (ac != 2)
	{
		ft_putstr_fd("Usage: ./cub3D <map_file>\n", 2);
		return (EXIT_FAILURE);
	}
	init_config(&cfg);
	parse_map(&cfg, av[1]);
	if (!check_components(&cfg))
		return (EXIT_FAILURE);
	//マップの表示
	print_parsed(&cfg);
	i = 0;
	while (cfg.map && cfg.map[i])
	{
		printf("%s\n", cfg.map[i]);
		i++;
	}
	free_map(cfg.map);
	return (EXIT_SUCCESS);
}

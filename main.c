/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywada <ywada@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 19:14:44 by ywada             #+#    #+#             */
/*   Updated: 2025/09/19 17:27:24 by ywada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "srcs/dda/dda.h"
#include "srcs/hooks/hooks.h"
#include <mlx.h>

int	main(int ac, char **av)
{
	t_cub3d	cub3d;
	char	*filename;

	if (ac != 2)
	{
		ft_putstr_fd("Usage: ./cub3D <map_file>\n", 2);
		return (EXIT_FAILURE);
	}
	filename = av[1];
	init_cub3d(&cub3d);
	set_cub3d(&cub3d, filename);
	set_cub3d2(&cub3d);
	mlx_key_hook(cub3d.win, key_up, &cub3d);
	mlx_hook(cub3d.win, 2, 1L << 0, key_down, &cub3d);
	mlx_hook(cub3d.win, 17, 0, destroy_hook, &cub3d);
	mlx_loop_hook(cub3d.mlx, render, &cub3d);
	dda(&cub3d);
	mlx_put_image_to_window(cub3d.mlx, cub3d.win, cub3d.img->img, 0, 0);
	mlx_loop(cub3d.mlx);
	end_cub3d(&cub3d);
	return (0);
}

// int main(int ac, char **av)
// {
// 	t_config	cfg;
// 	int			i;

// 	if (ac != 2)
// 	{
// 		ft_putstr_fd("Usage: ./cub3D <map_file>\n", 2);
// 		return (EXIT_FAILURE);
// 	}
// 	init_config(&cfg);
// 	parse_map(&cfg, av[1]);
// 	if (!check_components(&cfg))
// 		return (EXIT_FAILURE);
// 	//マップの表示
// 	print_parsed(&cfg);
// 	i = 0;
// 	while (cfg.map && cfg.map[i])
// 	{
// 		printf("%s\n", cfg.map[i]);
// 		i++;
// 	}
// 	free_map(cfg.map);
// 	return (EXIT_SUCCESS);
// }

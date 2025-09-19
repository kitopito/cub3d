/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywada <ywada@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 18:29:07 by ywada             #+#    #+#             */
/*   Updated: 2025/09/19 19:10:48 by ywada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

// void	print_parsed(const t_config *cfg)
// {
// 	int		i;
// 	int		f_hex;
// 	int		c_hex;
// 	int		x;
// 	int		y;
// 	char	c;

// 	i = 0;
// 	while (i < TEX_MAX)
// 	{
// 		if (cfg->texture_path[i])
// 			printf("TEX[%d]=%s\n", i, cfg->texture_path[i]);
// 		else
// 			printf("TEX[%d]=\n", i);
// 		i++;
// 	}
// 	printf("F=%d,%d,%d\n", cfg->floor_rgb[0], cfg->floor_rgb[1],
// 		cfg->floor_rgb[2]);
// 	printf("C=%d,%d,%d\n", cfg->ceiling_rgb[0], cfg->ceiling_rgb[1],
// 		cfg->ceiling_rgb[2]);
// 	f_hex = (cfg->floor_rgb[0] << 16) | (cfg->floor_rgb[1] << 8) |
// 	cfg->floor_rgb[2];
// 	c_hex = (cfg->ceiling_rgb[0] << 16) | (cfg->ceiling_rgb[1] << 8) |
// 	cfg->ceiling_rgb[2];
// 	printf("F_HEX=%d\n", f_hex);
// 	printf("C_HEX=%d\n", c_hex);
// 	printf("START=%d,%d,%c\n", cfg->start_x, cfg->start_y,
// 		cfg->start_direction ? cfg->start_direction : ' ');
// 	printf("SIZE=%d,%d\n", cfg->columns, cfg->rows);
// 	//
// 	y = 0;
// 	while (cfg->map[y])
// 	{
// 		x = 0;
// 		while (cfg->map[y][x])
// 		{
// 			c = cfg->map[y][x];
// 			// if (c == 'V')
// 			// 	write(1, "#", 1);
// 			// else
// 			write(1, &c, 1);
// 			x++;
// 		}
// 		printf("\n");
// 		y++;
// 	}
// 	printf("\n");
// }

// void	print_map(t_data *data)
// {
// 	int		x;
// 	int		y;
// 	char	c;

// 	y = 0;
// 	while (data->map[y])
// 	{
// 		x = 0;
// 		while (data->map[y][x])
// 		{
// 			c = data->map[y][x];
// 			// if (c == 'V')
// 			// 	write(1, "#", 1);
// 			// else
// 				write(1, &c, 1);
// 			x++;
// 		}
// 		printf("\n");
// 		y++;
// 	}
// 	printf("\n");
// }

// void	print_info(t_data *data)
// {
// 	// printf(YELLOW);
// 	// ======================== file ========================
// 	printf("NORTH : %s\n", data->texture_paths[NORTH]);
// 	printf("SOUTH : %s\n", data->texture_paths[SOUTH]);
// 	printf(" WEST : %s\n", data->texture_paths[WEST]);
// 	printf(" EAST : %s\n", data->texture_paths[EAST]);
// 	printf("ceiling : %3d, %3d, %3d\n", data->ceiling_rgb[0],
// 		data->ceiling_rgb[1], data->ceiling_rgb[2]);
// 	printf("  floor : %3d, %3d, %3d\n", data->floor_rgb[0], data->floor_rgb[1],
// 		data->floor_rgb[2]);

// 	// ======================== map ========================
// 	printf("map rows    : %d\n", data->rows);
// 	printf("map columns : %d\n", data->columns);

// 	// printf(END);
// }

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywada <ywada@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 19:24:38 by ywada             #+#    #+#             */
/*   Updated: 2025/09/15 21:21:59 by ywada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include "hooks/hooks.h"
#include <mlx.h>

void	init_cub3d(t_cub3d *cub3d)
{
	cub3d->mlx = NULL;
	cub3d->win = NULL;
	cub3d->config = NULL;
	cub3d->player = NULL;
	cub3d->img = NULL;
	cub3d->key_state = NULL;
}

t_config	*new_config(void)
{
	t_config	*config;

	config = malloc(sizeof(t_config));
	if (!config)
		return (NULL);
	config->north_texture = NULL;
	config->south_texture = NULL;
	config->west_texture = NULL;
	config->east_texture = NULL;
	config->map = NULL;
	init_config(config);
	return (config);
}

// int	set_config(t_cub3d *cub3d, char *filepath)
// {
// 	if (parse_map(cub3d->config, filepath) < 0)
// 	{
// 		// perror("Failed to parse map");
// 		return (-1);
// 	}
// 	if (check_map(cub3d->config) < 0)
// 	{
// 		// perror("Invalid map");
// 		return (-1);
// 	}
// 	if (load_textures(cub3d) < 0)
// 	{
// 		// perror("Failed to load textures");
// 		return (-1);
// 	}
// 	return (0);
// }

void	alloc_cub3d(t_cub3d *cub3d)
{
	cub3d->mlx = mlx_init();
	cub3d->win = mlx_new_window(cub3d->mlx, WINDOW_WIDTH, WINDOW_HEIGHT,
			"cub3d");
	cub3d->config = new_config();
	cub3d->player = malloc(sizeof(t_player));
	cub3d->img = malloc(sizeof(t_img_data));
	cub3d->key_state = malloc(sizeof(t_key_state));
	if (cub3d->mlx == NULL || cub3d->win == NULL || cub3d->config == NULL
		|| cub3d->player == NULL || cub3d->img == NULL
		|| cub3d->key_state == NULL)
	{
		free_cub3d(cub3d);
		perror("Failed to initialize Cub3D");
		exit(EXIT_FAILURE);
	}
}

void	set_cub3d(t_cub3d *cub3d, char *filepath)
{
	alloc_cub3d(cub3d);
	cub3d->img->img = mlx_new_image(cub3d->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	if (cub3d->img->img == NULL)
	{
		end_cub3d(cub3d);
		exit(EXIT_FAILURE);
	}
	cub3d->img->addr = mlx_get_data_addr(cub3d->img->img,
			&cub3d->img->bits_per_pixel, &cub3d->img->line_length,
			&cub3d->img->endian);
	init_key_state(cub3d->key_state);
	if (parse_map(cub3d->config, filepath) == 0
		|| check_components(cub3d->config) == 0)
	{
		end_cub3d(cub3d);
		exit(EXIT_FAILURE);
	}
}

void	free_cub3d(t_cub3d *cub3d)
{
	if (cub3d->win && cub3d->mlx)
		mlx_destroy_window(cub3d->mlx, cub3d->win);
	if (cub3d->mlx)
		mlx_destroy_display(cub3d->mlx);
	if (cub3d->config)
	{
		free(cub3d->config->north_texture);
		free(cub3d->config->south_texture);
		free(cub3d->config->west_texture);
		free(cub3d->config->east_texture);
		free_map(cub3d->config->map);
		free(cub3d->config);
	}
	free(cub3d->player);
	free(cub3d->img);
	free(cub3d->key_state);
}

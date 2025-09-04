/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywada <ywada@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 19:24:38 by ywada             #+#    #+#             */
/*   Updated: 2025/08/12 17:24:41 by ywada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

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

void	set_cub3d(t_cub3d *cub3d, char *filepath)
{
	init_cub3d(cub3d);
	cub3d->mlx = mlx_init();
	cub3d->win = mlx_new_window(cub3d->mlx, windowWidth, windowHeight, "cub3d");
	cub3d->config = new_config();
	cub3d->player = malloc(sizeof(t_player));
	cub3d->img = malloc(sizeof(t_img_data));
	cub3d->key_state = malloc(sizeof(t_key_state));
	if (cub3d->mlx == NULL || cub3d->win == NULL || cub3d->config == NULL
		|| cub3d->player == NULL || cub3d->img == NULL
		|| cub3d->key_state == NULL)
	{
		free_cub3d(cub3d);
		// perror("Failed to initialize Cub3D");
		exit(EXIT_FAILURE);
	}
	init_key_state(cub3d->key_state);
	// set_config(cub3d, filepath);
	if (parse_map(cub3d, filepath) < 0)
	{
		// in parse_map  check_map*(), load_textures() are called
		free_cub3d(cub3d);
		// perror("Failed to parse map");
		exit(EXIT_FAILURE);
	}
}

void	free_cub3d(t_cub3d *cub3d)
{
	cub3d->mlx = NULL;
	cub3d->win = NULL;
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
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywada <ywada@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 19:14:54 by ywada             #+#    #+#             */
/*   Updated: 2025/09/19 18:50:22 by ywada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include "dda/dda.h"
#include "hooks/hooks.h"

void	init_config(t_config *cfg)
{
	int	i;

	ft_bzero(cfg, sizeof(*cfg));
	i = 0;
	while (i < TEX_MAX)
	{
		cfg->texture_path[i] = NULL;
		i++;
	}
}

void	set_player(t_cub3d *cub3d)
{
	cub3d->player->x = cub3d->config->start_x + 0.5;
	cub3d->player->y = cub3d->config->start_y + 0.5;
	if (cub3d->config->start_direction == 'W')
	{
		cub3d->player->dir_x = -1.0;
		cub3d->player->dir_y = 0.0;
	}
	else if (cub3d->config->start_direction == 'E')
	{
		cub3d->player->dir_x = 1.0;
		cub3d->player->dir_y = 0.0;
	}
	else if (cub3d->config->start_direction == 'S')
	{
		cub3d->player->dir_x = 0.0;
		cub3d->player->dir_y = 1.0;
	}
	else if (cub3d->config->start_direction == 'N')
	{
		cub3d->player->dir_x = 0.0;
		cub3d->player->dir_y = -1.0;
	}
	cub3d->player->plane_x = -PLANE_WIDTH * cub3d->player->dir_y;
	cub3d->player->plane_y = +PLANE_WIDTH * cub3d->player->dir_x;
}

void	set_cub3d2(t_cub3d *cub3d)
{
	set_player(cub3d);
	cub3d->config->east_texture = load_texture(cub3d->mlx,
			cub3d->config->texture_path[TEX_EA]);
	cub3d->config->west_texture = load_texture(cub3d->mlx,
			cub3d->config->texture_path[TEX_WE]);
	cub3d->config->south_texture = load_texture(cub3d->mlx,
			cub3d->config->texture_path[TEX_SO]);
	cub3d->config->north_texture = load_texture(cub3d->mlx,
			cub3d->config->texture_path[TEX_NO]);
	if (cub3d->config->east_texture == NULL
		|| cub3d->config->west_texture == NULL
		|| cub3d->config->south_texture == NULL
		|| cub3d->config->north_texture == NULL)
	{
		perror("Failed to load texture");
		end_cub3d(cub3d);
		exit(EXIT_FAILURE);
	}
}

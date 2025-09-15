/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywada <ywada@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 19:49:49 by ywada             #+#    #+#             */
/*   Updated: 2025/09/15 20:58:04 by ywada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"
#include "../dda/dda.h"
#include "hooks.h"
#include <mlx.h>

int	render(t_cub3d *data)
{
	if (data->key_state->left)
	{
		rotate_player(data->player, ROTATION_ANGLE);
	}
	if (data->key_state->right)
	{
		rotate_player(data->player, -ROTATION_ANGLE);
	}
	move(data, data->player);
	dda(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img->img, 0, 0);
	return (0);
}

int	destroy_hook(t_cub3d *data)
{
	mlx_loop_end(data->mlx);
	return (0);
}

void	destroy_config(t_cub3d *cub3d)
{
	free_map(cub3d->config->map);
	if (cub3d->config->east_texture != NULL)
		mlx_destroy_image(cub3d->mlx, cub3d->config->east_texture->img);
	if (cub3d->config->west_texture != NULL)
		mlx_destroy_image(cub3d->mlx, cub3d->config->west_texture->img);
	if (cub3d->config->south_texture != NULL)
		mlx_destroy_image(cub3d->mlx, cub3d->config->south_texture->img);
	if (cub3d->config->north_texture != NULL)
		mlx_destroy_image(cub3d->mlx, cub3d->config->north_texture->img);
	free(cub3d->config->north_texture);
	free(cub3d->config->south_texture);
	free(cub3d->config->west_texture);
	free(cub3d->config->east_texture);
	free(cub3d->config->texture_path[TEX_EA]);
	free(cub3d->config->texture_path[TEX_WE]);
	free(cub3d->config->texture_path[TEX_SO]);
	free(cub3d->config->texture_path[TEX_NO]);
	free(cub3d->config);
}

void	end_cub3d(t_cub3d *cub3d)
{
	free(cub3d->player);
	free(cub3d->key_state);
	if (cub3d->config)
	{
		destroy_config(cub3d);
	}
	if (cub3d->img != NULL && cub3d->img->img != NULL)
		mlx_destroy_image(cub3d->mlx, cub3d->img->img);
	free(cub3d->img);
	mlx_destroy_window(cub3d->mlx, cub3d->win);
	mlx_destroy_display(cub3d->mlx);
	free(cub3d->mlx);
}

void	rotate_player(t_player *player, double angle)
{
	double	old_dir_x;
	double	old_dir_y;
	double	old_plane_x;
	double	old_plane_y;

	old_dir_x = player->dir_x;
	old_dir_y = player->dir_y;
	player->dir_x = old_dir_x * cos(angle) - old_dir_y * sin(angle);
	player->dir_y = old_dir_x * sin(angle) + old_dir_y * cos(angle);
	old_plane_x = player->plane_x;
	old_plane_y = player->plane_y;
	player->plane_x = old_plane_x * cos(angle) - old_plane_y * sin(angle);
	player->plane_y = old_plane_x * sin(angle) + old_plane_y * cos(angle);
}

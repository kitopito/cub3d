/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywada <ywada@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 19:15:02 by ywada             #+#    #+#             */
/*   Updated: 2025/09/15 18:50:35 by ywada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"
#include "../dda/dda.h"
#include "hooks.h"
#include <mlx.h>
#include <stdio.h>

int	key_up(int keycode, t_cub3d *data)
{
	if (keycode == KEYCODE_ESC)
	{
		mlx_loop_end(data->mlx);
	}
	else if (keycode == KEYCODE_W)
	{
		data->key_state->w = false;
	}
	else if (keycode == KEYCODE_A)
	{
		data->key_state->a = false;
	}
	else if (keycode == KEYCODE_S)
	{
		data->key_state->s = false;
	}
	else if (keycode == KEYCODE_D)
	{
		data->key_state->d = false;
	}
	else if (keycode == KEYCODE_LEFT)
	{
		data->key_state->left = false;
	}
	else if (keycode == KEYCODE_RIGHT)
	{
		data->key_state->right = false;
	}
	return (0);
}

int	key_down(int keycode, t_cub3d *data)
{
	printf("Key pressed: %d\n", keycode);
	if (keycode == KEYCODE_W)
	{
		data->key_state->w = true;
	}
	if (keycode == KEYCODE_A)
	{
		data->key_state->a = true;
	}
	if (keycode == KEYCODE_S)
	{
		data->key_state->s = true;
	}
	if (keycode == KEYCODE_D)
	{
		data->key_state->d = true;
	}
	if (keycode == KEYCODE_LEFT)
	{
		data->key_state->left = true;
	}
	if (keycode == KEYCODE_RIGHT)
	{
		data->key_state->right = true;
	}
	return (0);
}

void	move(t_cub3d *data, t_player *player)
{
	double	move_x;
	double	move_y;
	int		dest_x;
	int		dest_y;

	move_x = 0;
	move_y = 0;
	if (data->key_state->w)
	{
		move_x += data->player->dir_x * VELOCITY;
		move_y += data->player->dir_y * VELOCITY;
	}
	if (data->key_state->s)
	{
		move_x -= data->player->dir_x * VELOCITY;
		move_y -= data->player->dir_y * VELOCITY;
	}
	if (data->key_state->a)
	{
		move_x -= data->player->dir_y * VELOCITY;
		move_y += data->player->dir_x * VELOCITY;
	}
	if (data->key_state->d)
	{
		move_x += data->player->dir_y * VELOCITY;
		move_y -= data->player->dir_x * VELOCITY;
	}
	dest_x = (int)(player->x + move_x);
	dest_y = (int)(player->y + move_y);
	if (data->config->map[dest_y][dest_x] == '0')
	{
		player->x += move_x;
		player->y += move_y;
	}
	// if (data->config->map[(int)player->y][dest_x] == '0')
	// 	player->x += move_x;
	// if (data->config->map[dest_y][(int)player->x] == '0')
	// 	player->y += move_y;
}

int	render(t_cub3d *data)
{
	// printf("key state: W=%d, A=%d, S=%d, D=%d, LEFT=%d, RIGHT=%d\n",
	//        data->key_state->w, data->key_state->a, data->key_state->s,
	//        data->key_state->d, data->key_state->left,
	// data->key_state->right);
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

void	end_cub3d(t_cub3d *cub3d)
{
	free(cub3d->player);
	free(cub3d->key_state);
	if (cub3d->config)
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
	//
	if (cub3d->img != NULL && cub3d->img->img != NULL)
	{
		// printf("ほげ %p %p %p\n", cub3d->mlx, cub3d->img, cub3d->img->img);
		// printf("ほげ %d %d\n", cub3d->img->width, cub3d->img->height);
		mlx_destroy_image(cub3d->mlx, cub3d->img->img);
	}
	free(cub3d->img);
	mlx_destroy_window(cub3d->mlx, cub3d->win);
	mlx_destroy_display(cub3d->mlx);
	free(cub3d->mlx);
}

void	rotate_player(t_player *player, double angle)
{
	double	oldDirX;
	double	oldDirY;
	double	oldPlaneX;
	double	oldPlaneY;

	oldDirX = player->dir_x;
	oldDirY = player->dir_y;
	player->dir_x = oldDirX * cos(angle) - oldDirY * sin(angle);
	player->dir_y = oldDirX * sin(angle) + oldDirY * cos(angle);
	oldPlaneX = player->plane_x;
	oldPlaneY = player->plane_y;
	player->plane_x = oldPlaneX * cos(angle) - oldPlaneY * sin(angle);
	player->plane_y = oldPlaneX * sin(angle) + oldPlaneY * cos(angle);
}

void	init_key_state(t_key_state *state)
{
	state->w = false;
	state->a = false;
	state->s = false;
	state->d = false;
	state->left = false;
	state->right = false;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywada <ywada@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 19:15:02 by ywada             #+#    #+#             */
/*   Updated: 2025/09/19 18:56:34 by ywada            ###   ########.fr       */
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
		mlx_loop_end(data->mlx);
	else if (keycode == KEYCODE_W)
		data->key_state->w = false;
	else if (keycode == KEYCODE_A)
		data->key_state->a = false;
	else if (keycode == KEYCODE_S)
		data->key_state->s = false;
	else if (keycode == KEYCODE_D)
		data->key_state->d = false;
	else if (keycode == KEYCODE_LEFT)
		data->key_state->left = false;
	else if (keycode == KEYCODE_RIGHT)
		data->key_state->right = false;
	return (0);
}

int	key_down(int keycode, t_cub3d *data)
{
	printf("Key pressed: %d\n", keycode);
	if (keycode == KEYCODE_W)
		data->key_state->w = true;
	if (keycode == KEYCODE_A)
		data->key_state->a = true;
	if (keycode == KEYCODE_S)
		data->key_state->s = true;
	if (keycode == KEYCODE_D)
		data->key_state->d = true;
	if (keycode == KEYCODE_LEFT)
		data->key_state->left = true;
	if (keycode == KEYCODE_RIGHT)
		data->key_state->right = true;
	return (0);
}

void	calc_move_vector(t_cub3d *data, double *move_x, double *move_y)
{
	if (data->key_state->w)
	{
		*move_x += data->player->dir_x * VELOCITY;
		*move_y += data->player->dir_y * VELOCITY;
	}
	if (data->key_state->s)
	{
		*move_x -= data->player->dir_x * VELOCITY;
		*move_y -= data->player->dir_y * VELOCITY;
	}
	if (data->key_state->a)
	{
		*move_x += data->player->dir_y * VELOCITY;
		*move_y -= data->player->dir_x * VELOCITY;
	}
	if (data->key_state->d)
	{
		*move_x -= data->player->dir_y * VELOCITY;
		*move_y += data->player->dir_x * VELOCITY;
	}
}

void	move(t_cub3d *data, t_player *player)
{
	double	move_x;
	double	move_y;
	int		dest_x;
	int		dest_y;

	move_x = 0;
	move_y = 0;
	calc_move_vector(data, &move_x, &move_y);
	dest_x = (int)(player->x + move_x);
	dest_y = (int)(player->y + move_y);
	if (data->config->map[dest_y][dest_x] == '0')
	{
		player->x += move_x;
		player->y += move_y;
	}
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

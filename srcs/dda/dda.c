/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywada <ywada@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 19:15:22 by ywada             #+#    #+#             */
/*   Updated: 2025/09/19 18:58:53 by ywada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include "dda.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define MIN_WALL_DISTANCE 1e-13

void	dda_init_step(t_dda *dda_data)
{
	if (dda_data->ray_dir.x < 0)
	{
		dda_data->step_x = -1;
		dda_data->side_dist_x = (dda_data->x - dda_data->map_x)
			* dda_data->delta_x;
	}
	else
	{
		dda_data->step_x = 1;
		dda_data->side_dist_x = (dda_data->map_x + 1.0 - dda_data->x)
			* dda_data->delta_x;
	}
	if (dda_data->ray_dir.y < 0)
	{
		dda_data->step_y = -1;
		dda_data->side_dist_y = (dda_data->y - dda_data->map_y)
			* dda_data->delta_y;
	}
	else
	{
		dda_data->step_y = 1;
		dda_data->side_dist_y = (dda_data->map_y + 1.0 - dda_data->y)
			* dda_data->delta_y;
	}
}

void	perform_dda(t_dda *dda_data)
{
	dda_data->side = -1;
	while (1)
	{
		if (dda_data->side_dist_x < dda_data->side_dist_y)
		{
			dda_data->side_dist_x += dda_data->delta_x;
			dda_data->map_x += dda_data->step_x;
			dda_data->side = SIDE_X;
		}
		else
		{
			dda_data->side_dist_y += dda_data->delta_y;
			dda_data->map_y += dda_data->step_y;
			dda_data->side = SIDE_Y;
		}
		if (dda_data->map[dda_data->map_y][dda_data->map_x] > '0')
			break ;
	}
	if (dda_data->side == SIDE_X)
		dda_data->perp_wall_dist = dda_data->side_dist_x - dda_data->delta_x;
	else
		dda_data->perp_wall_dist = dda_data->side_dist_y - dda_data->delta_y;
}

void	calc_wall_dist(t_dda *dda_data)
{
	if (dda_data->side == SIDE_X)
		dda_data->wall_x = dda_data->y + dda_data->perp_wall_dist
			* dda_data->ray_dir.y;
	else
		dda_data->wall_x = dda_data->x + dda_data->perp_wall_dist
			* dda_data->ray_dir.x;
	if (dda_data->perp_wall_dist == 0)
		dda_data->perp_wall_dist = MIN_WALL_DISTANCE;
	dda_data->h = WINDOW_HEIGHT;
	dda_data->wall_x -= floor(dda_data->wall_x);
	dda_data->tex_x = (int)(dda_data->wall_x * dda_data->texture->width);
	if ((dda_data->side == SIDE_X && dda_data->ray_dir.x < 0)
		|| (dda_data->side == SIDE_Y && dda_data->ray_dir.y > 0))
		dda_data->tex_x = dda_data->texture->width - dda_data->tex_x - 1;
	dda_data->tex_step = (double)dda_data->texture->height
		/ dda_data->line_height;
	dda_data->tex_pos = 0.0;
}

void	dda_draw_line(t_dda *dda_data, t_cub3d *cub3d, int i)
{
	int	k;

	dda_data->line_height = (int)(dda_data->h / dda_data->perp_wall_dist);
	dda_data->draw_start = dda_data->h / 2 - dda_data->line_height / 2;
	k = dda_data->draw_start;
	while (k < dda_data->draw_start + dda_data->line_height)
	{
		if (k >= 0 && k < WINDOW_HEIGHT)
		{
			dda_data->tex_y = floor(dda_data->tex_pos);
			dda_data->color = mlx_pixel_get(dda_data->texture, dda_data->tex_x,
					dda_data->tex_y);
			my_mlx_pixel_put(cub3d->img, i, k, dda_data->color);
		}
		dda_data->tex_pos += dda_data->tex_step;
		k++;
	}
}

int	dda(t_cub3d *cub3d)
{
	int		i;
	t_dda	dda_data;

	init_dda(&dda_data, cub3d);
	fill_img_ceiling_floor(cub3d->img, cub3d->config);
	i = 0;
	while (i < WINDOW_WIDTH)
	{
		dda_init_ray(&dda_data, i);
		dda_init_step(&dda_data);
		perform_dda(&dda_data);
		if (dda_data.side == SIDE_X && dda_data.ray_dir.x < 0)
			dda_data.texture = cub3d->config->east_texture;
		else if (dda_data.side == SIDE_X && dda_data.ray_dir.x > 0)
			dda_data.texture = cub3d->config->west_texture;
		else if (dda_data.side == SIDE_Y && dda_data.ray_dir.y < 0)
			dda_data.texture = cub3d->config->south_texture;
		else
			dda_data.texture = cub3d->config->north_texture;
		calc_wall_dist(&dda_data);
		dda_draw_line(&dda_data, cub3d, i);
		i++;
	}
	return (0);
}

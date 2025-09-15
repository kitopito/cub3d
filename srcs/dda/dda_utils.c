/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywada <ywada@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 19:34:42 by ywada             #+#    #+#             */
/*   Updated: 2025/09/15 21:21:59 by ywada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dda.h"

void	my_mlx_pixel_put(t_img_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	fill_img_ceiling_floor(t_img_data *img_data, t_config *config)
{
	int	i;
	int	k;

	i = 0;
	while (i < WINDOW_HEIGHT / 2)
	{
		k = 0;
		while (k < WINDOW_WIDTH)
		{
			my_mlx_pixel_put(img_data, k, i, config->ceiling_color);
			k++;
		}
		i++;
	}
	while (i < WINDOW_HEIGHT)
	{
		k = 0;
		while (k < WINDOW_WIDTH)
		{
			my_mlx_pixel_put(img_data, k, i, config->floor_color);
			k++;
		}
		i++;
	}
}

void	dda_init_ray(t_dda *dda_data, int i)
{
	dda_data->camera_x = 2 * i / (double)WINDOW_WIDTH - 1;
	dda_data->ray_dir.x = dda_data->dir_x + dda_data->camera_x
		* dda_data->plane_x;
	dda_data->ray_dir.y = dda_data->dir_y + dda_data->camera_x
		* dda_data->plane_y;
	dda_data->map_x = (int)dda_data->x;
	dda_data->map_y = (int)dda_data->y;
	if (dda_data->ray_dir.x != 0)
		dda_data->delta_x = fabs(1 / dda_data->ray_dir.x);
	else
		dda_data->delta_x = 1e30;
	if (dda_data->ray_dir.y != 0)
		dda_data->delta_y = fabs(1 / dda_data->ray_dir.y);
	else
		dda_data->delta_y = 1e30;
}

void	init_dda(t_dda *dda_data, t_cub3d *cub3d)
{
	dda_data->step_x = 1;
	dda_data->step_y = 1;
	dda_data->delta_x = 0.5;
	dda_data->delta_y = 0.5;
	dda_data->side_dist_x = 0.0;
	dda_data->side_dist_y = 0.0;
	dda_data->map = cub3d->config->map;
	dda_data->map_width = cub3d->config->columns;
	dda_data->map_height = cub3d->config->rows;
	dda_data->x = cub3d->player->x;
	dda_data->y = cub3d->player->y;
	dda_data->dir_x = cub3d->player->dir_x;
	dda_data->dir_y = cub3d->player->dir_y;
	dda_data->plane_x = cub3d->player->plane_x;
	dda_data->plane_y = cub3d->player->plane_y;
}

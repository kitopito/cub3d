/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywada <ywada@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 19:15:22 by ywada             #+#    #+#             */
/*   Updated: 2025/08/12 01:18:58 by ywada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include "dda.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define SIDE_X 0
#define SIDE_Y 1

void	my_mlx_pixel_put(t_img_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	fill_img(t_img_data *img_data, int color)
{
	for (int y = 0; y < windowHeight; y++)
	{
		for (int x = 0; x < windowWidth; x++)
		{
			my_mlx_pixel_put(img_data, x, y, color);
		}
	}
}

void fill_img_ceiling_floor(t_img_data *img_data, t_config *config)
{
	int i = 0;
	int k;
	while (i < windowHeight / 2)
	{
		k = 0;
		while (k < windowWidth)
		{
			my_mlx_pixel_put(img_data, k, i, config->ceiling_color);
			k++;
		}
		i++;
	}
	while (i < windowHeight)
	{
		k = 0;
		while (k < windowWidth)
		{
			my_mlx_pixel_put(img_data, k, i, config->floor_color);
			k++;
		}
		i++;
	}
}

int	dda(t_cub3d *cub3d)
{
	int			i;
	// double		ray_length;
	t_vector	ray_dir;
	double		camera_x;
	int			mapX;
	int			mapY;
	int			side;
	int			h;
	int			line_height;
	int			draw_start;
	int			k;
	int			color;
	t_dda		*dda_data;
	void *img_data = cub3d->img;

	dda_data = malloc(sizeof(t_dda));
	// error 
	init_dda(dda_data, cub3d);
	//fill_img(cub3d->img, 0x000000);
	fill_img_ceiling_floor(cub3d->img, cub3d->config);
	i = 0;
	while (i < windowWidth)
	{
		camera_x = 2 * i / (double)windowWidth - 1;
		ray_dir.x = dda_data->dirX + camera_x * dda_data->planeX;
		ray_dir.y = dda_data->dirY + camera_x * dda_data->planeY;
		mapX = (int)dda_data->x;
		mapY = (int)dda_data->y;
		if (ray_dir.x != 0)
			dda_data->delta_x = fabs(1 / ray_dir.x);
		else
			dda_data->delta_x = 1e30;
		if (ray_dir.y != 0)
			dda_data->delta_y = fabs(1 / ray_dir.y);
		else
			dda_data->delta_y = 1e30;
		if (ray_dir.x < 0)
		{
			dda_data->step_x = -1;
			dda_data->side_dist_x = (dda_data->x - mapX) * dda_data->delta_x;
		}
		else
		{
			dda_data->step_x = 1;
			dda_data->side_dist_x = (mapX + 1.0 - dda_data->x)
				* dda_data->delta_x;
		}
		if (ray_dir.y < 0)
		{
			dda_data->step_y = -1;
			dda_data->side_dist_y = (dda_data->y - mapY) * dda_data->delta_y;
		}
		else
		{
			dda_data->step_y = 1;
			dda_data->side_dist_y = (mapY + 1.0 - dda_data->y)
				* dda_data->delta_y;
		}
		// printf("Ray direction: (%lf, %lf)\n", ray_dir.x, ray_dir.y);
		// printf("Delta distances: X = %lf, Y = %lf\n", dda_data->delta_x,
			// dda_data->delta_y);
			// printf("Initial side distances: X = %lf, Y = %lf\n",
			// dda_data->side_dist_x, dda_data->side_dist_y);
			side = -1;
			while (1)
			{
				// printf("Current map position: (%d, %d)\n", mapX, mapY);
				// printf("Side distances: X = %f, Y = %f\n",
				// dda_data->side_dist_x, dda_data->side_dist_y);
					if (dda_data->side_dist_x < dda_data->side_dist_y)
					{
						dda_data->side_dist_x += dda_data->delta_x;
						mapX += dda_data->step_x;
						side = SIDE_X;
					}
					else
					{
						dda_data->side_dist_y += dda_data->delta_y;
						mapY += dda_data->step_y;
						side = SIDE_Y;
					}
					// printf("Updated map position: (%d, %d)\n", mapX, mapY);
					if (dda_data->map[mapY][mapX] > '0')
					{
						// printf("Hit wall at (%d, %d) %c\n", mapX, mapY, dda_data->map[mapY][mapX]);
						break ;
					}
			}
			// printf("Map hit at (%d, %d) with side %d\n", mapX, mapY, side);
			double perp_wall_dist;
			if (side == SIDE_X)
				perp_wall_dist = dda_data->side_dist_x - dda_data->delta_x;
			else
				perp_wall_dist = dda_data->side_dist_y - dda_data->delta_y;
			//
			t_img_data *texture;
			if (side == SIDE_X && ray_dir.x > 0)
				texture = cub3d->config->east_texture;
			else if (side == SIDE_X && ray_dir.x < 0)
				texture = cub3d->config->west_texture;
			else if (side == SIDE_Y && ray_dir.y > 0)
				texture = cub3d->config->south_texture;
			else
				texture = cub3d->config->north_texture;
			//
			double wall_x;
			if (side == SIDE_X)
				wall_x = dda_data->y + perp_wall_dist * ray_dir.y;
			else
				wall_x = dda_data->x + perp_wall_dist * ray_dir.x;
			wall_x -= floor(wall_x);
			int tex_x = (int)(wall_x * texture->width); // width - 1にする？
			if ((side == SIDE_X && ray_dir.x > 0) || (side == SIDE_Y && ray_dir.y < 0))
				tex_x = texture->width - tex_x - 1;
			//
			double tex_step = (double)texture->height / line_height;
			double tex_pos = 0.0;
			//
			h = windowHeight;
			if (perp_wall_dist == 0)
				perp_wall_dist = 0.0000000000001;
			line_height = (int)(h / perp_wall_dist);
			draw_start = h / 2 - line_height / 2;
			k = draw_start;
			while (k < draw_start + line_height)
			{
				if (k >= 0 && k < windowHeight)
				{
					int tex_y = floor(tex_pos);
					color = mlx_pixel_get(texture, tex_x, tex_y);
					my_mlx_pixel_put(img_data, i, k, color);
					// printf("Pixel at (%d, %d) with color %06X\n", i, k,
					// color);
				}
				tex_pos += tex_step;
				k++;
			}
			i++;
	}
	return 0;
}

void	set_dda_data(t_dda *dda_data, t_cub3d *cub3d)
{
	dda_data->x = cub3d->player->x;
	dda_data->y = cub3d->player->y;
	dda_data->dirX = cub3d->player->dir_x;
	dda_data->dirY = cub3d->player->dir_y;
	dda_data->planeX = cub3d->player->plane_x;
	dda_data->planeY = cub3d->player->plane_y;
	dda_data->map = cub3d->config->map;
	dda_data->map_width = cub3d->config->columns;
	dda_data->map_height = cub3d->config->rows;
}

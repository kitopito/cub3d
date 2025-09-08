/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywada <ywada@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 19:15:12 by ywada             #+#    #+#             */
/*   Updated: 2025/08/12 01:23:15 by ywada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DDA_H
# define DDA_H
# include "../cub3d.h"
# include <math.h>
# include <stdlib.h>

typedef struct s_vector
{
	double	x;
	double	y;
}			t_vector;

typedef struct s_dda
{
	double	x;
	double	y;
	int		step_x;
	int		step_y;
	double	delta_x;
	double	delta_y;
	double	side_dist_x;
	double	side_dist_y;
	double	dirX;
	double	dirY;
	double	planeX;
	double	planeY;
	char	**map;
	int		map_width;
	int		map_height;
}			t_dda;

int			dda(t_cub3d *cub3d);

void init_dda(t_dda *dda_data, t_cub3d *cub3d);

void			my_mlx_pixel_put(t_img_data *data, int x, int y, int color);
int	mlx_pixel_get(t_img_data *data, int x, int y);

t_img_data	*load_texture(void *mlx, char *filename);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywada <ywada@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 19:15:12 by ywada             #+#    #+#             */
/*   Updated: 2025/09/15 20:15:36 by ywada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DDA_H
# define DDA_H
# include "../cub3d.h"
# include <math.h>
# include <stdlib.h>

# define SIDE_X 0
# define SIDE_Y 1

# define PLANE_WIDTH 0.66 // 画面の幅に対するカメラ平面の幅

typedef struct s_vector
{
	double		x;
	double		y;
}				t_vector;

typedef struct s_dda
{
	double		x;
	double		y;
	int			step_x;
	int			step_y;
	double		delta_x;
	double		delta_y;
	double		side_dist_x;
	double		side_dist_y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
	char		**map;
	int			map_width;
	int			map_height;
	t_vector	ray_dir;
	double		camera_x;
	int			map_x;
	int			map_y;
	int			side;
	int			h;
	int			line_height;
	int			draw_start;
	int			color;
	double		perp_wall_dist;
	t_img_data	*texture;
	double		wall_x;
	double		tex_step;
	double		tex_pos;
	int			tex_y;
	int			tex_x;
}				t_dda;

int				dda(t_cub3d *cub3d);

void			init_dda(t_dda *dda_data, t_cub3d *cub3d);

void			my_mlx_pixel_put(t_img_data *data, int x, int y, int color);
int				mlx_pixel_get(t_img_data *data, int x, int y);

t_img_data		*load_texture(void *mlx, char *filename);

void			dda_init_ray(t_dda *dda_data, int i);
void			fill_img_ceiling_floor(t_img_data *img_data, t_config *config);

#endif
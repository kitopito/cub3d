/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywada <ywada@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 19:14:34 by ywada             #+#    #+#             */
/*   Updated: 2025/08/11 20:34:12 by ywada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "srcs/hooks/key_state.h"
# include "libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define windowWidth 1280
# define windowHeight 720

typedef struct s_data
{
	char		**map;
	int			rows;
	int			columns;
}				t_data;

typedef struct s_img_data
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			width;
	int			height;
}				t_img_data;

typedef struct s_config
{
	t_img_data	*north_texture;
	t_img_data	*south_texture;
	t_img_data	*west_texture;
	t_img_data	*east_texture;
	char		**map;
	int			rows;
	int			columns;
	int			start_x;
	int			start_y;
	char		start_direction;
	int			floor_color;
	int			ceiling_color;
}				t_config;

typedef struct s_player
{
	double		x;
	double		y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
}				t_player;

typedef struct s_cub3d
{
	void		*mlx;
	void		*win;
	t_config	*config;
	t_player	*player;
	t_img_data	*img;
	t_key_state	*key_state;
}				t_cub3d;

// prototypes
void			init_data(t_data *data);
void			parse_map(t_data *data, char *filepath);
void			free_map(char **map);
void			init_cub3d(t_cub3d *cub3d);
void			set_cub3d(t_cub3d *cub3d, char *filepath);
void			free_cub3d(t_cub3d *cub3d);

#endif

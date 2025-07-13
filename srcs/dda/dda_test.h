
#ifndef DDA_TEST_H
# define DDA_TEST_H

#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../hooks/hooks.h"
#include "../hooks/key_state.h"

typedef struct s_dda
{
    double x;
    double y;
    int step_x;
    int step_y;
    double delta_x;
    double delta_y;
    double side_dist_x;
    double side_dist_y;
    double dirX;
    double dirY;
    double planeX;
    double planeY;
    int **map;
    int map_width;
    int map_height;
} t_dda;

typedef struct	s_img_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img_data;

typedef struct s_test
{
    t_dda *dda_data;
    void *mlx;
    void *win;
    t_img_data *img;
    t_key_state *key_state;
} t_test;

void	my_mlx_pixel_put(t_img_data *data, int x, int y, int color);

# define windowWidth 1280
# define windowHeight 720

#endif
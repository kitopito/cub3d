
#ifndef DDA_TEST_H
# define DDA_TEST_H

#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct s_dda_test
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
} t_dda_test;

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

# define windowWidth 1280
# define windowHeight 720

#endif
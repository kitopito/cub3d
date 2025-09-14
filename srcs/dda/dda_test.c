/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_test.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywada <ywada@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 19:15:29 by ywada             #+#    #+#             */
/*   Updated: 2025/08/12 01:25:16 by ywada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hooks/hooks.h"
#include "dda.h"
#include "dda_test.h"

#define mapWidth 24
#define mapHeight 24
#define screenWidth 640
#define screenHeight 480

int		worldMap[mapWidth][mapHeight] = {{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
			1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, {1, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, {1, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, {1, 0, 0, 0, 0,
			0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1}, {1, 0, 0,
			0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, {1,
			0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0,
			1}, {1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 1}, {1, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 1, 0, 1, 0,
			1, 0, 0, 0, 1}, {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 1}, {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 1}, {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
										{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
											0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
											{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
											0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
											{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
											0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
											{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
											0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
											{1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0,
											0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
											{1, 1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0,
											0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
											{1, 1, 0, 0, 0, 0, 5, 0, 1, 0, 0, 0,
											0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
											{1, 1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0,
											0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
											{1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0,
											0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
											{1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
											0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
											{1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0,
											0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
											{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
											1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
											1}};

int		miniMap[6][6] = {
	{1, 1, 1, 1, 1, 1},
	{1, 0, 1, 0, 1, 1},
	{1, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 1},
	{1, 1, 1, 1, 1, 1},
};

// void	dda_test_init_mini_map(t_dda *dda_test)
// {
// 	// int	**map;

// 	// // miniMapをint**に変換
// 	// map = malloc(6 * sizeof(int *));
// 	// for (int i = 0; i < 6; i++)
// 	// {
// 	// 	map[i] = malloc(6 * sizeof(int));
// 	// 	for (int j = 0; j < 6; j++)
// 	// 	{
// 	// 		map[i][j] = miniMap[j][i];
// 	// 	}
// 	// }
// 	dda_test->map = map;
// 	dda_test->map_width = 6;
// 	dda_test->map_height = 6;
// 	dda_test->x = 2;
// 	dda_test->y = 4;
// 	dda_test->dirX = 0.0;
// 	dda_test->dirY = -1.0;
// 	// calulate plane direction
// 	dda_test->planeX = -dda_test->dirY * 3;
// 	dda_test->planeY = dda_test->dirX * 3;
// }

void	my_mlx_pixel_put(t_img_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	dda_test_init(t_dda *dda_data, t_cub3d *cub3d)
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
    dda_data->dirX = cub3d->player->dir_x;
    dda_data->dirY = cub3d->player->dir_y;
    dda_data->planeX = cub3d->player->plane_x;
    dda_data->planeY = cub3d->player->plane_y;
}

void init_dda(t_dda *dda_data, t_cub3d *cub3d) {
    dda_test_init(dda_data, cub3d);
}

void init_test_cub3d(t_cub3d *cub3d)
{
	char	**map;
    
	cub3d->mlx = mlx_init();
	cub3d->win = mlx_new_window(cub3d->mlx, windowWidth, windowHeight, "cub3d");
	//
	cub3d->player->x = 22.0;
	cub3d->player->y = 12.0;
	cub3d->player->dir_x = -1.0;
	cub3d->player->dir_y = 0.0;
	cub3d->player->plane_x = 0.0;
	cub3d->player->plane_y = 0.66;
    //
    cub3d->config->rows = mapHeight;
    cub3d->config->columns = mapWidth;
    cub3d->config->ceiling_color = 0x87CEEB; // Sky blue color
    cub3d->config->floor_color = 0x550000; // Dark brown color
	// worldmapをint**に変換
	cub3d->config->map = malloc(mapHeight * sizeof(char *));
	for (int i = 0; i < mapHeight; i++)
	{
		cub3d->config->map[i] = malloc(mapWidth * sizeof(char));
		for (int j = 0; j < mapWidth; j++)
		{
			cub3d->config->map[i][j] = worldMap[j][i];
		}
	}
	cub3d->config->east_texture = load_texture(cub3d->mlx, "../../textures/animal_chara_radio_azarashi.xpm");
	cub3d->config->west_texture = load_texture(cub3d->mlx, "../../textures/building_kokuzeikyoku.xpm");
	//cub3d->config->west_texture = load_texture(cub3d->mlx, "../../textures/kanban_nature_chouju_hogoku.xpm");
	cub3d->config->south_texture = load_texture(cub3d->mlx, "../../textures/building_takoyaki_yatai.xpm");
	cub3d->config->north_texture = load_texture(cub3d->mlx, "../../textures/onepiece06_chopper.xpm");
    //
	init_key_state(cub3d->key_state);
}

int	main(void)
{
	// t_dda		dda_test;
	// t_test		test_data;
	// void		*mlx;
	// void		*mlx_win;
	// t_key_state	key_state;
    t_cub3d	cub3d;

    cub3d.player = malloc(sizeof(t_player));
    cub3d.config = malloc(sizeof(t_config));
    cub3d.key_state = malloc(sizeof(t_key_state));
    cub3d.img = malloc(sizeof(t_img_data));
    init_test_cub3d(&cub3d);
    //
	// dda_test_init(&dda_test);
	// dda_test_init_mini_map(&dda_test);
	// Here you would typically call your DDA function and process the results.
	// For this example, we will just print the initial values.
	printf("DDA Test Initialized:\n");
	printf("Position: (%lf, %lf)\n", cub3d.player->x, cub3d.player->y);
	// printf("Step: (%d, %d)\n", dda_test.step_x, dda_test.step_y);
	// printf("Delta: (%.2f, %.2f)\n", dda_test.delta_x, dda_test.delta_y);
	// test_data.dda_data = &dda_test;
	// test_data.img = &img;
	// test_data.key_state = &key_state;
	mlx_key_hook(cub3d.win, key_up, &cub3d);
	mlx_hook(cub3d.win, 2, 1L << 0, key_down, &cub3d);
	mlx_hook(cub3d.win, 17, 0, destroy_hook, &cub3d);
	mlx_loop_hook(cub3d.mlx, render, &cub3d);
    cub3d.img->img = mlx_new_image(cub3d.mlx, windowWidth, windowHeight);
	cub3d.img->addr = mlx_get_data_addr(cub3d.img->img, &cub3d.img->bits_per_pixel, &cub3d.img->line_length,
			&cub3d.img->endian);
	// my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
	dda(&cub3d);
	mlx_put_image_to_window(cub3d.mlx, cub3d.win, cub3d.img->img, 0, 0);
	mlx_loop(cub3d.mlx);
	end_cub3d(&cub3d);
	return (0);
}

/*
in directory: srcs/dda
cc -I../../minilibx-linux *.c ../hooks/*.c ../../minilibx-linux/libmlx.a -lXext
	-lX11 -lz -lm
*/
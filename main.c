/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywada <ywada@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 19:14:44 by ywada             #+#    #+#             */
/*   Updated: 2025/08/11 19:15:51 by ywada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// int main(int ac, char **av)
// {
// 	t_config	cfg;
// 	int			i;

// 	if (ac != 2)
// 	{
// 		ft_putstr_fd("Usage: ./cub3D <map_file>\n", 2);
// 		return (EXIT_FAILURE);
// 	}
// 	init_config(&cfg);
// 	parse_map(&cfg, av[1]);
// 	if (!check_components(&cfg))
// 		return (EXIT_FAILURE);
// 	//マップの表示
// 	print_parsed(&cfg);
// 	i = 0;
// 	while (cfg.map && cfg.map[i])
// 	{
// 		printf("%s\n", cfg.map[i]);
// 		i++;
// 	}
// 	free_map(cfg.map);
// 	return (EXIT_SUCCESS);
// }

#include "srcs/hooks/hooks.h"
#include "srcs/dda/dda.h"
#include <mlx.h>

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
	// char	**map;
    
	// cub3d->mlx = mlx_init();
	// cub3d->win = mlx_new_window(cub3d->mlx, windowWidth, windowHeight, "cub3d");
	//
	// cub3d->player->x = 22.0;
	// cub3d->player->y = 12.0;
	cub3d->player->x = cub3d->config->start_x + 0.5;
	cub3d->player->y = cub3d->config->start_y + 0.5;
	if (cub3d->config->start_direction == 'W') {
		cub3d->player->dir_x = -1.0;
		cub3d->player->dir_y = 0.0;
	}
	else if (cub3d->config->start_direction == 'E') {
		cub3d->player->dir_x = 1.0;
		cub3d->player->dir_y = 0.0;
	}
	else if (cub3d->config->start_direction == 'S') {
		cub3d->player->dir_x = 0.0;
		cub3d->player->dir_y = 1.0;
	}
	else if (cub3d->config->start_direction == 'N') {
		cub3d->player->dir_x = 0.0;
		cub3d->player->dir_y = -1.0;
	}
	// cub3d->player->x = cub3d->config->start_x + 0.5; // マップの中心に配置
	// cub3d->player->y = cub3d->config->start_y + 0.5; // マップの中心に配置
	//カメラ平面の設定
	// double fov = 60.0; // 視野角
	//
	double Plane_Width = 0.66; // 画面の幅に対するカメラ平面の幅
	cub3d->player->plane_x = Plane_Width * cub3d->player->dir_y;
	cub3d->player->plane_y = -Plane_Width * cub3d->player->dir_x;
	// cub3d->player->plane_x = 0.0;
	// cub3d->player->plane_y = 0.66;
    //
    // cub3d->config->rows = mapHeight;
    // cub3d->config->columns = mapWidth;
    // cub3d->config->ceiling_color = 0x87CEEB; // Sky blue color
    // cub3d->config->floor_color = 0x550000; // Dark brown color
	// worldmapをint**に変換
	// cub3d->config->map = malloc(mapHeight * sizeof(char *));
	// for (int i = 0; i < mapHeight; i++)
	// {
	// 	cub3d->config->map[i] = malloc(mapWidth * sizeof(char));
	// 	for (int j = 0; j < mapWidth; j++)
	// 	{
	// 		cub3d->config->map[i][j] = worldMap[j][i];
	// 	}
	// }
	cub3d->config->east_texture = load_texture(cub3d->mlx, cub3d->config->texture_path[TEX_EA]);
	cub3d->config->west_texture = load_texture(cub3d->mlx, cub3d->config->texture_path[TEX_WE]);
	//cub3d->config->west_texture = load_texture(cub3d->mlx, "../../textures/kanban_nature_chouju_hogoku.xpm");
	cub3d->config->south_texture = load_texture(cub3d->mlx, cub3d->config->texture_path[TEX_SO]);
	cub3d->config->north_texture = load_texture(cub3d->mlx, cub3d->config->texture_path[TEX_NO]);
	if (cub3d->config->east_texture == NULL || cub3d->config->west_texture == NULL
		|| cub3d->config->south_texture == NULL || cub3d->config->north_texture == NULL)
	{
		perror("Failed to load texture");
		end_cub3d(cub3d);
	}
    //
	// init_key_state(cub3d->key_state);
}

int	main(int ac, char **av)
{
    t_cub3d	cub3d;
	char	*filename;

	if (ac != 2)
	{
		ft_putstr_fd("Usage: ./cub3D <map_file>\n", 2);
		return (EXIT_FAILURE);
	}
	filename = av[1];

	init_cub3d(&cub3d);
	set_cub3d(&cub3d, filename);
	printf("ふが　\n");
	init_test_cub3d(&cub3d);
    // cub3d.player = malloc(sizeof(t_player));
    // cub3d.config = malloc(sizeof(t_config));
    // cub3d.key_state = malloc(sizeof(t_key_state));
    // cub3d.img = malloc(sizeof(t_img_data));
    // init_test_cub3d(&cub3d);
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
	// my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
	dda(&cub3d);
	mlx_put_image_to_window(cub3d.mlx, cub3d.win, cub3d.img->img, 0, 0);
	mlx_loop(cub3d.mlx);
	end_cub3d(&cub3d);
	return (0);
}
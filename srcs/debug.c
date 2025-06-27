#include "../cub3d.h"

// void	print_map(t_data *data)
// {
// 	int		x;
// 	int		y;
// 	char	c;

// 	y = 0;
// 	while (data->map[y])
// 	{
// 		x = 0;
// 		while (data->map[y][x])
// 		{
// 			c = data->map[y][x];
// 			// if (c == 'V')
// 			// 	write(1, "#", 1);
// 			// else
// 				write(1, &c, 1);
// 			x++;
// 		}
// 		printf("\n");
// 		y++;
// 	}
// 	printf("\n");
// }

// void	print_info(t_data *data)
// {
// 	// printf(YELLOW);
// 	// ======================== file ========================
// 	printf("NORTH : %s\n", data->texture_paths[NORTH]);
// 	printf("SOUTH : %s\n", data->texture_paths[SOUTH]);
// 	printf(" WEST : %s\n", data->texture_paths[WEST]);
// 	printf(" EAST : %s\n", data->texture_paths[EAST]);
// 	printf("ceiling : %3d, %3d, %3d\n", data->ceiling_rgb[0],
// 		data->ceiling_rgb[1], data->ceiling_rgb[2]);
// 	printf("  floor : %3d, %3d, %3d\n", data->floor_rgb[0], data->floor_rgb[1],
// 		data->floor_rgb[2]);

// 	// ======================== map ========================
// 	printf("map rows    : %d\n", data->rows);
// 	printf("map columns : %d\n", data->columns);

// 	// printf(END);
// }


#include "dda.h"
#include <mlx.h>

int	mlx_pixel_get(t_img_data *data, int x, int y)
{
	char	*src;

	if (x < 0 || x >= data->width || y < 0 || y >= data->height)
		return (0);
	src = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	return (*(unsigned int *)src);
}

t_img_data	*load_texture(void *mlx, char *filename)
{
	t_img_data	*texture;

	texture = malloc(sizeof(t_img_data));
	if (texture == NULL)
		return (NULL);
	texture->img = mlx_xpm_file_to_image(mlx, filename, &texture->width, &texture->height);
	if (texture->img == NULL)
	{
		free(texture);
		return (NULL);
	}
	texture->addr = mlx_get_data_addr(texture->img, &texture->bits_per_pixel, 
		&texture->line_length, &texture->endian);
	if (texture->addr == NULL)
	{
		mlx_destroy_image(mlx, texture->img);
		free(texture);
		return (NULL);
	}
	return (texture);
}

// cub3d.img->img = mlx_new_image(cub3d.mlx, windowWidth, windowHeight);
// cub3d.img->addr = mlx_get_data_addr(cub3d.img->img, &cub3d.img->bits_per_pixel, &cub3d.img->line_length,
// 		&cub3d.img->endian);

// void	free_texture(void *mlx, t_img_data *texture)
// {
// 	if (texture != NULL)
// 	{
// 		if (texture->img != NULL)
// 			mlx_destroy_image(mlx, texture->img);
// 		free(texture);
// 	}
// }
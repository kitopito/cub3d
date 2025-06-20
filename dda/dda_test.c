#include "dda_test.h"
#include "dda.h"

#define mapWidth 24
#define mapHeight 24
#define screenWidth 640
#define screenHeight 480

int worldMap[mapWidth][mapHeight]=
{
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,1,1,1,1,1,0,0,0,0,1,0,1,0,1,0,0,0,1},
  {1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,1,0,0,0,1,0,0,0,1},
  {1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,1,1,0,1,1,0,0,0,0,1,0,1,0,1,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,0,0,0,0,5,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

int miniMap[6][6] = {
    {1, 1, 1, 1, 1, 1},
    {1, 0, 1, 0, 1, 1},
    {1, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 1},
};

void dda_test_init(t_dda_test *dda_test)
{
    //worldmapをint**に変換
    int **map = malloc(mapHeight * sizeof(int *));
    for (int i = 0; i < mapHeight; i++) {
        map[i] = malloc(mapWidth * sizeof(int));
        for (int j = 0; j < mapWidth; j++) {
            map[i][j] = worldMap[j][i];
        }
    }
    dda_test->x = 22.5;
    dda_test->y = 12.5;
    dda_test->step_x = 1;
    dda_test->step_y = 1;
    dda_test->delta_x = 0.5;
    dda_test->delta_y = 0.5;
    dda_test->side_dist_x = 0.0;
    dda_test->side_dist_y = 0.0;
    dda_test->dirX = -1.0;
    dda_test->dirY = 0.0;
    dda_test->planeX = 0.0;
    dda_test->planeY = 0.66;
    dda_test->map = map;
    dda_test->map_width = mapWidth;
    dda_test->map_height = mapHeight;
}

void dda_test_init_mini_map(t_dda_test *dda_test)
{
    // miniMapをint**に変換
    int **map = malloc(6 * sizeof(int *));
    for (int i = 0; i < 6; i++) {
        map[i] = malloc(6 * sizeof(int));
        for (int j = 0; j < 6; j++) {
            map[i][j] = miniMap[j][i];
        }
    }
    dda_test->map = map;
    dda_test->map_width = 6;
    dda_test->map_height = 6;

    dda_test->x = 2;
    dda_test->y = 4;
    dda_test->dirX = 0.0;
    dda_test->dirY = -1.0;
    // calulate plane direction
    dda_test->planeX = -dda_test->dirY * 3;
    dda_test->planeY = dda_test->dirX * 3;
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int main(void)
{
    t_dda_test dda_test;

    //dda_test_init(&dda_test);
    dda_test_init_mini_map(&dda_test);

    // Here you would typically call your DDA function and process the results.
    // For this example, we will just print the initial values.
    printf("DDA Test Initialized:\n");
    printf("Position: (%lf, %lf)\n", dda_test.x, dda_test.y);
    printf("Step: (%d, %d)\n", dda_test.step_x, dda_test.step_y);
    printf("Delta: (%.2f, %.2f)\n", dda_test.delta_x, dda_test.delta_y);
    
    t_data	img;

	void *mlx = mlx_init();
	void *mlx_win = mlx_new_window(mlx, windowWidth, windowHeight, "Hello world!");
	img.img = mlx_new_image(mlx, windowWidth, windowHeight);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	//my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
    dda(&dda_test, &img);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);

    return 0;
}

#include "hooks.h"
#include "../../cub3d.h"
#include "../dda/dda_test.h"
#include "../dda/dda.h"

int key_hook(int keycode, t_test *data) {
    if (keycode == KEYCODE_ESC) {
        mlx_loop_end(data->mlx);
    }
    return 0;
}

int destroy_hook(t_test *data) {
    mlx_loop_end(data->mlx);
    return 0;
}

void end_cub3d(t_test *data) {
}
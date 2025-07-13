
#ifndef HOOKS_H
# define HOOKS_H

#include "../dda/dda_test.h"

# define KEYCODE_ESC 65307

int key_hook(int keycode, t_test *data);

int destroy_hook(t_test *data);

void end_cub3d(t_test *data);
    
#endif
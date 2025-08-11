/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywada <ywada@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 19:15:02 by ywada             #+#    #+#             */
/*   Updated: 2025/08/11 19:15:51 by ywada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>
#include "hooks.h"
#include "../../cub3d.h"
#include "../dda/dda_test.h"
#include "../dda/dda.h"

int key_up(int keycode, t_test *data) {
    if (keycode == KEYCODE_ESC) {
        mlx_loop_end(data->mlx);
    }
    else if (keycode == KEYCODE_W) {
        data->key_state->w = false;
    }
    else if (keycode == KEYCODE_A) {
        data->key_state->a = false;
    }
    else if (keycode == KEYCODE_S) {
        data->key_state->s = false;
    }
    else if (keycode == KEYCODE_D) {
        data->key_state->d = false;
    }
    else if (keycode == KEYCODE_LEFT) {
        data->key_state->left = false;
    }
    else if (keycode == KEYCODE_RIGHT) {
        data->key_state->right = false;
    }

    return 0;
}

int key_down(int keycode, t_test *data) {
    printf("Key pressed: %d\n", keycode);
    if (keycode == KEYCODE_W) {
        data->key_state->w = true;
    }
    if (keycode == KEYCODE_A) {
        data->key_state->a = true;
    }
    if (keycode == KEYCODE_S) {
        data->key_state->s = true;
    }
    if (keycode == KEYCODE_D) {
        data->key_state->d = true;
    }
    if (keycode == KEYCODE_LEFT) {
        data->key_state->left = true;
    }
    if (keycode == KEYCODE_RIGHT) {
        data->key_state->right = true;
    }

    return 0;
}

int render(t_test *data) {
    // printf("key state: W=%d, A=%d, S=%d, D=%d, LEFT=%d, RIGHT=%d\n",
    //        data->key_state->w, data->key_state->a, data->key_state->s,
    //        data->key_state->d, data->key_state->left, data->key_state->right);
    if (data->key_state->left) {
        rotate_player(data->dda_data, ROTATION_ANGLE);
    }
    if (data->key_state->right) {
        rotate_player(data->dda_data, -ROTATION_ANGLE);
    }
    if (data->key_state->w) {
        data->dda_data->x += data->dda_data->dirX * VELOCITY;
        data->dda_data->y += data->dda_data->dirY * VELOCITY;
    }
    if (data->key_state->s) {
        data->dda_data->x -= data->dda_data->dirX * VELOCITY;
        data->dda_data->y -= data->dda_data->dirY * VELOCITY;
    }
    if (data->key_state->a) {
        data->dda_data->x -= data->dda_data->dirY * VELOCITY;
        data->dda_data->y += data->dda_data->dirX * VELOCITY;
    }
    if (data->key_state->d) {
        data->dda_data->x += data->dda_data->dirY * VELOCITY;
        data->dda_data->y -= data->dda_data->dirX * VELOCITY;
    }
    dda(data->dda_data, data->img);
    mlx_put_image_to_window(data->mlx, data->win, data->img->img, 0, 0);
    return 0;
}

int destroy_hook(t_test *data) {
    mlx_loop_end(data->mlx);
    return 0;
}

void end_cub3d(t_test *data) {
}

void rotate_player(t_dda *dda_data, double angle) {
    double oldDirX = dda_data->dirX;
    double oldDirY = dda_data->dirY;
    dda_data->dirX = oldDirX * cos(angle) - oldDirY * sin(angle);
    dda_data->dirY = oldDirX * sin(angle) + oldDirY * cos(angle);
    
    double oldPlaneX = dda_data->planeX;
    double oldPlaneY = dda_data->planeY;
    dda_data->planeX = oldPlaneX * cos(angle) - oldPlaneY * sin(angle);
    dda_data->planeY = oldPlaneX * sin(angle) + oldPlaneY * cos(angle);
}

void init_key_state(t_key_state *state) {
    state->w = false;
    state->a = false;
    state->s = false;
    state->d = false;
    state->left = false;
    state->right = false;
}
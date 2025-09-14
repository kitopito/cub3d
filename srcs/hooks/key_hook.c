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
#include "../dda/dda.h"
#include <mlx.h>

int key_up(int keycode, t_cub3d *data) {
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

int key_down(int keycode, t_cub3d *data) {
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

int render(t_cub3d *data) {
    // printf("key state: W=%d, A=%d, S=%d, D=%d, LEFT=%d, RIGHT=%d\n",
    //        data->key_state->w, data->key_state->a, data->key_state->s,
    //        data->key_state->d, data->key_state->left, data->key_state->right);
    if (data->key_state->left) {
        rotate_player(data->player, ROTATION_ANGLE);
    }
    if (data->key_state->right) {
        rotate_player(data->player, -ROTATION_ANGLE);
    }
    if (data->key_state->w) {
        data->player->x += data->player->dir_x * VELOCITY;
        data->player->y += data->player->dir_y * VELOCITY;
    }
    if (data->key_state->s) {
        data->player->x -= data->player->dir_x * VELOCITY;
        data->player->y -= data->player->dir_y * VELOCITY;
    }
    if (data->key_state->a) {
        data->player->x -= data->player->dir_y * VELOCITY;
        data->player->y += data->player->dir_x * VELOCITY;
    }
    if (data->key_state->d) {
        data->player->x += data->player->dir_y * VELOCITY;
        data->player->y -= data->player->dir_x * VELOCITY;
    }
    dda(data);
    mlx_put_image_to_window(data->mlx, data->win, data->img->img, 0, 0);
    return 0;
}

int destroy_hook(t_cub3d *data) {
    mlx_loop_end(data->mlx);
    return 0;
}

void end_cub3d(t_cub3d *data) {
    //
    (void)data;
}

void rotate_player(t_player *player, double angle) {
    double oldDirX = player->dir_x;
    double oldDirY = player->dir_y;
    player->dir_x = oldDirX * cos(angle) - oldDirY * sin(angle);
    player->dir_y = oldDirX * sin(angle) + oldDirY * cos(angle);
    
    double oldPlaneX = player->plane_x;
    double oldPlaneY = player->plane_y;
    player->plane_x = oldPlaneX * cos(angle) - oldPlaneY * sin(angle);
    player->plane_y = oldPlaneX * sin(angle) + oldPlaneY * cos(angle);
}

void init_key_state(t_key_state *state) {
    state->w = false;
    state->a = false;
    state->s = false;
    state->d = false;
    state->left = false;
    state->right = false;
}
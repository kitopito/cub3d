/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywada <ywada@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 19:15:09 by ywada             #+#    #+#             */
/*   Updated: 2025/09/15 20:57:39 by ywada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOOKS_H
# define HOOKS_H

# include "key_state.h"

typedef struct s_cub3d	t_cub3d;
typedef struct s_player	t_player;

# define KEYCODE_ESC 65307
# define KEYCODE_W 119
# define KEYCODE_A 97
# define KEYCODE_S 115
# define KEYCODE_D 100
# define KEYCODE_LEFT 65361
# define KEYCODE_RIGHT 65363

# define VELOCITY 0.03
//# define ROTATION_ANGLE 0.005
# define ROTATION_ANGLE 0.01

void					init_key_state(t_key_state *state);

int						key_up(int keycode, t_cub3d *data);
int						key_down(int keycode, t_cub3d *data);

int						destroy_hook(t_cub3d *data);

void					end_cub3d(t_cub3d *data);

void					move(t_cub3d *data, t_player *player);
void					rotate_player(t_player *player, double angle);

int						render(t_cub3d *data);

#endif
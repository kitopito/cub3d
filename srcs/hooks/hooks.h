/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywada <ywada@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 19:15:09 by ywada             #+#    #+#             */
/*   Updated: 2025/08/11 19:15:51 by ywada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef HOOKS_H
# define HOOKS_H

//#include "../dda/dda_test.h"
#include "key_state.h"

typedef struct s_dda t_dda;
typedef struct s_test t_test;

# define KEYCODE_ESC 65307
# define KEYCODE_W 119
# define KEYCODE_A 97
# define KEYCODE_S 115
# define KEYCODE_D 100
# define KEYCODE_LEFT 65361
# define KEYCODE_RIGHT 65363

# define VELOCITY 0.03
# define ROTATION_ANGLE 0.005

void init_key_state(t_key_state *state);

int key_up(int keycode, t_test *data);
int key_down(int keycode, t_test *data);

int destroy_hook(t_test *data);

void end_cub3d(t_test *data);

void rotate_player(t_dda *dda_data, double angle);
    
int render(t_test *data);

#endif
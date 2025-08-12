/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_test.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywada <ywada@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 19:15:26 by ywada             #+#    #+#             */
/*   Updated: 2025/08/12 17:24:41 by ywada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DDA_TEST_H
# define DDA_TEST_H

# include "../hooks/hooks.h"
# include "../hooks/key_state.h"
# include <math.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_test
{
	t_dda		*dda_data;
	void		*mlx;
	void		*win;
	t_img_data	*img;
	t_key_state	*key_state;
}				t_test;

void			my_mlx_pixel_put(t_img_data *data, int x, int y, int color);

#endif
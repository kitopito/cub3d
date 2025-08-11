/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywada <ywada@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 19:24:38 by ywada             #+#    #+#             */
/*   Updated: 2025/08/11 19:36:01 by ywada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void init_cub3d(t_cub3d *cub3d) {
	cub3d->mlx = NULL;
	cub3d->win = NULL;
	cub3d->config = NULL;
	cub3d->player = NULL;
	cub3d->img = NULL;
	cub3d->key_state = NULL;
}

void set_cub3d(t_cub3d *cub3d, char *filepath) {
}

void free_cub3d(t_cub3d *cub3d) {
	cub3d->mlx = NULL;
	cub3d->win = NULL;
	if(cub3d->config) {
		free(cub3d->config->north_texture);
		free(cub3d->config->south_texture);
		free(cub3d->config->west_texture);
		free(cub3d->config->east_texture);
		free(cub3d->config->map);
		free(cub3d->config);
	}
	free(cub3d->player);
	free(cub3d->img);
	free(cub3d->key_state);
}
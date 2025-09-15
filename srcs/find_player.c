/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywada <ywada@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 20:44:35 by ywada             #+#    #+#             */
/*   Updated: 2025/09/15 20:55:51 by ywada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	find_player_row(t_config *cfg, int y, int *count, char *row)
{
	int	x;

	x = 0;
	while (row[x])
	{
		if (ft_strchr("NSEW", row[x]))
		{
			if (*count == 0)
			{
				cfg->start_x = x;
				cfg->start_y = y;
				cfg->start_direction = row[x];
			}
			(*count)++;
			row[x] = '0';
		}
		x++;
	}
}

int	find_player_start(t_config *cfg)
{
	int		y;
	int		count;
	char	*row;

	y = 0;
	count = 0;
	while (cfg->map && cfg->map[y])
	{
		row = cfg->map[y];
		find_player_row(cfg, y, &count, row);
		y++;
	}
	cfg->player_count = count;
	return (count == 1);
}

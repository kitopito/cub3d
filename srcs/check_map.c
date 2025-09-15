/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywada <ywada@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 21:17:12 by ywada             #+#    #+#             */
/*   Updated: 2025/09/15 21:17:47 by ywada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	no_zero_on_top_bottom(const t_config *cfg)
{
	int	len_top;
	int	len_bot;
	int	x;

	len_top = (int)ft_strlen(cfg->map[0]);
	x = 0;
	while (x < len_top)
	{
		if (cfg->map[0][x] == '0')
			return (0);
		x++;
	}
	len_bot = (int)ft_strlen(cfg->map[cfg->rows - 1]);
	x = 0;
	while (x < len_bot)
	{
		if (cfg->map[cfg->rows - 1][x] == '0')
			return (0);
		x++;
	}
	return (1);
}

int	no_zero_on_border(const t_config *cfg)
{
	int	y;
	int	len;

	if (cfg->rows == 0)
		return (0);
	if (no_zero_on_top_bottom(cfg) == 0)
		return (0);
	y = 0;
	while (y < cfg->rows)
	{
		len = (int)ft_strlen(cfg->map[y]);
		if (len > 0)
		{
			if (cfg->map[y][0] == '0')
				return (0);
			if (cfg->map[y][len - 1] == '0')
				return (0);
		}
		y++;
	}
	return (1);
}

int	is_zero_on_map_edge(const t_config *cfg, int x, int y, int len)
{
	int	len_up;
	int	len_dn;

	if (y == 0 || y == cfg->rows - 1 || x == 0 || x == len - 1)
		return (0);
	len_up = (int)ft_strlen(cfg->map[y - 1]);
	len_dn = (int)ft_strlen(cfg->map[y + 1]);
	if (x >= len_up || x >= len_dn)
		return (0);
	if (cfg->map[y - 1][x] == ' ' || cfg->map[y + 1][x] == ' ' || cfg->map[y][x
		- 1] == ' ' || cfg->map[y][x + 1] == ' ')
		return (0);
	return (1);
}

int	closed_by_walls(const t_config *cfg)
{
	int	y;
	int	x;
	int	len;

	y = 0;
	while (y < cfg->rows)
	{
		len = (int)ft_strlen(cfg->map[y]);
		x = 0;
		while (x < len)
		{
			if (cfg->map[y][x] == '0')
			{
				if (is_zero_on_map_edge(cfg, x, y, len) == 0)
					return (0);
			}
			x++;
		}
		y++;
	}
	return (1);
}

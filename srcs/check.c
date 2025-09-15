/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywada <ywada@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 18:28:44 by ywada             #+#    #+#             */
/*   Updated: 2025/09/15 21:17:05 by ywada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	file_exists(const char *p)
{
	int	fd;

	if (!p || !*p)
		return (0);
	fd = open(p, O_RDONLY);
	if (fd < 0)
		return (0);
	close(fd);
	return (1);
}

int	has_allowed_chars(const t_config *cfg)
{
	int		y;
	int		x;
	char	c;
	int		len;

	y = 0;
	while (y < cfg->rows)
	{
		len = (int)ft_strlen(cfg->map[y]);
		x = 0;
		while (x < len)
		{
			c = cfg->map[y][x];
			if (!(c == '0' || c == '1' || c == ' '))
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

static int	in_range_rgb(const int rgb[3])
{
	return (rgb[0] >= 0 && rgb[0] <= 255 && rgb[1] >= 0 && rgb[1] <= 255
		&& rgb[2] >= 0 && rgb[2] <= 255);
}

int	check_map_structure(const t_config *cfg)
{
	int	len_row;

	if (cfg->player_count != 1)
		return (ft_putendl_fd("Error: invalid player", 2), 0);
	if (cfg->start_y < 0 || cfg->start_y >= cfg->rows)
		return (ft_putendl_fd("Error: invalid player", 2), 0);
	len_row = (int)ft_strlen(cfg->map[cfg->start_y]);
	if (cfg->start_x < 0 || cfg->start_x >= len_row)
		return (ft_putendl_fd("Error: invalid player", 2), 0);
	if (!in_range_rgb(cfg->floor_rgb) || !in_range_rgb(cfg->ceiling_rgb))
		return (ft_putendl_fd("Error: invalid color", 2), 0);
	if (!has_allowed_chars(cfg))
		return (ft_putendl_fd("Error: invalid map", 2), 0);
	if (!no_zero_on_border(cfg))
		return (ft_putendl_fd("Error: invalid map", 2), 0);
	if (!closed_by_walls(cfg))
		return (ft_putendl_fd("Error: invalid map", 2), 0);
	return (1);
}

int	check_components(const t_config *cfg)
{
	int	i;

	if (!cfg->map || cfg->rows <= 0)
	{
		ft_putendl_fd("Error: invalid map", 2);
		return (0);
	}
	i = 0;
	while (i < TEX_MAX)
	{
		if (!cfg->texture_path[i] || !file_exists(cfg->texture_path[i]))
		{
			ft_putendl_fd("Error: texture missing", 2);
			return (0);
		}
		i++;
	}
	if (check_map_structure(cfg) == 0)
		return (0);
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywada <ywada@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 19:14:51 by ywada             #+#    #+#             */
/*   Updated: 2025/09/15 21:27:40 by ywada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	parse_rgb(char *s, int out[3])
{
	char	**sp;
	int		i;
	char	*p;
	int		v;

	sp = ft_split(s, ',');
	if (!sp || !sp[0] || !sp[1] || !sp[2] || sp[3])
		return (split_free(sp), 0);
	i = 0;
	while (i < 3)
	{
		p = skip_ws(sp[i]);
		if (!*p)
			return (split_free(sp), 0);
		v = ft_atoi(p);
		while (*p == ' ' || *p == '\t' || ft_isdigit(*p))
			p++;
		while (*p == ' ' || *p == '\t')
			p++;
		if (*p != '\0' || v < 0 || v > 255)
			return (split_free(sp), 0);
		out[i++] = v;
	}
	return (split_free(sp), 1);
}

static int	handle_meta_line(t_config *cfg, char *ln)
{
	char	*p;

	p = skip_ws(ln);
	if (*p == '\0')
		return (0);
	if (!cfg->texture_path[TEX_NO] && ft_strncmp(p, "NO ", 3) == 0)
		return ((cfg->texture_path[TEX_NO] = ft_strtrim(skip_ws(p + 3),
					" \t")) != NULL);
	if (!cfg->texture_path[TEX_SO] && ft_strncmp(p, "SO ", 3) == 0)
		return ((cfg->texture_path[TEX_SO] = ft_strtrim(skip_ws(p + 3),
					" \t")) != NULL);
	if (!cfg->texture_path[TEX_WE] && ft_strncmp(p, "WE ", 3) == 0)
		return ((cfg->texture_path[TEX_WE] = ft_strtrim(skip_ws(p + 3),
					" \t")) != NULL);
	if (!cfg->texture_path[TEX_EA] && ft_strncmp(p, "EA ", 3) == 0)
		return ((cfg->texture_path[TEX_EA] = ft_strtrim(skip_ws(p + 3),
					" \t")) != NULL);
	if (ft_strncmp(p, "F ", 2) == 0)
		return (parse_rgb(p + 2, cfg->floor_rgb));
	if (ft_strncmp(p, "C ", 2) == 0)
		return (parse_rgb(p + 2, cfg->ceiling_rgb));
	return (-1);
}

int	set_metadata(t_config *cfg, char **lines, int line_count, int *map_start)
{
	int	i;
	int	got;
	int	r;

	(void)cfg;
	i = 0;
	got = 0;
	while (i < line_count)
	{
		r = handle_meta_line(cfg, lines[i]);
		if (r == 1)
			got++;
		else if (r == -1)
			break ;
		i++;
	}
	*map_start = i;
	return (got == 6);
}

void	set_map_from(t_config *cfg, char **lines, int start, int count)
{
	int	i;
	int	cnt;

	i = start;
	cnt = 0;
	while (i < count && lines[i] && lines[i][0] != '\0')
	{
		cnt++;
		i++;
	}
	cfg->map = (char **)malloc(sizeof(char *) * (cnt + 1));
	if (!cfg->map)
		return ;
	cfg->rows = cnt;
	i = 0;
	while (i < cnt)
	{
		cfg->map[i] = ft_strdup(lines[start + i]);
		i++;
	}
	cfg->map[i] = NULL;
	cfg->columns = 0;
	if (cnt > 0)
		cfg->columns = (int)ft_strlen(cfg->map[0]);
}

int	parse_map(t_config *cfg, char *filepath)
{
	int		n;
	int		map_start;
	int		i;
	char	**file;

	file = read_all_lines(filepath, &n);
	if (!file || n <= 0)
		return (perror("Error\ninvalid or empty map file"), (0));
	if (!set_metadata(cfg, file, n, &map_start))
	{
		while (n)
			free(file[n-- - 1]);
		return (free(file), perror("Error\nmetadata parse error"), (0));
	}
	set_map_from(cfg, file, map_start, n);
	(void)find_player_start(cfg);
	cfg->floor_color = (cfg->floor_rgb[0] << 16)
		| (cfg->floor_rgb[1] << 8) | cfg->floor_rgb[2];
	cfg->ceiling_color = (cfg->ceiling_rgb[0] << 16)
		| (cfg->ceiling_rgb[1] << 8) | cfg->ceiling_rgb[2];
	i = 0;
	while (i < n)
		free(file[i++]);
	free(file);
	return (1);
}

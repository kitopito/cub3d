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

static int	handle_meta_line(t_data *d, char *ln)
{
	char	*p;

	p = skip_ws(ln);
	if (*p == '\0')
		return (0);
	if (!d->texture_paths[0] && ft_strncmp(p, "NO ", 3) == 0)
		return ((d->texture_paths[0] = ft_strtrim(skip_ws(p + 3), " \t")) != NULL);
	if (!d->texture_paths[1] && ft_strncmp(p, "SO ", 3) == 0)
		return ((d->texture_paths[1] = ft_strtrim(skip_ws(p + 3), " \t")) != NULL);
	if (!d->texture_paths[2] && ft_strncmp(p, "WE ", 3) == 0)
		return ((d->texture_paths[2] = ft_strtrim(skip_ws(p + 3), " \t")) != NULL);
	if (!d->texture_paths[3] && ft_strncmp(p, "EA ", 3) == 0)
		return ((d->texture_paths[3] = ft_strtrim(skip_ws(p + 3), " \t")) != NULL);
	if (ft_strncmp(p, "F ", 2) == 0)
		return (parse_rgb(p + 2, d->floor_rgb));
	if (ft_strncmp(p, "C ", 2) == 0)
		return (parse_rgb(p + 2, d->ceiling_rgb));
	return (-1);
}

int	set_metadata(t_data *d, char **lines, int n, int *map_start)
{
	int	i;
	int	got;
	int	r;

	i = 0;
	got = 0;
	while (i < n)
	{
		r = handle_meta_line(d, lines[i]);
		if (r == 1)
			got++;
		else if (r == -1)
			break ;
		i++;
	}
	*map_start = i;
	return (got == 6);
}

void	set_map_from(t_data *d, char **lines, int start, int n)
{
	int	i;
	int	cnt;

	i = start;
	cnt = 0;
	while (i < n && lines[i] && lines[i][0] != '\0')
	{
		cnt++;
		i++;
	}
	d->map = (char **)malloc(sizeof(char *) * (cnt + 1));
	if (!d->map)
		return ;
	d->rows = cnt;
	i = 0;
	while (i < cnt)
	{
		d->map[i] = ft_strdup(lines[start + i]);
		i++;
	}
	d->map[i] = NULL;
	d->columns = (cnt > 0) ? (int)ft_strlen(d->map[0]) : 0;
}

int	find_player_start(t_data *d)
{
	int		y;
	int		x;
	char	*row;

	y = 0;
	while (d->map && d->map[y])
	{
		row = d->map[y];
		x = 0;
		while (row[x])
		{
			if (ft_strchr("NSEW", row[x]))
			{
				d->start_x = x;
				d->start_y = y;
				d->start_dir = row[x];
				row[x] = '0';
				return (1);
			}
			x++;
		}
		y++;
	}
	return (0);
}

void	parse_map(t_data *d, char *path)
{
	int		n;
	int		map_start;
	int		i;
	char	**file;

	file = read_all_lines(path, &n);
	if (!file || n <= 0)
	{
		perror("invalid or empty map file");
		exit(EXIT_FAILURE);
	}
	d->texture_paths[0] = NULL;
	d->texture_paths[1] = NULL;
	d->texture_paths[2] = NULL;
	d->texture_paths[3] = NULL;
	if (!set_metadata(d, file, n, &map_start))
	{
		perror("metadata parse error");
		exit(EXIT_FAILURE);
	}
	set_map_from(d, file, map_start, n);
	(void)find_player_start(d);
	i = 0;
	while (i < n)
		free(file[i++]);
	free(file);
}

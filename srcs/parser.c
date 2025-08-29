#include "../cub3d.h"

static int	count_lines(char *path)
{
	int		fd;
	int		n;
	char	*line;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (-1);
	n = 0;
	line = get_next_line(fd);
	while (line)
	{
		n++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (n);
}

static char	**read_all_lines(char *path, int *out_n)
{
	int		fd;
	int		n;
	int		i;
	char	**arr;
	char	*line;

	n = count_lines(path);
	fd = open(path, O_RDONLY);
	if (n <= 0 || fd < 0)
		return (NULL);
	arr = (char **)malloc(sizeof(char *) * n);
	if (!arr)
		return (NULL);
	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		arr[i] = ft_strtrim(line, "\n");
		free(line);
		i++;
		line = get_next_line(fd);
	}
	close(fd);
	*out_n = n;
	return (arr);
}

static char	*skip_ws(char *s)
{
	while (*s == ' ' || *s == '\t')
		s++;
	return (s);
}

static int	free_splits(char **sp, int ret)
{
	int	i;

	i = 0;
	while (sp && sp[i])
	{
		free(sp[i]);
		i++;
	}
	if (sp)
		free(sp);
	return (ret);
}

static int	parse_rgb(char *s, int out[3])
{
	char	**sp;
	int		i;
	char	*p;
	int		v;

	sp = ft_split(s, ',');
	if (!sp || !sp[0] || !sp[1] || !sp[2] || sp[3])
		return (free_splits(sp, 0));
	i = 0;
	while (i < 3)
	{
		p = skip_ws(sp[i]);
		if (!*p)
			return (free_splits(sp, 0));
		v = ft_atoi(p);
		while (*p == ' ' || *p == '\t' || ft_isdigit(*p))
			p++;
		while (*p == ' ' || *p == '\t')
			p++;
		if (*p != '\0' || v < 0 || v > 255)
			return (free_splits(sp, 0));
		out[i] = v;
		i++;
	}
	return (free_splits(sp, 1));
}

static char	*dup_after_key(char *line, int skip)
{
	char	*p;

	p = skip_ws(line + skip);
	return (ft_strtrim(p, " \t"));
}

static int	handle_meta_line(t_data *d, char *ln)
{
	char	*p;

	p = skip_ws(ln);
	if (*p == '\0')
		return (0);
	if (!d->texture_paths[0] && ft_strncmp(p, "NO ", 3) == 0)
		return ((d->texture_paths[0] = dup_after_key(p, 3)) != NULL);
	if (!d->texture_paths[1] && ft_strncmp(p, "SO ", 3) == 0)
		return ((d->texture_paths[1] = dup_after_key(p, 3)) != NULL);
	if (!d->texture_paths[2] && ft_strncmp(p, "WE ", 3) == 0)
		return ((d->texture_paths[2] = dup_after_key(p, 3)) != NULL);
	if (!d->texture_paths[3] && ft_strncmp(p, "EA ", 3) == 0)
		return ((d->texture_paths[3] = dup_after_key(p, 3)) != NULL);
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
		{
			got++;
			i++;
			continue ;
		}
		if (r == 0)
		{
			i++;
			continue ;
		}
		break ;
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

static int	is_allowed(int c)
{
	return (ft_strchr("01 NSEW", c) != NULL);
}

int	parse_player_and_normalize(t_data *d)
{
	int		y;
	int		x;
	int		found;
	char	*row;

	y = 0;
	found = 0;
	while (d->map && d->map[y])
	{
		x = 0;
		row = d->map[y];
		while (row[x])
		{
			if (!is_allowed(row[x]))
				return (0);
			if (ft_strchr("NSEW", row[x]))
			{
				if (found)
					return (0);
				d->start_y = y;
				d->start_x = x;
				d->start_dir = row[x];
				row[x] = '0';
				found = 1;
			}
			x++;
		}
		y++;
	}
	return (found == 1);
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
	if (!parse_player_and_normalize(d))
	{
		perror("player parse error");
		exit(EXIT_FAILURE);
	}
	i = 0;
	while (i < n)
	{
		free(file[i]);
		i++;
	}
	free(file);
}

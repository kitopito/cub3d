#ifndef CUB3D_H
# define CUB3D_H

#include "libft/libft.h"
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

typedef struct s_data
{
  char    **map;
  int     rows;
  int     columns;
  char	  *texture_paths[4];
	int		  floor_rgb[3];
	int		  ceiling_rgb[3];
	int		  start_x;
	int		  start_y;
	char	  start_dir;
}   t_data;

// init.c
void    init_data(t_data *data);

// parser.c
void	parse_map(t_data *data, char *filepath);
int		set_metadata(t_data *data, char **lines, int line_count, int *map_start);
void	set_map_from(t_data *data, char **lines, int start, int count);
char	**read_all_lines(char *path, int *out_n);

// main.c
void    print_parsed(t_data *data);

// utils.c
void    free_map(char **map);
char    *skip_ws(char *s);
char    *dup_after_key(char *line, int skip);
void    split_free(char **sp);
#endif

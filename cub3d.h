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

// prototypes
void    init_data(t_data *data);
void    parse_map(t_data *data, char *filepath);
void    free_map(char **map);

//⇩REF前
int		set_metadata(t_data *data, char **lines, int line_count, int *map_start);
void	set_map_from(t_data *data, char **lines, int start, int count);
int		parse_player_and_normalize(t_data *data);

//main.c
void    print_parsed(t_data *data);

#endif

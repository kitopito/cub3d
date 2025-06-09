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
}   t_data;

// prototypes
void    init_data(t_data *data);
void    parse_map(t_data *data, char *filepath);
void    free_map(char **map);

#endif

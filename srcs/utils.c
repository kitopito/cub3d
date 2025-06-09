#include "../cub3d.h"

void free_map(char **map)
{
  int i = 0;

  if (!map)
    return;
  while (map[i])
  {
    free(map[i]);
    i++;
  }
  free(map);
}

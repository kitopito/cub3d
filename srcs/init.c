#include "../cub3d.h"

void	init_config(t_config *cfg)
{
	int	i;

	ft_bzero(cfg, sizeof(*cfg));
	i = 0;
	while (i < TEX_MAX)
	{
		cfg->texture_path[i] = NULL;
		i++;
	}
}
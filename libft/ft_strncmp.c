
#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	int		diff;

	if (n == 0)
		return (0);
	i = 0;
	while ((s1[i] != '\0') && (s2[i] != '\0') && (i < (n - 1)))
	{
		diff = (unsigned char)s1[i] - (unsigned char)s2[i];
		if (diff > 0)
			return (1);
		if (diff < 0)
			return (-1);
		i++;
	}
	diff = (unsigned char)s1[i] - (unsigned char)s2[i];
	if (diff > 0)
		return (1);
	if (diff < 0)
		return (-1);
	return (0);
}

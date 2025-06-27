
#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	i;

	if (s == NULL)
		return ;
	i = 0;
	while (*s != '\0' && f != NULL)
		f(i++, s++);
}

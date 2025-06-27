
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	if ((unsigned char)c == '\0')
		return ((char *)(s + ft_strlen(s)));
	while (*s != '\0')
	{
		if (*s == (unsigned char)c)
			return ((char *)s);
		s++;
	}
	return (NULL);
}

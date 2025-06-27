
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ret;

	ret = NULL;
	if ((unsigned char)c == '\0')
		return ((char *)(s + ft_strlen(s)));
	while (*s != '\0')
	{
		if (*s == (unsigned char)c)
			ret = ((char *)s);
		s++;
	}
	return (ret);
}

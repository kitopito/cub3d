
#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	srclen;

	srclen = ft_strlen(src);
	if (size == 0)
		return (srclen);
	i = 0;
	while (*src != '\0' && i++ < (size - 1))
		*dst++ = *src++;
	*dst = '\0';
	return (srclen);
}

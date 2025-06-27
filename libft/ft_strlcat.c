
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	dstlen;
	size_t	srclen;

	srclen = ft_strlen(src);
	dstlen = ft_strlen(dst);
	if (size <= dstlen)
		return (size + srclen);
	while (*dst != '\0')
		dst++;
	i = 0;
	while (*src != '\0' && i++ < (size - dstlen - 1))
		*dst++ = *src++;
	*dst = '\0';
	return (dstlen + srclen);
}

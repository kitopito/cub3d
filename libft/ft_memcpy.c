#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (dest == NULL && src == NULL)
		return (NULL);
	i = 0;
	while (i++ < n)
		((unsigned char *)dest)[i - 1] = ((unsigned char *)src)[i - 1];
	return (dest);
}

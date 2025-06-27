
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	char	*cur;

	ptr = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	cur = ptr;
	while (s1 != NULL && *s1 != '\0')
		*cur++ = *s1++;
	while (s2 != NULL && *s2 != '\0')
		*cur++ = *s2++;
	*cur = '\0';
	return (ptr);
}

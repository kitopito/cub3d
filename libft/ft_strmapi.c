
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*ptr;
	size_t	len;
	size_t	i;

	if (s == NULL)
		return (NULL);
	len = ft_strlen(s);
	ptr = malloc((len + 1) * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		if (f != NULL)
			ptr[i] = f(i, s[i]);
		else
			ptr[i] = s[i];
		i++;
	}
	ptr[len] = '\0';
	return (ptr);
}

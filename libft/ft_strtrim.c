
#include "libft.h"

char	*ft_strtrim(char const *s, char const *set)
{
	size_t	start;
	size_t	end;

	if (s == NULL || set == NULL)
		return (NULL);
	start = 0;
	while (s[start] != '\0')
	{
		if (ft_strchr(set, s[start]) == NULL)
			break ;
		start++;
	}
	end = ft_strlen(s);
	while (end-- > 0)
		if (ft_strchr(set, s[end]) == NULL)
			break ;
	return (ft_substr(s, start, end - start + 1));
}

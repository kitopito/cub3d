#include "libft.h"

static int	count_digits(int n)
{
	if (n == 0)
		return (0);
	if (n < 0)
		return (count_digits(-n / 10) + 2);
	return (count_digits(n / 10) + 1);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*ret;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	len = count_digits(n);
	ret = malloc((len + 1) * sizeof(char));
	if (ret == NULL)
		return (NULL);
	if (n < 0)
	{
		ret[0] = '-';
		n *= -1;
	}
	ret[len--] = '\0';
	while (n != 0)
	{
		ret[len--] = n % 10 + '0';
		n /= 10;
	}
	return (ret);
}
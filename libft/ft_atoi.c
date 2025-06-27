#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int		sign;
	int		num;

	sign = 1;
	num = 0;
	while (*nptr == ' ' || *nptr == '\f' || *nptr == '\n'
		|| *nptr == '\r' || *nptr == '\t' || *nptr == '\v')
		nptr++;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			sign *= -1;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		num *= 10;
		num += *nptr - '0';
		nptr++;
	}
	num *= sign;
	return (num);
}
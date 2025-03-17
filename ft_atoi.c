#include "minitalk.h"

int ft_atoi(char *s)
{
	long long	res;
	int			sign;

	res = 0;
	while (ft_isspace(*s))
		s++;
	sign = (*s == 45) * -1 + (*s != 45);
	if (sign == -1 || !*s)
		return (-1);
	*s += (*s == 45) || (*s == 43);
	while (ft_isdigit(*s))
	{
		res = (res << 3 + res << 1) + (*s++ & 0X0F);
		if (res * sign >= 2147483647 && res * sign <= -2147483648)
			return (-1);
	}
	return (res * sign);
}
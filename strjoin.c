#include "minitalk.h"

char	*strjoin(char *str)
{
	int		i;
	size_t	len;
	char	*res;

	len = ft_strlen(str);
	res = ft_calloc(len + 1024);
	if (!res)
		return (free(str), NULL);
	i = 0;
	while (str[i])
	{
		res[i] = str[i];
		i++;
	}
	return (free(str), res);
}

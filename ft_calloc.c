#include "minitalk.h"

void	*ft_calloc(size_t n)
{
	char *ptr;

	ptr = malloc(n);
	if (!ptr)
		return (NULL);
	ft_memset(ptr, '\0', n);
	return ((void *) ptr);
}

#include "minitalk.h"

void	*ft_memset(void *str, int c, size_t l)
{
	void			*s;
	size_t			r;

	s = str;
	r = 0x0101010101010101 * (unsigned char) c;
	while (l && (l % 8 != 0))
	{
		*((char *) s++) = (unsigned char) c;
		l--;
	}
	while (l >= sizeof(size_t))
	{
		*((size_t *) s) = r;
		l -= sizeof(size_t);
		s += sizeof(size_t);
	}
	while (l)
	{
		*((char *) s++) = (unsigned char) c;
		l--;
	}
	return (str);
}

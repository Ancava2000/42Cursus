#include <stddef.h>

size_t	ft_strspn(const char *s, const char *accept)
{
	size_t j;
	size_t count = 0;

	while(*s)
	{
		j = 0;
		while(accept[j])
		{
			if (*s == accept[j])
				break;
			j++;
		}
		if (accept[j] == '\0')
			return (count);
		s++;
		count++;
	}
	return (count);
}

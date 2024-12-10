#include "libft.h"

size_t	ft_strlen(const char *str);
void	*ft_memcpy(void *dest, const void *src, size_t count);

char	*strdup(const char *s){
	char	*str;
	size_t	len;

	if (s == NULL)
	{
		errno = ENOMEM;
		return (NULL);
	}
	len = ft_strlen(s);
	str = malloc(len + 1);
	if (str == NULL)
		return (NULL);
	ft_memcpy(str, s, len+1);
	return (str);	
}
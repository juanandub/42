#include "libft.h"

void	*ft_memset(void *s, int c, size_t n);

void	*calloc(size_t nmemb, size_t size){
	int	*arr;
	
	arr = (int *)malloc(nmemb * size);
	if (nmemb == 0 || size == 0)
	{
		return (arr);
	}
	if (arr == NULL)
		return (NULL);
	ft_memset(arr, 0, nmemb * size);

	return (arr);
}
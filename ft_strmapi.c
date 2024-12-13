#include "libft.h"

char *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
    size_t len = ft_strlen(s);
    char *result = malloc(len + 1);
    if (!result)
        return NULL;
    result[len] = '\0';
    for (size_t i = 0; i < len; i++)
        result[i] = f(i, s[i]);
    return result;
}
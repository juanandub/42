#include "libft.h"

char *ft_itoa(int n)
{
    int len = 1;
    int aux = n;
    while (aux /= 10)
        len++;
    char *result = malloc(len + 1 + (n < 0));
    if (!result)
        return NULL;
    result[len + (n < 0)] = '\0';
    if (n < 0)
        result[0] = '-';
    aux = len + (n < 0);
    while (len--)
    {
        if (n<0)
          n = -n;
        result[aux] = n % 10 + '0';
        n /= 10;
        aux--;
    }
    return result;
}
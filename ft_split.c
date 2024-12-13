#include "libft.h"

static size_t count_tokens(const char *s, char c) {
    size_t count = 0;
    const char *aux = s;
    while (aux = ft_strchr(aux, c))
    {
      count++;
      aux++;
    }

    return count;
}

static void free_all(char **result) {
    size_t i = 0;
    while (result[i]) {
        free(result[i]);
        i++;
    }
    free(result);
}

char **ft_split(char const *s, char c)
{
    size_t tokens = count_tokens(s, c);
    char **result = malloc(sizeof(char *) * (tokens + 1));
    if (!result)
        return NULL;

    const char *aux = s;
    size_t i = 0;
    while (i < tokens)
    {
        const char *next = ft_strchr(aux, c);
        size_t len = next ? next - aux : ft_strlen(aux);
        result[i] = ft_substr(aux, 0, len);
        if (!result[i]) {
            free_all(result);
            return NULL;
        }
        aux = next + 1;
        i++;
    }
    result[i] = NULL;
    return result;
}

// char **ft_split(char const *s, char c){
  
//   int i = 0;
//   int j = 0;
//   size_t len = ft_strlen(s);
//   size_t len_c = ft_strlen(s);
//   char *res = 0;
//   char *aux = (char *)s;
//   while (aux)
//   {
//     i++;
//     aux = ft_strchr(aux, c);
//   }
//   j = i;
//   char **str = malloc(i + 1);
//   if (str == NULL)
//     return (NULL);
//   aux = (char *)s;
//   while (i>0)
//   {
//     str = ft_substr(s,len - len_c, len - ft_strlen(aux));
//     aux = ft_strchr(aux, c);
//   }
//   str = '\0';
//   str = str - (j + 1);
//   return (str);
// }
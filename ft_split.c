#include "libft.h"

char **ft_split(char const *s, char c){
  
  int i = 0;
  char *aux = (char *)s;
  while ( aux = ft_strchr(aux, c))
  {
    i++;
  }
  char **str = malloc(i + 1);
  if (str == NULL)
    return (NULL);
  

  
}
/*
** menu.c for wolf3D in /home/le-mai_s/projet/Igraph/Wolf3D/menu
**
** Made by sebastien le-maire
** Login   <le-mai_s@epitech.net>
**
** Started on  Sun May 17 13:12:16 2015 sebastien le-maire
** Last update Sat May 23 09:27:04 2015 sebastien le-maire
*/

#include <stdlib.h>
#include <mlx.h>
#include "graph.h"

/*
** Dessine le menu.
*/

void	menu(t_param *param)
{
  wolf3D(param);
  title(725, 100, param);
  buttom_play(785, 300, param);
  buttom_test(785, 500, param);
  buttom_quit(785, 700, param);
}

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    i++;
  return (i);
}

char	*my_strdup(char *src)
{
  int	i;
  char *dest;

  i = 0;
  if ((dest = malloc(my_strlen(src) + 1)) == NULL)
    return (NULL);
  while (src[i])
    {
      dest[i] = src[i];
      i += 1;
    }
  dest[i] = '\0';
  return (dest);
}

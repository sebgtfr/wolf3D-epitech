/*
** memset.c for memset in /home/le-mai_s/rendu/Projet_Igraph_repository/MUL_2014_fdf
** 
** Made by sebastien le-maire
** Login   <le-mai_s@epitech.net>
** 
** Started on  Thu Apr 30 12:59:58 2015 sebastien le-maire
** Last update Wed May  6 23:48:19 2015 sebastien le-maire
*/

/*
** my_memset permet d'attribuer une valeur "c"
** à "size" byte de la mémoire du "s".
*/

void	*my_memset(void *s, int c, int size)
{
  int	i;

  i = 0;
  while (i < size)
    {
      ((char *)s)[i] = c;
      i++;
    }
  return (s);
}

/*
** get_buffer.c for get_buffer in /home/le-mai_s/projet/Igraph/Wolf3D
** 
** Made by sebastien le-maire
** Login   <le-mai_s@epitech.net>
** 
** Started on  Wed May  6 13:08:14 2015 sebastien le-maire
** Last update Tue May 26 17:24:09 2015 sebastien le-maire
*/

#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "graph.h"

/*
** add_elem_list ajoute un element à la fin de la liste mis en paramètre.
*/

t_frag_read     *add_elem_list(t_frag_read *param, char *str, int size)
{
  t_frag_read   *elem;
  t_frag_read   *last;
  int           i;

  i = -1;
  if ((elem = malloc(sizeof(t_frag_read))) == NULL)
    return (NULL);
  if ((elem->frag_str = malloc(sizeof(char) * (size + 1))) == NULL)
    return (NULL);
  while (++i < size)
    elem->frag_str[i] = str[i];
  elem->frag_str[i] = '\0';
  elem->next = NULL;
  if (param == NULL)
    return (elem);
  else
    {
      last = param;
      while (last->next != NULL)
	last = last->next;
      last->next = elem;
      return (param);
    }
}

/*
** utilise la valeur de i initialiser dans get_buffer pour definir la taille
** du buffer puis on remplis tout le buffer avec les fragments de la liste.
*/

char		*realloc_buff(char *buffer, int *i, t_frag_read **frag)
{
  int		j;
  t_frag_read   *tmp;

  free(buffer);
  tmp = *frag;
  if ((buffer = malloc(sizeof(char *) * (*i) + 1)) == NULL)
    {
      write(2, "Error realloc\n,", 14);
      exit(2);
    }
  *i = 0;
  while (tmp)
    {
      j = 0;
      while (tmp->frag_str[j])
	{
	  buffer[*i] = tmp->frag_str[j];
	  *i += 1;
	  j += 1;
	}
      free(tmp->frag_str);
      tmp = tmp->next;
    }
  buffer[*i] = '\0';
  return (buffer);
}

/*
** get_buffer lit le fichier mit en paramètre et retourne le buffer complet.
*/

char            *get_buffer(const int fd)
{
  char		*buffer;
  int		i;
  t_frag_read   *frag;
  int           ret;

  i = 0;
  frag = NULL;
  buffer = malloc(sizeof(char) * SIZE_BUFF);
  while ((ret = read(fd, buffer, SIZE_BUFF)) > 0)
    {
      if ((frag = add_elem_list(frag, buffer, ret)) == NULL)
	{
	  write(2, "Error malloc\n", 13);
	  exit(1);
	}
      i += ret;
    }
  buffer = realloc_buff(buffer, &i, &frag);
  while (frag != NULL)
    {
      free(frag);
      frag = frag->next;
    }
  if (ret == -1 || !buffer[0])
    return (NULL);
  return (buffer);
}

/*
** error.c for wolf3D in /home/le-mai_s/rendu/Projet_Igraph_repository/MUL_2014_wolf3d/sources
**
** Made by sebastien le-maire
** Login   <le-mai_s@epitech.net>
**
** Started on  Sat May 23 10:05:57 2015 sebastien le-maire
** Last update Sun Jun 11 12:30:17 2017 Sébastien Le Maire
*/

#include <unistd.h>
#include <stdlib.h>
#include "graph.h"

void	error(short choice)
{
  if (choice == 1)
    {
      write(2, "Usage: ./wolf3D file pseudo\n", 28);
      exit(1);
    }
  if (choice == 2)
    {
      write(2, "Error: minilibX failed\n", 23);
      exit(2);
    }
}

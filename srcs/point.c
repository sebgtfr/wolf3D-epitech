/*
** point.c for point in /home/le-mai_s/projet/Graph_test/lib/graph
** 
** Made by sebastien le-maire
** Login   <le-mai_s@epitech.net>
** 
** Started on  Mon Apr  6 11:15:11 2015 sebastien le-maire
** Last update Sun May 17 19:02:51 2015 sebastien le-maire
*/

#include "graph.h"

/*
** Remplis le point x et y de la structure coordonnée.
*/

void	point(t_coordonnee *point, float x, float y)
{
  point->x = x;
  point->y = y;
}

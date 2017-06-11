/*
** color.c for def_color in /home/le-mai_s/projet/Graph_test/Cube_projection_parallelisme
** 
** Made by sebastien le-maire
** Login   <le-mai_s@epitech.net>
** 
** Started on  Mon Apr  6 10:32:51 2015 sebastien le-maire
** Last update Fri May 22 16:05:11 2015 sebastien le-maire
*/

#include "graph.h"

/*
** remplis les champs r, g et b de la structure t_color.
*/

void   		color(t_color *color, int red, int green, int blue)
{
  color->red = red;
  color->green = green;
  color->blue = blue;
}

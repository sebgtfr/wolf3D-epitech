/*
** my_getcolor.c for my_getcolor in /home/le-mai_s/projet/Igraph/FDF
** 
** Made by sebastien le-maire
** Login   <le-mai_s@epitech.net>
** 
** Started on  Sun Apr  5 12:34:08 2015 sebastien le-maire
** Last update Fri May 22 16:04:38 2015 sebastien le-maire
*/

#include "graph.h"

/*
** remplit les octets correspondant au rouge avec r, Vert avec g et bleu avec b
*/

int	my_getcolor(t_color *color_in)
{
  int	color_out;

  if ((color_in->red >= 0 && color_in->red <= 255) ||
      (color_in->green >= 0 && color_in->green <= 255) ||
      (color_in->blue >= 0 && color_in->blue <= 255))
    {
      color_out = (color_in->red << 16) | (color_in->green << 8) |
	(color_in->blue);
      return (color_out);
    }
  return (0);
}

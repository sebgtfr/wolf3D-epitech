/*
** title.c for wolf3D in /home/le-mai_s/projet/Igraph/Wolf3D/menu
** 
** Made by sebastien le-maire
** Login   <le-mai_s@epitech.net>
** 
** Started on  Sun May 17 16:55:38 2015 sebastien le-maire
** Last update Fri May 22 16:03:28 2015 sebastien le-maire
*/

#include <mlx.h>
#include "graph.h"

void	title(int x, int y, t_param *param)
{
  color(&(param->rgb), 255, 255, 255);
  W(x, y, param);
  O((x + 100), y, param);
  L((x + 170), y, param);
  F((x + 240), y, param);
  Trois((x + 330), y, param);
  D((x + 400), y, param);
}

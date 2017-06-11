/*
** buttom2.c for wolf3d in /home/le-mai_s/rendu/Projet_Igraph_repository/MUL_2014_wolf3d/sources
** 
** Made by sebastien le-maire
** Login   <le-mai_s@epitech.net>
** 
** Started on  Sat May 23 09:24:05 2015 sebastien le-maire
** Last update Sat May 23 09:44:08 2015 sebastien le-maire
*/

#include <mlx.h>
#include "graph.h"

void	buttom_test(int x, int y, t_param *param)
{
  color(&(param->rgb), 150, 150, 150);
  buttom_background(x, y, param);
  x += 40;
  y += 40;
  color(&(param->rgb), 255, 0, 0);
  T(x, y, param);
  E((x + 70), y, param);
  S((x + 140), y, param);
  T((x + 210), y, param);
}

void	buttom_test_hover(int x, int y, t_param *param)
{
  color(&(param->rgb), 250, 250, 0);
  buttom_background(x, y, param);
  x += 40;
  y += 40;
  color(&(param->rgb), 0, 0, 0);
  T(x, y, param);
  E((x + 70), y, param);
  S((x + 140), y, param);
  T((x + 210), y, param);
}

/*
** draw.c for wolf3D in /home/le-mai_s/projet/Igraph/Wolf3D/sources
**
** Made by sebastien le-maire
** Login   <le-mai_s@epitech.net>
**
** Started on  Tue May 12 10:15:35 2015 sebastien le-maire
** Last update Sat May 23 13:59:45 2015 sebastien le-maire
*/

#include "graph.h"

/*
** Trace une ligne verticale entre ya et yb à la colonne x.
*/

void	draw_vertical_line(t_param *param, int ya, int yb, int x)
{
  while (ya <= yb)
    {
      my_pixel_put_to_image(&(param->img), &(param->rgb), x, ya);
      ya++;
    }
}

/*
** Déssine à la colonne x, le ciel, le mur et la terre.
*/

void	draw_wolf(t_param *param, int x)
{
  int	height_wall;
  int	start_wall;
  int	end_wall;
  int	y;

  height_wall = ((WIN_Y / (2 * param->wolf.k)));
  start_wall = (WIN_Y / 2) - height_wall;
  end_wall = (WIN_Y / 2) + height_wall;
  draw_vertical_line(param, start_wall, end_wall, x);
  y = 0;
  color(&(param->rgb), 3, 169, 244);
  draw_vertical_line(param, y, (start_wall - 1), x);
  color(&(param->rgb), 141, 110, 99);
  y = end_wall + 1;
  draw_vertical_line(param, y, (WIN_Y - 1), x);
}

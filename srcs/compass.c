/*
** compass.c for wolf3D in /home/le-mai_s/rendu/Projet_Igraph_repository/MUL_2014_wolf3d/sources
** 
** Made by sebastien le-maire
** Login   <le-mai_s@epitech.net>
** 
** Started on  Mon May 25 15:32:23 2015 sebastien le-maire
** Last update Mon May 25 18:02:06 2015 sebastien le-maire
*/

#include <math.h>
#include <mlx.h>
#include "graph.h"

/*
** Dessine une boussole.
*/

void		compass(t_param *param)
{
  int		x;
  int		y;
  t_color	frame;

  color(&frame, 0, 0, 0);
  x = 1769;
  while (x < 1920)
    {
      y = 0;
      while (y < 149)
	{
	  my_pixel_put_to_image(&(param->img), &frame, x, y);
	  y++;
	}
      x++;
    }
  arrow_compass(param);
  cardinal_points(param);
}

/*
** Dessine est gère le mouvement de la fleche.
*/

void		arrow_compass(t_param *param)
{
  t_coordonnee	o;
  t_coordonnee	p;
  t_coordonnee	l;
  t_coordonnee	r;
  t_color	arrow;
  float		angle;

  angle = RAD(param->wolf.player.a);
  o.x = 1843;
  o.y = 74;
  l.x = o.x - 5;
  l.y = o.y - 5;
  r.x = o.x + 5;
  r.y = o.y + 5;
  p.x = o.x + 25 * cosf(angle);
  p.y = o.y + 25 * sinf(angle);
  color(&arrow, 255, 255, 255);
  mlx_line_to_image(&(param->img), l, r, &arrow);
  mlx_line_to_image(&(param->img), o, p, &arrow);
  l.x = o.x - 5;
  l.y = o.y + 5;
  r.x = o.x + 5;
  r.y = o.y - 5;
  mlx_line_to_image(&(param->img), l, r, &arrow);
}

/*
** Ecrite les moints cardinaux.
*/

void	cardinal_points(t_param *param)
{
  mlx_string_put(param->img.window.mlx_ptr, param->img.window.win_ptr,
		 1830, 39, 0xFFFFFF, "North");
  mlx_string_put(param->img.window.mlx_ptr, param->img.window.win_ptr,
		 1830, 119, 0xFFFFFF, "South");
  mlx_string_put(param->img.window.mlx_ptr, param->img.window.win_ptr,
		 1790, 79, 0xFFFFFF, "West");
  mlx_string_put(param->img.window.mlx_ptr, param->img.window.win_ptr,
		 1880, 79, 0xFFFFFF, "East");
}

/*
** mlx_line_to_image.c for mlx_line_to_image in /home/le-mai_s/projet/Graph_test/lib/graph
** 
** Made by sebastien le-maire
** Login   <le-mai_s@epitech.net>
** 
** Started on  Tue Apr 28 12:14:40 2015 sebastien le-maire
** Last update Fri May 22 16:00:48 2015 sebastien le-maire
*/

#include <mlx.h>
#include "graph.h"

/*
** Dessine n'importe quel droite.
*/

void	diagonale_left_to_image(t_param_img *img, t_coordonnee *pointA,
				t_coordonnee *pointB, t_color *rgb)
{
  float	a;
  float	error;

  a = (pointB->y - pointA->y) / (pointB->x - pointA->x);
  error = 0;
  while (pointA->x >= pointB->x)
    {
      my_pixelA_put_to_image(img, rgb, (int)pointA->x, (int)pointA->y);
      error -= a;
      if (a < 0 && error > 0.5)
	{
	  error -= 1;
	  pointA->y += 1;
	}
      if (a > 0 && error < -0.5)
	{
	  error += 1;
	  pointA->y -= 1;
	}
      pointA->x -= 1;
    }
}

void	diagonale_right_to_image(t_param_img *img, t_coordonnee *pointA,
				 t_coordonnee *pointB, t_color *rgb)
{
  float	a;
  float	error;

  a = (pointB->y - pointA->y) / (pointB->x - pointA->x);
  error = 0;
  while (pointA->x <= pointB->x)
    {
      my_pixelA_put_to_image(img, rgb, (int)pointA->x, (int)pointA->y);
      error += a;
      if (a > 0 && error > 0.5)
	{
	  pointA->y += 1;
	  error -= 1;
	}
      if (a < 0 && error < -0.5)
	{
	  pointA->y -= 1;
	  error += 1;
	}
      pointA->x += 1;
    }
}

void	diagonale_Yplus_to_image(t_param_img *img, t_coordonnee *pointA,
				 t_coordonnee *pointB, t_color *rgb)
{
  float	a;
  float	error;

  a = (pointB->x - pointA->x) / (pointB->y - pointA->y);
  error = 0;
  while (pointA->y <= pointB->y)
    {
      my_pixelA_put_to_image(img, rgb, (int)pointA->x, (int)pointA->y);
      error += a;
      if (a > 0 && error > 0.5)
	{
	  pointA->x += 1;
	  error -= 1;
	}
      if (a < 0 && error < -0.5)
	{
	  pointA->x -= 1;
	  error += 1;
	}
      pointA->y += 1;
    }
}

void	diagonale_Ymoins_to_image(t_param_img *img, t_coordonnee *pointA,
				  t_coordonnee *pointB, t_color *rgb)
{
  float	a;
  float	error;

  a = (pointB->x - pointA->x) / (pointB->y - pointA->y);
  error = 0;
  while (pointA->y >= pointB->y)
    {
      my_pixelA_put_to_image(img, rgb, (int)pointA->x, (int)pointA->y);
      error += a;
      if (a > 0 && error > 0.5)
	{
	  pointA->x -= 1;
	  error -= 1;
	}
      if (a < 0 && error < -0.5)
	{
	  pointA->x += 1;
	  error += 1;
	}
      pointA->y -= 1;
    }
}

void	mlx_line_to_image(t_param_img *img, t_coordonnee pointA,
			  t_coordonnee pointB, t_color *rgb)
{
  float	a;
  
  if (pointB.x != pointA.x)
    a = (pointB.y - pointA.y) / (pointB.x - pointA.x);
  else
    a = 0;
  if (a <= 1 && a >= -1)
    {
      if (pointB.x > pointA.x)
	diagonale_right_to_image(img, &pointA, &pointB, rgb);
      else if (pointB.x < pointA.x)
	diagonale_left_to_image(img, &pointA, &pointB, rgb);
    }
  if ((a > 1 || a < -1) || (pointA.x == pointB.x && a == 0))
    {
      if (pointB.y > pointA.y)
	diagonale_Yplus_to_image(img, &pointA, &pointB, rgb);
      else if (pointB.y < pointA.y)
	diagonale_Ymoins_to_image(img, &pointA, &pointB, rgb);
    }
}

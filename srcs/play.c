/*
** play.c for wolf3D in /home/le-mai_s/projet/Igraph/Wolf3D/menu
** 
** Made by sebastien le-maire
** Login   <le-mai_s@epitech.net>
** 
** Started on  Sun May 17 13:13:37 2015 sebastien le-maire
** Last update Fri May 22 16:02:39 2015 sebastien le-maire
*/

#include <mlx.h>
#include "graph.h"

/*
** Dessine un carré 20x20 pixel.
*/

void	square(int x, int y, t_param *param)
{
  t_coordonnee	ptA;
  t_coordonnee	ptB;

  point(&ptA, x, y);
  point(&ptB, x, (y + 20));
  mlx_line_to_image(&(param->img), ptA, ptB, &(param->rgb));
  point(&ptB, (x + 20), y);
  mlx_line_to_image(&(param->img), ptA, ptB, &(param->rgb));
  point(&ptA, (x + 20), (y + 20));
  mlx_line_to_image(&(param->img), ptB, ptA, &(param->rgb));
  point(&ptB, x, (y + 20));
  mlx_line_to_image(&(param->img), ptA, ptB, &(param->rgb));
}

/*
** Dessine la lettre P.
*/

void	P(int x, int y, t_param *param)
{
  t_coordonnee	ptA;
  t_coordonnee	ptB;

  point(&ptA, x, y);
  point(&ptB, x, (y + 100));
  mlx_line_to_image(&(param->img), ptA, ptB, &(param->rgb));
  point(&ptB, (x + 40), y);
  mlx_line_to_image(&(param->img), ptA, ptB, &(param->rgb));
  point(&ptA, (x + 60), (y + 20));
  mlx_line_to_image(&(param->img), ptB, ptA, &(param->rgb));
  point(&ptB, (x + 60), (y + 40));
  mlx_line_to_image(&(param->img), ptA, ptB, &(param->rgb));
  point(&ptA, (x + 40), (y + 60));
  mlx_line_to_image(&(param->img), ptB, ptA, &(param->rgb));
  point(&ptB, (x + 20), (y + 60));
  mlx_line_to_image(&(param->img), ptA, ptB, &(param->rgb));
  point(&ptA, (x + 20), (y + 100));
  mlx_line_to_image(&(param->img), ptB, ptA, &(param->rgb));
  point(&ptB, x, (y + 100));
  mlx_line_to_image(&(param->img), ptA, ptB, &(param->rgb));
  square((x + 20), (y + 20), param);
  point(&ptA, (x + 1), (y + 1));
  filling(&(param->img), &(param->rgb), ptA, 0);
}

/*
** Dessine la lettre L.
*/

void	L(int x, int y, t_param *param)
{
  t_coordonnee	ptA;
  t_coordonnee	ptB;

  point(&ptA, x, y);
  point(&ptB, x, (y + 100));
  mlx_line_to_image(&(param->img), ptA, ptB, &(param->rgb));
  point(&ptB, (x + 20), y);
  mlx_line_to_image(&(param->img), ptA, ptB, &(param->rgb));
  point(&ptA, (x + 20), (y + 80));
  mlx_line_to_image(&(param->img), ptB, ptA, &(param->rgb));
  point(&ptB, (x + 60), (y + 80));
  mlx_line_to_image(&(param->img), ptA, ptB, &(param->rgb));
  point(&ptA, (x + 60), (y + 100));
  mlx_line_to_image(&(param->img), ptB, ptA, &(param->rgb));
  point(&ptB, x, (y + 100));
  mlx_line_to_image(&(param->img), ptA, ptB, &(param->rgb));
  point(&ptA, (x + 1), (y + 1));
  filling(&(param->img), &(param->rgb), ptA, 0);
}

/*
** Dessine la lettre A.
*/

void	A(int x, int y, t_param *param)
{
  t_coordonnee	ptA;
  t_coordonnee	ptB;

  point(&ptA, x, y);
  point(&ptB, x, (y + 100));
  mlx_line_to_image(&(param->img), ptA, ptB, &(param->rgb));
  point(&ptB, (x + 60), y);
  mlx_line_to_image(&(param->img), ptA, ptB, &(param->rgb));
  point(&ptA, (x + 60), (y + 100));
  mlx_line_to_image(&(param->img), ptA, ptB, &(param->rgb));
  point(&ptB, (x + 40), (y + 100));
  mlx_line_to_image(&(param->img), ptA, ptB, &(param->rgb));
  point(&ptA, (x + 40), (y + 60));
  mlx_line_to_image(&(param->img), ptA, ptB, &(param->rgb));
  point(&ptB, (x + 20), (y + 60));
  mlx_line_to_image(&(param->img), ptA, ptB, &(param->rgb));
  point(&ptA, (x + 20), (y + 100));
  mlx_line_to_image(&(param->img), ptA, ptB, &(param->rgb));
  point(&ptB, x, (y + 100));
  mlx_line_to_image(&(param->img), ptA, ptB, &(param->rgb));
  square((x + 20), (y + 20), param);
  point(&ptA, (x + 1), (y + 1));
  filling(&(param->img), &(param->rgb), ptA, 0);
}

/*
** Dessine la lettre Y.
*/

void	Y(int x, int y, t_param *param)
{
  t_coordonnee	ptA;
  t_coordonnee	ptB;

  point(&ptA, x, y);
  point(&ptB, (x + 20), y);
  mlx_line_to_image(&(param->img), ptA, ptB, &(param->rgb));
  point(&ptB, (x + 20), (y + 60));
  mlx_line_to_image(&(param->img), ptA, ptB, &(param->rgb));
  point(&ptA, (x + 20), (y + 100));
  mlx_line_to_image(&(param->img), ptA, ptB, &(param->rgb));
  point(&ptB, (x + 40), (y + 100));
  mlx_line_to_image(&(param->img), ptA, ptB, &(param->rgb));
  point(&ptA, (x + 40), (y + 60));
  mlx_line_to_image(&(param->img), ptA, ptB, &(param->rgb));
  point(&ptB, (x + 60), y);
  mlx_line_to_image(&(param->img), ptA, ptB, &(param->rgb));
  point(&ptA, (x + 40), y);
  mlx_line_to_image(&(param->img), ptA, ptB, &(param->rgb));
  point(&ptB, (x + 30), (y + 40));
  mlx_line_to_image(&(param->img), ptA, ptB, &(param->rgb));
  point(&ptA, (x + 20), y);
  mlx_line_to_image(&(param->img), ptA, ptB, &(param->rgb));
  point(&ptA, (x + 1), (y + 1));
  filling(&(param->img), &(param->rgb), ptA, 0);
}

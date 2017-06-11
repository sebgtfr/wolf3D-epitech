/*
** TroisD.c for wolf in /home/le-mai_s/projet/Igraph/Wolf3D/menu
**
** Made by sebastien le-maire
** Login   <le-mai_s@epitech.net>
**
** Started on  Sun May 17 17:35:03 2015 sebastien le-maire
** Last update Sat May 23 09:30:46 2015 sebastien le-maire
*/

#include <mlx.h>
#include "graph.h"

/*
** Dessine le nombre 3.
*/

void	Trois2(int x, int y, t_param *param)
{
  t_coordonnee	ptA;
  t_coordonnee	ptB;

  point(&ptA, (x + 30), (y + 60));
  point(&ptB, (x + 40), (y + 67));
  mlx_line_to_image(&(param->img), ptA, ptB, &(param->rgb));
  point(&ptB, (x + 20), (y + 60));
  mlx_line_to_image(&(param->img), ptA, ptB, &(param->rgb));
  point(&ptA, (x + 20), (y + 40));
  mlx_line_to_image(&(param->img), ptA, ptB, &(param->rgb));
  point(&ptB, (x + 30), (y + 40));
  mlx_line_to_image(&(param->img), ptA, ptB, &(param->rgb));
  point(&ptA, (x + 40), (y + 33));
  mlx_line_to_image(&(param->img), ptA, ptB, &(param->rgb));
  point(&ptB, (x + 40), (y + 27));
  mlx_line_to_image(&(param->img), ptA, ptB, &(param->rgb));
  point(&ptA, (x + 30), (y + 20));
  mlx_line_to_image(&(param->img), ptA, ptB, &(param->rgb));
  point(&ptB, x, (y + 20));
  mlx_line_to_image(&(param->img), ptA, ptB, &(param->rgb));
  point(&ptA, (x + 1), (y + 1));
  filling(&(param->img), &(param->rgb), ptA, 0);
}

void	Trois(int x, int y, t_param *param)
{
  t_coordonnee	ptA;
  t_coordonnee	ptB;

  point(&ptA, x, y);
  point(&ptB, x, (y + 20));
  mlx_line_to_image(&(param->img), ptA, ptB, &(param->rgb));
  point(&ptB, (x + 40), y);
  mlx_line_to_image(&(param->img), ptA, ptB, &(param->rgb));
  point(&ptA, (x + 60), (y + 20));
  mlx_line_to_image(&(param->img), ptA, ptB, &(param->rgb));
  point(&ptB, (x + 60), (y + 80));
  mlx_line_to_image(&(param->img), ptA, ptB, &(param->rgb));
  point(&ptA, (x + 40), (y + 100));
  mlx_line_to_image(&(param->img), ptA, ptB, &(param->rgb));
  point(&ptB, x, (y + 100));
  mlx_line_to_image(&(param->img), ptA, ptB, &(param->rgb));
  point(&ptA, x, (y + 80));
  mlx_line_to_image(&(param->img), ptA, ptB, &(param->rgb));
  point(&ptB, (x + 30), (y + 80));
  mlx_line_to_image(&(param->img), ptA, ptB, &(param->rgb));
  point(&ptA, (x + 40), (y + 73));
  mlx_line_to_image(&(param->img), ptA, ptB, &(param->rgb));
  point(&ptB, (x + 40), (y + 67));
  mlx_line_to_image(&(param->img), ptA, ptB, &(param->rgb));
  Trois2(x, y, param);
}

/*
** Dessine la lettre D.
*/

void	D(int x, int y, t_param *param)
{
  t_coordonnee	ptA;
  t_coordonnee	ptB;

  point(&ptA, x, y);
  point(&ptB, x, (y + 100));
  mlx_line_to_image(&(param->img), ptA, ptB, &(param->rgb));
  point(&ptB, (x + 40), y);
  mlx_line_to_image(&(param->img), ptA, ptB, &(param->rgb));
  point(&ptA, (x + 60), (y + 20));
  mlx_line_to_image(&(param->img), ptA, ptB, &(param->rgb));
  point(&ptB, (x + 60), (y + 80));
  mlx_line_to_image(&(param->img), ptA, ptB, &(param->rgb));
  point(&ptA, (x + 40), (y + 100));
  mlx_line_to_image(&(param->img), ptA, ptB, &(param->rgb));
  point(&ptB, x, (y + 100));
  mlx_line_to_image(&(param->img), ptA, ptB, &(param->rgb));
  rectangle((x + 20), (y + 20), param);
  point(&ptA, (x + 1), (y + 1));
  filling(&(param->img), &(param->rgb), ptA, 0);
}

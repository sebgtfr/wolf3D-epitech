/*
** quit.c for wolf3D in /home/le-mai_s/projet/Igraph/Wolf3D/menu
** 
** Made by sebastien le-maire
** Login   <le-mai_s@epitech.net>
** 
** Started on  Sun May 17 16:00:55 2015 sebastien le-maire
** Last update Fri May 22 16:03:26 2015 sebastien le-maire
*/

#include <mlx.h>
#include "graph.h"

/*
** Dessine un rectangle 20x60 pixel.
*/

void	rectangle(int x, int y, t_param *param)
{
  t_coordonnee	ptA;
  t_coordonnee	ptB;

  point(&ptA, x, y);
  point(&ptB, x, (y + 60));
  mlx_line_to_image(&(param->img), ptA, ptB, &(param->rgb));
  point(&ptB, (x + 20), y);
  mlx_line_to_image(&(param->img), ptA, ptB, &(param->rgb));
  point(&ptA, (x + 20), (y + 60));
  mlx_line_to_image(&(param->img), ptB, ptA, &(param->rgb));
  point(&ptB, x, (y + 60));
  mlx_line_to_image(&(param->img), ptA, ptB, &(param->rgb));
}

/*
** Dessine la lettre Q.
*/

void	Q(int x, int y, t_param *param)
{
  t_coordonnee	ptA;
  t_coordonnee	ptB;

  point(&ptA, x, y);
  point(&ptB, x, (y + 100));
  mlx_line_to_image(&(param->img), ptA, ptB, &(param->rgb));
  point(&ptB, (x + 60), y);
  mlx_line_to_image(&(param->img), ptA, ptB, &(param->rgb));
  point(&ptA, (x + 60), (y + 90));
  mlx_line_to_image(&(param->img), ptA, ptB, &(param->rgb));
  point(&ptB, (x + 70), (y + 110));
  mlx_line_to_image(&(param->img), ptA, ptB, &(param->rgb));
  point(&ptA, (x + 60), (y + 120));
  mlx_line_to_image(&(param->img), ptA, ptB, &(param->rgb));
  point(&ptB, (x + 50), (y + 100));
  mlx_line_to_image(&(param->img), ptA, ptB, &(param->rgb));
  point(&ptA, x, (y + 100));
  mlx_line_to_image(&(param->img), ptA, ptB, &(param->rgb));
  rectangle((x + 20), (y + 20), param);
  point(&ptA, (x + 1), (y + 1));
  filling(&(param->img), &(param->rgb), ptA, 0);
}

/*
** Dessine la lettre U.
*/

void	U(int x, int y, t_param *param)
{
  t_coordonnee	ptA;
  t_coordonnee	ptB;

  point(&ptA, x, y);
  point(&ptB, x, (y + 100));
  mlx_line_to_image(&(param->img), ptA, ptB, &(param->rgb));
  point(&ptB, (x + 20), y);
  mlx_line_to_image(&(param->img), ptA, ptB, &(param->rgb));
  point(&ptA, (x + 20), (y + 80));
  mlx_line_to_image(&(param->img), ptA, ptB, &(param->rgb));
  point(&ptB, (x + 40), (y + 80));
  mlx_line_to_image(&(param->img), ptA, ptB, &(param->rgb));
  point(&ptA, (x + 40), y);
  mlx_line_to_image(&(param->img), ptA, ptB, &(param->rgb));
  point(&ptB, (x + 60), y);
  mlx_line_to_image(&(param->img), ptA, ptB, &(param->rgb));
  point(&ptA, (x + 60), (y + 100));
  mlx_line_to_image(&(param->img), ptA, ptB, &(param->rgb));
  point(&ptB, x, (y + 100));
  mlx_line_to_image(&(param->img), ptA, ptB, &(param->rgb));
  point(&ptA, (x + 1), (y + 1));
  filling(&(param->img), &(param->rgb), ptA, 0);
}

/*
** Dessine la lettre I.
*/

void	I(int x, int y, t_param *param)
{
  t_coordonnee	ptA;
  t_coordonnee	ptB;

  point(&ptA, x, y);
  point(&ptB, x, (y + 100));
  mlx_line_to_image(&(param->img), ptA, ptB, &(param->rgb));
  point(&ptB, (x + 20), y);
  mlx_line_to_image(&(param->img), ptA, ptB, &(param->rgb));
  point(&ptA, (x + 20), (y + 100));
  mlx_line_to_image(&(param->img), ptB, ptA, &(param->rgb));
  point(&ptB, x, (y + 100));
  mlx_line_to_image(&(param->img), ptA, ptB, &(param->rgb));
  point(&ptA, (x + 1), (y + 1));
  filling(&(param->img), &(param->rgb), ptA, 0);
}

/*
** Dessine la lettre T.
*/

void	T(int x, int y, t_param *param)
{
  t_coordonnee	ptA;
  t_coordonnee	ptB;

  point(&ptA, x, y);
  point(&ptB, x, (y + 20));
  mlx_line_to_image(&(param->img), ptA, ptB, &(param->rgb));
  point(&ptB, (x + 60), y);
  mlx_line_to_image(&(param->img), ptA, ptB, &(param->rgb));
  point(&ptA, (x + 60), (y + 20));
  mlx_line_to_image(&(param->img), ptA, ptB, &(param->rgb));
  point(&ptB, (x + 40), (y + 20));
  mlx_line_to_image(&(param->img), ptA, ptB, &(param->rgb));
  point(&ptA, (x + 40), (y + 100));
  mlx_line_to_image(&(param->img), ptA, ptB, &(param->rgb));
  point(&ptB, (x + 20), (y + 100));
  mlx_line_to_image(&(param->img), ptA, ptB, &(param->rgb));
  point(&ptA, (x + 20), (y + 20));
  mlx_line_to_image(&(param->img), ptA, ptB, &(param->rgb));
  point(&ptB, x, (y + 20));
  mlx_line_to_image(&(param->img), ptA, ptB, &(param->rgb));
  point(&ptA, (x + 1), (y + 1));
  filling(&(param->img), &(param->rgb), ptA, 0);
}

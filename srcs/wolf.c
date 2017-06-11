/*
** wolf.c for wolf3d in /home/le-mai_s/projet/Igraph/Wolf3D/menu
** 
** Made by sebastien le-maire
** Login   <le-mai_s@epitech.net>
** 
** Started on  Sun May 17 16:43:27 2015 sebastien le-maire
** Last update Fri May 22 16:02:42 2015 sebastien le-maire
*/

#include <mlx.h>
#include "graph.h"

void	W2(int x, int y, t_param *param)
{
  t_coordonnee	ptA;
  t_coordonnee	ptB;

  point(&ptA, (x + 70), (y + 100));
  point(&ptB, (x + 90), y);
  mlx_line_to_image(&(param->img), ptA, ptB, &(param->rgb));
  point(&ptB, (x + 50), (y + 100));
  mlx_line_to_image(&(param->img), ptA, ptB, &(param->rgb));
  point(&ptA, (x + 45), (y + 60));
  mlx_line_to_image(&(param->img), ptA, ptB, &(param->rgb));
  point(&ptB, (x + 40), (y + 100));
  mlx_line_to_image(&(param->img), ptA, ptB, &(param->rgb));
  point(&ptA, (x + 20), (y + 100));
  mlx_line_to_image(&(param->img), ptA, ptB, &(param->rgb));
  point(&ptA, (x + 1), (y + 1));
  filling(&(param->img), &(param->rgb), ptA, 0);
}

void	W(int x, int y, t_param *param)
{
  t_coordonnee	ptA;
  t_coordonnee	ptB;

  point(&ptA, x, y);
  point(&ptB, (x + 20), (y + 100));
  mlx_line_to_image(&(param->img), ptA, ptB, &(param->rgb));
  point(&ptB, (x + 20), y);
  mlx_line_to_image(&(param->img), ptA, ptB, &(param->rgb));
  point(&ptA, (x + 30), (y + 60));
  mlx_line_to_image(&(param->img), ptA, ptB, &(param->rgb));
  point(&ptB, (x + 40), (y + 20));
  mlx_line_to_image(&(param->img), ptA, ptB, &(param->rgb));
  point(&ptA, (x + 50), (y + 20));
  mlx_line_to_image(&(param->img), ptA, ptB, &(param->rgb));
  point(&ptB, (x + 60), (y + 60));
  mlx_line_to_image(&(param->img), ptA, ptB, &(param->rgb));
  point(&ptA, (x + 70), y);
  mlx_line_to_image(&(param->img), ptA, ptB, &(param->rgb));
  point(&ptB, (x + 90), y);
  mlx_line_to_image(&(param->img), ptA, ptB, &(param->rgb));
  W2(x, y, param);
}

void	O(int x, int y, t_param *param)
{
  t_coordonnee	ptA;
  t_coordonnee	ptB;

  point(&ptA, x, y);
  point(&ptB, x, (y + 100));
  mlx_line_to_image(&(param->img), ptA, ptB, &(param->rgb));
  point(&ptB, (x + 60), y);
  mlx_line_to_image(&(param->img), ptA, ptB, &(param->rgb));
  point(&ptA, (x + 60), (y + 100));
  mlx_line_to_image(&(param->img), ptB, ptA, &(param->rgb));
  point(&ptB, x, (y + 100));
  mlx_line_to_image(&(param->img), ptA, ptB, &(param->rgb));
  rectangle((x + 20), (y + 20), param);
  point(&ptA, (x + 1), (y + 1));
  filling(&(param->img), &(param->rgb), ptA, 0);
}

void	F2(int x, int y, t_param *param)
{
  t_coordonnee	ptA;
  t_coordonnee	ptB;

  point(&ptA, (x + 40), (y + 60));
  point(&ptB, (x + 40), (y + 40));
  mlx_line_to_image(&(param->img), ptA, ptB, &(param->rgb));
  point(&ptB, (x + 20), (y + 60));
  mlx_line_to_image(&(param->img), ptA, ptB, &(param->rgb));
  point(&ptA, (x + 20), (y + 100));
  mlx_line_to_image(&(param->img), ptA, ptB, &(param->rgb));
  point(&ptB, x, (y + 100));
  mlx_line_to_image(&(param->img), ptA, ptB, &(param->rgb));
  point(&ptA, (x + 1), (y + 1));
  filling(&(param->img), &(param->rgb), ptA, 0);
}

void	F(int x, int y, t_param *param)
{
  t_coordonnee	ptA;
  t_coordonnee	ptB;

  point(&ptA, x, y);
  point(&ptB, x, (y + 100));
  mlx_line_to_image(&(param->img), ptA, ptB, &(param->rgb));
  point(&ptB, (x + 60), y);
  mlx_line_to_image(&(param->img), ptA, ptB, &(param->rgb));
  point(&ptA, (x + 60), (y + 20));
  mlx_line_to_image(&(param->img), ptA, ptB, &(param->rgb));
  point(&ptB, (x + 20), (y + 20));
  mlx_line_to_image(&(param->img), ptA, ptB, &(param->rgb));
  point(&ptA, (x + 20), (y + 40));
  mlx_line_to_image(&(param->img), ptA, ptB, &(param->rgb));
  point(&ptB, (x + 40), (y + 40));
  mlx_line_to_image(&(param->img), ptA, ptB, &(param->rgb));
  F2(x, y, param);
}

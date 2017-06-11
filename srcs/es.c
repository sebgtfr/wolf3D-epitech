/*
** es.c for wolf3d in /home/le-mai_s/rendu/Projet_Igraph_repository/MUL_2014_wolf3d/sources
** 
** Made by sebastien le-maire
** Login   <le-mai_s@epitech.net>
** 
** Started on  Sat May 23 09:30:54 2015 sebastien le-maire
** Last update Sat May 23 09:41:20 2015 sebastien le-maire
*/

#include <mlx.h>
#include "graph.h"

/*
** Déssine la lettre S
*/

void	S(int x, int y, t_param *param)
{
  t_coordonnee	ptA;
  t_coordonnee	ptB;

  point(&ptA, x, y);
  point(&ptB, x, (y + 60));
  mlx_line_to_image(&(param->img), ptA, ptB, &(param->rgb));
  point(&ptB, (x + 60), y);
  mlx_line_to_image(&(param->img), ptA, ptB, &(param->rgb));
  point(&ptA, (x + 60), (y + 20));
  mlx_line_to_image(&(param->img), ptA, ptB, &(param->rgb));
  point(&ptB, (x + 20), (y + 20));
  mlx_line_to_image(&(param->img), ptA, ptB, &(param->rgb));
  point(&ptA, (x + 20), (y + 40));
  mlx_line_to_image(&(param->img), ptA, ptB, &(param->rgb));
  point(&ptB, (x + 60), (y + 40));
  mlx_line_to_image(&(param->img), ptA, ptB, &(param->rgb));
  point(&ptA, (x + 60), (y + 100));
  mlx_line_to_image(&(param->img), ptA, ptB, &(param->rgb));
  S2(x, y, param);
}

void	S2(int x, int y, t_param *param)
{
  t_coordonnee	ptA;
  t_coordonnee	ptB;

  point(&ptA, (x + 60), (y + 100));
  point(&ptB, x, (y + 100));
  mlx_line_to_image(&(param->img), ptA, ptB, &(param->rgb));
  point(&ptA, x, (y + 80));
  mlx_line_to_image(&(param->img), ptA, ptB, &(param->rgb));
  point(&ptB, (x + 40), (y + 80));
  mlx_line_to_image(&(param->img), ptA, ptB, &(param->rgb));
  point(&ptA, (x + 40), (y + 60));
  mlx_line_to_image(&(param->img), ptA, ptB, &(param->rgb));
  point(&ptB, x, (y + 60));
  mlx_line_to_image(&(param->img), ptA, ptB, &(param->rgb));
  point(&ptA, (x + 1), (y + 1));
  filling(&(param->img), &(param->rgb), ptA, 0);
}

void	E(int x, int y, t_param *param)
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
  point(&ptA, (x + 40), (y + 60));
  mlx_line_to_image(&(param->img), ptA, ptB, &(param->rgb));
  point(&ptB, (x + 20), (y + 60));
  mlx_line_to_image(&(param->img), ptA, ptB, &(param->rgb));
  E2(x, y, param);
}

void	E2(int x, int y, t_param *param)
{
  t_coordonnee	ptA;
  t_coordonnee	ptB;

  point(&ptA, (x + 20), (y + 80));
  point(&ptB, (x + 20), (y + 60));
  mlx_line_to_image(&(param->img), ptA, ptB, &(param->rgb));
  point(&ptB, (x + 60), (y + 80));
  mlx_line_to_image(&(param->img), ptA, ptB, &(param->rgb));
  point(&ptA, (x + 60), (y + 100));
  mlx_line_to_image(&(param->img), ptA, ptB, &(param->rgb));
  point(&ptB, x, (y + 100));
  mlx_line_to_image(&(param->img), ptA, ptB, &(param->rgb));
  point(&ptA, (x + 1), (y + 1));
  filling(&(param->img), &(param->rgb), ptA, 0);
}

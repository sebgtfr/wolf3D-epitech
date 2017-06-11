/*
** calc.c for wolf3D in /home/le-mai_s/rendu/Projet_Igraph_repository/MUL_2014_wolf3d/sources
**
** Made by sebastien le-maire
** Login   <le-mai_s@epitech.net>
**
** Started on  Tue May 19 14:05:22 2015 sebastien le-maire
** Last update Sun Jun 11 12:43:13 2017 Sébastien Le Maire
*/

#include <stdlib.h>
#include <math.h>
#include <mlx.h>
#include "graph.h"

/*
** Calcule la rotation de la vision du personnage.
*/

void	rotation(float angle, float *x, float *y)
{
  float	tmp;

  angle = ((angle) * M_PI) / 180;
  tmp = *x;
  *x = ((tmp) * cosf(angle)) - ((*y) * sinf(angle));
  *y = ((tmp) * sinf(angle)) + ((*y) * cosf(angle));
}

/*
** Calcule la possition du point par où va passer le vecteur
** sur le plan de projection.
*/

void	init_plane(t_param *param, int x)
{
  param->wolf.vray.x = 0.5;
  param->wolf.vray.y = (((WIN_X / 2) - ((float)x)) / WIN_X);
  rotation(param->wolf.player.a, &(param->wolf.vray.x),
	   &(param->wolf.vray.y));
  param->wolf.vray.x += param->wolf.player.pos.x;
  param->wolf.vray.y += param->wolf.player.pos.y;
}

/*
** On initialise et on calcule le coeff. k en utilisant la formule
** des équations paramétriques pour calculer les intersections
** tout en regardant les données du tableau à chaque case.
*/

void	intersection(t_param *param, __attribute__((unused))int x)
{
  float	xp;
  float	yp;
  float	Vx;
  float	Vy;

  param->wolf.k = 1;
  Vx = (param->wolf.vray.x - param->wolf.player.pos.x);
  Vy = (param->wolf.vray.y - param->wolf.player.pos.y);
  xp = ((int)(param->wolf.player.pos.x + (param->wolf.k * Vx)));
  yp = ((int)(param->wolf.player.pos.y + (param->wolf.k * Vy)));
  while (param->wolf.laby.tab[(int)yp][(int)xp] == 0)
    {
      xp = ((param->wolf.player.pos.x + (param->wolf.k * Vx)));
      yp = ((param->wolf.player.pos.y + (param->wolf.k * Vy)));
      param->wolf.k += 0.005;
    }
  if ((param->wolf.menu == 1 && param->wolf.game.play == 1) &&
      (((int)yp) == (param->wolf.laby.size_y - 2)) &&
      ((((int)xp) == param->wolf.laby.size_x - 1)))
    color(&(param->rgb), 200, 0, 0);
  else if ((param->wolf.menu == 1 && param->wolf.game.play == 1) &&
	   (((int)yp) == 1) && ((((int)xp) == 0)))
    color(&(param->rgb), 0, 0, 250);
  else
    color(&(param->rgb), 69, 90, 100);
}

/*
** Gere l'ajout de bonus par niveaux.
*/

void	add_bonus(int *bonus, int level)
{
  if (level <= 3)
    *bonus = 25 * (level - 1);
  else if (level == 4)
    *bonus = 150;
  else
    *bonus = 150 + (25 * (level - 4));
}

/*
** gere_key.c for wolf3D in /home/le-mai_s/projet/Igraph/Wolf3D
**
** Made by sebastien le-maire
** Login   <le-mai_s@epitech.net>
**
** Started on  Wed May  6 09:33:09 2015 sebastien le-maire
** Last update Sun Jun 11 12:33:27 2017 Sébastien Le Maire
*/

#include <unistd.h>
#include <stdlib.h>
#include <math.h>
#include "graph.h"

/*
** menu = 1 signifie qu'on est dans le jeu.
** key_press: echap = "quitter le programme".
** Cf: man_wolf.txt
*/

int	key_press(int keycode, t_param *param)
{
  if (param->wolf.menu == 1)
    {
      if (keycode == ECHAP)
	my_free_and_exit(param, 1);
      if (keycode == TOP_ARROW || keycode == K_Z)
	param->wolf.mv.up = 1;
      else if (keycode == BOTTOM_ARROW || keycode == K_S)
	param->wolf.mv.down = 1;
      else if (keycode == LEFT_ARROW || keycode == K_Q)
	param->wolf.mv.left = 1;
      else if (keycode == RIGHT_ARROW || keycode == K_D)
	param->wolf.mv.right = 1;
      if (keycode == K_R || keycode == MAJ_G)
	param->wolf.mv.run = ((param->wolf.mv.run * 100) == 4) ? 0.09 : 0.04;
    }
  return (EXIT_SUCCESS);
}

/*
** menu = 1 signifie qu'on est dans le jeu.
** key_release s'enclenche lorsqu'on reste appuyé sur la touche.
*/

int	key_release(int keycode, t_param *param)
{
  if (param->wolf.menu == 1)
    {
      if (keycode == TOP_ARROW || keycode == K_Z)
	param->wolf.mv.up = 0;
      else if (keycode == BOTTOM_ARROW || keycode == K_S)
	param->wolf.mv.down = 0;
      else if (keycode == LEFT_ARROW || keycode == K_Q)
	param->wolf.mv.left = 0;
      else if (keycode == RIGHT_ARROW || keycode == K_D)
	param->wolf.mv.right = 0;
    }
  return (EXIT_SUCCESS);
}

/*
** move check les nouvelles coordonnées de la possition
** du joueur. S'il n'est pas dans un mur, il peut avancer
** ou reculer. Sinon, il ne bouge pas.
*/

void	move(t_param *param, char choice)
{
  float	x;
  float	y;
  float	angle;

  angle = RAD(param->wolf.player.a);
  if (choice == 0)
    {
      x = param->wolf.player.pos.x + (param->wolf.mv.run * cosf(angle));
      y = param->wolf.player.pos.y + (param->wolf.mv.run * sinf(angle));
    }
  else
    {
      x = param->wolf.player.pos.x - (param->wolf.mv.run * cosf(angle));
      y = param->wolf.player.pos.y - (param->wolf.mv.run * sinf(angle));
    }
  if ((((int)x > 0) && ((int)x < (param->img.image.size_line / 4))) &&
      (((int)y > 0) && ((int)y < param->img.image.nb_line)) &&
      param->wolf.laby.tab[(int)y][(int)x] == 0)
    {
      param->wolf.player.pos.x = x;
      param->wolf.player.pos.y = y;
    }
}

/*
** Turn permet la rotation du personnage.
*/

void	turn(t_param *param, char choice)
{
  if (choice == 0)
    param->wolf.player.a += 6;
  else
    param->wolf.player.a -= 6;
}

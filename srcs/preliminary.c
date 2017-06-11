/*
** preliminary.c for wolf3D in /home/le-mai_s/projet/Igraph/Wolf3D
**
** Made by sebastien le-maire
** Login   <le-mai_s@epitech.net>
**
** Started on  Sat May  9 11:06:58 2015 sebastien le-maire
** Last update Sun Jun 11 12:31:19 2017 Sébastien Le Maire
*/

#include <unistd.h>
#include <stdlib.h>
#include "mlx.h"
#include "graph.h"

/*
++ On check la map pour voir si les bords sont bien des murs.
** Initialise les variables au préliminaire, à l'origine :
** - position d'origine du personnage.
** - angle de vue initiale.
*/

void	init_preliminary(t_param *param)
{
  if (check_map(param->wolf.laby.tab, param->wolf.laby.size_x,
		param->wolf.laby.size_y) != 0)
    {
      my_free_and_exit(param, 0);
      write(2, "Error: map invalid\n", 19);
      write(2, "Your map must be composite of one in edge !\n", 44);
      exit(3);
    }
  param->wolf.player.pos.x = 0;
  param->wolf.player.pos.y = 0;
  while (param->wolf.laby.tab[(int)param->wolf.player.pos.y]
	 [(int)param->wolf.player.pos.x] == 1)
    {
      param->wolf.player.pos.x += 1;
      if (param->wolf.player.pos.x == param->wolf.laby.size_x)
	{
	  param->wolf.player.pos.y += 1;
	  param->wolf.player.pos.x = 0;
	}
    }
  param->wolf.player.pos.x += 0.2;
  param->wolf.player.pos.y += (param->wolf.menu == 0) ? 1.5 : 0.5;
  param->wolf.mv.run = 0.04;
  param->wolf.player.a = 0;
}

/*
** Fonction qui vérifie si les bords sont des murs.
*/

int	check_map(int **map, int size_x, int size_y)
{
  int	x;
  int	y;

  y = 0;
  while (y < size_y)
    {
      x = 0;
      while (x < size_x)
	{
	  if ((y == 0 || y == (size_y - 1)) && (map[y][x] != 1))
	    return (1);
	  if ((x == 0 || x == (size_x - 1)) && (map[y][x] != 1))
	    return (1);
	  x++;
	}
      y++;
    }
  return (0);
}

/*
** Ecrit un message de fin. Il est en évènement pour pouvoir
** réactiver autorepeaton.
*/

int	exit_wolf(t_param *param)
{
  free(param->wolf.file);
  write(1, "End program\n", 12);
  exit(0);
}

/*
** Free le tableau à deux dimension de la carte et "détruit" la fenêtre.
*/

void	my_free_and_exit(t_param *param, char img)
{
  int	y;

  if (img == 0 || img == 1)
    {
      y = 0;
      while (y < param->wolf.laby.size_y)
	free(param->wolf.laby.tab[y++]);
      free(param->wolf.laby.tab);
    }
  if (img == 1  || img == 2)
    {
      mlx_do_key_autorepeaton(param->img.window.mlx_ptr);
      mlx_loop_hook(param->img.window.mlx_ptr, exit_wolf, param);
      mlx_loop(param->img.window.mlx_ptr);
    }
}

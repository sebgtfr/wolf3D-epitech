/*
** gere_mouse.c for wolf3D in /home/le-mai_s/projet/Igraph/Wolf3D
**
** Made by sebastien le-maire
** Login   <le-mai_s@epitech.net>
**
** Started on  Wed May  6 09:36:29 2015 sebastien le-maire
** Last update Sun Jun 11 12:41:24 2017 Sébastien Le Maire
*/

#include <unistd.h>
#include <stdlib.h>
#include "mlx.h"
#include "graph.h"

/*
** Lance le jeu.
*/

void	play_action(t_param *param)
{
  param->wolf.menu = 1;
  param->wolf.game.play = 1;
  free(param->wolf.file);
  if ((param->wolf.file = my_strdup("./maps/level1.map")) == NULL)
    my_free_and_exit(param, 1);
  my_free_and_exit(param, 0);
  if (init_laby(param->wolf.file, param) != 0)
    my_free_and_exit(param, 2);
  init_preliminary(param);
  my_memset(param->img.image.data, 0, SIZE_IMG);
  mlx_loop_hook(param->img.window.mlx_ptr, wolf3D, param);
}

/*
** Lance le test de la map mis en paramètre.
*/

void	test_map_action(t_param *param)
{
  param->wolf.menu = 1;
  param->wolf.game.play = 0;
  my_free_and_exit(param, 0);
  if (init_laby(param->wolf.file, param) != 0)
    my_free_and_exit(param, 2);
  init_preliminary(param);
  my_memset(param->img.image.data, 0, SIZE_IMG);
  mlx_loop_hook(param->img.window.mlx_ptr, wolf3D, param);
}

/*
** Vérifie si le fichier est une carte valide.
*/

void	check_file(char *buffer, t_param *param)
{
  int	i;

  i = 0;
  while (buffer[i])
    {
      if ((buffer[i] != ' ') &&
	  (buffer[i] != '\n') &&
	  (buffer[i] != '0') &&
	  (buffer[i] != '1'))
	{
	  write(2, "Error: file invalid !\n", 22);
	  my_free_and_exit(param, 2);
	}
      else
	i++;
    }
}

/*
** Si menu = 0, On est dans le menu. A la possition du bouton play,
** lance le labyrinthe et à la possition du bouton quit,
** quitte le programme.
*/

int	gere_mouse(__attribute__((unused))int buttom, int x, int y,
		   t_param *param)
{
  if ((param->wolf.menu == 0) &&
      (x >= 785 && x <= 1135) && (y >= 300 && y <= 480))
    play_action(param);
  else if ((param->wolf.menu == 0) &&
	   ((x >= 785 && x <= 1135) && (y >= 500 && y <= 680)))
    test_map_action(param);
  else if ((param->wolf.menu == 0) &&
	   ((x >= 785 && x <= 1135) && (y >= 700 && y <= 880)))
    my_free_and_exit(param, 1);
  return (EXIT_SUCCESS);
}

/*
** Si menu = 0, On est dans le menu. Si on passe sur le bouton play,
** le bouton play change de couleur. Même chose sur le bouton
** quit.
*/

int	mouse_hover(int x, int y, t_param *param)
{
  if (param->wolf.menu == 0)
    {
      if (((x >= 785 && x <= 1135) && (y >= 300 && y <= 480)))
	buttom_play_hover(785, 300, param);
      else
	buttom_play(785, 300, param);
      if (((x >= 785 && x <= 1135) && (y >= 500 && y <= 680)))
	buttom_test_hover(785, 500, param);
      else
	buttom_test(785, 500, param);
      if (((x >= 785 && x <= 1135) && (y >= 700 && y <= 880)))
	buttom_quit_hover(785, 700, param);
      else
	buttom_quit(785, 700, param);
      mlx_put_image_to_window(param->img.window.mlx_ptr,
			      param->img.window.win_ptr,
			      param->img.image.img_ptr, 0, 0);
    }
  return (EXIT_SUCCESS);
}

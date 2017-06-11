/*
** wolf3D.c for wolf3D in /home/le-mai_s/projet/Igraph/Wolf3D
**
** Made by sebastien le-maire
** Login   <le-mai_s@epitech.net>
**
** Started on  Wed May  6 09:40:23 2015 sebastien le-maire
** Last update Sun Jun 11 12:46:18 2017 Sébastien Le Maire
*/

#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <mlx.h>
#include "graph.h"

/*
** Il s'agit du déplacement du personnage, selon le flags
** il avance, recule, tourne à droite ou à gauche.
*/

void	action_character(t_param *param)
{
  if (param->wolf.mv.up == 1)
    move(param, 0);
  if (param->wolf.mv.down == 1)
    move(param, 1);
  if (param->wolf.mv.left == 1)
    turn(param, 0);
  if (param->wolf.mv.right == 1)
    turn(param, 1);
}

/*
** Dessine le wolf3D via le raycasting.
** Cette fonction est tourner en boucle dans la fonction
** mlx_loop_hook
*/

int		wolf3D(t_param *param)
{
  int		x;

  action_character(param);
  x = -1;
  while (++x < WIN_X)
    {
      init_plane(param, x);
      intersection(param, x);
      draw_wolf(param, x);
    }
  mlx_put_image_to_window(param->img.window.mlx_ptr,
			  param->img.window.win_ptr,
			  param->img.image.img_ptr, 0, 0);
  if (param->wolf.menu == 1)
    compass(param);
  if (param->wolf.menu == 1 && param->wolf.game.play == 1)
    change_map(param);
  return (EXIT_SUCCESS);
}

/*
** Change de niveau lorsqu'on s'approche du mur rouge.
*/

void		change_map(t_param *param)
{
  static int	level = 1;
  int		bonus;

  cpt_score(param, level);
  picture_frame(param, level, param->wolf.game.score);
  if ((param->wolf.player.pos.y > (param->wolf.laby.size_y - 2)) &&
      (param->wolf.player.pos.y < (param->wolf.laby.size_y - 1)) &&
      ((param->wolf.player.pos.x < (param->wolf.laby.size_x - 1)) &&
       ((param->wolf.player.pos.x > param->wolf.laby.size_x - 1.5))))
    {
      if (++level <= 6)
	{
	  add_bonus(&bonus, level);
	  param->wolf.game.score += bonus;
	  my_free_and_exit(param, 0);
	  param->wolf.file[12] = ('0' + level);
	}
      else
	victory(param);
      if (init_laby(param->wolf.file, param) != 0)
	my_free_and_exit(param, 1);
      init_preliminary(param);
    }
}

/*
** Affiche "victory !", votre pseudo et votre score puis il enregistre
** votre score et votre pseudo dans le fichier score.txt à la fin du
** fichier. Si le fichier n'existe pas, il le crée avec les tous les
** droits pour le propriétaire, et le droite de lecture pour le groupe
** et pour les autres.
*/

void	victory(t_param *param)
{
  int	fd;

  (void)write(1, "Victory !\n", 10);
  (void)write(1, param->wolf.game.pseudo,
	my_strlen(param->wolf.game.pseudo));
  (void)write(1, " : ", 3);
  put_nbr_in_term(param->wolf.game.score);
  (void)write(1, "\n", 1);
  if ((fd = open("score.txt", O_WRONLY | O_APPEND | O_CREAT,
		 S_IRWXU | S_IRGRP | S_IROTH)) == -1)
    {
      (void)write(2, "Error: open failed !\n", 21);
      my_free_and_exit(param, 1);
    }
  (void)write(fd, param->wolf.game.pseudo,
	      my_strlen(param->wolf.game.pseudo));
  (void)write(fd, " : ", 3);
  put_nbr_in_file(param->wolf.game.score, fd);
  (void)write(fd, " | win\n", 7);
  close(fd);
  my_free_and_exit(param, 1);
}

/*
** Affiche lose puis enregistre le résultat dans le fichier
** de sauvegarde. s'il il n'existe pas, il le crée.
*/

void		lose(t_param *param, int level)
{
  int	fd;
  char	level_txt[8] = "Level 1\0";

  if ((fd = open("score.txt", O_WRONLY | O_APPEND | O_CREAT,
		 S_IRWXU | S_IRGRP | S_IROTH)) == -1)
    {
      (void)write(2, "Error: open failed !\n", 21);
      my_free_and_exit(param, 1);
    }
  (void)write(1, "Lose !\n", 7);
  level_txt[6] = (level + '0');
  (void)write(fd, param->wolf.game.pseudo,
	      my_strlen(param->wolf.game.pseudo));
  (void)write(fd, " : ", 3);
  (void)write(fd, level_txt, 8);
  (void)write(fd, " | lose\n", 8);
  close(fd);
}

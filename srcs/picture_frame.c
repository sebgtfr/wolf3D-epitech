/*
** picture_frame.c for wolf3D in /home/le-mai_s/rendu/Projet_Igraph_repository/MUL_2014_wolf3d/sources
**
** Made by sebastien le-maire
** Login   <le-mai_s@epitech.net>
**
** Started on  Sun May 24 20:19:35 2015 sebastien le-maire
** Last update Sun Jun 11 12:43:37 2017 Sébastien Le Maire
*/

#include <unistd.h>
#include <mlx.h>
#include "graph.h"

/*
** Déssine un cadre noir avec écrit à l'intérieur,
** le niveau et le score.
*/

void		picture_frame(t_param *param, int level, int score)
{
  int		x;
  int		y;
  t_color	frame;
  char		level_txt[8] = "Level 1\0";

  level_txt[6] = (level + '0');
  color(&frame, 0, 0, 0);
  x = 1769;
  while (x < 1920)
    {
      y = 824;
      while (y < 975)
	{
	  my_pixel_put_to_image(&(param->img), &frame, x, y);
	  y++;
	}
      x++;
    }
  mlx_string_put(param->img.window.mlx_ptr, param->img.window.win_ptr,
		 1819, 874, 0xFFFFFF, level_txt);
  mlx_string_put(param->img.window.mlx_ptr, param->img.window.win_ptr,
		 1819, 904, 0xFFFFFF, "Score :");
  put_nbr_in_win(param, score);
}

/*
** Ecrit un nombre dans une fenètre.
*/

void		put_nbr_in_win(t_param *param, int nb)
{
  int	result;
  int	d;
  int	dec;
  char	inter[2];

  inter[1] = '\0';
  d = 1;
  dec = 0;
  while ((nb / d) >= 10)
    d *= 10;
  while (d > 0)
    {
      result = (nb / d) % 10;
      inter[0] = (result + '0');
      mlx_string_put(param->img.window.mlx_ptr, param->img.window.win_ptr,
		     (1865 + dec), 904, 0xFFFFFF, inter);
      dec += 7;
      d /= 10;
    }
}

/*
** Ecrit un nombre dans un fichier.
*/

void	put_nbr_in_file(int nb, int fd)
{
  char	inter[2];
  int	result;
  int	d;

  d = 1;
  inter[1] = '\0';
  while ((nb / d) >= 10)
    d *= 10;
  while (d > 0)
    {
      result = (nb / d) % 10;
      inter[0] = (result + '0');
      (void)write(fd, inter, 1);
      d /= 10;
    }
}


/*
** Ecrit un nombre dans un terminal.
*/

void	put_nbr_in_term(int nb)
{
  char	inter[2];
  int	result;
  int	d;

  d = 1;
  inter[1] = '\0';
  while ((nb / d) >= 10)
    d *= 10;
  while (d > 0)
    {
      result = (nb / d) % 10;
      inter[0] = (result + '0');
      (void)write(1, inter, 1);
      d /= 10;
    }
}

/*
** Décompte le score, si le score = 0, lance lose.
*/

void		cpt_score(t_param *param, int level)
{
  static int	cpt = 0;

  cpt += 1;
  if (cpt == 20)
    {
      cpt = 0;
      param->wolf.game.score -= 1;
    }
  if (param->wolf.game.score == 0)
    {
      lose(param, level);
      my_free_and_exit(param, 1);
    }
}

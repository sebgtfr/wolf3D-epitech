/*
** main_wolf.c for wolf3D in /home/le-mai_s/projet/Igraph/Wolf3D
**
** Made by sebastien le-maire
** Login   <le-mai_s@epitech.net>
**
** Started on  Mon May  4 15:03:47 2015 sebastien le-maire
** Last update Tue May 26 17:28:12 2015 sebastien le-maire
*/

#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <mlx.h>
#include "graph.h"

/*
** init_mlx recupère toutes les données de la minilibX
*/

int	init_mlx(t_param *param)
{
  if (init_laby("./maps/menu", param) != 0)
    return (-1);
  if ((param->img.window.mlx_ptr = mlx_init()) == NULL)
    return (1);
  if ((param->img.window.win_ptr =
       mlx_new_window(param->img.window.mlx_ptr, 1920, 975, "Wolf3D"))
      == NULL)
    return (2);
  if ((param->img.image.img_ptr = 
       mlx_new_image(param->img.window.mlx_ptr, 1920, 975)) == NULL)
    return (3);
  WIN_Y = 975;
  if ((param->img.image.data = 
       mlx_get_data_addr(param->img.image.img_ptr, &(param->img.image.bpp),
			 &(param->img.image.size_line),
			 &(param->img.image.endian))) == NULL)
    return (4);
  return (0);
}

/*
** init_laby ouvre le fichier, le lit et stock le texte dans un buffer.
*/

int	init_laby(char *file, t_param *param)
{
  int	fd;
  char	*buffer;

  if ((fd = open(file, O_RDONLY)) == -1)
    {
      write(2, "Error: open failed\n", 19);
      return (1);
    }
  if ((buffer = get_buffer(fd)) == NULL)
    {
      write(2,"Error: read failed\n", 19);
      return (2);
    }
  close (fd);
  if ((param->wolf.menu == 1 && param->wolf.game.play == 0))
    check_file(buffer, param);
  param->wolf.laby.size_x = 0;
  param->wolf.laby.size_y = 1;
  return (def_laby_xy(buffer, param));
}

/*
** def_laby_xy definit la taille x et y du labyrinthe et
** il malloc la 1ère coordonnée du tableau d'int.
*/

int	def_laby_xy(char *buffer, t_param *param)
{
  int	pos;
  int	ret;

  pos = -1;
  while (buffer[++pos])
    {
      if (buffer[pos] == '\n')
	param->wolf.laby.size_y += 1;
      if ((param->wolf.laby.size_y == 1) &&
	  (buffer[pos] == '0' || buffer[pos] == '1'))
	param->wolf.laby.size_x += 1;
    }
  if (((param->wolf.laby.tab =
	malloc(sizeof(int *) * param->wolf.laby.size_y)) == NULL) ||
      ((ret = filling_tab_laby(buffer, 0, param)) == 3))
    {
      write(2, "Error: malloc failed\n", 21);
      return (3);
    }
  return (ret);
}

/*
** filling_tab_laby remplis le tableau d'int servant de source pour la map.
*/

int	filling_tab_laby(char *buffer, int pos, t_param *param)
{
  int	x;
  int	y;

  y = -1;
  while (++y < param->wolf.laby.size_y)
    {
      if ((param->wolf.laby.tab[y] =
	   malloc(sizeof(int) * param->wolf.laby.size_x)) == NULL)
	return (3);
      x = 0;
      while (x < param->wolf.laby.size_x)
	{
	  if (buffer[pos] != ' ' && buffer[pos] != '\n')
	    {
	      if ((param->wolf.laby.tab[y][x++] = conv_int_wolf(buffer[pos]))
		  == 2)
		{
		  write(1, "Error: map invalid ! \nnumber accept are 0 or 1\n", 48);
		  return (4); 
		}
	    }
	  pos++;
	}
    }
  return (0);
}

/*
** Dans le main, on initialise la fenètre via minilibx.
** Puis on lance la boucle des évènements.
*/

int		main(int argc, char **argv)
{
  t_param	param;
  int		err;

  if (argc != 3)
    error(1);
  param.wolf.game.score = 100;
  param.wolf.menu = 0;
  if ((param.wolf.file = my_strdup(argv[1])) == NULL)
    return (1);
  if ((param.wolf.game.pseudo = my_strdup(argv[2])) == NULL)
    return (2);
  if ((err = init_mlx(&param)) > 0)
    error(2);
  if (err == -1)
    return (3);
  init_preliminary(&param);
  menu(&param);
  mlx_expose_hook(param.img.window.win_ptr, gere_expose, &param);
  mlx_do_key_autorepeatoff(param.img.window.mlx_ptr);
  mlx_hook(param.img.window.win_ptr, 3, (1L<<1), key_release, &param);
  mlx_hook(param.img.window.win_ptr, 2, (1L<<0), key_press, &param);
  mlx_hook(param.img.window.win_ptr, 6, (1L<<6), mouse_hover, &param);
  mlx_mouse_hook(param.img.window.win_ptr, gere_mouse, &param);
  mlx_loop(param.img.window.mlx_ptr);
  return (0);
}

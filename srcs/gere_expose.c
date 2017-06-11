/*
** gere_expose.c for wolf3D in /home/le-mai_s/projet/Igraph/Wolf3D
**
** Made by sebastien le-maire
** Login   <le-mai_s@epitech.net>
**
** Started on  Wed May  6 09:31:47 2015 sebastien le-maire
** Last update Sun Jun 11 12:32:41 2017 Sébastien Le Maire
*/

#include <stdlib.h>
#include <mlx.h>
#include "graph.h"

/*
** Gère l'expose : affiche l'image.
*/

int	gere_expose(t_param *param)
{
  mlx_put_image_to_window(param->img.window.mlx_ptr,
			  param->img.window.win_ptr,
			  param->img.image.img_ptr, 0, 0);
  return (EXIT_SUCCESS);
}

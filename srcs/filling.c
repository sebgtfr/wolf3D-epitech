/*
** filling.c for filling in /home/le-mai_s/projet/Graph_test/lib/graph
** 
** Made by sebastien le-maire
** Login   <le-mai_s@epitech.net>
** 
** Started on  Tue Apr 28 21:49:47 2015 sebastien le-maire
** Last update Fri May 22 16:01:02 2015 sebastien le-maire
*/

#include <mlx.h>
#include "graph.h"

void		vertical_filling(t_param_img *img, t_color *rgb, t_coordonnee *pointP,
				 int stack_max)
{
  if ((((int *)img->image.data)
       [POS_POINT_PIXEL + (1 * (img->image.size_line / 4))] >> 24) == 0)
    {
      pointP->y += 1;
      filling(img, rgb, *pointP, stack_max);
    }
  if ((((int *)img->image.data)
       [POS_POINT_PIXEL - (1 * (img->image.size_line / 4))] >> 24) == 0)
    {
      pointP->y -= 1;
      filling(img, rgb, *pointP, stack_max);
    }
}

void		horizontal_filling(t_param_img *img, t_color *rgb, t_coordonnee *pointP,
				   int stack_max)
{
  if ((((int *)img->image.data)[POS_POINT_PIXEL + 1] >> 24) == 0)
    {
      pointP->x += 1;
      filling(img, rgb, *pointP, stack_max);
    }
  if ((((int *)img->image.data)[POS_POINT_PIXEL - 1] >> 24) == 0)
    {
      pointP->x -= 1;
      filling(img, rgb, *pointP, stack_max);
    }
}

void		filling(t_param_img *img, t_color *rgb, t_coordonnee pointP, 
			int stack_max)
{
  if (stack_max++ >= 60000)
    return ;
  my_pixelA_put_to_image(img, rgb, (int)pointP.x, (int)pointP.y);
  if (((int)pointP.x > 0 && (int)pointP.x < (img->image.size_line / 4) - 1))
    horizontal_filling(img, rgb, &pointP, stack_max);
  if (((int)pointP.y > 0 && (int)pointP.y < img->image.nb_line))
    vertical_filling(img, rgb, &pointP, stack_max);
    }

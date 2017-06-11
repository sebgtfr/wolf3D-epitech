/*
** my_pixel_put_to_image.c for my_pixel_put_to_pixel in /home/le-mai_s/projet/Graph_test/lib/graph
** 
** Made by sebastien le-maire
** Login   <le-mai_s@epitech.net>
** 
** Started on  Fri Apr 24 11:54:25 2015 sebastien le-maire
** Last update Fri May 22 15:39:13 2015 sebastien le-maire
*/

#include <mlx.h>
#include "graph.h"

void	my_put_bit_to_alpha(t_param_img *img, int pos_x, int pos_y)
{
  (((int *)img->image.data)[POS_PIXEL]) |= (1 << 24);
}

/*
** Colore un pixel à la position pos_x et pos_y comme my_pixel_put_to_image
** mais la transparence est égale à 1.
*/

void	my_pixelA_put_to_image(t_param_img *img, t_color *rgb,
			       int pos_x, int pos_y)
{
  ((int *)img->image.data)[POS_PIXEL] = 
    mlx_get_color_value(img->window.mlx_ptr, my_getcolor(rgb));
  my_put_bit_to_alpha(img, pos_x, pos_y);
}

/*
** Colore un pixel à la position pos_x et pos_y.
*/

void	my_pixel_put_to_image(t_param_img *img, t_color *rgb,
			      int pos_x, int pos_y)
{
  ((int *)img->image.data)[POS_PIXEL] = 
    mlx_get_color_value(img->window.mlx_ptr, my_getcolor(rgb));
}

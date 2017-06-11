/*
** buttom.c for wolf3D in /home/le-mai_s/projet/Igraph/Wolf3D/menu
** 
** Made by sebastien le-maire
** Login   <le-mai_s@epitech.net>
** 
** Started on  Sun May 17 14:59:47 2015 sebastien le-maire
** Last update Fri May 22 16:06:43 2015 sebastien le-maire
*/

#include <mlx.h>
#include "graph.h"

/*
** buttom_background dessine le contour d'un bouton.
*/

void	buttom_background(int x, int y, t_param *param)
{
  int	xb;
  int	yb;

  xb = x;
  while (xb <= (x + 350))
    {
      yb = y;
      while (yb <= (y + 180))
	{
	  my_pixel_put_to_image(&(param->img), &(param->rgb), xb, yb);
	  yb++;
	}
      xb++;
    }
}

/*
** Objet : buttom play avec la souris hors du bouton.
*/

void	buttom_play(int x, int y, t_param *param)
{
  color(&(param->rgb), 150, 150, 150);
  buttom_background(x, y, param);
  x += 40;
  y += 40;
  color(&(param->rgb), 255, 0, 0);
  P(x, y, param);
  L((x + 70), y, param);
  A((x + 140), y, param);
  Y((x + 210), y, param);
}

/*
** Objet : buttom play avec la souris sur le bouton.
*/

void	buttom_play_hover(int x, int y, t_param *param)
{
  color(&(param->rgb), 250, 250, 0);
  buttom_background(x, y, param);
  x += 40;
  y += 40;
  color(&(param->rgb), 0, 0, 0);
  P(x, y, param);
  L((x + 70), y, param);
  A((x + 140), y, param);
  Y((x + 210), y, param);
}

/*
** Objet : buttom quit avec la souris hors du bouton.
*/

void	buttom_quit(int x, int y, t_param *param)
{
  color(&(param->rgb), 150, 150, 150);
  buttom_background(x, y, param);
  x += 60;
  y += 40;
  color(&(param->rgb), 255, 0, 0);
  Q(x, y, param);
  U((x + 70), y, param);
  I((x + 140), y, param);
  T((x + 170), y, param);
}

/*
** Objet : buttom quit avec la souris sur le bouton.
*/

void	buttom_quit_hover(int x, int y, t_param *param)
{
  color(&(param->rgb), 250, 250, 0);
  buttom_background(x, y, param);
  x += 60;
  y += 40;
  color(&(param->rgb), 0, 0, 0);
  Q(x, y, param);
  U((x + 70), y, param);
  I((x + 140), y, param);
  T((x + 170), y, param);
}

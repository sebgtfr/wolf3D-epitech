/*
** conv_int_wolf.c for wolf3D in /home/le-mai_s/projet/Igraph/Wolf3D
** 
** Made by sebastien le-maire
** Login   <le-mai_s@epitech.net>
** 
** Started on  Wed May  6 12:18:45 2015 sebastien le-maire
** Last update Thu May  7 11:13:35 2015 sebastien le-maire
*/

/*
** Convertit les 0 et les 1 dans le buffer en nombre.
** Retourne une erreur si ce n'est pas un 1 ou un 0.
*/

int	conv_int_wolf(char c)
{
  int	nb;

  if (c && c == '0')
    nb = 0;
  else if (c && c == '1')
    nb = 1;
  else
    nb = 2;
  return (nb);
}

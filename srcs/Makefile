##
## Makefile for FDF in /home/le-mai_s/projet/Igraph/FDF
## 
## Made by sebastien le-maire
## Login   <le-mai_s@epitech.net>
## 
## Started on  Tue Mar 31 10:55:11 2015 sebastien le-maire
## Last update Sun Jun 11 12:12:27 2017 Sébastien Le Maire
##

NAME	= wolf3D

CFLAGS	= -I../include

LDFLAGS	= -L/usr/lib64 -L/usr/lib64/X11 -lXext -lX11 -lmlx -lm

SRC	= point.c \
	  conv_int_wolf.c \
	  color.c \
	  my_getcolor.c \
	  my_pixel_put_to_image.c \
	  error.c \
	  my_memset.c \
	  preliminary.c \
	  get_buffer.c \
	  gere_expose.c \
	  gere_key.c \
	  gere_mouse.c \
	  draw.c \
	  mlx_line_to_image.c \
	  filling.c \
	  play.c \
	  quit.c \
	  wolf.c \
	  TroisD.c \
	  es.c \
	  title.c \
	  buttom.c \
	  buttom2.c \
	  menu.c \
	  calc.c \
	  picture_frame.c \
	  compass.c \
	  wolf3D.c \
	  main_wolf.c

OBJ	= $(SRC:.c=.o)

CC	= gcc

RM	= rm -f

CP	= cp

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS) $(CFLAGS)
	$(CP) $(NAME) ..

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)
	$(RM) ../$(NAME)

re: fclean all

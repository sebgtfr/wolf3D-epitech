##
## Makefile for wold3d in /home/le-mai_s/rendu/tek1/wolf3D-epitech
## 
## Made by Sébastien Le Maire
## Login   <le-mai_s@epitech.net>
## 
## Started on  Sun Jun 11 12:22:31 2017 Sébastien Le Maire
## Last update Sun Jun 11 12:58:09 2017 Sébastien Le Maire
##

ifeq ($(DEBUG), yes)

CFLAGS		+= -g -g3 -ggdb

endif

PATH_SRCS	= ./srcs/

NAME		= wold3d

CFLAGS		+= -Wall -Wextra -Werror
CFLAGS		+= -I./include
CFLAGS		+= -I./libX/include

LDFLAGS		= -L./libX/lib -lXext -lX11 -lmlx -lm

SRCS		= $(PATH_SRCS)point.c
SRCS		+= $(PATH_SRCS)conv_int_wolf.c
SRCS		+= $(PATH_SRCS)color.c
SRCS		+= $(PATH_SRCS)my_getcolor.c
SRCS		+= $(PATH_SRCS)my_pixel_put_to_image.c
SRCS		+= $(PATH_SRCS)error.c
SRCS		+= $(PATH_SRCS)my_memset.c
SRCS		+= $(PATH_SRCS)preliminary.c
SRCS		+= $(PATH_SRCS)get_buffer.c
SRCS		+= $(PATH_SRCS)gere_expose.c
SRCS		+= $(PATH_SRCS)gere_key.c
SRCS		+= $(PATH_SRCS)gere_mouse.c
SRCS		+= $(PATH_SRCS)draw.c
SRCS		+= $(PATH_SRCS)mlx_line_to_image.c
SRCS		+= $(PATH_SRCS)filling.c
SRCS		+= $(PATH_SRCS)play.c
SRCS		+= $(PATH_SRCS)quit.c
SRCS		+= $(PATH_SRCS)wolf.c
SRCS		+= $(PATH_SRCS)TroisD.c
SRCS		+= $(PATH_SRCS)es.c
SRCS		+= $(PATH_SRCS)title.c
SRCS		+= $(PATH_SRCS)buttom.c
SRCS		+= $(PATH_SRCS)buttom2.c
SRCS		+= $(PATH_SRCS)menu.c
SRCS		+= $(PATH_SRCS)calc.c
SRCS		+= $(PATH_SRCS)picture_frame.c
SRCS		+= $(PATH_SRCS)compass.c
SRCS		+= $(PATH_SRCS)wolf3D.c
SRCS		+= $(PATH_SRCS)main_wolf.c

OBJS		= $(SRCS:.c=.o)

CC		= gcc

RM		= rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(LDFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

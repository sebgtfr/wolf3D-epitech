/*
** graph.h for graph in /home/le-mai_s/projet/Graph_test/include
**
** Made by sebastien le-maire
** Login   <le-mai_s@epitech.net>
**
** Started on  Mon Apr  6 10:41:24 2015 sebastien le-maire
** Last update Sun Jun 11 12:45:50 2017 Sébastien Le Maire
*/

#ifndef GRAPH_H_
# define GRAPH_H_

# define SIZE_BUFF 500
# define POS_PIXEL (((img->image.size_line / 4) * pos_y) + pos_x)
# define POS_POINT_PIXEL (((img->image.size_line / 4) * ((int)pointP->y)) + ((int)pointP->x))
# define WIN_X (param->img.image.size_line / 4)
# define WIN_Y (param->img.image.nb_line)
# define SIZE_IMG (param->img.image.size_line * param->img.image.nb_line)
# define SIZE_LABY (param->wolf.laby.size_x * param->wolf.laby.size_y)
# define RAD(a) ((a * M_PI) / 180)
# define ECHAP (65307)
# define TOP_ARROW (65362)
# define BOTTOM_ARROW (65364)
# define LEFT_ARROW (65361)
# define RIGHT_ARROW (65363)
# define K_Z (122)
# define K_S (115)
# define K_Q (113)
# define K_D (100)
# define K_R (114)
# define MAJ_G (65505)

typedef	struct		s_frag_read
{
  char			*frag_str;
  struct s_frag_read	*next;
}			t_frag_read;

typedef	struct	s_coordonnee
{
  float		x;
  float		y;
}		t_coordonnee;

typedef	struct	s_img
{
  void		*img_ptr;
  char		*data;
  int		bpp;
  int		size_line;
  int		nb_line;
  int		endian;
}		t_img;

typedef	struct	s_window
{
  void		*mlx_ptr;
  void		*win_ptr;
}		t_window;

typedef	struct	s_color
{
  int		red;
  int		green;
  int		blue;
}		t_color;

typedef	struct	s_param_img
{
  t_window	window;
  t_img		image;
}		t_param_img;

typedef struct	s_laby
{
  int		size_x;
  int		size_y;
  int		**tab;
}		t_laby;

typedef struct	s_player
{
  t_coordonnee	pos;
  float		a;
}		t_player;

typedef	struct	s_move
{
  char		up;
  char		down;
  char		left;
  char		right;
  float		run;

}		t_move;

typedef	struct	s_game
{
  char		play;
  char		*pseudo;
  int		score;

}		t_game;

typedef struct	s_wolf
{
  t_laby	laby;
  t_player	player;
  t_coordonnee	vray;
  t_move	mv;
  t_game	game;
  double	k;
  char		menu;
  char		*file;
}		t_wolf;

typedef struct	s_param
{
  t_param_img	img;
  t_color	rgb;
  t_coordonnee	pt;
  t_wolf	wolf;
}		t_param;

int		my_strlen(char *);
char		*my_strcpy(char *, char *);
char		*my_strdup(char *);
char		*realloc_buff(char *, int *, t_frag_read **);
char		*get_buffer(const int);
t_frag_read	*add_elem_list(t_frag_read *, char *, int);
void		point(t_coordonnee *, float, float);
void		color(t_color *, int, int, int);
int		my_getcolor(t_color *);
int		my_getnbr(char *);
int		conv_int_wolf(char);
void		error(short);
void		my_pixel_put_to_image(t_param_img *, t_color *, int, int);
void		*my_memset(void *, int, int);
void		rotation(float, float *, float *);
int		init_laby(char *, t_param *);
int		def_laby_xy(char *, t_param *);
int		filling_tab_laby(char *, int, t_param *);
int		init_mlx(t_param *);
void		init_preliminary(t_param *);
int		check_map(int **, int, int);
void		my_free_and_exit(t_param *, char);
int		exit_wolf(t_param *);
int		gere_expose(t_param *);
int		key_press(int, t_param *);
int		key_release(int, t_param *);
void		move(t_param *, char);
int		gere_mouse(int, int, int, t_param *);
int		mouse_hover(int, int, t_param *);
void		play_action(t_param *);
void		test_map_action(t_param *);
void		check_file(char *, t_param *);
void		my_pixelA_put_to_image(t_param_img *, t_color *, int, int);
void		diagonale_left_to_image(t_param_img *, t_coordonnee *, t_coordonnee *, t_color *);
void		diagonale_right_to_image(t_param_img *, t_coordonnee *, t_coordonnee *, t_color *);
void		diagonale_Yplus_to_image(t_param_img *, t_coordonnee *, t_coordonnee *, t_color *);
void		diagonale_Ymoins_to_image(t_param_img *, t_coordonnee *, t_coordonnee *, t_color *);
void		mlx_line_to_image(t_param_img *, t_coordonnee, t_coordonnee, t_color *);
void		my_put_bit_to_alpha(t_param_img *, int, int);
void		horizontal_filling(t_param_img *, t_color *, t_coordonnee *, int);
void		vertical_filling(t_param_img *, t_color *, t_coordonnee *, int);
void		filling(t_param_img *, t_color *, t_coordonnee, int);
void		buttom_background(int, int, t_param *);
void		buttom_play(int, int, t_param *);
void		buttom_play_hover(int, int, t_param *);
void		buttom_quit(int, int, t_param *);
void		buttom_quit_hover(int, int, t_param *);
void		buttom_test(int, int, t_param *);
void		buttom_test_hover(int, int, t_param *);
void		square(int, int, t_param *);
void		rectangle(int, int, t_param *);
void		P(int, int, t_param *);
void		L(int, int, t_param *);
void		A(int, int, t_param *);
void		Y(int, int, t_param *);
void		Q(int, int, t_param *);
void		U(int, int, t_param *);
void		I(int, int, t_param *);
void		T(int, int, t_param *);
void		W(int, int, t_param *);
void		W2(int, int, t_param *);
void		O(int, int, t_param *);
void		F(int, int, t_param *);
void		F2(int, int, t_param *);
void		Trois(int, int, t_param *);
void		Trois2(int, int, t_param *);
void		D(int, int, t_param *);
void		S(int, int, t_param *);
void		S2(int, int, t_param *);
void		E(int, int, t_param *);
void		E2(int, int, t_param *);
void		title(int, int, t_param *);
void		menu(t_param *);
void		init_plane(t_param *, int);
void		intersection(t_param *, int);
void		draw_wolf(t_param *, int);
void		change_map(t_param *);
void		victory(t_param *);
void		picture_frame(t_param *, int, int);
void		put_nbr_in_win(t_param *, int);
void		put_nbr_in_file(int, int);
void		put_nbr_in_term(int);
void		cpt_score(t_param *, int);
void		add_bonus(int *, int);
void		lose(t_param *, int);
void		compass(t_param *);
void		arrow_compass(t_param *);
void		cardinal_points(t_param *);
void		turn(t_param *, char);
int		wolf3D(t_param *);
void		draw_vertical_line(t_param *, int, int, int);

#endif /* GRAPH_H_ */

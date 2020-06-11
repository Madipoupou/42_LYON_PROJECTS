/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fractol.h                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/13 18:56:35 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/14 15:23:47 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "../libft/includes/libft.h"
# include "../minilibx/mlx.h"
# include <time.h>
# include <math.h>
# include <stdlib.h>
# include <pthread.h>

# define WIN_L		1750
# define WIN_H		1100
# define FRAC_L		1000
# define FRAC_H		1000
# define ZOOM_VAL	2
# define TOT_FRAC	9
# define COL_RANGE	6
# define NB_THREAD	10

typedef struct	s_col
{
	int	color[11];
	int	mode;
	int	range;
	int	random;
}				t_col;

typedef struct	s_bag
{
	void			*mlx;
	void			*win;
	void			*img_ptr;
	unsigned int	*img;
	int				trash[3];
	int				choice;
	int				i_max;
	double			lim;
	double			size;
	double			posx;
	double			posy;
	int				edit;
	double			julia_param[2];
	t_col			col;
	double			zoom;
	double			move_value;
	void			(*ft_init)(struct s_bag *);
	void			(*ft_frac)(struct s_bag *, double, double, int);
}				t_bag;

typedef struct	s_thread_info
{
	t_bag	*ptr_bag;
	double	zoomx;
	double	zoomy;
	int		y_start;
	int		y_end;
}				t_thread_info;

/*
**	ERROR FUNCTIONS
*/
int				ft_usage(void);
int				ft_puterror(char *str);

/*
**	EVENT MANAGEMENT
*/
int				ft_keymg(int key, void *ptr);
int				ft_mousemg(int button, int x, int y, void *param);
int				ft_motionmg(int x, int y, void *ptr);
int				ft_bpress(int button, int x, int y, void *ptr);
int				ft_brelease(int button, int x, int y, void *ptr);

/*
**	FRACTAL FUNCTIONS
*/
void			ft_sync_frac(void *ptr);
void			ft_initmand(t_bag *ptr);
void			ft_mandelbrot(t_bag *ptr, double zoomx, double zoomy, int y);
void			ft_initjulia(t_bag *ptr);
void			ft_julia(t_bag *ptr, double zoomx, double zoomy, int y);

/*
**	VARIOUS FUNCTIONS
*/
void			ft_context(void *ptr, int color);
void			ft_commands(t_bag *ptr, int color, int x[2], int y[2]);
void			ft_info_panel(t_bag *ptr_bag);
void			ft_info_iter(t_bag *ptr_bag);
void			ft_info_color(t_bag *ptr_bag);
void			ft_info_color_random(t_bag *ptr_bag);
void			ft_draw_rectangle(t_bag *ptr, int x[2], int y[2], int color);
void			ft_resetimg(t_bag *ptr);
double			ft_abs(double f);

/*
**	MENU FUNCTIONS
*/
void			ft_menu_selector(t_bag *ptr_bag, int y);
void			ft_reinit(t_bag *ptr_bag, int choice);
void			ft_menu(t_bag *ptr_bag, int x[2], int y[2], int color);
void			ft_menu2(t_bag *ptr_bag, int x[2], int y[2], int color);

/*
**	COLOR FUNCTIONS
*/
void			ft_initcol(t_bag *ptr);
void			ft_lblue(t_bag *ptr);
void			ft_lgreen(t_bag *ptr);
void			ft_red(t_bag *ptr);
void			ft_brown(t_bag *ptr);
void			ft_yellow(t_bag *ptr);
void			ft_teal(t_bag *ptr);
int				ft_colormg(t_bag *ptr_bag);
int				ft_colormg_reverse(t_bag *ptr_bag);

#endif

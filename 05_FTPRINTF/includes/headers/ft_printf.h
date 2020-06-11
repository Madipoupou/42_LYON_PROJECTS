/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.h                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/20 17:54:35 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/17 16:15:30 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>

typedef struct	s_attibutes
{
	int			h;
	int			hh;
	int			l;
	int			ll;
	int			longd;
	int			prec;
	int			width;
	int			opt1;
	int			opt2;
	int			opt3;
	int			opt4;
	int			opt5;
}				t_attributes;
typedef char *(*t_pf_func)(char *, va_list *, t_attributes *);
typedef struct	s_conf
{
	char		*str;
	t_pf_func	func;
}				t_conv;

/*
** Printf format management
*/
void			ft_dispatch(char **str, size_t *i, va_list *ap);

/*
** Printf function and attributes
*/
int				ft_fprintf(int fd, const char *format, ...);
int				ft_printf(const char *format,
		...) __attribute__((format(printf,1,2)));
size_t			ft_putstr_pf(char *str, int fd);
void			ft_init_attributes(t_attributes *ptr);
void			ft_eval_attributes(t_attributes *ptr, char *sub);
void			ft_enhance_left(char **res, char c, int len);
void			ft_enhance_right(char **res, char c, int len);
void			ft_intadjust(char *res, t_attributes *att);
void			ft_delzero(char **res);
int				ft_color_manager(const char *str);

/*
** Extraction functions
*/
char			*pf_int_arg(char *sub, va_list *ap, t_attributes *att);
char			*ft_toa1(char *sub, long long int x, t_attributes *att);
char			*ft_toa2(char *sub, long long int x, t_attributes *att);
char			*ft_toa3(char *sub, long long int x, t_attributes *att);
char			*pf_b_arg(char *sub, va_list *ap, t_attributes *att);
char			*pf_c_arg(char *sub, va_list *ap, t_attributes *att);
char			*pf_s_arg(char *sub, va_list *ap, t_attributes *att);
char			*pf_p_arg(char *sub, va_list *ap, t_attributes *att);
char			*pf_f_arg(char *sub, va_list *ap, t_attributes *att);
char			*pf_pc_arg(char *sub, va_list *ap, t_attributes *att);

/*
** Color and various  define
*/
# define NB_COLOR		11
# define CONV_NB		7
# define CONV_STR		"diouxXbcspf%"
# define C_NONE         "\033[0m"
# define C_BOLD         "\033[1m"
# define C_BLACK        "\033[30m"
# define C_RED          "\033[31m"
# define C_GREEN        "\033[32m"
# define C_BROWN        "\033[33m"
# define C_BLUE         "\033[34m"
# define C_MAGENTA      "\033[35m"
# define C_CYAN         "\033[36m"
# define C_GRAY         "\033[37m"
# define C_YELLOW		"\033[0;33m"
# define N				"@@+NULL+@@"

#endif

/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fdf.h                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/28 01:38:57 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/11 20:51:14 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "./../minilibx/mlx.h"
# include "./../libft/includes/libft.h"
# include <stdlib.h>
# include <math.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# define ISO_CST1 0.75
# define ISO_CST2 0.75

/*
** COORD AND PARSING
*/
void	ft_drawline(int *point1, int *point2, char *img_str, int color);
int		ft_parse(int fd, t_list **lst, int *size);
void	ft_updatecoord(t_list *lst, int h, int l, int z);

/*
** MATRIX
*/
void	ft_isomatrix(void **ptr, int first);
void	ft_dispmatrix(int *size, void **ptr);
void	ft_display(t_list *lst, int *size);

/*
** EVENT_MANAGER
*/
void	ft_slide(int key, void **ptr);
void	ft_zoom(int mouse, void **ptr);
void	ft_editheight(int key, void **ptr);
void	ft_changecolor(void **ptr);
void	ft_rotate(int key, void **ptr);
int		ft_keymanager(int key, void *param);
int		ft_mousemanager(int key, int x, int y, void *param);

/*
** COLOR MANAGEMENT / WINDOW DECORATION
*/
void	ft_putrgb(char **color);
char	ft_hextochar(char a, char b);
void	ft_context(void **ptr, int color);

/*
** UTIL.C
*/
int		ft_max(int a, int b);
int		ft_abs(int a);
int		ft_usage(void);
int		ft_puterror(char *str);
void	ft_strtabdel(char **tab);
void	ft_lstintdel(void *content, size_t size);

#endif

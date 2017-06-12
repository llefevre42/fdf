/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llefevre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/21 15:34:06 by llefevre          #+#    #+#             */
/*   Updated: 2017/06/10 16:48:00 by llefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "./libft/libft.h"
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h> 		//delete
# include "mlx.h"
# include <math.h>
# define BUFSIZE 200048

struct	s_tab
{
	long int	tab;
	int			xpo;
	int			ypo;
};
typedef struct s_tab	t_tab;

struct				s_tri
{
	void			*mlx;
	void			*win;
	void			*win2;
	void			*interface;
	int			*interface_i;
	char			*input;
	long int		color;
	long int		swap_color;
	int				lon;
	int				centrex;
	int				centrey;
	int				zoom;
	int				nbr_zoom;
	int				haut;
	int				droite;
	int				xp;
	int				yp;
	int				xs;
	int				ys;
	int				egal;
	int				colonebis;
	int				spacebis;
	int 			hauttab;
	int				largtab;
	int				reste;
	int				z;
	int				rota;
};
typedef struct		 s_tri	t_tri;

int		face_cache(int x, int y, int xp, int yp, t_tri *lst, int color);
double	ft_pow(double x,double y);
void	ft_convert(char *hex, int i, long *sum);
long	ft_htoi(char *hex);
int		put_cub_bis(int x, int y, int xp, int yp, t_tri *lst);
void	affiche_marge(t_tri *lst);
int		tri(char *str, t_tri *lst, int ***tab);
void	full_tab(t_tri *lst, int ***tab);
void	ft_strlen_custom(char *str, t_tri *lst);
void	affiche_cub(int keycode, t_tri *lst);
char	*ft_read(char *av);
int		put_cub(int x, int y, t_tri *lst);
int		my_key_funct(int keycode, void *param);
int		put_mousse(int	keycode, int x, int y, void *param);
void	ft_error(int i);
void	atoi_dimentionelle(char str, t_tri *lst);
void	print_ligne(t_tri *lst);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llefevre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/21 15:34:06 by llefevre          #+#    #+#             */
/*   Updated: 2017/09/05 21:33:28 by llefevre         ###   ########.fr       */
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
# define BUFSIZE 2000048
# define MIN 1 
# define NEG -5
# define MID 5
# define MAX 10


struct				s_li
{

	long int	i;
	long int	x;
	long int	y;
	long int	dx;
	long int	dy;
	long int	cx;
	long int	cy;
	long int	somme;
};
typedef struct		 s_li	t_li;

struct				s_str
{
	long int	i;
	long int	j;
	long int	k;
	long int	w;
};
typedef struct		 s_str	t_str;

struct				s_strc
{
	long int	i;
	long int	jb;
	long int	neg;
	long int	c;
	long int	w;
	long int	res;
	char		*coloris;
};
typedef struct		 s_strc	t_strc;

struct				s_pla
{
	long int		space;
	long int		colone;
	long int		p;
	long int		rest_ligne;
	long int		x2;
	long int		y2;
	long int		x3;
	long int 		y3;
	long int		z3;
	long int		color_swap;
	long int		swap;
};
typedef struct		 s_pla	t_pla;

struct				s_tri
{
	void		*mlx;
	void		*win;
	void		*win2;
	void		*pt_img;
	unsigned int			*img;
	void		*interface;
	int			*interface_i;
	char		*input;
	long int	color;
	long int	swap_color;
	int			lon;
	long int	centrex;
	long int	centrey;
	long int	zoom;
	long int	nbr_p;
	long int	haut;
	long int	droite;
	long int	xp;
	long int	yp;
	long int	xs;
	long int	ys;
	long int	egal;
	long int	colonebis;
	long int	spacebis;
	long int	htab;
	long int	ltab;
	long int	reste;
	long double		z;
	long double	max_z;
	long int	bra;
	long int	rotaz;
	long int	rotay;
	long int	rotax;
	long int	s_rota;
	long double	**tab;
	long int	t1;
	long int	t2;
};
typedef struct		 s_tri	t_tri;

void	ligne_setup(t_pla *s, t_tri *l);
int		put_mousse_echap(int key, int x, int y, t_tri *lst);
void	auto_size(t_tri *lst);
void	auto_size_z(t_tri *lst);
void	next_marge(t_tri *lst);
void	last_marge(t_tri *lst);
void	suite_marge(t_tri *lst);
void	last_affiche(int keycode, t_tri *lst);
void	next_affiche(int keycode, t_tri *lst);
void	suite_affiche(int keycode, t_tri *lst, long int i, long int end);
void	norme_main(t_tri *lst, int *trash1, int *trash2, int *trash3);
void	positif(t_li *l, t_tri *lst);
void	negatif(t_li *l, t_tri *lst);
void	print(t_pla *s, t_tri *l, int c);
void	put_mousse_next(int key, int x, int y, t_tri *lst);
void	while_strlen(char *str, t_tri *lst, t_str *s);
void	color(char *str, t_tri *l, t_strc *s);
void	number(char *str, t_tri *l, t_strc *s);
void	hauteur_couleur(t_pla *s, t_tri *l);
void	couleur_et_ligne(t_pla *s, t_tri *l);
void	post_reset(t_pla *s, t_tri *l);
void	couleur_rota(t_pla *s, t_tri *l);
void	a_la_ligne(t_pla *s, t_tri *l);
void	couleur_et_ligne(t_pla *s, t_tri *l);
void    ligne_d(t_pla *s, t_tri *l);
void    ligne_h(t_pla *s, t_tri *l);
void    ligne_p(t_pla *s, t_tri *l);
void	crea_tab(t_tri *lst);
double	ft_pow(double x,double y);
void	ft_convert(char *hex, int i, long *sum);
long	ft_htoi(char *hex);
int		put_cub_bis(int x, int y, t_tri *lst);
void	affiche_marge(t_tri *lst);
int		tri(t_tri *lst);
void	full_tab(t_tri *lst);
void	ft_strlen_custom1(char *str, t_tri *lst);
void	ft_strlen_custom2(char *str, t_tri *lst);
void	affiche_cub(int keycode, t_tri *lst);
char	*ft_read(char *av);
int		put_cub(long int x, long int y, t_tri *lst);
int		my_key_funct(int keycode, void *param);
int		put_mousse(int	keycode, int x, int y, void *param);
void	ft_error(int i);
void	atoi_dimentionelle(char str, t_tri *lst);
void	print_ligne(t_tri *lst);
void	rotation(t_pla *s,t_tri *lst);
void	rotationx(t_pla *s, t_tri *lst);
void	rotationy(t_pla *s, t_tri *lst);
void	rotationz(t_pla *s, t_tri *lst);

#endif

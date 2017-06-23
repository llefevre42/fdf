/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   placement.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llefevre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 21:59:28 by llefevre          #+#    #+#             */
/*   Updated: 2017/06/23 08:18:47 by llefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	couleur_et_ligne(t_pla *s, t_tri *l)
{
	s->colone -= (l->tab[s->p][3] * l->z);
	l->tab[s->p][1] = s->space;
	l->tab[s->p][2] = s->colone;
	l->xs = s->space;
	l->ys = s->colone;
	if (l->tab[s->p][4] != -1 && l->color != 0)
		l->color = l->tab[s->p][4];
	if (l->tab[s->p][4] == -1 && l->color != 0)
		hauteur_couleur(s, l);
	if ((s->space > 0 && s->space < 2000) && (s->colone > 0 \
			&& s->colone < 1200))
		put_cub(s->space, s->colone, l);
	if (s->p >= 1 && l->tab[s->p - 1][0] != 0  \
			&& s->p - 1 != (l->ltab * s->rest_ligne) - 1)
		ligne_p(s, l);
	if (s->p >= l->ltab && l->tab[s->p - l->ltab][0] != 0)
		ligne_h(s, l);
	if (s->p >= l->ltab + 1 && l->tab[s->p - l->ltab - 1][0] != 0 \
			&& s->p - l->ltab - 1 != (l->ltab * s->rest_ligne) - l->ltab - 1)
		ligne_d(s, l);
	l->tab[s->p][0] = 1;
	s->colone += (l->tab[s->p][3] * l->z);
}

void	post_reset(t_pla *s, t_tri *l)
{
	if (l->s_rota != 0)
	{
		s->space = s->x3;
		s->colone = s->y3;
		l->tab[s->p][3] = s->z3;
	}
	s->p++;
	l->xp = s->space;
	l->yp = s->colone;
	s->space += l->zoom;
	l->color = s->swap;
}

void	couleur_rota(t_pla *s, t_tri *l)
{
	if (l->s_rota != 0)
	{
		s->x3 = s->space;
		s->y3 = s->colone;
		s->z3 = l->tab[s->p][3];
		rotation(s, l);
	}
}

void	a_la_ligne(t_pla *s, t_tri *l)
{
	if (s->p == (l->ltab * s->rest_ligne) + l->ltab)
	{
		s->colone += l->zoom;
		s->space = l->droite - (l->centrex * l->zoom);
		s->rest_ligne++;
		s->p = l->ltab * s->rest_ligne;
	}
}

int		tri(t_tri *lst)
{
	t_pla s;

	s.p = 0;
	s.rest_ligne = 0;
	s.space = lst->droite - (lst->centrex * lst->zoom);
	s.colone = lst->haut - (lst->centrey * lst->zoom);
	lst->lon = 1;
	lst->xp = s.space;
	lst->yp = s.colone;
	s.swap = lst->color;
	while (s.p < lst->nbr_p)
	{
		a_la_ligne(&s, lst);
		couleur_rota(&s, lst);
		couleur_et_ligne(&s, lst);
		post_reset(&s, lst);
	}
	mlx_put_image_to_window(lst->mlx, lst->win, lst->pt_img, 0, 0);
	return (0);
}

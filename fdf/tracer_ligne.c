/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tracer_ligne.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llefevre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/18 17:51:19 by llefevre          #+#    #+#             */
/*   Updated: 2017/07/12 15:29:10 by llefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	hauteur_couleur(t_pla *s, t_tri *l)
{
	if (l->tab[s->p][3] >= MID && l->tab[s->p][3] < MAX)
		l->color /= 2;
	if (l->tab[s->p][3] >= MAX)
		l->color /= 6;
	if (l->tab[s->p][3] >= NEG && l->tab[s->p][3] < MIN)
		l->color /= 9;
	if (l->tab[s->p][3] < MIN)
		l->color /= 11;
}

void	print(t_pla *s, t_tri *l, int c)
{
	l->color /= c;
	print_ligne(l);
	l->color *= c;
}

void	ligne_p(t_pla *s, t_tri *l)
{
	l->xp = l->tab[s->p - 1][1];
	l->yp = l->tab[s->p - 1][2];
	if (l->tab[s->p - 1][4] != -1 && l->color != 0)
		l->color = l->tab[s->p - 1][4];
	print_ligne(l);
}

void	ligne_h(t_pla *s, t_tri *l)
{
	l->xp = l->tab[s->p - l->ltab][1];
	l->yp = l->tab[s->p - l->ltab][2];
	if (l->tab[s->p - l->ltab][4] != -1 && l->color != 0)
		l->color = l->tab[s->p - l->ltab][4];
	print_ligne(l);
}

void	ligne_d(t_pla *s, t_tri *l)
{
	l->xp = l->tab[s->p - l->ltab - 1][1];
	l->yp = l->tab[s->p - l->ltab - 1][2];
	if (l->tab[s->p - l->ltab - 1][4] != -1 && l->color != 0)
		l->color = l->tab[s->p - l->ltab - 1][4];
	print_ligne(l);
}

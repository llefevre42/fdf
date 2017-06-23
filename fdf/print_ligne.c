/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ligne.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llefevre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 21:57:19 by llefevre          #+#    #+#             */
/*   Updated: 2017/06/23 10:08:59 by llefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

long int	ft_abs(long int nbr)
{
	if (nbr < 0)
		nbr *= -1;
	return (nbr);
}

void		positif(t_li *l, t_tri *lst)
{
	l->somme = l->dx / 2;
	l->i = 1;
	while (l->i <= l->dx)
	{
		l->x += l->cx;
		l->somme += l->dy;
		if (l->somme >= l->dx)
		{
			l->somme -= l->dx;
			l->y += l->cy;
		}
		if ((l->x < 2000 && l->x > 0) && (l->y < 1200 && l->y > 0))
			put_cub(l->x, l->y, lst);
		l->i++;
	}
}

void		negatif(t_li *l, t_tri *lst)
{
	l->somme = l->dy / 2;
	l->i = 1;
	while (l->i <= l->dy)
	{
		l->y += l->cy;
		l->somme += l->dx;
		if (l->somme >= l->dy)
		{
			l->somme -= l->dy;
			l->x += l->cx;
		}
		if ((l->x < 2000 && l->x > 0) && (l->y < 1200 && l->y > 0))
			put_cub(l->x, l->y, lst);
		l->i++;
	}
}

void		print_ligne(t_tri *lst)
{
	t_li	l;

	l.x = lst->xp;
	l.y = lst->yp;
	l.dx = lst->xs - lst->xp;
	l.dy = lst->ys - lst->yp;
	l.cx = (l.dx > 0) ? 1 : -1;
	l.cy = (l.dy > 0) ? 1 : -1;
	l.dx = ft_abs(l.dx);
	l.dy = ft_abs(l.dy);
	if (l.dx > l.dy)
		positif(&l, lst);
	else
		negatif(&l, lst);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ligne.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llefevre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 21:57:19 by llefevre          #+#    #+#             */
/*   Updated: 2017/06/09 18:07:45 by llefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_ligne(t_tri *lst)
{
	int i;
	int x;
	int y;
	int	dx;
	int dy;
	int cx;
	int cy;
	int	somme;

	x = lst->xp;
	y = lst->yp;
	dx = lst->xs - lst->xp;
	dy = lst->ys - lst->yp;
	cx = (dx > 0 ) ? 1 : -1;
	cy = (dy > 0 ) ? 1 : -1;
	dx = abs(dx);
	dy = abs(dy);
	if (dx > dy)
	{
		somme = dx / 2 ;
		i = 1;
		while (i <= dx)
		{
			x += cx ;
			somme += dy ;
			if (somme >= dx)
			{
				somme -= dx;
				y += cy;
			}
//			if((x < 1000 && x > 0) && (y < 1000 && y > 0))
				put_cub(x, y, lst);
			i++;
		}
	}
	else
	{
		somme = dy / 2 ;
		i = 1;
		while(i <= dy)
		{
			y += cy ;
			somme += dx;
			if (somme >= dy)
			{
				somme -= dy;
				x += cx;
			}
//			if((x < 1000 && x > 0) && (y < 1000 && y > 0))
				put_cub(x, y, lst);
			i++;
		}
	}
}


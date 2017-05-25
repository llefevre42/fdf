/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parthing_fdf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llefevre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/21 15:37:41 by llefevre          #+#    #+#             */
/*   Updated: 2017/05/25 23:25:05 by llefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

int		put_cub(int x, int y, t_tri *lst);

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
//	put_cub(x, y, lst);
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
			put_cub(x, y, lst);
			i++;
		} 
	}
}
	
void	centrage(char *str, t_tri *lst)
{
	int		i;

	lst->centrex = 0;
	lst->centrey = 0;
	i = 0;
	while(str[i++] != '\n')
		if(str[i] != ' ')
			lst->centrex++;
	i = 0;
	while(str[i++] != '\0')
		if(str[i] == '\n')
			lst->centrey++;
	lst->centrey++;
	lst->centrex /= 2;
	lst->centrey /= 2;
}


int		tri(char *str, t_tri *lst)
{
	int		i;
	int		space;
	int		colone;
	int		j;

	j = 0;
	space = lst->droite - (lst->centrex * 10) - (lst->centrex * (5 * lst->nbr_zoom));
	colone = lst->haut - (lst->centrey * 10) - (lst->centrey * (5 * lst->nbr_zoom));
	lst->lon = 1;
	i = 0;
	lst->xp = space;
	lst->yp = colone;
	while(str[i] != '\0')
	{
		while(str[i] == ' ' || str[i] == '\n')
		{
			j++;
			if(str[i] == '\n')
			{
				j = 0;
				colone += lst->zoom;
				space = lst->droite - (lst->centrex * 10) - (lst->centrex * (5 * lst->nbr_zoom));
			}
			i++;
		}
		if(str[i] >= 48 && str[i] <= 57)
		{
			if( j  >= 2 && j <= 5)
				colone -= 5;
			if( j  >= 5 && j <= 8)
				colone += 5;
			lst->xs = space;
			lst->ys = colone;
			printf("%d	%d	%d	%d\n", lst->xp, lst->yp, lst->xs, lst->ys);
			if(str[i - 1] != '\n')
				print_ligne(lst);
			put_cub(space , colone, lst);
		}
		lst->xp = space;
		lst->yp = colone;
		space += lst->zoom;
		i++;
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parthing_fdf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llefevre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/21 15:37:41 by llefevre          #+#    #+#             */
/*   Updated: 2017/06/02 20:56:33 by llefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

int		put_cub(int x, int y, t_tri *lst);

void	ft_strlen_custom(char *str, t_tri *lst);

void	full_tab(t_tri *lst, int ***tab)
{
	int k;
	int i;

	k = 0;
	i = 0;
	i = lst->hauttab * lst->largtab;
	while(k < i)
	{
		tab[0][k][0] = 0;
		tab[0][k][1] = 0;
		tab[0][k][2] = 0;
		k++;
	}
}

void	atoi_dimentionelle(char str, t_tri *lst)
{
	lst->egal *= 10;
	lst->egal += (int)str - '0';
}

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


int		tri(char *str, t_tri *lst, int ***tab)
{
	int		i;
	int		space;
	int		colone;
	int		neg;
	int		ptab;
	int		rest_ligne;

	ptab = 0;
	rest_ligne = 0;
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
			if(str[i] == '\n')
			{
				colone += lst->zoom;
				space = lst->droite - (lst->centrex * 10) - (lst->centrex * (5 * lst->nbr_zoom));
				rest_ligne++;
				ptab = lst->largtab * rest_ligne;
				printf("ligne + 1");
			}
			i++;
		}
		if((str[i] >= 48 && str[i] <= 57) || str[i] == 45)
		{
			if(str[i] == 45)
			{
				neg = 1;
				i++;
			}
			while(str[i] >= 48 && str[i] <= 57)
			{
				atoi_dimentionelle(str[i], lst);
				i++;
			}
			i--;
			if(lst->egal != 0)
				colone -= (lst->egal * lst->z);
			tab[0][ptab][1] = space;
			tab[0][ptab][2] = colone;
			lst->xs = space;
			lst->ys = colone;
			put_cub(space , colone, lst);
			if(ptab >= 1 && (tab[0][ptab - 1][0] != 0 && str[i - 1] != '\n'))
			{
				lst->xp = tab[0][ptab - 1][1];
				lst->yp = tab[0][ptab - 1][2];
				print_ligne(lst);
			}
			if(ptab >= lst->largtab && tab[0][ptab - lst->largtab][0] != 0)
			{
				lst->xp = tab[0][ptab - lst->largtab][1];
				lst->yp = tab[0][ptab - lst->largtab][2];
				print_ligne(lst);
			}
			tab[0][ptab][0] = 1;
			ptab++;
			if(lst->egal != 0)				
				colone += (lst->egal * lst->z);
		}
		lst->xp = space;
		lst->yp = colone;
		space += lst->zoom;	
		neg = 0;
		lst->egal = 0;
		i++;
	}
	return (0);
}

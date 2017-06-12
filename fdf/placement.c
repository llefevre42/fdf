/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   placement.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llefevre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 21:59:28 by llefevre          #+#    #+#             */
/*   Updated: 2017/06/10 22:33:15 by llefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	atoi_dimentionelle(char str, t_tri *lst)
{
	lst->egal *= 10;
	lst->egal += (int)str - '0';
}

int		tri(char *str, t_tri *lst, int ***tab)
{
	char	*coloris;
	int		i;
	int		space;
	int		colone;
	int		neg;
	int		ptab;
	int		rest_ligne;
	int		c;
	int		w;
	int		p;
	int		x2;
	int		y2;
	int		x3;
	int 	y3;
	long int	color_swap;
	long int	swap;
	
	p = 0;
	c = 0;
	w = 0;
	ptab = 0;
	rest_ligne = 0;
	space = lst->droite - (lst->centrex * lst->zoom);
	colone = lst->haut - (lst->centrey * lst->zoom);
	lst->lon = 1;
	i = 0;
	lst->xp = space;
	lst->yp = colone;
	swap = lst->color;
	if(!(coloris = malloc(sizeof(char) * (6 + 1))))
		return (0);
	while(str[i] != '\0')
	{
		color_swap = 0;
		w = 0;
		while(str[i] == ' ' || str[i] == '\n')
		{
			if(str[i] == '\n')
			{
				colone += lst->zoom;
				space = lst->droite - (lst->centrex * lst->zoom);
				rest_ligne++;
				ptab = lst->largtab * rest_ligne;
			}
			i++;
		}
		p = i;
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
			if(str[i] == ',')
			{
				i += 3;
				c = i;
				while((str[i] >= '0' && str[i] <= '9') || (str[i] >= 'A' && str[i] <= 'F'))
					i++;
				while(c < i)
				{
					coloris[w] = str[c];
					c++;
					w++;
				}
				coloris[w] = '\0';
				color_swap = ft_htoi(coloris) - 1;
				ft_strclr(coloris);
			}
			if(color_swap != 0 && lst->color != 0)
				lst->color = color_swap;
			i--;
/*			if(lst->egal != 0)
			{
				if(neg == 1)
					colone += (lst->egal * lst->z);
				else
					colone -= (lst->egal * lst->z);
			}
*/			if(lst->rota != 0)
			{
				x3 = space;
				y3 = colone;
/*				space = lst->droite - (lst->centrex * lst->zoom);
				colone = lst->haut - (lst->centrey * lst->zoom);
*/				x2 = 1000 + (space * cos(lst->rota * 0.0174533) - colone * sin(lst->rota * 0.0174533));
				y2 = 600 + (space * sin(lst->rota * 0.0174533) + colone * cos(lst->rota * 0.0174533));
				space = x2;
				colone = y2;

				printf("%d %d\n", x2, y2);
			}
			if(lst->egal != 0)
			{
				if(neg == 1)
					colone += (lst->egal * lst->z);
				else
					colone -= (lst->egal * lst->z);
			}
			tab[0][ptab][1] = space;
			tab[0][ptab][2] = colone;
			lst->xs = space;
			lst->ys = colone;
//			if(ptab >= lst->largtab + 1 && tab[0][ptab - lst->largtab - 1][0] != 0 && str[p - 1] != '\n')
//				face_cache(tab[0][ptab - lst->largtab - 1][1] + 1, tab[0][ptab - lst->largtab - 1][2] + 1, space - tab[0][ptab - lst->largtab - 1][1] - 1, colone - tab[0][ptab - lst->largtab - 1][2] - 1, lst , 0);
//			if((space < 1000 && space > 0) && (colone < 1000 && colone > 0))
				put_cub(space , colone, lst);
			if(ptab >= 1 && (tab[0][ptab - 1][0] != 0 && str[p - 1] != '\n'))
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
			if(ptab >= lst->largtab + 1 && tab[0][ptab - lst->largtab - 1][0] != 0 && str[p - 1] != '\n')
			{
				lst->xp = tab[0][ptab - lst->largtab - 1][1];
				lst->yp = tab[0][ptab - lst->largtab - 1][2];
				print_ligne(lst);
			}
			tab[0][ptab][0] = 1;
			ptab++;
			if(lst->egal != 0)
			{
				if(neg == 1)
					colone -= (lst->egal * lst->z);
				else
					colone += (lst->egal * lst->z);
			}
			if(lst->rota != 0)
			{
				space = x3;
				colone = y3;
			}
			lst->xp = space;
			lst->yp = colone;
			space += lst->zoom;
			neg = 0;
			lst->egal = 0;
			lst->color = swap;
		}
		i++;
	}
	return (0);
}

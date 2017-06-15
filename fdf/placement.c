/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   placement.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llefevre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 21:59:28 by llefevre          #+#    #+#             */
/*   Updated: 2017/06/15 19:11:58 by llefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	atoi_dimentionelle(char str, t_tri *lst)
{
	lst->egal *= 10;
	lst->egal += (int)str - '0';
}

int		tri(char *str, t_tri *lst)
{
	long int		space;
	long int		colone;
	long int		ptab;
	long int		rest_ligne;
	long int		x2;
	long int		y2;
	long int		x3;
	long int 		y3;
	long int		color_swap;
	long int		swap;

	ptab = 0;
	rest_ligne = 0;
	space = lst->droite - (lst->centrex * lst->zoom);
	colone = lst->haut - (lst->centrey * lst->zoom);
	lst->lon = 1;
	lst->xp = space;
	lst->yp = colone;
	swap = lst->color;
	while(ptab < lst->largtab * lst->hauttab)
	{
			printf("PO\n");
		color_swap = 0;
		if(ptab == (lst->largtab * rest_ligne) + lst->largtab)
		{
			colone += lst->zoom;
			space = lst->droite - (lst->centrex * lst->zoom);
			rest_ligne++;
			ptab = lst->largtab * rest_ligne;
		}
			printf("PW\n");
			if(color_swap != 0 && lst->color != 0)
				lst->color = color_swap;
			printf("Pu\n");

/*			if(lst->rota != 0)
			{
				x3 = space;
				y3 = colone;
				space = lst->droite - (lst->centrex * lst->zoom);
				colone = lst->haut - (lst->centrey * lst->zoom);
				x2 = 1000 + (space * cos(lst->rota * 0.0174533) - colone * sin(lst->rota * 0.0174533));
				y2 = 600 + (space * sin(lst->rota * 0.0174533) + colone * cos(lst->rota * 0.0174533));
				space = x2;
				colone = y2;
			}
*/
			printf("1- %p\n" ,lst);
			printf("2- %p\n" ,lst->tab);
			printf("3- %p\n" ,lst->tab[ptab]);
			printf("4- %ld\n" ,lst->tab[ptab][0]);
			if (lst)
			{
			  printf("a ");
			  if (lst->tab)
			    {
			      printf("b ");
			      if (lst->tab[ptab])
				{
				  printf("c %ld\n", ptab);  
				}
			    }
			}
			colone -= (lst->tab[ptab][3] * lst->z);
			printf("AH\n");
			lst->tab[ptab][1] = space;
			lst->tab[ptab][2] = colone;
			lst->xs = space;
			lst->ys = colone;
			printf("0H\n");
			if(lst->tab[ptab][4] != -1 && lst->color != 0)
				lst->color = lst->tab[ptab][4];
			if((space >= 0 && space <= 2000) && (colone >= 0 && colone <= 1200))
				put_cub(space , colone, lst);
			if(ptab >= 1 && lst->tab[ptab - 1][0] != 0 && ptab - 1 != (lst->largtab * rest_ligne) - 1)
			{
				lst->xp = lst->tab[ptab - 1][1];
				lst->yp = lst->tab[ptab - 1][2];
				if(lst->tab[ptab - 1][4] != -1 && lst->color != 0)
					lst->color = lst->tab[ptab - 1][4];
				print_ligne(lst);
			}
			if(ptab >= lst->largtab && lst->tab[ptab - lst->largtab][0] != 0)
			{
				lst->xp = lst->tab[ptab - lst->largtab][1];
				lst->yp = lst->tab[ptab - lst->largtab][2];
				if(lst->tab[ptab - lst->largtab][4] != -1 && lst->color != 0)
					lst->color = lst->tab[ptab - lst->largtab][4];
				print_ligne(lst);
			}
			if(ptab >= lst->largtab + 1 && lst->tab[ptab - lst->largtab - 1][0] != 0 && ptab - lst->largtab - 1 != (lst->largtab * rest_ligne) - lst->largtab - 1)
			{
				lst->xp = lst->tab[ptab - lst->largtab - 1][1];
				lst->yp = lst->tab[ptab - lst->largtab - 1][2];
				if(lst->tab[ptab - lst->largtab - 1][4] != -1 && lst->color != 0)
					lst->color = lst->tab[ptab - lst->largtab - 1][4];
				print_ligne(lst);
			}
			printf("IH\n");
			lst->tab[ptab][0] = 1;
			colone += (lst->tab[ptab][3] * lst->z);
			printf("YH\n");
			ptab++;
/*			if(lst->rota != 0)
			{
				space = x3;
				colone = y3;
			}
*/			lst->xp = space;
			lst->yp = colone;
			space += lst->zoom;
			lst->color = swap;
			printf("PH\n");
	}
	mlx_put_image_to_window(lst->mlx, lst->win, lst->pt_img, 0, 0);
	return (0);
}

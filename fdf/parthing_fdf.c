/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parthing_fdf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llefevre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/21 15:37:41 by llefevre          #+#    #+#             */
/*   Updated: 2017/05/23 15:22:19 by llefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

int		put_cub(int x, int y, t_tri *lst);

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

	space = lst->droite - (lst->centrex * 10) - (lst->centrex * (5 * lst->nbr_zoom));
	colone = lst->haut - (lst->centrey * 10) - (lst->centrey * (5 * lst->nbr_zoom));
	lst->lon = 1;
	lst->color = 0X00FF00;
	i = 0;
	while(str[i] != '\0')
	{
		while(str[i] == ' ' || str[i] == '\n')
		{
			if(str[i] == '\n')
			{
				colone += lst->zoom;
				space = lst->droite - (lst->centrex * 10) - (lst->centrex * (5 * lst->nbr_zoom));
			}
			i++;
		}
		if(str[i] >= 48 && str[i] <= 57)
			put_cub(space , colone, lst);
		space += lst->zoom;	
		i++;
	}
	return (0);
}

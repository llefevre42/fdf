/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_mousse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llefevre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 21:50:43 by llefevre          #+#    #+#             */
/*   Updated: 2017/06/15 16:01:35 by llefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		put_mousse(int	keycode, int x, int y, void *param)
{
	t_tri *lst;
	int swap;
	lst = ((t_tri *)param);
	swap = lst->color;
	lst->color = 0X000000;
	tri(lst->input, lst);
	lst->color = swap;
	printf("mousse %d (%d:%d)\n",keycode ,x ,y);
	lst->lon = 10;
	if((x >= 225 && x <= 475) && (y >= 505 && y <= 605))
	{
		lst->color = 0X3A8EBA;
		affiche_cub(0, lst);
	}
	if((x >= 20 && x <= 245) && (y >= 505 && y <= 605))
	{
		lst->color = 0XFF0000;
		affiche_cub(0, lst);
	}
	if((x >= 225 && x <= 470) && (y >= 400 && y <= 500))
	{
		lst->color = 0XFFFF00;
		affiche_cub(0, lst);
	}
	if((x >= 20 && x <= 245) && (y >= 400 && y <= 500))
	{
		lst->color = 0X00FF00;
		affiche_cub(0, lst);
	}
	if((x >= 70 && x <= 120) && (y >= 170 && y <= 220))
	{
		lst->zoom += 5;
		lst->nbr_zoom++;
		affiche_cub(0, lst);
	}
	if((x >= 130 && x <= 180) && (y >= 170 && y <= 220))
	{
		lst->zoom -= 5;
		lst->nbr_zoom++;
		affiche_cub(0, lst);

	}
	if((x >= 320 && x <= 370) && (y >= 170 && y <= 220))
	{
		lst->z += 1;
		affiche_cub(0, lst);
	}
	if((x >= 380 && x <= 430) && (y >= 170 && y <= 220))
	{
		lst->z -= 1;
		affiche_cub(0, lst);
	}
	if((x >= 220 && x <= 270) && (y >= 270 && y <= 320))
	{
		lst->haut -= 10;
		affiche_cub(0, lst);
	}
	if((x >= 220 && x <= 270) && (y >= 330 && y <= 380))
	{
		lst->haut += 10;
		affiche_cub(0, lst);
	}
	if((x >= 160 && x <= 210) && (y >= 330 && y <= 380))
	{
		lst->droite -= 10;
		affiche_cub(0, lst);
	}
	if((x >= 280 && x <= 330) && (y >= 300 && y <= 380))
	{
		lst->droite += 10;
		affiche_cub(0, lst);
	}
	/*	if(keycode == 1)
		{
		lst->color = 0XFF0000;
		put_cub(x, y, lst);
		}
		if(keycode == 2)
		{
		lst->color = 0X00FF00;
		put_cub(x, y, lst);
		}
		if(keycode == 3)
		{
		lst->color = 0X0000FF;
		put_cub(x, y, lst);
		}
		*/	return (0);
}

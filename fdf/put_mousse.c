/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_mousse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llefevre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 21:50:43 by llefevre          #+#    #+#             */
/*   Updated: 2017/10/06 23:42:43 by llefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		put_mousse(int keycode, int x, int y, void *param)
{
	t_tri	*lst;
	int		key;

	key = 0;
	lst = ((t_tri *)param);
	if ((x >= 225 && x <= 475) && (y >= 505 && y <= 605))
		lst->color = 0X3A8EBA;
	if ((x >= 20 && x <= 245) && (y >= 505 && y <= 605))
		lst->color = 0XFF0000;
	if ((x >= 225 && x <= 470) && (y >= 400 && y <= 500))
		lst->color = 0XFFFF00;
	if ((x >= 20 && x <= 245) && (y >= 400 && y <= 500))
		lst->color = 0X00FF00;
	if ((x >= 70 && x <= 120) && (y >= 170 && y <= 220))
		key = 87;
	if ((x >= 130 && x <= 180) && (y >= 170 && y <= 220))
		key = 84;
	if ((x >= 320 && x <= 370) && (y >= 170 && y <= 220))
		key = 86;
	if ((x >= 380 && x <= 430) && (y >= 170 && y <= 220))
		key = 83;
	put_mousse_next(key, x, y, lst);
	return (0);
}

void	put_mousse_next(int key, int x, int y, t_tri *lst)
{
	if ((x >= 220 && x <= 270) && (y >= 270 && y <= 320))
		key = 126;
	if ((x >= 220 && x <= 270) && (y >= 330 && y <= 380))
		key = 125;
	if ((x >= 160 && x <= 210) && (y >= 330 && y <= 380))
		key = 123;
	if ((x >= 280 && x <= 330) && (y >= 300 && y <= 380))
		key = 124;
	if ((x >= 20 && x <= 40) && (y >= 20 && y <= 40))
		exit(1);
	if ((x >= 220 && x <= 270) && (y >= 700 && y <= 750))
		key = 35;
	if ((x >= 220 && x <= 270) && (y >= 760 && y <= 810))
		key = 41;
	if ((x >= 120 && x <= 170) && (y >= 700 && y <= 750))
		key = 31;
	if ((x >= 120 && x <= 170) && (y >= 760 && y <= 810))
		key = 37;
	if ((x >= 320 && x <= 370) && (y >= 700 && y <= 750))
		key = 34;
	if ((x >= 320 && x <= 370) && (y >= 760 && y <= 810))
		key = 40;
	if ((x >= 445 && x <= 465) && (y >= 20 && y <= 40))
		key = 65;
	affiche_cub(key, lst);
}

int		put_mousse_echap(int key, int x, int y, t_tri *lst)
{
	if ((x >= 0 && x <= 30) && (y >= -30 && y <= 0))
		exit(1);
	return (0);
}

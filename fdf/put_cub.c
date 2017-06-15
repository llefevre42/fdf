/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_cub.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llefevre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 21:52:08 by llefevre          #+#    #+#             */
/*   Updated: 2017/06/15 18:30:11 by llefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		put_cub(int x, int y, t_tri *lst)
{
	int x1;
	int y1;

	y1 = y;
	x1 = x;
	while (y < y1 + 1)
	{
		x = x1;
		while(x < x1 + 1)
		{
//			mlx_pixel_put(lst->mlx, lst->win, x, y, lst->color);
			lst->img[x + ((y - 1) * 2000)] = lst->color;
			x++;
		}
		y++;
	}
	return (0);
}

int		put_cub_bis(int x, int y, int yp, int xp, t_tri *lst)
{
	int x1;
	int y1;

	y1 = y;
	x1 = x;
	while (y < y1 + yp)
	{
		x = x1;
		while(x < x1 + xp)
		{
			mlx_pixel_put(lst->mlx, lst->win2, x, y, lst->color);
			x++;
		}
		y++;
	}
	return (0);
}

int		face_cache(int x, int y, int yp, int xp, t_tri *lst, int color)
{
	int x1;
	int y1;

	y1 = y;
	x1 = x;
	while (y < y1 + yp)
	{
		x = x1;
		while(x < x1 + xp)
		{
			mlx_pixel_put(lst->mlx, lst->win, x, y, color);
			x++;
		}
		y++;
	}
	return (0);
}

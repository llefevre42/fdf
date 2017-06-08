/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_mousse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llefevre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 21:50:43 by llefevre          #+#    #+#             */
/*   Updated: 2017/06/02 21:51:06 by llefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		put_mousse(int	keycode, int x, int y, void *param)
{
	t_tri *lst;
	lst = ((t_tri *)param);
	lst->color = 0X00FF00;
	printf("mousse %d (%d:%d)\n",keycode ,x ,y);
	lst->lon = 10;
	if(keycode == 1)
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
	return (0);
}

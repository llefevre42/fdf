/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_cube.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llefevre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 18:30:35 by llefevre          #+#    #+#             */
/*   Updated: 2017/05/21 15:32:17 by llefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "mlx.h"
#include "put_cub.h"
int		put_cub(int x, int y, void *param)
{
	int x1;
	int y1;

	t_tri lst;
	lst = *((t_tri *)param);

	printf("mousse (%d:%d)\n",x ,y);
	y1 = y;
	x1 = x;
	while (y < y1 + lst.lon)
	{
		x = x1;
		while(x < x1 + lst.lon)
		{
			printf("(%d:%d)\n",x1 ,y1);
			printf("(%d:%d)\n",x ,y);
			mlx_pixel_put(lst.mlx, lst.win, x, y, lst.color);
			x++;
		}
		y++;
	}
	return (0);
}

int		my_key_funct(int keycode, void *param)
{
	int x;
	int y;
	t_tri lst;

	x = 0;
	y = 0;
	lst = *((t_tri *)param);
	lst.lon = keycode;
	printf("keycode : %d\n", keycode);
	if(keycode == 25)
	{
		lst.color = 0XFF0000;
		put_cub(x, y, &lst);
	}
	if(keycode == 18)
	{
		lst.color = 0X00FF00;
		put_cub(x, y, &lst);
	}
	if(keycode == 35)
	{
		lst.color = 0X0000FF;
		put_cub(x, y, &lst);
	}
	if(keycode == 53)
		exit(0);
	return (0);
}

int		put_mousse(int	keycode, int x, int y, void *param)
{
	t_tri lst;
	lst = *((t_tri *)param);
	lst.color = 0X00FF00;
	printf("mousse %d (%d:%d)\n",keycode ,x ,y);
	if(keycode == 1)
	{
		lst.color = 0XFF0000;
		put_cub(x, y, &lst);
	}
	if(keycode == 2)
	{
		lst.color = 0X00FF00;
		put_cub(x, y, &lst);
	}
	if(keycode == 3)
	{
		lst.color = 0X0000FF;
		put_cub(x, y, &lst);
	}
	return (0);
}
int		main(void)
{
	t_tri	lst;
	int		x;
	int		y;

	lst.lon = 20;
	lst.mlx = mlx_init();
	lst.win = mlx_new_window(lst.mlx, 1500, 1500, "yanma_mlx_42");
	mlx_key_hook(lst.win, my_key_funct, &lst);
	y = 0;
	while (y < 1500)
	{
		x = 0;
		while( x < 1500)
		{
			mlx_pixel_put(lst.mlx, lst.win, x, y, 0XFFFFFF);
			x++;
		}
		y++;
	}
	mlx_mouse_hook(lst.win, put_mousse, &lst);
	//	lst.pt_img = mlx_new_image(lst.mlx, x, y);
	//	lst.img =  mlx_get_data_addr(lst.pt_img, 32, 1600, 0);
	//	mlx_put_image_to_window(lst.mlx, lst.win, lst.pt_img, 0, 0);
	mlx_loop(lst.mlx);
	return (0);
}

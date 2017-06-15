/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   affiche_marge.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llefevre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/05 17:25:47 by llefevre          #+#    #+#             */
/*   Updated: 2017/06/15 15:56:05 by llefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	affiche_marge(t_tri *lst)
{
	int x;
	int y;
	int y1;
	int x1;
	int t;
	int l;
	int bit;
	int size;
	int	endian;

	bit = 50;
	size = 50;
	endian = 50;

	t = 50;
	l = 50;
	lst->color = 0X22427C;
	put_cub_bis(0, 0, 15, 500, lst);
	put_cub_bis(0, 0, 1000, 15, lst);
	put_cub_bis(485, 0, 1000, 15, lst);
	put_cub_bis(0, 985, 15, 500, lst);
	lst->color = 0XFFFFFF;
	put_cub_bis(150, 50, 60, 10, lst);	
	put_cub_bis(300, 50, 60, 10, lst);	
	put_cub_bis(250, 50, 60, 10, lst);	
	put_cub_bis(150, 50, 10, 40, lst);	
	put_cub_bis(300, 50, 10, 40, lst);	
	put_cub_bis(150, 70, 10, 25, lst);	
	put_cub_bis(300, 70, 10, 25, lst);	
	put_cub_bis(220, 65, 10, 30, lst);	
	put_cub_bis(220, 100, 10, 30, lst);	
	put_cub_bis(220, 70, 40, 10, lst);	
	lst->color = 0X00FF00;
	put_cub_bis(20, 400, 100, 225, lst);	
	lst->color = 0XFF0000;
	put_cub_bis(20, 505, 100, 225, lst);	
	lst->color = 0XFFFF00;
	put_cub_bis(255, 400, 100, 225, lst);	
	lst->color = 0X3A8EBA;
	put_cub_bis(255, 505, 100, 225, lst);
	lst->color = 0XFFFFFF;
	mlx_string_put(lst->mlx, lst->win2, 70 , 140, 0X00FF00, "ZOOM +");
	put_cub_bis(70, 170, 50, 50, lst);
	mlx_string_put(lst->mlx, lst->win2, 130 , 140, 0X00FF00, "ZOOM -");
	put_cub_bis(130, 170, 50, 50, lst);
	mlx_string_put(lst->mlx, lst->win2, 330 , 140, 0X00FF00, "Z +");
	put_cub_bis(320, 170, 50, 50, lst);
	mlx_string_put(lst->mlx, lst->win2, 390 , 140, 0X00FF00, "Z -");
	put_cub_bis(380, 170, 50, 50, lst);
	
	mlx_string_put(lst->mlx, lst->win2, 200 , 240, 0X00FF00, "DIRECTION");
	put_cub_bis(220, 270, 50, 50, lst);
	put_cub_bis(220, 330, 50, 50, lst);
	put_cub_bis(160, 330, 50, 50, lst);
	put_cub_bis(280, 330, 50, 50, lst);
/*	printf("La\n");
	lst->color = 0XFF0000;
	y1 = y;			
	x1 = x;
	while (y < y1 + 1200)
	{
		x = x1;
		while(x < x1 + 1500)
		{
			mlx_pixel_put(lst->mlx, lst->win, x, y, lst->color);
			x++;
		}
		y++;
	}
	lst->interface = mlx_new_image(lst->mlx, 50, 50);
	printf("La\n");
	printf("%s\n", (char*)lst->interface);
	lst->interface_i = (int*)mlx_get_data_addr(lst->interface, &bit, &size, &endian);
	printf("La\n");
	for(int qwer = 0; qwer < 50; qwer++)
		lst->interface_i[qwer] = 0xFFFFFF;
	mlx_put_image_to_window(lst->mlx, lst->win, lst->interface_i, 50, 50); 
	printf("La\n");
*/}

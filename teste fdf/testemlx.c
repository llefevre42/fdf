/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testemlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llefevre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 13:25:55 by llefevre          #+#    #+#             */
/*   Updated: 2017/05/20 14:53:42 by llefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "mlx.h"
#include "yanma.h"


int		my_key_funct(int keycode, void *param)
{
	printf("%d\n",keycode);
	if(keycode == 53)
		exit(0);
	return (0);
}

int		my_mouse_funct(int keycode, int x, int y, void *param)
{
/*	int x2;
	int y2;
*/	printf("mousse %d (%d:%d)\n",keycode ,x ,y);
/*	x2 = x + 15;
	y2 = y + 15;
	while (y < y2)
	{
		while( x < x2)
		{
			mlx_pixel_put(mlx, win, x, y, 0X0000FF);
			x++;
		}
		y++;
	}
*/	return (0);
}


int		main(void)
{
	void	*mlx;
	void	*win;
	int		x;
	int		y;
	int 	lon;
	int		color;

	color = 0X00FF00;
	lon = 15;
	mlx = mlx_init();
	win = mlx_new_window(mlx, 1500, 1000, "yanma_mlx_42");
	y = lon * 0;
	while (y < 999)
	{
		x = 1;
		while( x < 1499)
		{
			mlx_pixel_put(mlx, win, x, y, color);
			x++;
		}
		y++;
	}
	y = lon * 0;
	while (y < lon * 1)
	{
		x = lon * 5;
		while( x < lon * 8)
		{
			mlx_pixel_put(mlx, win, x, y, 0X000000);
			x++;
		}
		y++;
	}
	y = lon * 0;
	while (y < lon * 1)
	{
		x = lon * 16;
		while( x < lon * 19)
		{
			mlx_pixel_put(mlx, win, x, y, 0X000000);
			x++;
		}
		y++;
	}																	//ligne 1
	y = lon * 1;
	while (y < lon * 2)
	{
		x = lon * 1;
		while( x < lon * 4)
		{
			mlx_pixel_put(mlx, win, x, y, 0X0000000);
			x++;
		}
		y++;
	}
	y = lon * 1;
	while (y < lon * 2)
	{
		x = lon * 5;
		while( x < lon * 7)
		{
			mlx_pixel_put(mlx, win, x, y, 0X000000);
			x++;
		}
		y++;
	}	
	y = lon * 1;
	while (y < lon * 2)
	{
		x = lon * 7;
		while( x < (lon * 8 ))
		{
			mlx_pixel_put(mlx, win, x, y, SHINEY);
			x++;
		}
		y++;
	}
	y = lon * 1;
	while (y < lon * 2)
	{
		x = lon * 8;
		while( x < lon * 10)
		{
			mlx_pixel_put(mlx, win, x, y, 0X000000);
			x++;
		}
		y++;
	}
	y = lon * 1;
	while (y < lon * 2)
	{
		x = lon * 16;
		while( x < lon * 17)
		{
			mlx_pixel_put(mlx, win, x, y, 0X000000);
			x++;
		}
		y++;
	}

	y = lon * 1;
	while (y < lon * 2)
	{
		x = lon * 17;
		while( x < lon * 19)
		{
			mlx_pixel_put(mlx, win, x, y, SHINEY);
			x++;
		}
		y++;
	}
	y = lon * 1;
	while (y < lon * 2)
	{
		x = lon * 19;
		while( x < lon * 23)
		{
			mlx_pixel_put(mlx, win, x, y, 0X000000);
			x++;
		}
		y++;
	}																		//l2
	y = lon * 2;
	while (y <  lon * 3)
	{
		x = lon * 0;
		while( x < lon * 1)
		{
			mlx_pixel_put(mlx, win, x, y, 0X000000);
			x++;
		}
		y++;
	}
	y = lon * 2;
	while (y < lon * 3)
	{
		x = lon * 3;
		while( x < lon * 4)
		{
			mlx_pixel_put(mlx, win, x, y, SHINEY);
			x++;
		}
		y++;
	}
	y = lon * 2;
	while (y < lon * 3)
	{
		x = lon * 4;
		while( x < lon * 6)
		{
			mlx_pixel_put(mlx, win, x, y, 0X000000);
			x++;
		}
		y++;
	}
	y = lon * 2;
	while (y < lon * 3)
	{
		x = lon * 6;
		while( x < lon * 7)
		{
			mlx_pixel_put(mlx, win, x, y, SHINEY);
			x++;
		}
		y++;
	}
	y = lon * 2;
	while (y < lon * 3)
	{
		x = lon * 7;
		while( x < lon * 8)
		{
			mlx_pixel_put(mlx, win, x, y, 0X000000);
			x++;
		}
		y++;
	}
	y = lon * 2;
	while (y < lon * 3)
	{
		x = lon * 9;
		while( x < lon * 11)
		{
			mlx_pixel_put(mlx, win, x, y, 0X000000);
			x++;
		}
		y++;
	}
	y = lon * 2;
	while (y < lon * 3)
	{
		x = lon * 17;
		while( x < lon * 20)
		{
			mlx_pixel_put(mlx, win, x, y, 0X000000);
			x++;
		}
		y++;
	}
	y = lon * 2;
	while (y < lon * 3)
	{
		x = lon * 20;
		while( x < lon * 22)
		{
			mlx_pixel_put(mlx, win, x, y, SHINEY);
			x++;
		}
		y++;
	}
	y = lon * 2;
	while (y < lon * 3)
	{
		x = lon * 22;
		while( x < lon * 24)
		{
			mlx_pixel_put(mlx, win, x, y, 0X000000);
			x++;
		}
		y++;
	}															//l3
	y = lon * 3;
	while (y < lon * 4)
	{
		x = lon * 1;
		while( x < lon * 2)
		{
			mlx_pixel_put(mlx, win, x, y, 0X000000);
			x++;
		}
		y++;
	}
	y = lon * 3;
	while (y < lon * 4)
	{
		x = lon * 2;
		while( x < lon * 5)
		{
			mlx_pixel_put(mlx, win, x, y, SHINEY);
			x++;
		}
		y++;
	}
	y = lon * 3;
	while (y < lon * 4)
	{
		x = lon * 5;
		while( x < lon * 6)
		{
			mlx_pixel_put(mlx, win, x, y, 0X000000);
			x++;
		}
		y++;
	}
	y = lon * 3;
	while (y < lon * 4)
	{
		x = lon * 6;
		while( x < lon * 7)
		{
			mlx_pixel_put(mlx, win, x, y, SHINEY);
			x++;
		}
		y++;
	}
	y = lon * 3;
	while (y < lon * 4)
	{
		x = lon * 7;
		while( x < lon * 9)
		{
			mlx_pixel_put(mlx, win, x, y, 0X000000);
			x++;
		}
		y++;
	}
	y = lon * 3;
	while (y < lon * 4)
	{
		x = lon * 9;
		while( x < lon * 10)
		{
			mlx_pixel_put(mlx, win, x, y, SHINEY);
			x++;
		}
		y++;
	}
	y = lon * 3;
	while (y < lon * 4)
	{
		x = lon * 10;
		while( x < lon * 13)
		{
			mlx_pixel_put(mlx, win, x, y, 0X000000);
			x++;
		}
		y++;
	}
	y = lon * 3;
	while (y < lon * 4)
	{
		x = lon * 16;
		while( x < lon * 18)
		{
			mlx_pixel_put(mlx, win, x, y, 0X000000);
			x++;
		}
		y++;
	}
	y = lon * 3;
	while (y < lon * 4)
	{
		x = lon * 18;
		while( x < lon * 20)
		{
			mlx_pixel_put(mlx, win, x, y, SHINEY);
			x++;
		}
		y++;
	}
	y = lon * 3;
	while (y < lon * 4)
	{
		x = lon * 20;
		while( x < lon * 22)
		{
			mlx_pixel_put(mlx, win, x, y, 0X000000);
			x++;
		}
		y++;
	}
	y = lon * 3;
	while (y < lon * 4)
	{
		x = lon * 22;
		while( x < lon * 24)
		{
			mlx_pixel_put(mlx, win, x, y, SHINEY);
			x++;
		}
		y++;
	}
	y = lon * 3;
	while (y < lon * 4)
	{
		x = lon * 24;
		while( x < lon * 26)
		{
			mlx_pixel_put(mlx, win, x, y, 0X000000);
			x++;
		}
		y++;
	}														//l4

	y = lon * 4;
	while (y < lon * 5)
	{
		x = lon * 2;
		while( x < lon * 4)
		{
			mlx_pixel_put(mlx, win, x, y, 0X000000);
			x++;
		}
		y++;
	}
	y = lon * 4;
	while (y < lon * 5)
	{
		x = lon * 5;
		while( x < lon * 6)
		{
			mlx_pixel_put(mlx, win, x, y, 0X000000);
			x++;
		}
		y++;
	}
	y = lon * 4;
	while (y < lon * 5)
	{
		x = lon * 6;
		while( x < lon * 8)
		{
			mlx_pixel_put(mlx, win, x, y, SHINEY);
			x++;
		}
		y++;
	}
	y = lon * 4;
	while (y < lon * 5)
	{
		x = lon * 8;
		while( x < lon * 9)
		{
			mlx_pixel_put(mlx, win, x, y, 0X000000);
			x++;
		}
		y++;
	}
	y = lon * 4;
	while (y < lon * 5)
	{
		x = lon * 9;
		while( x < lon * 10)
		{
			mlx_pixel_put(mlx, win, x, y, SHINEY);
			x++;
		}
		y++;
	}
	y = lon * 4;
	while (y < lon * 5)
	{
		x = lon * 10;
		while( x < lon * 11)
		{
			mlx_pixel_put(mlx, win, x, y, 0X000000);
			x++;
		}
		y++;
	}
	y = lon * 4;
	while (y < lon * 5)
	{
		x = lon * 11;
		while( x < lon * 12)
		{
			mlx_pixel_put(mlx, win, x, y, SHINEY);
			x++;
		}
		y++;
	}

	y = lon * 4;
	while (y < lon * 5)
	{
		x = lon * 12;
		while( x < lon * 16)
		{
			mlx_pixel_put(mlx, win, x, y, 0X000000);
			x++;
		}
		y++;
	}
	y = lon * 4;
	while (y < lon * 5)
	{
		x = lon * 16;
		while( x < lon * 18)
		{
			mlx_pixel_put(mlx, win, x, y, SHINEY);
			x++;
		}
		y++;
	}
	y = lon * 4;
	while (y < lon * 5)
	{
		x = lon * 18;
		while( x < lon * 23)
		{
			mlx_pixel_put(mlx, win, x, y, 0X000000);
			x++;
		}
		y++;
	}
	y = lon * 4;
	while (y < lon * 5)
	{
		x = lon * 23;
		while( x < lon * 25)
		{
			mlx_pixel_put(mlx, win, x, y, SHINEY);
			x++;
		}
		y++;
	}
	y = lon * 4;
	while (y < lon * 5)
	{
		x = lon * 25;
		while( x < lon * 26)
		{
			mlx_pixel_put(mlx, win, x, y, 0X000000);
			x++;
		}
		y++;
	}																//ll

	y = lon * 5;
	while (y < lon * 6)
	{
		x = lon * 4;
		while( x < lon * 6)
		{
			mlx_pixel_put(mlx, win, x, y, 0X000000);
			x++;
		}
		y++;
	}
	y = lon * 5;
	while (y < lon * 6)
	{
		x = lon * 6;
		while( x < lon * 7)
		{
			mlx_pixel_put(mlx, win, x, y, SHINEY);
			x++;
		}
		y++;
	}
	y = lon * 5;
	while (y < lon * 6)
	{
		x = lon * 7;
		while( x < lon * 8)
		{
			mlx_pixel_put(mlx, win, x, y, 0X000000);
			x++;
		}
		y++;
	}
	y = lon * 5;
	while (y < lon * 6)
	{
		x = lon * 8;
		while( x < lon * 13)
		{
			mlx_pixel_put(mlx, win, x, y, SHINEY);
			x++;
		}
		y++;
	}
	y = lon * 5;
	while (y < lon * 6)
	{
		x = lon * 13;
		while( x < lon * 14)
		{
			mlx_pixel_put(mlx, win, x, y, 0X000000);
			x++;
		}
		y++;
	}
	y = lon * 5;
	while (y < lon * 6)
	{
		x = lon * 14;
		while( x < lon * 16)
		{
			mlx_pixel_put(mlx, win, x, y, SHINEY);
			x++;
		}
		y++;
	}
	y = lon * 5;
	while (y < lon * 6)
	{
		x = lon * 16;
		while( x < lon * 20)
		{
			mlx_pixel_put(mlx, win, x, y, 0X000000);
			x++;
		}
		y++;
	}
	y = lon * 5;
	while (y < lon * 6)
	{
		x = lon * 22;
		while( x < lon * 25)
		{
			mlx_pixel_put(mlx, win, x, y, 0X000000);
			x++;
		}
		y++;
	}														//l
	y = lon * 6;
	while (y < lon * 7)
	{
		x = lon * 5;
		while( x < lon * 6)
		{
			mlx_pixel_put(mlx, win, x, y, 0X00FF00);
			x++;
		}
		y++;
	}
	y = lon * 6;
	while (y < lon * 7)
	{
		x = lon * 6;
		while( x < lon * 9)
		{
			mlx_pixel_put(mlx, win, x, y, SHINEY);
			x++;
		}
		y++;
	}
	y = lon * 6;
	while (y < lon * 7)
	{
		x = lon * 9;
		while( x < lon * 12)
		{
			mlx_pixel_put(mlx, win, x, y, 0X00FF00);
			x++;
		}
		y++;
	}
	y = lon * 6;
	while (y < lon * 7)
	{
		x = lon * 12;
		while( x < lon * 13)
		{
			mlx_pixel_put(mlx, win, x, y, SHINEY);
			x++;
		}
		y++;
	}
	y = lon * 6;
	while (y < lon * 7)
	{
		x = lon * 13;
		while( x < lon * 16)
		{
			mlx_pixel_put(mlx, win, x, y, 0X000000);
			x++;
		}
		y++;
	}
	y = lon * 6;
	while (y < lon * 7)
	{
		x = lon * 17;
		while( x < lon * 20)
		{
			mlx_pixel_put(mlx, win, x, y, 0X000000);
			x++;
		}
		y++;
	}																	//ll
	y = lon * 7;
	while (y < lon * 8)
	{
		x = lon * 4;
		while( x < lon * 5)
		{
			mlx_pixel_put(mlx, win, x, y, 0X000000);
			x++;
		}
		y++;
	}	y = lon * 7;
	while (y < lon * 8)
	{
		x = lon * 5;
		while( x < lon * 6)
		{
			mlx_pixel_put(mlx, win, x, y, 0X00FF00);
			x++;
		}
		y++;
	}
	y = lon * 7;
	while (y < lon * 8)
	{
		x = lon * 6;
		while( x < lon * 8)
		{
			mlx_pixel_put(mlx, win, x, y, SHINEY);
			x++;
		}
		y++;
	}

	y = lon * 7;
	while (y < lon * 8)
	{
		x = lon * 8;
		while( x < lon * 9)
		{
			mlx_pixel_put(mlx, win, x, y, 0X00FF00);
			x++;
		}
		y++;
	}
	y = lon * 7;
	while (y < lon * 8)
	{
		x = lon * 10;
		while( x < lon * 11)
		{
			mlx_pixel_put(mlx, win, x, y, 0X000000);
			x++;
		}
		y++;
	}
	y = lon * 7;
	while (y < lon * 8)
	{
		x = lon * 11;
		while( x < lon * 13)
		{
			mlx_pixel_put(mlx, win, x, y, 0X00FF00);
			x++;
		}
		y++;
	}
	y = lon * 7;
	while (y < lon * 8)
	{
		x = lon * 13;
		while( x < lon * 14)
		{
			mlx_pixel_put(mlx, win, x, y, 0X000000);
			x++;
		}
		y++;
	}
	y = lon * 7;
	while (y < lon * 8)
	{
		x = lon * 15;
		while( x < lon * 17)
		{
			mlx_pixel_put(mlx, win, x, y, 0X000000);
			x++;
		}
		y++;
	}
	y = lon * 7;
	while (y < lon * 8)
	{
		x = lon * 20;
		while( x < lon * 22)
		{
			mlx_pixel_put(mlx, win, x, y, 0X000000);
			x++;
		}
		y++;
	}																//ll

	y = lon * 8;
	while (y < lon * 9)
	{
		x = lon * 4;
		while( x < lon * 5)
		{
			mlx_pixel_put(mlx, win, x, y, 0X000000);
			x++;
		}
		y++;
	}
	y = lon * 8;
	while (y < lon * 9)
	{
		x = lon * 5;
		while( x < lon * 9)
		{
			mlx_pixel_put(mlx, win, x, y, 0X00FF00);
			x++;
		}
		y++;
	}
	y = lon * 8;
	while (y < lon * 9)
	{
		x = lon * 9;
		while( x < lon * 11)
		{
			mlx_pixel_put(mlx, win, x, y, 0X000000);
			x++;
		}
		y++;
	}
	y = lon * 8;
	while (y < lon * 9)
	{
		x = lon * 11;
		while( x < lon * 13)
		{
			mlx_pixel_put(mlx, win, x, y, 0X00FF00);
			x++;
		}
		y++;
	}

	y = lon * 8;
	while (y < lon * 9)
	{
		x = lon * 13;
		while( x < lon * 14)
		{
			mlx_pixel_put(mlx, win, x, y, 0X000000);
			x++;
		}
		y++;
	}
	y = lon * 8;
	while (y < lon * 9)
	{
		x = lon * 17;
		while( x < lon * 20)
		{
			mlx_pixel_put(mlx, win, x, y, 0X000000);
			x++;
		}
		y++;
	}
	y = lon * 8;
	while (y < lon * 9)
	{
		x = lon * 20;
		while( x < lon * 22)
		{
			mlx_pixel_put(mlx, win, x, y, SHINEY);
			x++;
		}
		y++;
	}
	y = lon * 8;
	while (y < lon * 9)
	{
		x = lon * 22;
		while( x < lon * 24)
		{
			mlx_pixel_put(mlx, win, x, y, 0X000000);
			x++;
		}												//ll
		y++;
	}
	y = lon * 9;
	while (y < lon * 10)
	{
		x = lon * 4;
		while( x < lon * 6)
		{
			mlx_pixel_put(mlx, win, x, y, 0X000000);
			x++;
		}
		y++;
	}
	y = lon * 9;
	while (y < lon * 10)
	{
		x = lon * 6;
		while( x < lon * 7)
		{
			mlx_pixel_put(mlx, win, x, y, SHINEY);
			x++;
		}
		y++;
	}
	y = lon * 9;
	while (y < lon * 10)
	{
		x = lon * 7;
		while( x < lon * 8)
		{
			mlx_pixel_put(mlx, win, x, y, 0X000000);
			x++;
		}
		y++;
	}
	y = lon * 9;
	while (y < lon * 10)
	{
		x = lon * 8;
		while( x < lon * 9)
		{
			mlx_pixel_put(mlx, win, x, y, 0X00FF00);
			x++;
		}
		y++;
	}
	y = lon * 9;
	while (y < lon * 10)
	{
		x = lon * 9;
		while( x < lon * 11)
		{
			mlx_pixel_put(mlx, win, x, y, 0X000000);
			x++;
		}
		y++;
	}
	y = lon * 9;
	while (y < lon * 10)
	{
		x = lon * 11;
		while( x < lon * 13)
		{
			mlx_pixel_put(mlx, win, x, y, 0X00FF00);
			x++;
		}
		y++;
	}
	y = lon * 9;
	while (y < lon * 10)
	{
		x = lon * 13;
		while( x < lon * 15)
		{
			mlx_pixel_put(mlx, win, x, y, 0X000000);
			x++;
		}
		y++;
	}
	y = lon * 9;
	while (y < lon * 10)
	{
		x = lon * 17;
		while( x < lon * 20)
		{
			mlx_pixel_put(mlx, win, x, y, SHINEY);
			x++;
		}
		y++;
	}
	y = lon * 9;
	while (y < lon * 10)
	{
		x = lon * 20;
		while( x < lon * 22)
		{
			mlx_pixel_put(mlx, win, x, y, 0X000000);
			x++;
		}
		y++;
	}
	y = lon * 9;
	while (y < lon * 10)
	{
		x = lon * 24;
		while( x < lon * 25)
		{
			mlx_pixel_put(mlx, win, x, y, 0X000000);
			x++;
		}
		y++;
	}																	//LL

	y = lon * 10;
	while (y < lon * 11)
	{
		x = lon * 5;
		while( x < lon * 6)
		{
			mlx_pixel_put(mlx, win, x, y, 0X000000);
			x++;
		}
		y++;
	}
	y = lon * 10;
	while (y < lon * 11)
	{
		x = lon * 6;
		while( x < lon * 7)
		{
			mlx_pixel_put(mlx, win, x, y, SHINEY);
			x++;
		}
		y++;
	}
	y = lon * 10;
	while (y < lon * 11)
	{
		x = lon * 7;
		while( x < lon * 9)
		{
			mlx_pixel_put(mlx, win, x, y, 0X000000);
			x++;
		}
		y++;
	}
	y = lon * 10;
	while (y < lon * 11)
	{
		x = lon * 9;
		while( x < lon * 12)
		{
			mlx_pixel_put(mlx, win, x, y, 0X00FF00);
			x++;
		}
		y++;
	}
	y = lon * 10;
	while (y < lon * 11)
	{
		x = lon * 12;
		while( x < lon * 14)
		{
			mlx_pixel_put(mlx, win, x, y, 0X000000);
			x++;
		}
		y++;
	}
	y = lon * 10;
	while (y < lon * 11)
	{
		x = lon * 15;
		while( x < lon * 17)
		{
			mlx_pixel_put(mlx, win, x, y, 0X000000);
			x++;
		}
		y++;
	}
	y = lon * 10;
	while (y < lon * 11)
	{
		x = lon * 17;
		while( x < lon * 20)
		{
			mlx_pixel_put(mlx, win, x, y, SHINEY);
			x++;
		}
		y++;
	}
	y = lon * 10;
	while (y < lon * 11)
	{
		x = lon * 22;
		while( x < lon * 25)
		{
			mlx_pixel_put(mlx, win, x, y, 0X000000);
			x++;
		}
		y++;
	}															//LL
	y = lon * 11;
	while (y < lon * 12)
	{
		x = lon * 6;
		while( x < lon * 13)
		{
			mlx_pixel_put(mlx, win, x, y, 0X000000);
			x++;
		}
		y++;
	}
	y = lon * 11;
	while (y < lon * 12)
	{
		x = lon * 15;
		while( x < lon * 16)
		{
			mlx_pixel_put(mlx, win, x, y, 0X000000);
			x++;
		}
		y++;
	}
	y = lon * 11;
	while (y < lon * 12)
	{
		x = lon * 17;
		while( x < lon * 19)
		{
			mlx_pixel_put(mlx, win, x, y, 0X000000);
			x++;
		}
		y++;
	}
	y = lon * 11;
	while (y < lon * 12)
	{
		x = lon * 22;
		while( x < lon * 23)
		{
			mlx_pixel_put(mlx, win, x, y, 0X000000);
			x++;
		}
		y++;
	}															//LL
	y = lon * 12;
	while (y < lon * 13)
	{
		x = lon * 7;
		while( x < lon * 8)
		{
			mlx_pixel_put(mlx, win, x, y, 0X000000);
			x++;
		}
		y++;
	}
	y = lon * 12;
	while (y < lon * 13)
	{
		x = lon * 12;
		while( x < lon * 13)
		{
			mlx_pixel_put(mlx, win, x, y, 0X000000);
			x++;
		}
		y++;
	}
	y = lon * 12;
	while (y < lon * 13)
	{
		x = lon * 15;
		while( x < lon * 16)
		{
			mlx_pixel_put(mlx, win, x, y, 0X000000);
			x++;
		}
		y++;
	}
	y = lon * 12;
	while (y < lon * 13)
	{
		x = lon * 17;
		while( x < lon * 18)
		{
			mlx_pixel_put(mlx, win, x, y, 0X000000);
			x++;
		}
		y++;
	}
	y = lon * 12;
	while (y < lon * 13)
	{
		x = lon * 19;
		while( x < lon * 22)
		{
			mlx_pixel_put(mlx, win, x, y, 0X000000);
			x++;
		}
		y++;
	}														//LL
	y = lon * 13;
	while (y < lon * 14)
	{
		x = lon * 7;
		while( x < lon * 8)
		{
			mlx_pixel_put(mlx, win, x, y, 0X000000);
			x++;
		}
		y++;
	}
	y = lon * 13;
	while (y < lon * 14)
	{
		x = lon * 12;
		while( x < lon * 13)
		{
			mlx_pixel_put(mlx, win, x, y, 0X000000);
			x++;
		}
		y++;
	}
	y = lon * 13;
	while (y < lon * 14)
	{
		x = lon * 14;
		while( x < lon * 16)
		{
			mlx_pixel_put(mlx, win, x, y, 0X000000);
			x++;
		}
		y++;
	}
	y = lon * 13;
	while (y < lon * 14)
	{
		x = lon * 17;
		while( x < lon * 18)
		{
			mlx_pixel_put(mlx, win, x, y, 0X000000);
			x++;
		}
		y++;
	}															//LL
	y = lon * 14;
	while (y < lon * 15)
	{
		x = lon * 7;
		while( x < lon * 9)
		{
			mlx_pixel_put(mlx, win, x, y, 0X000000);
			x++;
		}
		y++;
	}
	y = lon * 14;
	while (y < lon * 15)
	{
		x = lon * 11;
		while( x < lon * 13)
		{
			mlx_pixel_put(mlx, win, x, y, 0X000000);
			x++;
		}
		y++;
	}
	y = lon * 14;
	while (y < lon * 15)
	{
		x = lon * 14;
		while( x < lon * 15)
		{
			mlx_pixel_put(mlx, win, x, y, 0X000000);
			x++;
		}
		y++;
	}
	y = lon * 15;
	while (y < lon * 16)
	{
		x = lon * 10;
		while( x < lon * 12)
		{
			mlx_pixel_put(mlx, win, x, y, 0X000000);
			x++;
		}
		y++;
	}
//	mlx_mouse_hook(win, my_mouse_funct(win, mlx), 0);
	mlx_key_hook(win, my_key_funct, 0);
	mlx_loop(mlx);
}

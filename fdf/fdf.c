/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llefevre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/20 20:03:11 by llefevre          #+#    #+#             */
/*   Updated: 2017/05/23 15:27:51 by llefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "mlx.h"
#include "fdf.h"

int		centrage(char *str, t_tri *lst);

int		tri(char *str, t_tri *lst);

void	affiche_cub(int keycode, t_tri *lst)
{	
	int x;
	int y;
	y = 0;
	lst->color = 0X000000;
	while (y < 1000)
	{
		x = 0;
		while(x < 1000)
		{
			mlx_pixel_put(lst->mlx, lst->win, x, y, lst->color);
			x++;
		}
		y++;
	}
	if(keycode == 126)
		lst->haut -= 10;
	if(keycode == 125)
		lst->haut += 10;
	if(keycode == 124)
		lst->droite += 10;
	if(keycode == 123)
		lst->droite -= 10;
	if(keycode == 87)
	{
		lst->zoom = lst->zoom + 5;
		lst->nbr_zoom++;
	}
	if(keycode == 84)
	{
		lst->zoom = lst->zoom - 5;
		lst->nbr_zoom--;
	}
	centrage(lst->input, lst);
	tri(lst->input, lst);
}

char	*ft_read(char *av)
{
	int		fd;
	ssize_t	bsiz;
	char	buf[BUFSIZE];
	char	*out;

	fd = open(av, O_RDONLY);
	out = NULL;
	if (fd == -1)
		return (NULL);
	while ((bsiz = read(fd, &buf, BUFSIZE)) > 0)
		out = ft_malloncat(out, buf, (size_t)bsiz);
	return (out);
}

int		put_cub(int x, int y, t_tri *lst)
{
	int x1;
	int y1;

	y1 = y;
	x1 = x;
	while (y < y1 + lst->lon)
	{
		x = x1;
		while(x < x1 + lst->lon)
		{
			mlx_pixel_put(lst->mlx, lst->win, x, y, lst->color);
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
	t_tri *lst;

	x = 0;
	y = 0;
	lst = ((t_tri *)param);
	lst->lon = keycode;
	printf("keycode : %d\n", keycode);
	if(keycode == 126)
		affiche_cub(keycode, lst);
	if(keycode == 125)
		affiche_cub(keycode, lst);
	if(keycode == 123)
		affiche_cub(keycode, lst);
	if(keycode == 124)
		affiche_cub(keycode, lst);
	if(keycode == 87)
		affiche_cub(keycode, lst);
	if(keycode == 84)
		affiche_cub(keycode, lst);
	if(keycode == 25)
	{
		lst->color = 0XFF0000;
		put_cub(x, y, lst);
	}
	if(keycode == 18)
	{
		lst->color = 0X00FF00;
		put_cub(x, y, lst);
	}
	if(keycode == 35)
	{
		lst->color = 0X0000FF;
		put_cub(x, y, lst);
	}
	if(keycode == 53)
		exit(0);
	return (0);
}

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

void	ft_error(int i)
{
	if (i == 0)
	{
		printf("error\n");
		exit(1);
	}
}

int		main(int ac, char **av)
{
	t_tri	lst;
	int		y;
	int		x;
	char	*input;

	lst.zoom = 10;
	if (ac == 2)
	{
		lst.input = ft_read(av[1]);
		if (!lst.input)
			ft_error(0);
	}
	else
		printf("LA MAP ENCULER\n");
	lst.mlx = mlx_init();
	lst.win = mlx_new_window(lst.mlx, 1000, 1000, "yanma_mlx_42");
	lst.droite = 500;
	lst.haut = 500;
	affiche_cub(0, &lst);
	mlx_key_hook(lst.win, my_key_funct, &lst);
	mlx_mouse_hook(lst.win, put_mousse, &lst);
	mlx_loop(lst.mlx);
	return (0);
}

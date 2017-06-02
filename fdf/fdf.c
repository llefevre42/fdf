/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llefevre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/20 20:03:11 by llefevre          #+#    #+#             */
/*   Updated: 2017/06/02 20:56:30 by llefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "mlx.h"
#include "fdf.h"

int		centrage(char *str, t_tri *lst);

int		tri(char *str, t_tri *lst, int ***tab);

void	full_tab(t_tri *lst, int ***tab);

void		ft_strlen_custom(char *str, t_tri *lst)
{
	int i;
	int j;
	int k;
	int w;

	k = 0;
	i = 0;
	j = 0;
	w = 0;
	while(str[i] != '\0')
	{
		while(str[i] != '\n' && str[i] != '\0')
		{
			if(str[i] >= '0' && str[i] <= '9')
			{
				j++;
				while((str[i] >= '0' && str[i] <= '9') || str[i] == ',' || str[i] == 'X')
					i++;
			}
			else
				i++;
		}
		w++;
		if(j > k)
			k = j;
		j = 0;
		if(str[i] == '\n')
			i++;
	}
	lst->largtab = k;
	lst->hauttab = w;
}

void	affiche_cub(int keycode, t_tri *lst)
{
//	t_tab 	*tab;
	int		**tab;
	int i;

	i = 0;
	ft_strlen_custom(lst->input,lst);
	printf("%d %d\n", lst->hauttab, lst->largtab);
	tab = malloc(sizeof(int *) * (lst->hauttab * lst->largtab));
	while(i < (lst->hauttab * lst->largtab))
	{
		tab[i] = malloc(sizeof(int) * 3);
		i++;
	}
//	tab = (t_tab*)malloc((sizeof(t_tab) + 1) * (size_t)(lst->hauttab * lst->largtab));	
	full_tab(lst , &tab);
	lst->color = 0X000000;
	centrage(lst->input, lst);
	tri(lst->input, lst, &tab);
	if(keycode == 126)
		lst->haut -= 10;
	if(keycode == 125)
		lst->haut += 10;
	if(keycode == 124)
		lst->droite += 10;
	if(keycode == 123)
		lst->droite -= 10;
	if(keycode == 86)
		lst->z += 3;
	if(keycode == 83)
		lst->z -= 3;
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
	if(keycode == 89)
		lst->color = 0XFF0000;
	else if(keycode == 91)
		lst->color = 0X00FF00;
	else if(keycode == 92)
		lst->color = 0X0000FF;
	else
		lst->color = 0XFFFFFF;
	centrage(lst->input, lst);
	tri(lst->input, lst, &tab);
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
	if(keycode == 86)
		affiche_cub(keycode, lst);
	if(keycode == 83)
		affiche_cub(keycode, lst);
	if(keycode == 87)
		affiche_cub(keycode, lst);
	if(keycode == 84)
		affiche_cub(keycode, lst);
	if(keycode == 89)
		affiche_cub(keycode, lst);
	if(keycode == 91)
		affiche_cub(keycode, lst);
	if(keycode == 92)
		affiche_cub(keycode, lst);
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

	lst.reste = 0;
	lst.z = 3;
	lst.zoom = 10;
	lst.nbr_zoom = 0;
	if (ac == 2)
	{
		lst.input = ft_read(av[1]);
		printf("VU\n");
		if (!lst.input)
			ft_error(0);
	}
	else
		printf("LA MAP ENCULER\n");
	lst.mlx = mlx_init();
	lst.win = mlx_new_window(lst.mlx, 1000, 1000, "Fdf");	
	lst.droite = 500;	
	lst.haut = 500;
	affiche_cub(0, &lst);
	mlx_key_hook(lst.win, my_key_funct, &lst);
	mlx_mouse_hook(lst.win, put_mousse, &lst);
	mlx_loop(lst.mlx);
	return (0);
}

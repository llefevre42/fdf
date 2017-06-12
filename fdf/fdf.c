/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llefevre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/20 20:03:11 by llefevre          #+#    #+#             */
/*   Updated: 2017/06/09 18:38:29 by llefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

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

	lst.color = 0XFFFFFF;
	lst.reste = 0;
	lst.z = 1;
	lst.zoom = 10;
	lst.nbr_zoom = 1;
	if (ac == 2)
	{
		lst.input = ft_read(av[1]);
		if (!lst.input)
			ft_error(0);
	}
	else
		printf("LA MAP ENCULER\n");
	lst.mlx = mlx_init();
	lst.win = mlx_new_window(lst.mlx, 2000, 1200, "Fdf");
	lst.win2 = mlx_new_window(lst.mlx, 500, 1000, "fdf_bis");	
	lst.droite = 1000;	
	lst.haut = 600;
	affiche_marge(&lst);
	affiche_cub(0, &lst);
//	mlx_key_hook(lst.win, my_key_funct, &lst);
	mlx_hook(lst.win, 2 , (1L<<0) , my_key_funct, &lst);
	mlx_hook(lst.win2, 2 , (1L<<0) , my_key_funct, &lst);
	mlx_mouse_hook(lst.win2, put_mousse, &lst);
	mlx_loop(lst.mlx);
	return (0);
}

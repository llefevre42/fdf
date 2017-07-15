/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llefevre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/20 20:03:11 by llefevre          #+#    #+#             */
/*   Updated: 2017/07/13 23:42:56 by llefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	crea_tab(t_tri *lst)
{
	long int i;

	i = 0;
	ft_strlen_custom1(lst->input, lst);
	if (!(lst->tab = malloc(sizeof(long int *) * (lst->htab * lst->ltab))))
		ft_error(0);
	while (i < (lst->htab * lst->ltab))
	{
		if (!(lst->tab[i] = malloc(sizeof(long int) * 5)))
			ft_error(0);
		i++;
	}
	full_tab(lst);
	ft_strlen_custom2(lst->input, lst);
	auto_size(lst);
}

char	*ft_read(char *av)
{
	int		fd;
	ssize_t	bsiz;
	char	buf[BUFSIZE];
	char	*out;

	if ((strcmp(av, "Makefile") == 0) || (strcmp(av, "random") == 0))
		ft_error(0);
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

void	norme_main(t_tri *lst, int *trash1, int *trash2, int *trash3)
{
	int i;

	i = 0;
	lst->mlx = mlx_init();
	lst->win = mlx_new_window(lst->mlx, 2000, 1200, "Fdf");
	lst->win2 = mlx_new_window(lst->mlx, 500, 1000, "fdf_bis");
	lst->droite = 1000;
	lst->haut = 600;
	affiche_marge(lst);
	crea_tab(lst);
	lst->pt_img = mlx_new_image(lst->mlx, 2000, 1200);
	lst->img = (unsigned \
			int *)mlx_get_data_addr(lst->pt_img, trash1, trash2, trash3);
	affiche_cub(0, lst);
	mlx_hook(lst->win, 2, (1L << 0), my_key_funct, lst);
	mlx_hook(lst->win2, 2, (1L << 0), my_key_funct, lst);
	mlx_mouse_hook(lst->win2, put_mousse, lst);
	mlx_mouse_hook(lst->win, put_mousse_echap, lst);
	mlx_loop(lst->mlx);
	while (i < lst->ltab * lst->htab)
	{
		ft_memdel((void **)&(lst->tab[i]));
		i++;
	}
}

int		main(int ac, char **av)
{
	t_tri	lst;
	int		trash1;
	int		trash2;
	int		trash3;

	lst.rotaz = 0;
	lst.rotay = 0;
	lst.rotax = 0;
	lst.color = 0XFFFFFF;
	lst.reste = 0;
	lst.z = 1;
	lst.nbr_zoom = 1;
	if (ac == 2)
	{
		lst.input = ft_read(av[1]);
		if (!lst.input)
			ft_error(0);
	}
	else
		ft_error(0);
	norme_main(&lst, &trash1, &trash2, &trash3);
	return (0);
}

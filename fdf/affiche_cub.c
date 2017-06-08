/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   affiche_cub.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llefevre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 21:54:04 by llefevre          #+#    #+#             */
/*   Updated: 2017/06/08 06:03:27 by llefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	affiche_cub(int keycode, t_tri *lst)
{
	int		**tab;
	int i;

	i = 0;
	ft_strlen_custom(lst->input,lst);
	tab = malloc(sizeof(int *) * (lst->hauttab * lst->largtab));
	while(i < (lst->hauttab * lst->largtab))
	{
		tab[i] = malloc(sizeof(int) * 3);
		i++;
	}
	full_tab(lst , &tab);
	mlx_clear_window(lst->mlx, lst->win);
//	lst->swap_color = lst->color;
//	lst->color = 0X000000;
//	tri(lst->input, lst, &tab);
//	lst->color = lst->swap_color;
	if(keycode == 126)
		lst->haut -= 10;
	if(keycode == 125)
		lst->haut += 10;
	if(keycode == 124)
		lst->droite += 10;
	if(keycode == 123)
		lst->droite -= 10;
	if(keycode == 86)
		lst->z += 1;
	if(keycode == 83)
		lst->z -= 1;
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
	tri(lst->input, lst, &tab);
}

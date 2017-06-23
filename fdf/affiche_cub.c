/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   affiche_cub.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llefevre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 21:54:04 by llefevre          #+#    #+#             */
/*   Updated: 2017/06/23 08:53:15 by llefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	last_affiche(int keycode, t_tri *lst)
{
	if (keycode == 37)
	{
		lst->rotay -= 5;
		lst->s_rota = 2;
	}
	if (keycode == 34)
	{
		lst->rotax += 5;
		lst->s_rota = 3;
	}
	if (keycode == 40)
	{
		lst->rotax -= 5;
		lst->s_rota = 3;
	}
	if (keycode == 65)
	{
		lst->s_rota = 0;
		lst->color = 0XFFFFFF;
		lst->z = 1;
		lst->zoom = 41;
		lst->nbr_zoom = 1;
		lst->droite = 1000;
		lst->haut = 600;
	}
}

void	next_affiche(int keycode, t_tri *lst)
{
	if (keycode == 89)
		lst->color = 0XFF0000;
	if (keycode == 91)
		lst->color = 0X00FF00;
	if (keycode == 92)
		lst->color = 0X0000FF;
	if (keycode == 35)
	{
		lst->rotaz += 5;
		lst->s_rota = 1;
	}
	if (keycode == 41)
	{
		lst->rotaz -= 5;
		lst->s_rota = 1;
	}
	if (keycode == 31)
	{
		lst->rotay += 5;
		lst->s_rota = 2;
	}
}

void	suite_affiche(int keycode, t_tri *lst, long int i, long int end)
{
	while (i++ < end)
		lst->img[i] = 0X000000;
	if (keycode == 126)
		lst->haut -= 10;
	if (keycode == 125)
		lst->haut += 10;
	if (keycode == 124)
		lst->droite += 10;
	if (keycode == 123)
		lst->droite -= 10;
	if (keycode == 86)
		lst->z += 1;
	if (keycode == 83)
		lst->z -= 1;
	if (keycode == 87)
	{
		lst->zoom = lst->zoom + 5;
		lst->nbr_zoom++;
	}
	if (keycode == 84)
	{
		lst->zoom = lst->zoom - 5;
		lst->nbr_zoom--;
	}
}

void	affiche_cub(int keycode, t_tri *lst)
{
	long int	i;
	long int	end;

	end = 2000 * 1200;
	i = 0;
	while (i < end - 10)
	{
		lst->img[i] = 0X000000;
		lst->img[i + 1] = 0X000000;
		lst->img[i + 2] = 0X000000;
		lst->img[i + 3] = 0X000000;
		lst->img[i + 4] = 0X000000;
		lst->img[i + 5] = 0X000000;
		lst->img[i + 6] = 0X000000;
		lst->img[i + 7] = 0X000000;
		lst->img[i + 8] = 0X000000;
		lst->img[i + 9] = 0X000000;
		i += 10;
	}
	suite_affiche(keycode, lst, i, end);
	next_affiche(keycode, lst);
	last_affiche(keycode, lst);
	tri(lst);
}

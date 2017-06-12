/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_keycode.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llefevre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 21:51:33 by llefevre          #+#    #+#             */
/*   Updated: 2017/06/09 22:17:20 by llefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
	if(keycode == 35)
		affiche_cub(keycode, lst);
	if(keycode == 41)
		affiche_cub(keycode, lst);
	if(keycode == 53)
		exit(0);
	return (0);
}

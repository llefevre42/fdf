/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_keycode.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llefevre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 21:51:33 by llefevre          #+#    #+#             */
/*   Updated: 2017/07/15 17:44:18 by llefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		my_key_funct(int keycode, void *param)
{
	t_tri *lst;

	lst = ((t_tri *)param);
	lst->lon = keycode;
	printf("keycode : %d\n", keycode);
	if (keycode == 126 || (keycode == 123) || (keycode == 124) \
			|| (keycode == 125) || (keycode == 86) || (keycode == 83) \
			|| (keycode == 87) || (keycode == 84) || (keycode == 89) \
			|| (keycode == 91) || (keycode == 92) || (keycode == 35) \
			|| (keycode == 41) || (keycode == 31) || (keycode == 37) \
			|| (keycode == 40) || (keycode == 34) || (keycode == 65) \
			|| (keycode == 67)) 
		affiche_cub(keycode, lst);
	if (keycode == 53)
		exit(0);
	return (0);
}

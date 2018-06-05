/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   full_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llefevre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 21:56:11 by llefevre          #+#    #+#             */
/*   Updated: 2017/10/06 23:12:33 by llefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	full_tab(t_tri *lst)
{
	long int k;
	long int i;

	k = 0;
	i = 0;
	i = lst->htab * lst->ltab;
	while (k < i)
	{
		lst->tab[k][0] = 0;
		lst->tab[k][1] = 0;
		lst->tab[k][2] = 0;
		lst->tab[k][3] = 0;
		lst->tab[k][4] = -1;
		k++;
	}
}
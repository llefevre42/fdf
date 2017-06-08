/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlen_custom.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llefevre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 21:54:56 by llefevre          #+#    #+#             */
/*   Updated: 2017/06/08 06:01:37 by llefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
	lst->centrex = lst->largtab / 2;
	lst->centrey = lst->hauttab / 2;
}

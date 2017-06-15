/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlen_custom.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llefevre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 21:54:56 by llefevre          #+#    #+#             */
/*   Updated: 2017/06/15 18:22:45 by llefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_strlen_custom1(char *str, t_tri *lst)
{
	long long int i;
	long long int j;
	long long int k;
	long long int w;

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

void		ft_strlen_custom2(char *str, t_tri *lst)
{
	long int i;
	long int jb;
	int neg;
	long int c;
	long int w;
	char *coloris;

	lst->egal = 0;
	w = 0;
	c = 0;
	neg = 1;
	jb = 0;
	i = 0;
	if(!(coloris = malloc(sizeof(char) * (6 + 1))))
		return;
	while(str[i] != '\0')
	{
		while(str[i] != '\n' && str[i] != '\0')
		{
			if((str[i] >= 48 && str[i] <= 57) || str[i] == '-')
			{
				if(str[i] == '-')
				{
					neg = 1;
					i++;
				}
				while(str[i] >= 48 && str[i] <= 57)
				{
					atoi_dimentionelle(str[i], lst);
					i++;
				}
				lst->tab[jb][3] = lst->egal;
				if(str[i] == ',')
				{
					i += 3;
					c = i;
					w = 0;
					while((str[i] >= '0' && str[i] <= '9') || (str[i] >= 'A' && str[i] <= 'F'))
						i++;
					while(c < i)
					{
						coloris[w] = str[c];
						c++;
						w++;
					}
					coloris[w] = '\0';
					lst->tab[jb][4] = ft_htoi(coloris) - 1;
					ft_strclr(coloris);
				}
				if(lst->egal != 0)
				{
					if(neg == 1)
					{
						lst->tab[jb][3] *= -1;
					}
				}
				neg = 0;
				lst->egal = 0;
				jb++;
			}
			else
				i++;
		}
		if(str[i] == '\n')
			i++;
	}
}

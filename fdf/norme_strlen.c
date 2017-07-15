/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norme_strlen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llefevre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/21 19:16:02 by llefevre          #+#    #+#             */
/*   Updated: 2017/07/13 19:01:43 by llefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	color(char *str, t_tri *l, t_strc *s)
{
	if (str[s->i] == ',')
	{
		s->i += 3;
		s->c = s->i;
		s->w = 0;
		while ((str[s->i] >= '0' && str[s->i] <= '9') \
				|| (str[s->i] >= 'A' && str[s->i] <= 'F'))
			s->i++;
		while (s->c < s->i)
		{
			s->coloris[s->w] = str[s->c];
			s->c++;
			s->w++;
		}
		s->coloris[s->w] = '\0';
		l->tab[s->jb][4] = ft_htoi(s->coloris) - 1;
		ft_strclr(s->coloris);
	}
}

void	number(char *str, t_tri *l, t_strc *s)
{
	if ((str[s->i] >= 48 && str[s->i] <= 57) || str[s->i] == '-')
	{
		l->nbr_p++;
		if (str[s->i] == '-')
		{
			s->neg = 1;
			s->i++;
		}
		while (str[s->i] >= 48 && str[s->i] <= 57)
		{
			atoi_dimentionelle(str[s->i], l);
			s->i++;
		}
		l->tab[s->jb][3] = l->egal;
		color(str, l, s);
		if (s->neg == 1)
			l->tab[s->jb][3] *= -1;
		s->neg = 0;
		l->egal = 0;
		s->jb++;
	}
	else
		s->i++;
}

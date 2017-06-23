/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlen_custom.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llefevre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 21:54:56 by llefevre          #+#    #+#             */
/*   Updated: 2017/06/23 08:57:51 by llefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	atoi_dimentionelle(char str, t_tri *lst)
{
	lst->egal *= 10;
	lst->egal += (long int)str - '0';
}

void	while_strlen(char *str, t_tri *lst, t_str *s)
{
	while (str[s->i] != '\n' && str[s->i] != '\0')
	{
		if (str[s->i] >= '0' && str[s->i] <= '9')
		{
			s->j++;
			while ((str[s->i] >= '0' && str[s->i] <= '9') \
					|| (str[s->i] >= 'A' && str[s->i] <= 'F') \
					|| str[s->i] == ',' || str[s->i] == 'X')
				s->i++;
		}
		else
			s->i++;
	}
	s->w++;
	if (s->j > s->k)
		s->k = s->j;
	s->j = 0;
	if (str[s->i] == '\n')
		s->i++;
}

void	ft_strlen_custom1(char *str, t_tri *lst)
{
	t_str s;

	s.k = 0;
	s.i = 0;
	s.j = 0;
	s.w = 0;
	while (str[s.i] != '\0')
		while_strlen(str, lst, &s);
	lst->ltab = s.k;
	lst->htab = s.w;
	lst->centrex = lst->ltab / 2;
	lst->centrey = lst->htab / 2;
}

void	ft_strlen_custom2(char *str, t_tri *lst)
{
	t_strc s;

	s.res = 0;
	lst->egal = 0;
	lst->nbr_p = 0;
	s.w = 0;
	s.c = 0;
	s.neg = 0;
	s.jb = 0;
	s.i = 0;
	if (!(s.coloris = malloc(sizeof(char) * (6 + 1))))
		return ;
	while (str[s.i] != '\0')
	{
		while (str[s.i] != '\n' && str[s.i] != '\0')
			number(str, lst, &s);
		if (str[s.i] == '\n')
			s.i++;
	}
	free(s.coloris);
	s.coloris = NULL;
}

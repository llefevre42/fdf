/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llefevre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 22:01:08 by llefevre          #+#    #+#             */
/*   Updated: 2017/07/15 17:20:27 by llefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotationz(t_pla *s, t_tri *lst)
{
	long int swap;
	long int swap2;

	s->space -= 1000;
	s->colone -= 600;
	swap = 1000 + (s->space * cos(lst->rotaz * 0.0174533) \
			- s->colone * sin(lst->rotaz * 0.0174533));
	swap2 = 600 + (s->space * sin(lst->rotaz * 0.0174533) \
			+ s->colone * cos(lst->rotaz * 0.0174533));
	s->space = swap;
	s->colone = swap2;
}

void	rotationy(t_pla *s, t_tri *lst)
{
	long int swap;
	long int swap2;

	s->space -= 1000;
	s->colone += 600;
	swap = 1000 + (s->space * cos(lst->rotay * 0.0174533) \
			- (lst->tab[s->p][3]) * sin(lst->rotay * 0.0174533));
	swap2 = 600 + (s->space * sin(lst->rotay * 0.0174533) \
			+ (lst->tab[s->p][3]) * cos(lst->rotay * 0.0174533));
	s->space = swap;
	lst->tab[s->p][3] = swap2;
}

void	rotationx(t_pla *s, t_tri *lst)
{
	long int swap;
	long int swap2;

	s->colone -= 600;
	swap = 1000 + lst->tab[s->p][3] * sin(lst->rotax * 0.0174533) \
			- s->colone * sin(lst->rotax * 0.0174533);
	swap2 = 1600 + lst->tab[s->p][3] * cos(lst->rotax * 0.0174533) \
			+ s->colone * sin(lst->rotax * 0.0174533);
	lst->tab[s->p][3] = swap;
	s->colone = swap2;
}

void	rotation(t_pla *s, t_tri *lst)
{
	if (lst->s_rota == 1)
		rotationz(s, lst);
	if (lst->s_rota == 2)
		rotationy(s, lst);
	if (lst->s_rota == 3)
		rotationx(s, lst);
}

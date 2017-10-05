/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ligne_setup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llefevre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/15 17:31:31 by llefevre          #+#    #+#             */
/*   Updated: 2017/08/19 20:49:02 by llefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ligne_setup(t_pla *s, t_tri *l)
{
	if (s->p >= 1 && l->tab[s->p - 1][0] != 0  \
			&& s->p - 1 != (l->ltab * s->rest_ligne) - 1)
		ligne_p(s, l);
	if (s->p >= l->ltab && l->tab[s->p - l->ltab][0] != 0)
		ligne_h(s, l);
	if (s->p >= l->ltab + 1 && l->tab[s->p - l->ltab - 1][0] != 0 \
			&& s->p - l->ltab - 1 != (l->ltab * s->rest_ligne) - l->ltab - 1)
		ligne_d(s, l);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auto_size.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llefevre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 16:15:59 by llefevre          #+#    #+#             */
/*   Updated: 2017/07/11 16:48:31 by llefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	auto_size(t_tri *lst)
{
	if (lst->ltab <= 15)
		lst->zoom = 41;
	else if (lst->ltab <= 50)
		lst->zoom = 21;
	else if (lst->ltab <= 200)
		lst->zoom = 7;
	else if (lst->ltab <= 500)
		lst->zoom = 5;
	else if (lst->ltab > 500)
		lst->zoom = 2;
}

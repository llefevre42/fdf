/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auto_size.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llefevre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 16:15:59 by llefevre          #+#    #+#             */
/*   Updated: 2017/10/06 23:45:27 by llefevre         ###   ########.fr       */
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
		lst->zoom = 6;
	else if (lst->ltab <= 1000)
		lst->zoom = 2;
	else if (lst->ltab > 1000)
		lst->zoom = 1;
}

void	auto_size_z(t_tri *lst)
{
	int i;

	i = 0;
	if (lst->nbr_p < 1)
		ft_error(0);
	lst->max_z = lst->tab[0][3];
	while (i < lst->nbr_p)
	{
		if (lst->max_z < lst->tab[i][3])
			lst->max_z = lst->tab[i][3];
		i++;
	}
	auto_size_z2(lst);
}

void	auto_size_z2(t_tri *lst)
{
	int i;

	i = -1;
	if (lst->max_z > 200)
		while (++i < lst->nbr_p)
		{
			lst->tab[i][3] /= 10;
			if (lst->tab[i][3] > 0 && lst->tab[i][3] < 1)
				lst->tab[i][3] += 1;
		}
	else if (lst->max_z > 1000)
		while (++i < lst->nbr_p)
		{
			lst->tab[i][3] /= 100;
			if (lst->tab[i][3] > 0 && lst->tab[i][3] < 1)
				lst->tab[i][3] += 1;
		}
	else if (lst->max_z > 1500)
		while (++i < lst->nbr_p)
		{
			lst->tab[i][3] /= 1000;
			if (lst->tab[i][3] > 0 && lst->tab[i][3] < 1)
				lst->tab[i][3] += 1;
		}
}

int		ft_is_valid(char *line)
{
	int i;

	i = 0;
	if (line == NULL)
		ft_error(0);
	while (line[i])
	{
		if (ft_isdigit(line[i]) || line[i] == ' ' || line[i] == ',' ||
				line[i] == '\n' || line[i] == 'x' || line[i] == 'X' ||
				line[i] == '-' || line[i] == '+' ||
				(line[i] >= 'a' && line[i] <= 'f') ||
				(line[i] >= 'A' && line[i] <= 'F'))
			i++;
		else
			ft_error(0);
	}
	return (1);
}

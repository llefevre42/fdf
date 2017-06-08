/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   affiche_marge.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llefevre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/05 17:25:47 by llefevre          #+#    #+#             */
/*   Updated: 2017/06/07 19:15:06 by llefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	affiche_marge(t_tri *lst)
{
	int x;
	int y;
	int y1;
	int x1;

	lst->color = 0X22427C;
	put_cub_bis(1000, 0, 15, 500, lst);
	put_cub_bis(1000, 0, 1000, 15, lst);
	put_cub_bis(1485, 0, 1000, 15, lst);
	put_cub_bis(1000, 985, 15, 500, lst);
	lst->color = 0XFFFFFF;
	put_cub_bis(1150, 50, 60, 10, lst);	
	put_cub_bis(1300, 50, 60, 10, lst);	
	put_cub_bis(1250, 50, 60, 10, lst);	
	put_cub_bis(1150, 50, 10, 40, lst);	
	put_cub_bis(1300, 50, 10, 40, lst);	
	put_cub_bis(1150, 70, 10, 25, lst);	
	put_cub_bis(1300, 70, 10, 25, lst);	
	put_cub_bis(1220, 65, 10, 30, lst);	
	put_cub_bis(1220, 100, 10, 30, lst);	
	put_cub_bis(1220, 70, 40, 10, lst);	
	lst->color = 0X00FF00;
	put_cub_bis(1020, 400, 100, 225, lst);	
	lst->color = 0XFF0000;
	put_cub_bis(1020, 505, 100, 225, lst);	
	lst->color = 0XFFFF00;
	put_cub_bis(1255, 400, 100, 225, lst);	
	lst->color = 0X3A8EBA;
	put_cub_bis(1255, 505, 100, 225, lst);	
}

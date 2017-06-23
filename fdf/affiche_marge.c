/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   affiche_marge.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llefevre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/05 17:25:47 by llefevre          #+#    #+#             */
/*   Updated: 2017/06/23 10:03:56 by llefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	suite_marge(t_tri *lst)
{
	put_cub_bis(150, 70, lst);
	put_cub_bis(300, 70, lst);
	lst->t1 = 30;
	lst->t2 = 10;
	put_cub_bis(220, 65, lst);
	put_cub_bis(220, 100, lst);
	lst->t1 = 10;
	lst->t2 = 40;
	put_cub_bis(220, 70, lst);
	lst->color = 0X00FF00;
	lst->t1 = 225;
	lst->t2 = 100;
	put_cub_bis(20, 400, lst);
	lst->color = 0XFF0000;
	lst->t1 = 20;
	lst->t2 = 20;
	put_cub_bis(20, 20, lst);
	mlx_string_put(lst->mlx, lst->win2, 25, 18, 0X000000, "X");
	lst->t1 = 225;
	lst->t2 = 100;
	put_cub_bis(20, 505, lst);
}

void	next_marge(t_tri *lst)
{
	lst->color = 0XFFFF00;
	put_cub_bis(255, 400, lst);
	lst->color = 0X3A8EBA;
	put_cub_bis(255, 505, lst);
	lst->color = 0XFFFFFF;
	mlx_string_put(lst->mlx, lst->win2, 60, 140, 0X00FF00, "ZOOM +");
	lst->t1 = 50;
	lst->t2 = 50;
	put_cub_bis(70, 170, lst);
	mlx_string_put(lst->mlx, lst->win2, 130, 140, 0X00FF00, "ZOOM -");
	put_cub_bis(130, 170, lst);
	mlx_string_put(lst->mlx, lst->win2, 330, 140, 0X00FF00, "Z +");
	put_cub_bis(320, 170, lst);
	mlx_string_put(lst->mlx, lst->win2, 390, 140, 0X00FF00, "Z -");
	put_cub_bis(380, 170, lst);
	mlx_string_put(lst->mlx, lst->win2, 200, 240, 0X00FF00, "DIRECTION");
	put_cub_bis(220, 270, lst);
	put_cub_bis(220, 330, lst);
	put_cub_bis(160, 330, lst);
	put_cub_bis(280, 330, lst);
}

void	last_marge(t_tri *lst)
{
	mlx_string_put(lst->mlx, lst->win2, 240, 670, 0X00FF00, "Z");
	put_cub_bis(220, 700, lst);
	put_cub_bis(220, 760, lst);
	mlx_string_put(lst->mlx, lst->win2, 140, 670, 0X00FF00, "Y");
	put_cub_bis(120, 700, lst);
	put_cub_bis(120, 760, lst);
	mlx_string_put(lst->mlx, lst->win2, 340, 670, 0X00FF00, "X");
	put_cub_bis(320, 700, lst);
	put_cub_bis(320, 760, lst);
	lst->t1 = 20;
	lst->t2 = 20;
	lst->color = 0XFFFF00;
	put_cub_bis(445, 20, lst);
	lst->color = 0XFFFFFF;
	mlx_string_put(lst->mlx, lst->win2, 425, 40, 0X00FF00, "RESET");
}

void	affiche_marge(t_tri *lst)
{
	lst->color = 0X22427C;
	lst->t1 = 500;
	lst->t2 = 15;
	put_cub_bis(0, 0, lst);
	put_cub_bis(0, 985, lst);
	lst->t1 = 15;
	lst->t2 = 1000;
	put_cub_bis(0, 0, lst);
	put_cub_bis(485, 0, lst);
	lst->t1 = 10;
	lst->t2 = 60;
	lst->color = 0XFFFFFF;
	put_cub_bis(150, 50, lst);
	put_cub_bis(300, 50, lst);
	put_cub_bis(250, 50, lst);
	lst->t1 = 40;
	lst->t2 = 10;
	put_cub_bis(150, 50, lst);
	put_cub_bis(300, 50, lst);
	lst->t1 = 25;
	lst->t2 = 10;
	suite_marge(lst);
	next_marge(lst);
	last_marge(lst);
}

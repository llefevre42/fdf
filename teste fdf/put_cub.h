/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_cub.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llefevre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 21:44:28 by llefevre          #+#    #+#             */
/*   Updated: 2017/05/20 20:40:03 by llefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUT_CUB_H
# define PUT_CUB_H

struct	s_tri
{
	void			*mlx;
	void			*win;
	long int		color;
	int				lon;
	void			*pt_img;
	char			*img;
	int				chang;

};
typedef struct s_tri	t_tri;

#endif

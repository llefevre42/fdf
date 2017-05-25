/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llefevre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/21 15:34:06 by llefevre          #+#    #+#             */
/*   Updated: 2017/05/25 22:40:33 by llefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "./libft/libft.h"
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h> 		//delete
# define BUFSIZE 256

struct	s_tri
{
	void			*mlx;
	void			*win;
	char			*input;
	long int		color;
	int				lon;
	int				centrex;
	int				centrey;
	int				zoom;
	int				nbr_zoom;
	int				haut;
	int				droite;
	int				xp;
	int				yp;
	int				xs;
	int				ys;
};
typedef struct s_tri	t_tri;

#endif

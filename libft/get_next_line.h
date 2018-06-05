/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llefevre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 16:12:22 by llefevre          #+#    #+#             */
/*   Updated: 2017/10/06 23:57:48 by llefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 5000000
# include "libft.h"
# include <unistd.h>
# include <stdlib.h>

struct	s_gnl
{
	char			*str;
	int				itm;
	int				fd;
	int				read;
	struct s_gnl	*next;
};
typedef struct s_gnl	t_gnl;

#endif

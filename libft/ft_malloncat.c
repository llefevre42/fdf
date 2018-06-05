/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mallobufcat.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llefevre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 11:06:17 by llefevre          #+#    #+#             */
/*   Updated: 2017/10/06 22:20:45 by llefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_malloncat(char *in, char *buf, size_t n)
{
	size_t	i;
	ssize_t	j;
	size_t	k;
	char	*out;

	j = -1;
	k = 0;
	i = (in ? ft_strlen(in) : 0);
	if (!(out = (char*)ft_memalloc(sizeof(char) * (i + n + 1))))
		return (0);
	while (in && in[++j])
		out[j] = in[j];
	while (n-- > 0)
		out[j++] = buf[k++];
	out[j] = '\0';
	if (in)
	{
		ft_strclr(in);
		ft_strdel(&in);
	}
	return (out);
}

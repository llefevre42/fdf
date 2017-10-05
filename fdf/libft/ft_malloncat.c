/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mallobufcat.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llefevre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 11:06:17 by llefevre          #+#    #+#             */
/*   Updated: 2017/08/29 11:41:46 by llefevre         ###   ########.fr       */
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
	if (!(in))
		in = malloc(0);
	i = ft_strlen(in);
	if (!(out = malloc(sizeof(char) * (i + n + 1))))
		return (0);
	while (in[++j])
		out[j] = in[j];
	while (n-- > 0)
		out[j++] = buf[k++];
	out[j] = '\0';
	ft_strclr(in);
	ft_strdel(&in);
	return (out);
}

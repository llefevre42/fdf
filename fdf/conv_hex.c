/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_hex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llefevre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 18:57:47 by llefevre          #+#    #+#             */
/*   Updated: 2017/06/14 22:36:05 by llefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

double		ft_pow(double x, double y)
{
	return (exp(log(x) * y));
}

void		ft_convert(char *hex, int i, long *sum)
{
	int			len;

	len = 0;
	while (hex[len] != '\0')
		len++;
	while (hex[i] != '\0')
	{
		if (hex[i] >= '0' && hex[i] <= '9')
			*sum += (hex[i] - '0') * ft_pow(16, len - 1);
		if (hex[i] >= 'A' && hex[i] <= 'F')
			*sum += (hex[i] - 55) * ft_pow(16, len - 1);
		if (hex[i] >= 'a' && hex[i] <= 'f')
			*sum += (hex[i] - 87) * ft_pow(16, len - 1);
		i++;
		len--;
	}
}

long			ft_htoi(char *hex)
{
	int			i;
	long		sum;
	int			minus;

	i = 0;
	minus = 0;
	if (hex[i] == '-')
		minus = 1;
	sum = 0;
	ft_convert(hex, i, &sum);
	if (ft_strcmp(hex, "10") == 0)
		return (16);
	if (ft_strcmp(hex, "-10") == 0)
		return (-16);
	if (sum > 15)
		sum++;
	if (minus)
		return (-sum);
	return (sum);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 11:47:31 by mdubina           #+#    #+#             */
/*   Updated: 2017/01/20 13:32:43 by mdubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ft_atoi_hex(char *str)
{
	char	*base;
	char	*base1;
	int		i;
	int		j;
	int		res;

	base = "0123456789ABCDEF";
	base1 = "0123456789abcdef";
	i = 0;
	res = 0;
	while ((str[i] >= 48 && str[i] <= 57) || (str[i] >= 'A' && str[i] <= 'F') \
		|| (str[i] >= 'a' && str[i] <= 'f'))
	{
		j = 0;
		while (j < 16)
		{
			if (str[i] == base[j] || str[i] == base1[j])
				res = res * 16 + j;
			j++;
		}
		i++;
		if (i == 2)
			break ;
	}
	return (res);
}

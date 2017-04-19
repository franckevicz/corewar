/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 11:37:02 by mdubina           #+#    #+#             */
/*   Updated: 2017/02/10 17:54:56 by mdubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long int		ft_atoi(const char *str)
{
	long int	res;
	long int	i;
	long int	sign;

	i = 0;
	sign = 1;
	res = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' || str[i] == '\r'\
	|| str[i] == '\f' || str[i] == '\v')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] > 47 && str[i] < 58 && str[i])
	{
		res = res * 10 + (str[i] - 48);
		i++;
	}
	return (res * sign);
}

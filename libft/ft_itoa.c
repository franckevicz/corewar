/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 14:30:12 by mdubina           #+#    #+#             */
/*   Updated: 2016/12/03 12:20:26 by mdubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			count(int n)
{
	int				i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		i++;
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static char			*swap(char *str)
{
	size_t			i;
	size_t			len;
	char			s;

	i = 0;
	len = 0;
	while (str[len])
		len++;
	len -= 1;
	while (i < len)
	{
		s = str[i];
		str[i] = str[len];
		str[len] = s;
		i++;
		len--;
	}
	return (str);
}

static char			*fill(char *res, int sign, int len, int n)
{
	int				i;
	unsigned int	num;

	i = 0;
	if (n < 0)
		n *= -1;
	num = (unsigned int)n;
	while (i < len)
	{
		res[i] = (num % 10) + '0';
		num = num / 10;
		i++;
	}
	if (sign)
		res[i - 1] = '-';
	res[i] = '\0';
	return (res);
}

char				*ft_itoa(long long int n)
{
	char			*res;
	int				len;
	int				sign;

	len = count(n);
	sign = 0;
	if ((res = (char *)malloc(sizeof(char) * (len + 1))) == 0)
		return (NULL);
	if (n == 0 || n == -0)
	{
		res[0] = '0';
		res[1] = '\0';
		return (res);
	}
	if (n < 0)
		sign = 1;
	res = fill(res, sign, len, n);
	return (swap(res));
}

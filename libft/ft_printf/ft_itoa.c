/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 14:30:12 by mdubina           #+#    #+#             */
/*   Updated: 2017/01/08 12:50:28 by mdubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int			count(long long int n)
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

static char			*fill(char *res, int len, long long int n)
{
	int						i;
	unsigned long long int	num;

	i = 0;
	if (n < 0)
		n *= -1;
	num = (unsigned long long int)n;
	while (i < len)
	{
		res[i] = (num % 10) + '0';
		num = num / 10;
		i++;
	}
	if (res[i - 1] == '0')
		res[i - 1] = '\0';
	else
		res[i] = '\0';
	return (res);
}

char				*ft_itoa(long long int n)
{
	char			*res;
	int				len;

	len = count(n);
	if ((res = (char *)malloc(sizeof(char) * (len + 1))) == 0)
		return (NULL);
	if (n == 0 || n == -0)
	{
		res[0] = '0';
		res[1] = '\0';
		return (res);
	}
	res = fill(res, len, n);
	return (swap(res));
}

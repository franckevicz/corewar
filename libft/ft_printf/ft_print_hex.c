/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 19:23:18 by mdubina           #+#    #+#             */
/*   Updated: 2017/01/08 18:16:11 by mdubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int			count(unsigned long long int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static char			*swap(char *str)
{
	size_t	i;
	size_t	len;
	char	s;

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

char				*ft_print_hex(unsigned long long n, int x)
{
	char			*res;
	unsigned int	len;
	int				i;
	char			*mas;

	x ? (mas = "0123456789abcdef") : \
		(mas = "0123456789ABCDEF");
	len = count(n);
	i = 0;
	if ((res = (char *)malloc(sizeof(char) * (len + 1))) == 0)
		return (NULL);
	if (n == 0 || n == -0)
	{
		res[0] = '0';
		res[1] = '\0';
		return (res);
	}
	while (n)
	{
		res[i] = mas[n % 16];
		n /= 16;
		i++;
	}
	res[i] = '\0';
	return (swap(res));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_octal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/29 13:46:13 by mdubina           #+#    #+#             */
/*   Updated: 2017/01/08 13:53:22 by mdubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	count(unsigned long long int n)
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

static char	*swap(char *str)
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

char		*ft_print_octal_o(unsigned long long n)
{
	char			*res;
	unsigned int	len;
	int				i;

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
		res[i] = (n % 8) + 48;
		n /= 8;
		i++;
	}
	res[i] = '\0';
	return (swap(res));
}

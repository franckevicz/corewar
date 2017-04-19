/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 17:06:34 by mdubina           #+#    #+#             */
/*   Updated: 2017/01/08 16:23:38 by mdubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

unsigned long long	ft_transform_u(int *array, va_list ap, int count, char c)
{
	unsigned long long nb;

	nb = 0;
	if (count == 0 && c != 'U')
		nb = (unsigned int)va_arg(ap, int);
	else if ((array[1] == 1 && count == 1) || c == 'U' || c == 'O')
		nb = (unsigned long int)va_arg(ap, long int);
	else if (array[1] == 2 && count == 2)
		nb = (unsigned long long)va_arg(ap, long long int);
	else if (array[0] == 1 && count == 1)
		nb = (unsigned short int)va_arg(ap, int);
	else if (array[0] == 2 && count == 2)
		nb = (unsigned char)va_arg(ap, int);
	else if (array[2] == 1 && count == 1)
		nb = va_arg(ap, long long int);
	else if (array[3] == 1 && count == 1)
		nb = (unsigned long long)va_arg(ap, size_t);
	return (nb);
}

void				ft_if_width_u(int *array, char *s, int tmp)
{
	while ((array[9] - ft_strlen_1(s) - array[8]) > 0)
	{
		ft_helper_putchar('0');
		array[9]--;
	}
	if (array[8])
		ft_helper_putchar('0');
	if (array[11] && s[0] == '0' && array[9])
	{
		ft_putchar('0');
		array[8] = 0;
	}
	else if (array[11] && !array[9] && s[0] == '0')
		ft_putchar(' ');
	else
		ft_putstr(s);
	if ((array[11] && !array[9]) || (array[8] && !array[11]))
		array[10]--;
	while ((array[10] - tmp - array[6]) > 0)
	{
		ft_helper_putchar(' ');
		array[10]--;
	}
}

void				ft_if_min_width_u(int *array, char *s, int tmp)
{
	if ((array[8] && s[0] == '0' && !array[11]) || (array[8] && array[9]))
		ft_helper_putchar(' ');
	while ((array[10] - tmp - array[6] - array[8]) > 0 && array[7])
	{
		ft_helper_putchar('0');
		array[10]--;
	}
	while ((array[9] - ft_strlen_1(s) - array[8]) > 0)
	{
		ft_helper_putchar('0');
		array[9]--;
	}
	if (array[8] && (array[9] || s[0] != '0'))
		ft_helper_putchar('0');
	if (array[11] && !array[9] && s[0] == '0' && array[10])
		ft_putchar(' ');
	else if (array[11] && !array[9] && s[0] == '0' && !array[10])
		array[8] ? ft_putchar('0') : g_counter--;
	else
		ft_putstr(s);
}

void				ft_helper_putchar(char c)
{
	ft_putchar(c);
	g_counter++;
}

void				ft_parse_u(int *array, va_list ap, char c)
{
	unsigned long long	nb;
	char				*s;
	int					tmp;
	int					count;

	count = array[0] + array[1] + array[2] + array[3];
	nb = ft_transform_u(array, ap, count, c);
	s = ft_itoa_u(nb);
	ft_strlen_1(s) > array[9] ? (tmp = ft_strlen_1(s)) : \
		(tmp = array[9]);
	array[8] = 0;
	if (array[4])
		ft_if_width_u(array, s, tmp);
	else
	{
		while ((array[10] - tmp - array[6] - array[8]) > 0 && (array[9] || \
			(!array[9] && !array[7]) || s[0] == '0'))
		{
			ft_helper_putchar(' ');
			array[10]--;
		}
		ft_if_min_width_u(array, s, tmp);
	}
	g_counter += ft_strlen_1(s);
	free(s);
}

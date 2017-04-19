/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 11:23:06 by mdubina           #+#    #+#             */
/*   Updated: 2017/01/08 16:22:16 by mdubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void			ft_print_sign(int *array, long long int nb)
{
	if (array[5] > 0 && nb >= 0)
	{
		ft_putchar('+');
		g_counter++;
	}
	if (nb < 0)
	{
		ft_putchar('-');
		g_counter++;
	}
	if (array[6] && !array[5] && nb >= 0)
	{
		ft_putchar(' ');
		g_counter++;
	}
}

long long int	ft_transform_d(int *array, va_list ap, int count, char c)
{
	long long int nb;

	nb = 0;
	if (count == 0 && c != 'D')
		nb = (int)va_arg(ap, int);
	else if (array[3] == 1)
		nb = (unsigned long long)va_arg(ap, size_t);
	else if (array[2] == 1)
		nb = va_arg(ap, long long int);
	else if ((array[1] == 1) || (count == 0 && c == 'D'))
		nb = (long int)va_arg(ap, long int);
	else if (array[0] == 2)
		nb = (signed char)va_arg(ap, int);
	else if ((array[1] == 1 && count == 1) || (count == 0 && c == 'D'))
		nb = (long int)va_arg(ap, long int);
	else if (array[1] == 2 && count == 2)
		nb = va_arg(ap, long long);
	else if (array[0] == 1 && count == 1)
		nb = (short int)va_arg(ap, int);
	return (nb);
}

void			ft_if_width(int *array, char *s, long long int nb, int tmp)
{
	ft_print_sign(array, nb);
	while ((array[9] - ft_strlen_1(s)) > 0)
	{
		ft_putchar('0');
		g_counter++;
		array[9]--;
	}
	if (array[11] && !array[9] && s[0] == '0' && !array[10])
		!array[10] ? g_counter-- : ft_putchar(' ');
	else
		ft_putstr(s);
	if (array[5])
		array[6] = 0;
	while ((array[10] - tmp - array[6]) > 0)
	{
		ft_putchar(' ');
		g_counter++;
		array[10]--;
	}
}

void			ft_if_min_width(int *array, char *s, long long int nb, int tmp)
{
	while ((array[10] - tmp - array[6]) > 0 && (array[9] || (!array[9] \
					&& !array[7])))
	{
		ft_putchar(' ');
		g_counter++;
		array[10]--;
	}
	ft_print_sign(array, nb);
	while ((array[10] - tmp - array[6]) > 0 && array[7])
	{
		ft_putchar('0');
		g_counter++;
		array[10]--;
	}
	while ((array[9] - ft_strlen_1(s)) > 0)
	{
		ft_putchar('0');
		g_counter++;
		array[9]--;
	}
	if (array[11] && !array[9] && s[0] == '0')
		!array[10] ? g_counter-- : ft_putchar(' ');
	else
		ft_putstr(s);
}

void			ft_parse_d(int *array, va_list ap, char c)
{
	long long int	nb;
	char			*s;
	int				tmp;
	int				count;

	count = array[0] + array[1] + array[2] + array[3];
	nb = ft_transform_d(array, ap, count, c);
	s = ft_itoa(nb);
	if (ft_strlen_1(s) > array[9])
		tmp = ft_strlen_1(s);
	else
		tmp = array[9];
	if (nb < 0 || array[5])
		tmp++;
	if (array[4])
		ft_if_width(array, s, nb, tmp);
	else
		ft_if_min_width(array, s, nb, tmp);
	g_counter += ft_strlen_1(s);
	free(s);
}

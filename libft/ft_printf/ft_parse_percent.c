/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_percent.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 13:09:17 by mdubina           #+#    #+#             */
/*   Updated: 2017/01/08 16:33:27 by mdubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_parse_percent(int *array)
{
	if (!array[4])
	{
		while ((array[10] - 1) > 0)
		{
			array[7] ? ft_putchar('0') : ft_putchar(' ');
			g_counter++;
			array[10]--;
		}
		ft_putchar('%');
		g_counter++;
	}
	else
	{
		ft_putchar('%');
		g_counter++;
		while ((array[10] - 1) > 0)
		{
			ft_putchar(' ');
			g_counter++;
			array[10]--;
		}
	}
}

void	ft_parse_p(int *array, va_list ap)
{
	char	*s;
	int		tmp;

	s = ft_print_hex(va_arg(ap, unsigned long long int), 1);
	array[8] = 2;
	if (ft_strlen_1(s) > array[9])
		tmp = ft_strlen_1(s);
	else
		tmp = array[9];
	if (s[0] == '0')
	{
		ft_putstr("0x");
		g_counter += 2;
	}
	if (array[4])
		ft_if_width_x(array, s, tmp, 'x');
	else
		ft_if_min_width_x(array, s, tmp, 'x');
	g_counter += ft_strlen_1(s);
	free(s);
}

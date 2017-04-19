/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 15:57:43 by mdubina           #+#    #+#             */
/*   Updated: 2017/01/08 15:26:18 by mdubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_parse_c(int *array, va_list ap, char c)
{
	char s;

	if (c == 'c')
	{
		s = va_arg(ap, int);
		array[4] ? ft_if_width_c(array, s) : ft_if_min_width_c(array, s);
	}
	else
		array[4] ? ft_if_width_uc(array, va_arg(ap, wchar_t)) : \
			ft_if_min_width_uc(array, va_arg(ap, wchar_t));
}

void	ft_if_width_c(int *array, char s)
{
	ft_putchar(s);
	g_counter++;
	while ((array[10] - 1) > 0)
	{
		ft_putchar(' ');
		g_counter++;
		array[10]--;
	}
}

void	ft_if_min_width_c(int *array, char s)
{
	while ((array[10] - 1) > 0)
	{
		array[7] ? ft_putchar('0') : ft_putchar(' ');
		g_counter++;
		array[10]--;
	}
	ft_putchar(s);
	g_counter++;
}

void	ft_if_width_uc(int *array, wchar_t s)
{
	write(1, &s, 1);
	g_counter++;
	while ((array[10] - 1) > 0)
	{
		ft_putchar(' ');
		g_counter++;
		array[10]--;
	}
}

void	ft_if_min_width_uc(int *array, wchar_t s)
{
	while ((array[10] - 1) > 0)
	{
		ft_putchar(' ');
		g_counter++;
		array[10]--;
	}
	write(1, &s, 1);
	g_counter++;
}

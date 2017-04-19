/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 13:04:01 by mdubina           #+#    #+#             */
/*   Updated: 2017/01/08 15:28:28 by mdubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_parse_s(int *array, va_list ap, char c)
{
	char *s;

	if (c == 's')
	{
		s = va_arg(ap, char *);
		if (s == NULL && c == 's')
		{
			s = (char *)malloc(sizeof(char) * 7);
			s = "(null)";
		}
		array[4] ? ft_if_width_s(array, s) : ft_if_min_width_s(array, s);
	}
	else
		array[4] ? ft_if_width_us(array, va_arg(ap, int*)) : \
			ft_if_min_width_us(array, va_arg(ap, int*));
}

void	ft_if_width_s(int *array, char *s)
{
	int i;

	i = 0;
	while (((array[9] - i) > 0 && s[i]) || (s[i] && !array[9]))
	{
		ft_putchar(s[i]);
		i++;
		g_counter++;
	}
	while ((array[10] - i) > 0)
	{
		ft_putchar(' ');
		g_counter++;
		i++;
	}
}

void	ft_if_min_width_s(int *array, char *s)
{
	int i;
	int tmp;

	i = 0;
	array[9] ? (tmp = array[9]) : \
		(tmp = ft_strlen_1(s));
	while ((array[10] - tmp) > 0)
	{
		array[7] ? ft_putchar('0') : ft_putchar(' ');
		g_counter++;
		array[10]--;
	}
	while (i < tmp && s[i])
	{
		ft_putchar(s[i]);
		i++;
		g_counter++;
		array[10]--;
	}
	while (i < tmp && array[10])
	{
		ft_putchar(' ');
		i++;
		g_counter++;
	}
}

void	ft_if_width_us(int *array, int *s)
{
	int i;

	i = 0;
	while (((array[9] - i) > 0 && s[i]) || (s[i] && !array[9]))
	{
		write(1, &s[i], 1);
		i++;
		g_counter++;
	}
	while ((array[10] - i) > 0)
	{
		ft_putchar(' ');
		g_counter++;
		i++;
	}
}

void	ft_if_min_width_us(int *array, int *s)
{
	int i;
	int tmp;

	i = 0;
	array[9] ? (tmp = array[9]) : \
		(tmp = ft_strlen_int(s));
	while ((array[10] - tmp) > 0)
	{
		ft_putchar(' ');
		g_counter++;
		array[10]--;
	}
	while (i < tmp && s[i])
	{
		write(1, &s[i], 1);
		i++;
		g_counter++;
		array[10]--;
	}
	while (i < tmp && array[10])
	{
		ft_putchar(' ');
		i++;
		g_counter++;
	}
}

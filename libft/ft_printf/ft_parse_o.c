/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_o.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 18:34:11 by mdubina           #+#    #+#             */
/*   Updated: 2017/01/09 11:23:47 by mdubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_parse_o(int *array, va_list ap, char c)
{
	unsigned long long	nb;
	char				*s;
	int					tmp;
	int					count;

	count = array[0] + array[1] + array[2] + array[3];
	nb = ft_transform_u(array, ap, count, c);
	s = ft_print_octal_o(nb);
	ft_strlen_1(s) > array[9] ? (tmp = ft_strlen_1(s)) : \
		(tmp = array[9]);
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

void	ft_parse_x(int *array, va_list ap, char c)
{
	unsigned long long	nb;
	char				*s;
	int					tmp;
	int					count;

	count = array[0] + array[1] + array[2] + array[3];
	nb = ft_transform_u(array, ap, count, c);
	s = ft_print_hex(nb, (c == 'x' ? 1 : 0));
	if (array[8])
		array[8] = 2;
	if (ft_strlen_1(s) > array[9])
		tmp = ft_strlen_1(s);
	else
		tmp = array[9];
	if (array[4])
		ft_if_width_x(array, s, tmp, c);
	else
		ft_if_min_width_x(array, s, tmp, c);
	g_counter += ft_strlen_1(s);
	free(s);
}

void	ft_if_width_x(int *array, char *s, int tmp, char c)
{
	if (array[8] && s[0] != '0')
	{
		c == 'x' ? ft_putstr("0x") : ft_putstr("0X");
		g_counter += 2;
	}
	while ((array[9] - ft_strlen_1(s)) > 0)
	{
		ft_putchar('0');
		g_counter++;
		array[9]--;
	}
	if (array[11] && !array[9] && s[0] == '0')
	{
		ft_putchar(' ');
		array[8] = 0;
	}
	else
		ft_putstr(s);
	while ((array[10] - tmp - array[6] - array[8]) > 0)
	{
		ft_putchar(' ');
		g_counter++;
		array[10]--;
	}
}

void	ft_if_min_width_x(int *array, char *s, int tmp, char c)
{
	if (array[11] && s[0] == '0' && !array[9])
	{
		array[8] = 0;
		s[0] = ' ';
	}
	while ((array[10] - tmp - array[6] - array[8]) > 0 && (array[9] || \
				(!array[9] && !array[7]) || s[0] == ' '))
	{
		ft_putchar(' ');
		g_counter++;
		array[10]--;
	}
	if (array[8] && s[0] != '0')
	{
		c == 'x' ? ft_putstr("0x") : ft_putstr("0X");
		g_counter += 2;
	}
	ft_if_min_width_x2(array, s, tmp);
}

void	ft_if_min_width_x2(int *array, char *s, int tmp)
{
	while ((array[10] - tmp - array[6] - array[8]) > 0 && array[7])
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
	if (array[11] && !array[9] && s[0] == ' ' && !array[10])
		g_counter--;
	else
		ft_putstr(s);
}

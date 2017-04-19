/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/26 11:37:40 by mdubina           #+#    #+#             */
/*   Updated: 2017/01/09 12:27:46 by mdubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_print(int *array, va_list ap, char c)
{
	if (c == 'd' || c == 'D' || c == 'i')
		ft_parse_d(array, ap, c);
	else if (c == 'u' || c == 'U')
		ft_parse_u(array, ap, c);
	else if (c == 'o' || c == 'O')
		ft_parse_o(array, ap, c);
	else if (c == 'x' || c == 'X')
		ft_parse_x(array, ap, c);
	else if (c == 's' || c == 'S')
		ft_parse_s(array, ap, c);
	else if (c == 'c' || c == 'C')
		ft_parse_c(array, ap, c);
	else if (c == 'p')
		ft_parse_p(array, ap);
	else if (c == '%')
		ft_parse_percent(array);
}

void	ft_parse(va_list ap, int *i, const char *format)
{
	int array[12];
	int z;

	z = 0;
	while (z < 12)
		array[z++] = 0;
	(*i)++;
	while (format[*i])
	{
		if (!ft_is_modificator(format[*i]) && !ft_is_specifier(format[*i]) \
			&& !ft_isdigit(format[*i]))
		{
			(*i)--;
			return ;
		}
		ft_parse_modificator(i, format, array);
		ft_parse_modificator2(i, format, array);
		if (ft_is_specifier(format[*i]))
			break ;
		(*i)++;
	}
	ft_is_specifier(format[*i]) ? ft_print(array, ap, format[*i]) : (*i)--;
}

void	ft_parse_modificator2(int *i, const char *format, int *array)
{
	if (format[*i] == '.')
	{
		(*i)++;
		array[11]++;
		array[9] = ft_atoi(&(format[*i]));
		while (ft_isdigit(format[*i]))
			(*i)++;
	}
	if (format[*i] == '+')
		array[5]++;
}

void	ft_parse_modificator(int *i, const char *format, int *array)
{
	if (format[*i] == '0' && (ft_isdigit_zero(format[(*i) + 1]) \
		|| format[(*i) + 1] == '+'))
		array[7]++;
	if (ft_isdigit_zero(format[*i]) && format[(*i) - 1] != '.')
	{
		array[10] = ft_atoi(&(format[*i]));
		while (ft_isdigit(format[*i]))
			(*i)++;
	}
	if (format[*i] == 'h')
		array[0]++;
	if (format[*i] == 'l')
		array[1]++;
	if (format[*i] == 'j')
		array[2]++;
	if (format[*i] == 'z')
		array[3]++;
	if (format[*i] == '-')
		array[4]++;
	if (format[*i] == ' ')
		array[6]++;
	if (format[*i] == '#')
		array[8]++;
}

int		ft_printf(const char *format, ...)
{
	int		i;
	va_list	ap;

	g_counter = 0;
	va_start(ap, format);
	i = 0;
	while (format[i])
	{
		if (format[i] == '%' && !format[i + 1])
			return (g_counter);
		if (format[i] == '%')
		{
			ft_parse(ap, &i, format);
			i++;
		}
		else
		{
			ft_putchar(format[i++]);
			g_counter++;
		}
	}
	va_end(ap);
	return (g_counter);
}

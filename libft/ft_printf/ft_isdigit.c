/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 16:26:57 by mdubina           #+#    #+#             */
/*   Updated: 2017/01/08 12:48:42 by mdubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int c)
{
	if (c > 47 && c < 58)
		return (1);
	return (0);
}

int	ft_isdigit_zero(int c)
{
	if (c > 48 && c < 58)
		return (1);
	return (0);
}

int	ft_is_specifier(char c)
{
	if (c == 's' || c == 'S' || c == 'p' || c == 'D' || c == 'd' || c == 'i' \
			|| c == 'o' || c == 'O' || c == 'u' || c == 'U' || c == 'x' || \
			c == 'X' || c == 'c' || c == 'C' || c == '%')
		return (1);
	return (0);
}

int	ft_is_modificator(char c)
{
	if (c == '0' || c == 'h' || c == 'l' || c == 'j' || c == 'z' || c == '-' \
			|| c == ' ' || c == '#' || c == '.' || c == '+')
		return (1);
	return (0);
}

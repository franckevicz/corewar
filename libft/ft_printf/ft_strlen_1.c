/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 14:32:12 by mdubina           #+#    #+#             */
/*   Updated: 2017/02/10 17:54:10 by mdubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_strlen_1(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int		ft_strlen_int(int *s)
{
	int i;

	i = 0;
	while (s[i] != 0)
		i++;
	return (i);
}

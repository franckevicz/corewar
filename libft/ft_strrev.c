/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 16:04:32 by mdubina           #+#    #+#             */
/*   Updated: 2016/12/01 16:11:48 by mdubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrev(char *str)
{
	int		i;
	int		d;
	char	temp;

	i = 0;
	d = ft_strlen(str) - 1;
	while (i < d)
	{
		temp = str[d];
		str[d] = str[i];
		str[i] = temp;
		i++;
		d--;
	}
	return (str);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 19:21:38 by mdubina           #+#    #+#             */
/*   Updated: 2016/11/26 20:40:56 by mdubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnew(size_t size)
{
	char	*str;
	size_t	i;

	i = 0;
	if ((str = ft_memalloc(size + 1)))
	{
		while (i < size)
		{
			str[i] = 0;
			i++;
		}
		return (str);
	}
	return (NULL);
}

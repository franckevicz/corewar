/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 12:22:55 by mdubina           #+#    #+#             */
/*   Updated: 2016/11/25 13:37:58 by mdubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memchr(const void *str, int c, size_t n)
{
	size_t			i;

	i = 0;
	while (i < n)
	{
		if (((char *)str)[i] == c)
		{
			return ((unsigned char*)str + i);
		}
		i++;
	}
	return (NULL);
}

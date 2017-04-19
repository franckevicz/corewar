/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 14:21:44 by mdubina           #+#    #+#             */
/*   Updated: 2016/11/24 14:16:54 by mdubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	y;
	size_t	siz;

	i = 0;
	siz = size;
	while (dst[i] && siz != 0)
	{
		i++;
		siz--;
	}
	if (size - i == 0)
		return (ft_strlen(src) + i);
	y = ft_strlen(dst) + ft_strlen(src);
	while (*src && siz - 1 != 0)
	{
		dst[i] = *src;
		src++;
		i++;
		siz--;
	}
	dst[i] = '\0';
	return (y);
}

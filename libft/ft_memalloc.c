/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 17:36:13 by mdubina           #+#    #+#             */
/*   Updated: 2016/11/24 19:07:13 by mdubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memalloc(size_t size)
{
	char	*ptr;
	size_t	i;

	if ((ptr = malloc(sizeof(*ptr) * size)))
	{
		i = 0;
		while (i < size)
		{
			ptr[i] = 0;
			i++;
		}
		return ((void *)ptr);
	}
	return (NULL);
}

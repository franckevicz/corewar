/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 18:55:55 by mdubina           #+#    #+#             */
/*   Updated: 2016/11/21 19:03:02 by mdubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *memptr, int val, size_t num)
{
	unsigned int i;

	i = 0;
	while (i < num)
	{
		((char*)memptr)[i] = (char)val;
		i++;
	}
	return (memptr);
}

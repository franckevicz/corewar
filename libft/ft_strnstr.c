/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 10:29:49 by mdubina           #+#    #+#             */
/*   Updated: 2016/11/24 19:51:12 by mdubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	y;
	size_t	z;
	char	*res;

	i = 0;
	res = (char*)big;
	if (ft_strlen(little) == 0)
		return (&(res[i]));
	while (big[i] && i < len)
	{
		y = 0;
		z = i;
		while (big[i] == little[y] && little[y] && i < len)
		{
			i++;
			y++;
			if (little[y] == '\0')
				return (&(res[z]));
		}
		i++;
	}
	return (NULL);
}

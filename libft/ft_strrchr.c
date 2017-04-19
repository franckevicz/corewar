/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 09:51:10 by mdubina           #+#    #+#             */
/*   Updated: 2016/11/24 15:52:14 by mdubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrchr(const char *s, int c)
{
	char	*res;
	int		i;

	i = 0;
	res = (char *)s;
	while (s[i])
		i++;
	while (i >= 0)
	{
		if (res[i] == c)
			return (&res[i]);
		i--;
	}
	return (NULL);
}

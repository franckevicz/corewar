/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 09:31:55 by mdubina           #+#    #+#             */
/*   Updated: 2016/11/24 15:50:17 by mdubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strchr(const char *s, int c)
{
	char	*res;
	int		i;

	i = 0;
	res = (char *)s;
	while (res[i])
	{
		if (s[i] == c)
			return (&(res[i]));
		i++;
	}
	if (s[i] == c)
		return (&(res[i]));
	return (NULL);
}

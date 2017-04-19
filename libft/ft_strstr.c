/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 10:00:11 by mdubina           #+#    #+#             */
/*   Updated: 2016/11/24 16:45:46 by mdubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strstr(const char *big, const char *little)
{
	int		i;
	int		y;
	int		z;
	char	*res;

	i = 0;
	res = (char *)big;
	if (ft_strlen(little) == 0)
		return (&(res[i]));
	while (big[i])
	{
		y = 0;
		z = i;
		while (big[i] == little[y] && little[y])
		{
			i++;
			y++;
			if (little[y] == '\0')
				return (&(res[z]));
		}
		i = z;
		i++;
	}
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 14:07:58 by mdubina           #+#    #+#             */
/*   Updated: 2016/12/23 14:38:35 by mdubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		y;

	if (!(s1) || !(s2))
		return (NULL);
	if ((str = ft_strnew(ft_strlen(s1) + ft_strlen(s2))))
	{
		i = 0;
		while (s1[i])
		{
			str[i] = s1[i];
			i++;
		}
		y = 0;
		while (s2[y])
		{
			str[i] = s2[y];
			y++;
			i++;
		}
		str[i] = '\0';
		return (str);
	}
	return (NULL);
}

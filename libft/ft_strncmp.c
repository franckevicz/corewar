/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 11:19:26 by mdubina           #+#    #+#             */
/*   Updated: 2016/12/02 11:10:20 by mdubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*s3;
	unsigned char	*s4;

	s3 = (unsigned char*)s1;
	s4 = (unsigned char*)s2;
	i = 0;
	if (i == n)
		return (0);
	while (s3[i] == s4[i] && i < n)
	{
		if ((s3[i] == '\0' && s4[i] == '\0') || i == n - 1)
			return (0);
		i++;
	}
	return (s3[i] - s4[i]);
}

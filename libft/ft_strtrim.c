/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 14:33:19 by mdubina           #+#    #+#             */
/*   Updated: 2016/11/30 19:10:35 by mdubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *s)
{
	char	*str;
	int		i;
	int		len;

	i = 0;
	if (!(s))
		return (NULL);
	while (*s == ' ' || *s == '\n' || *s == '\t')
		s++;
	len = ft_strlen(s);
	if (*s != '\0')
	{
		while (s[len - 1] == ' ' || s[len - 1] == '\n' || s[len - 1] == '\t')
			len--;
	}
	if ((str = ((char *)malloc(sizeof(*str) * (len + 1)))) == 0)
		return (str);
	while (i < len)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

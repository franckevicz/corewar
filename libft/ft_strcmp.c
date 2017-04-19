/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 10:51:23 by mdubina           #+#    #+#             */
/*   Updated: 2016/11/26 20:37:03 by mdubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 == *s2)
	{
		s1++;
		s2++;
		if ((unsigned char)*s1 == '\0' && (unsigned char)*s2 == '\0')
			return (0);
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

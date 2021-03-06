/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 15:23:26 by mdubina           #+#    #+#             */
/*   Updated: 2016/11/22 15:25:39 by mdubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcpy(char *dest, const char *src)
{
	int	k;

	k = 0;
	while (src[k])
	{
		dest[k] = src[k];
		k++;
	}
	dest[k] = '\0';
	return (dest);
}

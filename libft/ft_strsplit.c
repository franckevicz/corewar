/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 18:53:51 by mdubina           #+#    #+#             */
/*   Updated: 2016/12/03 12:19:43 by mdubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**words(char **res, const char *s, char c)
{
	int		i;
	int		words;

	i = 0;
	words = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
			words++;
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	if ((res = (char**)malloc(sizeof(*res) * (words + 1))))
	{
		res[words] = 0;
		return (res);
	}
	return (NULL);
}

static char	**letters(char **res, const	char *s, char c)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	while (s[i] == c)
		i++;
	while (s[i] != '\0')
	{
		i++;
		if (s[i] == c || s[i] == '\0')
		{
			if (((res[j] = ft_strnew(k + 1)) == 0))
				return (NULL);
			j++;
			k = 0;
			while (s[i] == c)
				i++;
		}
		k++;
	}
	return (res);
}

static char	**fill_res(char **res, const char *s, char c)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	while (s[i] == c)
		i++;
	while (s[i])
	{
		res[j][k] = s[i];
		i++;
		k++;
		if (s[i] == c)
		{
			res[j][k] = '\0';
			j++;
			k = 0;
			while (s[i] == c)
				i++;
		}
	}
	return (res);
}

char		**ft_strsplit(const char *s, char c)
{
	char	**res;

	if (!(s) || !(c))
		return (NULL);
	res = NULL;
	if (((res = words(res, s, c)) && \
		(res = letters(res, s, c)) && 	\
		(res = fill_res(res, s, c))))
		return (res);
	return (NULL);
}

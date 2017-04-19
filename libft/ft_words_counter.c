/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_brainfuck.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 14:28:17 by mdubina           #+#    #+#             */
/*   Updated: 2016/12/01 14:55:09 by mdubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_words_counter(char *str)
{
	int i;
	int words;

	i = 0;
	words = 0;
	while (str[i] == '\n' || str[i] == '\t' || str[i] == ' ')
		i++;
	while (str[i] != '\n' && str[i] != '\t' && str[i] != ' ' && str[i] != '\0')
	{
		i++;
		if (str[i] == '\n' || str[i] == '\t' || str[i] == ' ')
			words++;
		while (str[i] == '\n' || str[i] == '\t' || str[i] == ' ')
			i++;
	}
	if (str[i - 1] != '\n' && str[i - 1] != '\t' && str[i - 1] != ' ')
		words++;
	return (words);
}

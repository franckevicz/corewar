/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 08:42:32 by mdubina           #+#    #+#             */
/*   Updated: 2016/12/23 16:20:05 by mdubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_strjoin_my(char *s1, char *s2)
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
			str[i++] = s2[y++];
		str[i] = '\0';
		free(s1);
		return (str);
	}
	return (NULL);
}

static int		ft_buff_cheker(char **line, char *buffer)
{
	int i;
	int j;
	int flag;

	i = 0;
	j = 0;
	while (buffer[i] != '\n' && buffer[i])
		i++;
	(buffer[i] == '\n') ? (flag = 1) : \
				(flag = 0);
	if (flag)
	{
		buffer[i++] = '\0';
		*line = ft_strjoin_my(*line, buffer);
		while (buffer[i])
			buffer[j++] = buffer[i++];
		buffer[j] = '\0';
		return (1);
	}
	*line = ft_strjoin_my(*line, buffer);
	buffer[0] = '\0';
	return (0);
}

static void		ft_help(int i, char *str, char **line, char *buffer)
{
	int j;

	j = 0;
	str[i] = '\0';
	i++;
	*line = ft_strjoin_my(*line, str);
	while (str[i])
	{
		buffer[j] = str[i];
		j++;
		i++;
	}
	buffer[j] = '\0';
}

static int		ft_read(int fd, char **line, char *buffer, int flag)
{
	char	*str;
	int		i;
	int		page;

	page = 1;
	while (page && flag != 1)
	{
		str = ft_strnew(BUFF_SIZE);
		page = read(fd, str, BUFF_SIZE);
		i = 0;
		while (i < page && str[i] != '\n')
			i++;
		(str[i] == '\n') ? (flag = 1) : \
				(flag = 0);
		if (flag == 0 && page != 0)
			*line = ft_strjoin_my(*line, str);
		if (flag == 1)
			ft_help(i, str, line, buffer);
		free(str);
	}
	if (page == 0 && !(*line[0]))
		return (0);
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	static char	buffer[BUFF_SIZE];
	int			flag;

	flag = 3;
	if (line == NULL)
		return (-1);
	if (read(fd, *line, 0) == -1)
		return (-1);
	*line = ft_strnew(1);
	if (buffer[0])
	{
		if ((flag = ft_buff_cheker(line, buffer)) != 1)
			return (ft_read(fd, line, buffer, flag));
	}
	return (ft_read(fd, line, buffer, flag));
}

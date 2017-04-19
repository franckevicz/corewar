/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_body.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 17:13:21 by mdubina           #+#    #+#             */
/*   Updated: 2017/03/31 17:13:23 by mdubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
 ** Помечает лейбл у конкретной строки
*/

int		ft_take_label(t_data *s, char *line, int stroka)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (line[i] != LABEL_CHAR && line[i])
		i++;
	if (line[0] == LABEL_CHAR)
		exit(ft_printf("Error: empty label in line #%d\n", stroka));
	if (i != 0 && line[i] == LABEL_CHAR && line[i - 1] != DIRECT_CHAR &&
		line[i - 1] != SEPARATOR_CHAR && line[i - 1] != ' ' &&
		line[i - 1] != '\t')
	{
		line[i] = '\0';
		while (line[j] == ' ')
			j++;
		s->f[s->count].label = ft_strdup(&line[j]);
		line[i] = ':';
		return (i + 1);
	}
	else
		s->f[s->count].label = NULL;
	return (0);
}

/*
 ** Записует аргументы функции
*/

void	ft_parse_function_2(t_data *s, char *line, int i, int len)
{
	int j;

	while (line[i] == ' ' || line[i] == '\t')
		i++;
	while (i < len)
	{
		j = i;
		while (line[i] && line[i] != SEPARATOR_CHAR)
			i++;
		line[i] = '\0';
		s->f[s->count].line = ft_strdup(&line[j]);
		s->f[s->count].label = NULL;
		s->f[s->count].stroka = s->f[s->count - 1].stroka;
		s->count++;
		if (i >= len)
			break ;
		line[i] = SEPARATOR_CHAR;
		i++;
	}
}

/*
 ** Помечает лейбл и записует имя функции
*/

void	ft_parse_function(t_data *s, char *line, int stroka)
{
	int i;
	int j;

	if (s->f[s->count].label == NULL)
		line = &line[ft_take_label(s, line, stroka)];
	else if (!line[0])
		exit(ft_printf("Error: empty line after label \"%s\"\n",
					s->f[s->count].label));
	i = 0;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	if (!line[i])
		return ;
	j = i;
	while (line[i] != ' ' && line[i] != '\t' && line[i])
		i++;
	if (i == ft_strlen(line))
		exit(ft_printf("Error: wrong func or count arg in line #%d\n", stroka));
	line[i] = '\0';
	s->f[s->count].line = ft_strdup(&line[j]);
	s->f[s->count].stroka = stroka;
	s->f[s->count].type_arg = 0;
	line[i] = ' ';
	s->count++;
	ft_parse_function_2(s, line, i, ft_strlen(line));
}

/*
** Разбивает строку на элементы:
** - имя функции и лейбл при наличии
** - аргемент№1
** - аргумент№2
** - аргумент№3
*/

void	ft_trim_comment(char *line)
{
	int i;

	i = 0;
	while (line[i])
	{
		if (line[i] == COMMENT_CHAR)
		{
			i--;
			while (line[i] == ' ' || line[i] == '\t')
				i--;
			line[++i] = '\0';
			return ;
		}
		i++;
	}
}

void	ft_parse_body(t_data *s)
{
	int i;
	int j;

	i = 0;
	while (s->array[i])
	{
		if (ft_strncmp(s->array[i], NAME_CMD_STRING,
					(size_t)ft_strlen(NAME_CMD_STRING)) != 0 &&
			ft_strncmp(s->array[i], COMMENT_CMD_STRING,
					(size_t)ft_strlen(COMMENT_CMD_STRING)) != 0 &&
				s->array[i][0] != COMMENT_CHAR)
		{
			ft_trim_comment(s->array[i]);
			ft_parse_function(s, s->array[i], i + 1);
		}
		i++;
	}
	i = -1;
	j = 0;
	while (++i < s->count)
		if (s->f[i].line)
			j++;
	if (!j)
		exit(ft_printf("Error: empty file\n"));
}

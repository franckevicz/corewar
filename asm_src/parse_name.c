/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_name.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 17:13:31 by mdubina           #+#    #+#             */
/*   Updated: 2017/03/31 17:13:33 by mdubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
 ** Проверяет наличие правильного расширения у файла
*/

void	check_name_file(t_data *s, char *file_name)
{
	int i;

	i = 0;
	while (file_name[i])
		i++;
	if (ft_strcmp(&file_name[i - 2], ".s") != 0)
		exit(ft_printf("Error: wrong format\n"));
	file_name[i - 2] = '\0';
	s->file_name = ft_strjoin(file_name, ".cor");
	file_name[i - 2] = '.';
}

/*
 ** Считывает всю информацию с файла построчно, записывает в двумерный массив
*/

void	ft_read(char *name, t_data *s)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	check_name_file(s, name);
	if ((fd = open(name, O_RDONLY)) < 0)
		exit(ft_printf("Error: can't open file\n"));
	while (get_next_line(fd, &line) > 0)
	{
		i++;
		free(line);
	}
	free(line);
	s->array = (char **)malloc(sizeof(char *) * (i + 1));
	s->f = (t_func*)malloc(sizeof(t_func) * i * 4);
	ft_fill_zero(s->f, i * 4);
	fd = open(name, O_RDONLY);
	i = 0;
	while (get_next_line(fd, &line) > 0)
		s->array[i++] = line;
	free(line);
	s->array[i] = NULL;
}

/*
 **Парсит имя программы (Byte-code) в структуру
*/

int		ft_parse_name(t_data *s, char *line)
{
	int i;
	int j;

	i = 0;
	j = 0;
	ft_bzero(s->h->prog_name, PROG_NAME_LENGTH);
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	if (line[i] != '"')
		exit(ft_printf("Error on name line\n"));
	i++;
	while (line[i] != '"')
	{
		s->h->prog_name[j++] = line[i];
		if (j > PROG_NAME_LENGTH)
			exit(ft_printf("Error: Name is too long!\n"));
		i++;
	}
	i++;
	if (line[i])
		exit(ft_printf("Error on name line\n"));
	return (j);
}

/*
 **Парсит описание (Byte-code) в структуру
*/

int		ft_parse_comment(t_data *s, char *line)
{
	int i;
	int j;

	i = 0;
	j = 0;
	ft_bzero(s->h->comment, COMMENT_LENGTH);
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	if (line[i] != '"')
		exit(ft_printf("Error on comment line\n"));
	i++;
	while (line[i] != '"')
	{
		s->h->comment[j++] = line[i++];
		if (j > COMMENT_LENGTH)
			exit(ft_printf("Error: Comment is too long!\n"));
	}
	i++;
	if (line[i])
		exit(ft_printf("Error on comment line\n"));
	return (j);
}

/*
 **Проверяет наличие необходимых элементов и запускает парсинг шляпы
*/

int		ft_parse_head(t_data *s, char *name, int i)
{
	ft_read(name, s);
	while (s->array[++i] != NULL)
	{
		if (ft_strncmp(s->array[i], NAME_CMD_STRING,
					(size_t)ft_strlen(NAME_CMD_STRING)) == 0)
		{
			if (s->h->prog_name[0])
				exit(ft_printf("Error: multiple name!\n"));
			if (ft_parse_name(s, &s->array[i][5]) == 0)
				exit(ft_printf("Error: Empty name!\n"));
		}
		else if (ft_strncmp(s->array[i], COMMENT_CMD_STRING,
							(size_t)ft_strlen(COMMENT_CMD_STRING)) == 0)
		{
			if (s->h->comment[0])
				exit(ft_printf("Error: multiple comment!\n"));
			if (ft_parse_comment(s, &s->array[i][8]) == 0)
				exit(ft_printf("Error: Empty comment!\n"));
		}
	}
	if (!s->h->comment[0])
		exit(ft_printf("Error: comment not found!\n"));
	if (!s->h->prog_name[0])
		exit(ft_printf("Error: program_name not found!\n"));
	return (1);
}

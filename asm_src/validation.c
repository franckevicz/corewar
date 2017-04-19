/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 17:13:50 by mdubina           #+#    #+#             */
/*   Updated: 2017/03/31 17:13:53 by mdubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
** Првоеряет тип функции и записует его
*/

void	take_type_function(t_data *s)
{
	int i;
	int j;

	i = 0;
	while (i < s->count)
	{
		j = 0;
		s->f[i].type_func = 0;
		while (j < 16 && s->f[i].line)
		{
			if (ft_strcmp(s->f[i].line, g_tab[j].name) == 0)
				s->f[i].type_func = j + 1;
			j++;
		}
		if (s->f[i].type_func == 0)
			take_type_arg(s, i);
		i++;
	}
}

/*
** Првоеряет соответствует ли формат аргумента типа №2
*/

void	correct_arg(t_data *s, char *line)
{
	int i;

	i = 0;
	if (line[0] == ':')
	{
		while (i < s->count)
		{
			if (s->f[i].label && ft_strcmp(&line[1], s->f[i].label) == 0)
				return ;
			i++;
		}
		exit(ft_printf("Error: label \"%s\" not found\n", &line[1]));
	}
	else
	{
		i = line[0] == '-' ? 1 : 0;
		if (!ft_line_is_digit(&line[i]))
			exit(ft_printf("Error: not valid arg \"%s\"\n", line));
	}
}

/*
** Првоеряет соответствует ли формат аргумента типа №1, №3
*/

void	arg_validation(t_data *s, int type_func, int i)
{
	int j;

	j = -1;
	while (++j < g_tab[type_func].count_arg)
	{
		if ((s->f[i + j].type_arg & g_tab[type_func].arg[j]) == 0)
			exit(ft_printf("Error: wrong type of arg #%d in line %d\n", j + 1,
						s->f[j + i].stroka));
		if (s->f[j + i].type_arg == 1 && ft_atoi(s->f[j + i].line) > REG_NUMBER)
			exit(ft_printf("Error: reg \"%s\" exceed max_value in line #%d",
						s->f[j + i].line, s->f[j + i].stroka));
		else if (s->f[j + i].type_arg == 2 || s->f[j + i].type_arg == 4)
			correct_arg(s, s->f[j + i].line);
	}
}

/*
** Првоеряет кол-во аргументов необходимых для конкретной функции
*/

void	func_validation(t_data *s, int i, int line_num)
{
	int j;
	int count;

	j = i;
	count = 0;
	if (g_tab[s->f[i].type_func - 1].coding_byte)
		s->f[i].code_byte = 1;
	else
		s->f[i].code_byte = 0;
	while (j < s->count && s->f[j].stroka == line_num)
	{
		if (s->f[j].type_arg)
			count++;
		j++;
	}
	if (count != g_tab[s->f[i].type_func - 1].count_arg)
		exit(ft_printf("Error: wrong number of arg in line #%d\n", line_num));
	arg_validation(s, s->f[i].type_func - 1, i + 1);
}

/*
** Проверяет имя лейбла и запускает валидацию
*/

void	validation(t_data *s)
{
	int i;
	int j;

	i = 0;
	take_type_function(s);
	while (i < s->count)
	{
		if (s->f[i].label)
		{
			ft_check_double_label(s, i, s->f[i].label);
			j = 0;
			while (s->f[i].label[j])
			{
				if ((s->f[i].label[j] < 97 || s->f[i].label[j] > 122) &&
					s->f[i].label[j] != '_' && !ft_isdigit(s->f[i].label[j]))
					exit(ft_printf("Error: forbidden char '%c' in line #%d\n",
								s->f[i].label[j], s->f[i].stroka));
				j++;
			}
		}
		if (s->f[i].type_func)
			func_validation(s, i, s->f[i].stroka);
		i++;
	}
}

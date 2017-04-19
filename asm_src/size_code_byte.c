/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_code_byte.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 17:13:42 by mdubina           #+#    #+#             */
/*   Updated: 2017/03/31 17:13:44 by mdubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	print_big_endian(const void *ptr, size_t size, int fd)
{
	while (size--)
		write(fd, (ptr + size), 1);
	return ;
}

void	ft_write_coding_byte(t_data *s, int nb, int count_arg)
{
	int		i;
	char	src[4];

	i = 0;
	ft_bzero(src, 4);
	while (i < count_arg)
	{
		if (s->f[nb + i].type_arg == 4)
			src[i] = 3;
		else
			src[i] = (char)s->f[nb + i].type_arg;
		i++;
	}
	s->f[nb - 1].code_byte_src = (src[0] << 6) | (src[1] << 4) | (src[2] << 2);
}

void	ft_take_size_elem(int nb, t_func *f)
{
	int i;

	i = nb;
	if (!f[i].type_func)
	{
		while (i >= 0 && !f[i].type_func)
			i--;
	}
	if (f[nb].type_func && f[nb].code_byte)
		f[nb].size = 2;
	else if (f[nb].type_func)
		f[nb].size = 1;
	else if (f[nb].type_arg == 1)
		f[nb].size = 1;
	else if (f[nb].type_arg == 2 && g_tab[f[i].type_func - 1].flag_direct_size)
		f[nb].size = 2;
	else if (f[nb].type_arg == 2)
		f[nb].size = 4;
	else if (f[nb].type_arg == 4)
		f[nb].size = 2;
	else
		exit(ft_printf("Error: some trouble with define size for \"%s\"\n",
					f[nb].line));
}

void	ft_write_ob_code(t_data *s)
{
	int i;

	s->h->prog_size = 0;
	i = 0;
	while (i < s->count)
	{
		if (s->f[i].type_func && s->f[i].code_byte)
			ft_write_coding_byte(s, i + 1,
								g_tab[s->f[i].type_func - 1].count_arg);
		ft_take_size_elem(i, s->f);
		s->h->prog_size += s->f[i].size;
		i++;
	}
}

/*
** Првоеряет тип аргумента и записует его
*/

void	take_type_arg(t_data *s, int count)
{
	int i;

	i = 0;
	if (s->f[count].line[0] == 'r' && ft_line_is_digit(&s->f[count].line[1]))
	{
		s->f[count].type_arg = T_REG;
		s->f[count].line = &s->f[count].line[1];
	}
	else if (s->f[count].line[0] == DIRECT_CHAR)
	{
		s->f[count].type_arg = T_DIR;
		s->f[count].line = &s->f[count].line[1];
	}
	else if (s->f[count].line[0] == LABEL_CHAR)
		s->f[count].type_arg = T_IND;
	else
	{
		i = s->f[count].line[0] == '-' ? 1 : 0;
		if (ft_line_is_digit(&s->f[count].line[i]))
			s->f[count].type_arg = T_IND;
		else
			exit(ft_printf("Error: wrong arg or func_name \"%s\" in line #%d\n",
						s->f[count].line, s->f[count].stroka));
	}
}

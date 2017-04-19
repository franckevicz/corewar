/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 17:13:58 by mdubina           #+#    #+#             */
/*   Updated: 2017/03/31 17:14:01 by mdubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	ft_write_head(t_data *s)
{
	int magic;
	int i;

	magic = COREWAR_EXEC_MAGIC;
	print_big_endian(&magic, 4, s->fd);
	i = -1;
	while (++i < PROG_NAME_LENGTH)
		write(s->fd, &(s->h->prog_name[i]), 1);
	i = 0;
	print_big_endian(&i, 4, s->fd);
	print_big_endian(&s->h->prog_size, 4, s->fd);
	i = -1;
	while (++i < COMMENT_LENGTH)
		write(s->fd, &(s->h->comment[i]), 1);
	i = 0;
	print_big_endian(&i, 4, s->fd);
}

int		ft_write_label(t_data *s, int nb, t_func f, int x)
{
	int i;

	i = nb;
	x = 0;
	while (--i >= 0)
	{
		x += s->f[i].size;
		if (s->f[i].label && ft_strcmp(&f.line[1], s->f[i].label) == 0 &&
			ft_write_label_help(s, f, x, 1))
			return (1);
	}
	x = 0;
	i = nb - 1;
	while (++i < s->count)
	{
		if (s->f[i].label && ft_strcmp(&f.line[1], s->f[i].label) == 0 &&
			ft_write_label_help(s, f, x, 0))
			return (1);
		x += s->f[i].size;
	}
	return (0);
}

void	ft_write_direct(t_data *s, int nb, t_func f)
{
	int x;

	x = (int)ft_atoi(f.line);
	if (f.line[0] != ':')
		print_big_endian(&x, (size_t)f.size, s->fd);
	else
	{
		while (!s->f[nb].type_func)
			nb--;
		if (!ft_write_label(s, nb, f, x))
			exit(ft_printf("Error: lable \"%s\" not found\n", f.line));
	}
}

void	ft_write_body(t_data *s, int nb, t_func f)
{
	int x;

	x = (int)ft_atoi(f.line);
	if (f.type_func && f.code_byte)
	{
		print_big_endian(&f.type_func, 1, s->fd);
		print_big_endian(&f.code_byte_src, 1, s->fd);
	}
	else if (f.type_func)
		print_big_endian(&f.type_func, 1, s->fd);
	else if (f.type_arg == 1)
		print_big_endian(&x, 1, s->fd);
	else if (f.type_arg == 4 && f.line[0] != LABEL_CHAR)
		print_big_endian(&x, 2, s->fd);
	else if (f.type_arg == 2 || f.type_arg == 4)
		ft_write_direct(s, nb, f);
	else
		exit(ft_printf("Error: some trouble to write arg \"%s\"\n", f.line));
}

void	ft_write_in_file(t_data *s)
{
	int i;

	i = 0;
	s->fd = open(s->file_name, O_RDWR | O_CREAT, 0666);
	if (s->fd < 0)
		exit(ft_printf("Error: Can't create the file \"%s\"\n", s->file_name));
	ft_write_head(s);
	while (i < s->count)
	{
		ft_write_body(s, i, s->f[i]);
		i++;
	}
}

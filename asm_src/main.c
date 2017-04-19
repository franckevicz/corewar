/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 17:12:40 by mdubina           #+#    #+#             */
/*   Updated: 2017/03/31 17:12:43 by mdubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	ft_fill_zero(t_func *f, int count)
{
	int i;

	i = 0;
	while (i < count)
	{
		ft_bzero(&f[i], sizeof(t_func));
		i++;
	}
}

void	ft_check_double_label(t_data *s, int nb, char *label)
{
	int i;

	i = 0;
	while (i < s->count)
	{
		if (i != nb && s->f[i].label && ft_strcmp(label, s->f[i].label) == 0)
			exit(ft_printf("Error: double lable \"%s\"\n", label));
		i++;
	}
}

int		ft_write_label_help(t_data *s, t_func f, int x, int flag)
{
	if (flag)
		x = 65536 - x;
	print_big_endian(&x, (size_t)f.size, s->fd);
	return (1);
}

int		main(int ac, char **av)
{
	t_data		s[1];
	t_header	h[1];
	int			g;

	s->h = h;
	s->count = 0;
	if (ac != 2)
		return (ft_printf("Error: counts arg\n"));
	ft_parse_head(s, av[1], -1);
	g = open(s->file_name, O_RDONLY);
	if (g > 0)
		return (ft_printf(
			"File \"%s\" already exist, please delete it and repeat!\n",
			s->file_name));
		ft_parse_body(s);
	validation(s);
	ft_write_ob_code(s);
	ft_write_in_file(s);
	ft_printf("File \"%s\" successful created!!!o_O\n", s->file_name);
	return (0);
}

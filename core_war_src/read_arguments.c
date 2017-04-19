/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_arguments.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 10:02:08 by mdubina           #+#    #+#             */
/*   Updated: 2017/03/31 10:02:13 by mdubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core_war.h"

int		ft_read_tru_args(t_arena *mem, t_process *process, int *args, int *inc)
{
	if (args[4] && (3 << inc[0] & (char)inc[2]) == (3 << inc[0]) &&
		(g_tab[process->operation - 1].arg[inc[1]] & T_IND))
		args[inc[1]] = get_indirect(mem, process);
	else if (args[4] && (2 << inc[0] & (char)inc[2]) == (2 << inc[0]) &&
			(g_tab[process->operation - 1].arg[inc[1]] & T_DIR) &&
			(1 << inc[0] & (char)inc[2]) != (1 << inc[0]))
		args[inc[1]] = get_direct(mem, process, (g_tab[process->operation -
													1].flag_direct_size ? 2
																		: 4));
	else if (args[4] && (1 << inc[0] & (char)inc[2]) == (1 << inc[0]) &&
			(g_tab[process->operation - 1].arg[inc[1]] & T_REG) &&
			(2 << inc[0] & (char)inc[2]) != 2 << inc[0])
	{
		args[3] = get_reg(mem, process);
		if (!args[3])
			args[4] = 0;
		args[inc[1]] = process->r[args[3]];
	}
	else
		return (0);
	return (1);
}

int		ft_read_wr_args(t_process *process, int *args, int *inc)
{
	args[4] = 0;
	if ((3 << inc[0] & (char)inc[2]) == (3 << inc[0]))
		process->shift += 2;
	else if ((2 << inc[0] & (char)inc[2]) == (2 << inc[0]))
		process->shift += g_tab[process->operation - 1].flag_direct_size
						? 2 : 4;
	else if ((1 << inc[0] & (char)inc[2]) == (1 << inc[0]))
		process->shift += 1;
	else
	{
		process->shift = 2;
		return (1);
	}
	return (0);
}

int		*read_args(t_arena *mem, t_process *process)
{
	int *args;
	int inc[3];

	inc[0] = 6;
	inc[1] = 0;
	args = (int *)malloc(sizeof(int) * 5);
	args[4] = 1;
	inc[2] = mem[(process->position + 1) % MEM_SIZE].elem;
	process->shift += 1;
	while (inc[1] < g_tab[process->operation - 1].count_arg)
	{
		if (!ft_read_tru_args(mem, process, args, inc) &&
			ft_read_wr_args(process, args, inc))
			return (args);
		inc[0] -= 2;
		inc[1]++;
	}
	return (args);
}

void	set_player_id(t_data2 *d, int count, int num)
{
	int i;

	i = 0;
	while (i < count)
	{
		if (d->p[i].id == num)
		{
			d->p[d->player_count].id = d->player_count + 10;
			return ;
		}
		i++;
	}
	d->p[d->player_count].id = d->player_count + 1;
}

void	check_player_id(t_data2 *d, int count, long num)
{
	int i;

	if (num < -2147483648 || num > 2147483647)
		exit(ft_printf("Please enter the numbers among values"
							"[-2147483648, 2147483647]\n"));
	i = 0;
	while (i < count)
	{
		if (d->p[i].id == num)
			exit(ft_printf("Players' numbers should be different\n"));
		i++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 10:00:48 by mdubina           #+#    #+#             */
/*   Updated: 2017/03/31 10:00:51 by mdubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core_war.h"

void	make_and(t_data2 *d, t_player *player, t_process *process)
{
	int *args;

	args = read_args(d->arena, process);
	if (!args[4] && player)
	{
		free(args);
		return ;
	}
	process->r[args[3]] = args[0] & args[1];
	process->caret = !process->r[args[3]] ? 1 : 0;
	free(args);
}

void	make_or(t_data2 *d, t_player *player, t_process *process)
{
	int *args;

	args = read_args(d->arena, process);
	if (!args[4] && player)
	{
		free(args);
		return ;
	}
	process->r[args[3]] = args[0] | args[1];
	process->caret = !process->r[args[3]] ? 1 : 0;
	free(args);
}

void	make_xor(t_data2 *d, t_player *player, t_process *process)
{
	int *args;

	args = read_args(d->arena, process);
	if (!args[4] && player)
	{
		free(args);
		return ;
	}
	process->r[args[3]] = args[0] ^ args[1];
	process->caret = !process->r[args[3]] ? 1 : 0;
	free(args);
}

void	make_zjmp(t_data2 *d, t_player *player, t_process *process)
{
	int args;

	args = get_direct(d->arena, process, 2);
	if (process->caret && player)
		process->position = (MEM_SIZE + process->position + (args % IDX_MOD) -
							process->shift) % MEM_SIZE;
}

void	make_ldi(t_data2 *d, t_player *player, t_process *process)
{
	int				*args;
	int				i;
	unsigned char	result[4];

	i = 0;
	args = read_args(d->arena, process);
	if (!args[4] && player)
	{
		free(args);
		return ;
	}
	while (i < 4)
	{
		result[3 - i] = d->arena[(MEM_SIZE + process->position +
								((args[0] + args[1]) % IDX_MOD + i)) %
								MEM_SIZE].elem;
		i++;
	}
	process->r[args[3]] = *(int *)result;
	free(args);
}

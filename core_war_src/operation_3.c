/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 10:00:55 by mdubina           #+#    #+#             */
/*   Updated: 2017/03/31 10:00:57 by mdubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core_war.h"

void	make_sti(t_data2 *d, t_player *player, t_process *process)
{
	int *args;
	int i;
	int j;

	i = -1;
	j = 24;
	args = read_args(d->arena, process);
	if (!args[4] && player)
	{
		free(args);
		return ;
	}
	args[3] = (int)d->arena[process->position + 2].elem;
	while (++i < 4)
	{
		d->arena[(MEM_SIZE + process->position + ((args[1] + args[2]) % IDX_MOD)
			+ i) % MEM_SIZE].elem = (unsigned char)(process->r[args[3]] >> j);
		d->arena[(MEM_SIZE + process->position + ((args[1] + args[2]) % IDX_MOD)
			+ i) % MEM_SIZE].wrote = 1;
		d->arena[(MEM_SIZE + process->position + ((args[1] + args[2]) % IDX_MOD)
			+ i) % MEM_SIZE].id_player = process->id;
		j -= 8;
	}
	free(args);
}

void	make_lld(t_data2 *d, t_player *player, t_process *process)
{
	int *args;

	args = read_args(d->arena, process);
	if (!args[4] && player)
	{
		free(args);
		return ;
	}
	if (args[3] > 0 && args[3] <= REG_NUMBER)
	{
		process->r[args[3]] = args[0] >> 16;
		process->caret = !process->r[args[3]] ? 1 : 0;
	}
	free(args);
}

void	make_lldi(t_data2 *d, t_player *player, t_process *process)
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
		result[3 - i] = d->arena[
			(MEM_SIZE + process->position + ((args[0] + args[1]) % MEM_SIZE) +
				i) % MEM_SIZE].elem;
		i++;
	}
	process->r[args[3]] = *(int *)result;
	free(args);
}

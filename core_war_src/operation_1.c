/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 10:00:39 by mdubina           #+#    #+#             */
/*   Updated: 2017/03/31 10:00:41 by mdubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core_war.h"

void	make_live(t_data2 *d, t_player *player, t_process *process)
{
	int id;
	int i;

	i = 0;
	id = get_direct(d->arena, process, 4);
	process->alive++;
	while (i < d->player_count)
	{
		if (player[i].id == id)
		{
			if (d->f->live && !d->f->flag_v)
				ft_printf("A process shows that player %d (%s) is alive\n",
						player[i].id, player[i].name);
			player[i].last_live = d->cur_cycle;
			player[i].count_liv++;
			break ;
		}
		i++;
	}
}

void	make_ld(t_data2 *d, t_player *player, t_process *process)
{
	int *args;
	int	shift;

	args = read_args(d->arena, process);
	if (!args[4] && player)
	{
		free(args);
		return ;
	}
	shift = process->shift;
	process->shift = 2;
	if (d->arena[process->position + 1].elem >> 6 == 3)
		args[0] = get_indirect_idx(d->arena, process);
	if (args[3] <= REG_NUMBER && args[3] > 0)
	{
		process->r[args[3]] = args[0];
		process->caret = !process->r[args[3]] ? 1 : 0;
	}
	process->shift = shift;
	free(args);
}

void	make_st_help(t_data2 *d, t_process *process, int elem_1, int elem_2)
{
	int i;
	int j;

	i = -1;
	j = 24;
	while (++i < 4)
	{
		d->arena[(MEM_SIZE + process->position + i + (elem_2 % IDX_MOD)) %
				MEM_SIZE].elem = (unsigned char)(
				process->r[elem_1] >> j);
		d->arena[(MEM_SIZE + process->position + i + (elem_2 % IDX_MOD)) %
				MEM_SIZE].wrote = 1;
		d->arena[(MEM_SIZE + process->position + i + (elem_2 % IDX_MOD)) %
				MEM_SIZE].id_player = process->id;
		j -= 8;
	}
}

void	make_st(t_data2 *d, t_player *player, t_process *process)
{
	int elem_1;
	int elem_2;

	elem_2 = 0;
	if (d->arena[process->position + 1].elem != 112 &&
		d->arena[process->position + 1].elem != 80)
	{
		free(read_args(d->arena, process));
		return ;
	}
	process->shift += 1;
	elem_1 = get_reg(d->arena, process);
	if ((48 & d->arena[process->position + 1].elem) == 48)
	{
		elem_2 = get_direct(d->arena, process, 2);
		process->shift -= 2;
		make_st_help(d, process, elem_1, elem_2);
	}
	else
		process->r[get_reg(d->arena, process)] = process->r[elem_1];
	if (player->debug)
		ft_printf("Operation ST on pos %d, stored %d in %d", process->position,
			elem_1, elem_2);
}

void	make_add(t_data2 *d, t_player *player, t_process *process)
{
	int *args;

	args = read_args(d->arena, process);
	if (!args[4] && player)
	{
		free(args);
		return ;
	}
	process->r[args[3]] = args[0] + args[1];
	process->caret = !process->r[args[3]] ? 1 : 0;
	if (player->debug)
		ft_printf("Operation ADD on pos. {%d} added %d & %d in r[%d]\n",
				process->position, args[0], args[1], args[3]);
	free(args);
}

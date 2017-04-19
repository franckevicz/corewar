/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 10:01:00 by mdubina           #+#    #+#             */
/*   Updated: 2017/03/31 10:01:03 by mdubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core_war.h"

void	make_fork(t_data2 *d, t_player *player, t_process *process)
{
	int			args;
	t_process	*new_process;
	t_process	*first;

	if (player)
		args = 0;
	first = d->head_process;
	args = get_direct(d->arena, process, 2);
	new_process = (t_process *)malloc(sizeof(*new_process));
	ft_memmove(new_process, process, sizeof(*process));
	first->prev = new_process;
	new_process->next = first;
	new_process->prev = NULL;
	d->head_process = new_process;
	new_process->shift = 0;
	new_process->delay = 0;
	new_process->operation = 0;
	new_process->alive = 0;
	new_process->position =
			(MEM_SIZE + process->position + args % IDX_MOD) % MEM_SIZE;
}

void	make_lfork(t_data2 *d, t_player *player, t_process *process)
{
	int			args;
	t_process	*new_process;
	t_process	*first;

	if (player)
		args = 0;
	first = d->head_process;
	args = get_direct(d->arena, process, 2);
	new_process = (t_process*)malloc(sizeof(*new_process));
	ft_memmove(new_process, process, sizeof(*process));
	first->prev = new_process;
	new_process->next = first;
	new_process->prev = NULL;
	d->head_process = new_process;
	new_process->shift = 0;
	new_process->delay = 0;
	new_process->operation = 0;
	new_process->alive = 0;
	new_process->position = (MEM_SIZE + process->position + args) % MEM_SIZE;
}

void	make_aff(t_data2 *d, t_player *player, t_process *process)
{
	int		reg;

	process->shift += 1;
	if (d->arena[process->position + 1].elem != 64)
	{
		free(read_args(d->arena, process));
		return ;
	}
	reg = get_reg(d->arena, process);
	if (d->f->aff && player)
		write(1, &process->r[reg], 1);
	return ;
}

void	make_sub(t_data2 *d, t_player *player, t_process *process)
{
	int *args;

	args = read_args(d->arena, process);
	if (!args[4] && player)
	{
		free(args);
		return ;
	}
	process->r[args[3]] = args[0] - args[1];
	process->caret = !process->r[args[3]] ? 1 : 0;
	free(args);
}

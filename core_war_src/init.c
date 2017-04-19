/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 10:01:58 by mdubina           #+#    #+#             */
/*   Updated: 2017/03/31 10:02:00 by mdubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core_war.h"

t_process	*init_processes(t_data2 *d)
{
	int			i;
	t_process	*process;
	t_process	*head;

	i = 0;
	head = NULL;
	while (i < d->player_count)
	{
		process = (t_process*)malloc(sizeof(t_process));
		ft_bzero(process, sizeof(*process));
		process->r[1] = d->p[i].id;
		process->position = d->p[i].start;
		process->id = d->p[i].nb;
		if (head == NULL)
			head = process;
		else
		{
			head->prev = process;
			process->next = head;
			head = process;
		}
		i++;
	}
	return (head);
}

void		ft_init_machine(t_data2 *d)
{
	int i;
	int j;
	int k;

	if (d->f->dump && d->f->flag_v)
		d->f->flag_v = 0;
	d->v->speed = 5;
	d->v->status = 0;
	i = 0;
	while (i < d->player_count)
	{
		k = MEM_SIZE / d->player_count * i;
		j = 0;
		d->p[i].start = k;
		while (j < d->p[i].size_prog)
		{
			d->arena[k].id_player = d->p[i].nb;
			d->arena[k++].elem = d->p[i].program[j++];
		}
		i++;
	}
	d->death_delta = CYCLE_TO_DIE;
	d->death_count = CYCLE_TO_DIE;
	d->last_decrease = 0;
	d->head_process = init_processes(d);
}

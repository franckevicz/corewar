/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   killing_processes.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 10:00:39 by mdubina           #+#    #+#             */
/*   Updated: 2017/03/31 10:00:41 by mdubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core_war.h"

void		kill_death_process(t_data2 *d)
{
	int			items;
	t_process	*crawler;
	t_process	*prev;

	d->max_lives = 0;
	d->sound_death = 0;
	crawler = d->head_process;
	items = lst_process_len(crawler);
	while (crawler->next)
		crawler = crawler->next;
	while (crawler && items)
	{
		prev = crawler;
		crawler = crawler->prev;
		if (!prev->alive && crawler && prev)
			del_list_prc(&prev, &d->head_process, d, &items);
		else
		{
			d->max_lives += prev->alive;
			prev->alive = 0;
		}
	}
	decreasing_count(d, items);
	erasing_count_lives(d);
	return ;
}

void		decreasing_count(t_data2 *d, int items)
{
	if (d->sound_death && d->f->flag_v && d->f->say)
		system("say -v Whisper oy");
	if (!items)
		d->head_process = NULL;
	if (d->max_lives >= NBR_LIVE || d->last_decrease >= MAX_CHECKS)
	{
		d->death_delta -= CYCLE_DELTA;
		d->death_count += d->death_delta;
		d->last_decrease = 0;
	}
	else
	{
		d->death_count += d->death_delta;
		d->last_decrease++;
	}
}

void		erasing_count_lives(t_data2 *d)
{
	int			i;
	t_player	*player;

	i = 0;
	player = d->p;
	d->winner = player[i].nb;
	while (i < d->player_count)
	{
		player[i].count_liv = 0;
		i++;
	}
	return ;
}

void		del_list_prc(t_process **elem, t_process **head, t_data2 *d, \
															int *items)
{
	t_process *next;
	t_process *prev;

	if (elem == NULL || head == NULL || *elem == NULL || *head == NULL)
		return ;
	if (*elem == d->head_process)
		d->head_process = (*elem)->next;
	next = (*elem)->next;
	prev = (*elem)->prev;
	prev->next = next;
	if (next)
		next->prev = prev;
	free(*elem);
	(*items)--;
	d->sound_death = 1;
	return ;
}

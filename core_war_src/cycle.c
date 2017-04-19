/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycle.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 10:00:30 by mdubina           #+#    #+#             */
/*   Updated: 2017/03/31 10:00:32 by mdubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core_war.h"

/*
** Глобальна змінна з вказівниками на функції
*/

void		(*g_func[17])(t_data2*, t_player*, t_process*) =
{
	NULL,
	make_live,
	make_ld,
	make_st,
	make_add,
	make_sub,
	make_and,
	make_or,
	make_xor,
	make_zjmp,
	make_ldi,
	make_sti,
	make_fork,
	make_lld,
	make_lldi,
	make_lfork,
	make_aff
};

void		ft_dump(t_data2 *d, int j)
{
	char *line;

	if (d->f->dump && j == d->f->dump)
	{
		ft_show_arena(d);
		while (get_next_line(0, &line))
		{
			if (line[0] == 'q')
			{
				free(line);
				exit(0);
			}
			else if (ft_line_is_digit(line))
			{
				d->f->dump += ft_atoi(line);
				free(line);
				return ;
			}
			else
			{
				ft_printf("Please enter the number or press \'q\' to quit\n");
				free(line);
			}
		}
	}
}

/*
** while (player[i].name[0]) - елемент із пустим ім'ям cимволізує
** про закінчення масиву гравців
*/

void		let_the_game_begin(t_data2 *d, int j)
{
	t_process		*process;

	while (d->head_process && d->death_count > 0)
	{
		ft_dump(d, j);
		if (d->f->flag_v)
			ft_clear(d->arena, j % 20 == 0 ? 1 : 0);
		process = d->head_process;
		d->cur_cycle = j;
		d->count_process = lst_process_len(process);
		while (process)
		{
			choose_op(d, d->p, process);
			process = process->next;
		}
		d->v->cycle = j;
		if (j >= d->death_count)
			kill_death_process(d);
		if (d->f->flag_v)
			ft_show_map(d);
		j++;
	}
}

void		choose_the_winner(t_data2 *d)
{
	int			i;
	int			winner_alive;
	t_player	*player;

	i = 0;
	winner_alive = -1;
	player = d->p;
	d->winner = player[i].nb;
	while (i < d->player_count)
	{
		if (player[i].last_live > winner_alive)
		{
			d->winner = player[i].nb;
			winner_alive = player[i].last_live;
		}
		i++;
	}
	return ;
}

void		choose_op(t_data2 *d, t_player *player, t_process *process)
{
	d->arena[process->position].caretka = 1;
	if (process->delay)
		process->delay--;
	else if (process->operation)
	{
		process->shift = 1;
		(*g_func[process->operation])(d, player, process);
		process->position = (process->position + process->shift) % MEM_SIZE;
		process->shift = 0;
		process->operation = 0;
	}
	else if (d->arena[process->position].elem != 0 &&
			d->arena[process->position].elem <= 16)
	{
		process->operation = d->arena[process->position % MEM_SIZE].elem;
		process->delay = (short)(
				g_tab[d->arena[process->position % MEM_SIZE].elem - 1].cycle -
				2);
	}
	else
		process->position = (process->position + 1) % MEM_SIZE;
}

int			lst_process_len(t_process *head)
{
	int			i;
	t_process	*crawler;

	crawler = head;
	i = 0;
	if (head == NULL)
		return (0);
	crawler = crawler->next;
	i++;
	while (crawler)
	{
		crawler = crawler->next;
		i++;
	}
	return (i);
}

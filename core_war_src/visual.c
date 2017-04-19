/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 10:01:13 by mdubina           #+#    #+#             */
/*   Updated: 2017/03/31 10:01:15 by mdubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core_war.h"

int		ft_color_player_1(t_data2 *d, int i)
{
	if (d->arena[i].id_player == 1)
	{
		if (d->arena[i].caretka)
			return (1);
		else if (d->arena[i].wrote)
			return (2);
		else
			return (3);
	}
	else if (d->arena[i].id_player == 2)
	{
		if (d->arena[i].caretka)
			return (4);
		else if (d->arena[i].wrote)
			return (5);
		else
			return (6);
	}
	else if (!d->arena[i].id_player && d->arena[i].caretka)
		return (77);
	return (0);
}

int		ft_color_player_2(t_data2 *d, int i)
{
	if (d->arena[i].id_player == 3)
	{
		if (d->arena[i].caretka)
			return (7);
		else if (d->arena[i].wrote)
			return (8);
		else
			return (9);
	}
	else if (d->arena[i].id_player == 4)
	{
		if (d->arena[i].caretka)
			return (10);
		else if (d->arena[i].wrote)
			return (11);
		else
			return (12);
	}
	return (0);
}

void	ft_init_color(void)
{
	init_pair(0, COLOR_WHITE, COLOR_BLACK);
	init_pair(1, COLOR_WHITE, COLOR_GREEN);
	init_pair(2, COLOR_BLACK, COLOR_GREEN);
	init_pair(3, COLOR_GREEN, COLOR_BLACK);
	init_pair(4, COLOR_WHITE, COLOR_BLUE);
	init_pair(5, COLOR_BLACK, COLOR_BLUE);
	init_pair(6, COLOR_BLUE, COLOR_BLACK);
	init_pair(7, COLOR_WHITE, COLOR_MAGENTA);
	init_pair(8, COLOR_BLACK, COLOR_MAGENTA);
	init_pair(9, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(10, COLOR_WHITE, COLOR_CYAN);
	init_pair(11, COLOR_BLACK, COLOR_CYAN);
	init_pair(12, COLOR_CYAN, COLOR_BLACK);
	init_pair(20, COLOR_GREEN, COLOR_BLACK);
	init_pair(21, COLOR_RED, COLOR_BLACK);
	init_pair(77, COLOR_BLACK, COLOR_WHITE);
}

void	ft_key_usual(t_data2 *d, int ch)
{
	if (ch == '+' && d->v->speed > 1)
		d->v->speed /= 2;
	else if (ch == '-')
		d->v->speed *= 2;
	else if (ch == 's')
		d->f->say = d->f->say ? 0 : 1;
	else if (ch == 'q')
	{
		clear();
		refresh();
		system("reset");
		exit(0);
	}
}

void	ft_key_ncurses(t_data2 *d)
{
	int ch;

	mvprintw(61, 196, "Key control:");
	mvprintw(62, 196, "space - run/pause");
	mvprintw(63, 196, "key \"s\" - turn sound off/on");
	timeout(d->v->speed);
	if ((ch = getch()) && d->v->status)
	{
		ft_key_usual(d, ch);
		if (ch == ' ')
		{
			d->v->status = 0;
			attron(COLOR_PAIR(21));
			mvprintw(2, 196, "Status: PAUSED");
			attroff(COLOR_PAIR(21));
			refresh();
		}
	}
	while ((ch = getch()) && !d->v->status)
	{
		ft_key_usual(d, ch);
		timeout(d->v->speed);
		if (ch == ' ')
			d->v->status = 1;
	}
}

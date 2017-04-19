/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual_bar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 10:01:21 by mdubina           #+#    #+#             */
/*   Updated: 2017/03/31 10:01:23 by mdubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core_war.h"

void	ft_print_bar(t_data2 *d)
{
	int i;
	int j;

	i = -1;
	mvprintw(4, 196, "Delay: %3d ms ", d->v->speed);
	mvprintw(6, 196, "Cycle: %d", d->v->cycle);
	mvprintw(10, 196, "Next check: %d", d->death_count);
	mvprintw(12, 196, "Cycle to death: %4d", d->death_delta);
	j = 16;
	while (++i < d->player_count)
	{
		mvprintw(j, 196, "Player    #%-6d %.23s", d->p[i].id, d->p[i].name);
		mvprintw(j + 1, 196, "%20.s", d->p[i].name);
		mvprintw(j + 2, 196, "Said live: %-6d %s", d->p[i].count_liv, "times");
		mvprintw(j + 4, 196, "Last live: %-6d %s", d->p[i].last_live, "cycle");
		mvprintw(j + 6, 194, "__________________________________________");
		j += 8;
	}
	mvprintw(j + 2, 196, "Count of processes %5d", d->count_process);
	mvprintw(j + 4, 196, "Sound  :  %s", d->f->say ? "On " : "Off");
	ft_key_ncurses(d);
	attron(COLOR_PAIR(20));
	mvprintw(2, 196, "Status: Run   ");
	attroff(COLOR_PAIR(20));
	refresh();
}

void	ft_print_map(t_data2 *d, int row, int col, int color)
{
	int i;
	int k;
	int j;

	k = row;
	j = col;
	i = 0;
	while (i < MEM_SIZE)
	{
		if (i % 64 == 0 && j)
		{
			mvprintw(row - k + 1, col - j - 1, " |");
			mvprintw(row - k + 1, col - j + 45, " |");
			j = col;
			k--;
		}
		color = d->arena[i].id_player < 3 ? ft_color_player_1(d, i)
											: ft_color_player_2(d, i);
		attron(COLOR_PAIR(color));
		mvprintw(row - k, col - j, "%.2x ", d->arena[i].elem);
		attroff(COLOR_PAIR(color));
		i++;
		j -= 3;
	}
}

void	ft_show_map(t_data2 *d)
{
	int row;
	int col;
	int color;

	color = 0;
	getmaxyx(stdscr, row, col);
	ft_print_map(d, row, col, color);
	ft_print_bar(d);
}

void	ft_init_visual(void)
{
	initscr();
	noecho();
	cbreak();
	start_color();
	ft_init_color();
}

void	ft_clear(t_arena *a, int f)
{
	int i;

	i = 0;
	while (i < MEM_SIZE)
	{
		a[i].caretka = 0;
		if (f)
			a[i].wrote = 0;
		i++;
	}
}

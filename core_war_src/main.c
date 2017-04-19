/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 10:00:18 by mdubina           #+#    #+#             */
/*   Updated: 2017/03/31 10:00:21 by mdubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core_war.h"

void	ft_show_arena(t_data2 *d)
{
	int i;

	i = 0;
	while (i < MEM_SIZE)
	{
		if (i % 64 == 0 && i)
			ft_printf("\n");
		if (d->arena[i].id_player == 1)
			ft_printf(RED);
		else if (d->arena[i].id_player == 2)
			ft_printf(GRN);
		else if (d->arena[i].id_player == 3)
			ft_printf(BLU);
		else if (d->arena[i].id_player == 4)
			ft_printf(MAG);
		else
			ft_printf(WHT);
		if (d->arena[i].elem < 0)
			ft_printf("%.2x " RESET, d->arena[i].elem + 256);
		else
			ft_printf("%.2x " RESET, d->arena[i].elem);
		i++;
	}
	ft_printf("\n");
}

int		main(int ac, char **av)
{
	t_data2 d[1];

	ft_bzero(&d, sizeof(t_data2));
	d->p = (t_player *)malloc(sizeof(t_player) * MAX_PLAYERS);
	ft_bzero(d->p, sizeof(t_player) * MAX_PLAYERS);
	ft_check_arg(ac, av, d);
	if (d->f->flag_v)
		ft_init_visual();
	ft_init_machine(d);
	let_the_game_begin(d, 1);
	if (d->f->flag_v)
	{
		endwin();
		system("reset");
	}
	choose_the_winner(d);
	ft_printf("%cPlayer %d (%s) won\n", d->f->aff ? '\n' : '\0',
			d->p[d->winner - 1].id, d->p[d->winner - 1].name);
	return (0);
}

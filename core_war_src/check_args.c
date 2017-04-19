/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 14:05:14 by mdubina           #+#    #+#             */
/*   Updated: 2017/03/31 14:05:16 by mdubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core_war.h"

int		get_indirect(t_arena *mem, t_process *process)
{
	char	num[4];
	char	result[4];
	int		i;
	int		inder;

	i = 0;
	ft_bzero(num, 4);
	ft_bzero(result, 4);
	while (i < 2)
	{
		num[1 - i] = mem[(process->position + process->shift + i) %
						MEM_SIZE].elem;
		i++;
	}
	inder = (*(int *)num) % MEM_SIZE;
	i = 0;
	while (i < 4)
	{
		result[3 - i] = mem[((process->position + inder) + i) % MEM_SIZE].elem;
		i++;
	}
	process->shift += 2;
	return (*(int *)(result));
}

int		get_indirect_idx(t_arena *mem, t_process *process)
{
	char	num[4];
	char	result[4];
	int		i;
	int		inder;

	i = 0;
	ft_bzero(num, 4);
	ft_bzero(result, 4);
	while (i < 2)
	{
		num[1 - i] = mem[(process->position + process->shift + i) %
						MEM_SIZE].elem;
		i++;
	}
	inder = (*(short *)num) % IDX_MOD;
	i = 0;
	while (i < 4)
	{
		result[3 - i] = mem[(process->position + inder + i) % MEM_SIZE].elem;
		i++;
	}
	process->shift += 2;
	return (*(int *)(result));
}

int		get_direct(t_arena *mem, t_process *process, int size)
{
	char	num[4];
	int		i;

	i = 0;
	ft_bzero(num, 4);
	while (i < size)
	{
		num[3 - i] = mem[(process->position + process->shift + i) %
						MEM_SIZE].elem;
		i++;
	}
	process->shift += (g_tab[process->operation - 1].flag_direct_size ? 2 : 4);
	if (size == 2)
	{
		num[0] = num[2];
		num[2] = 0;
		num[1] = num[3];
		num[3] = 0;
		return (*(short *)(num));
	}
	return (*(int *)(num));
}

int		get_reg(t_arena *mem, t_process *process)
{
	int res;

	res = (int)mem[(process->position + process->shift) % MEM_SIZE].elem;
	if (res < 1 || res > REG_NUMBER)
		return (0);
	process->shift += 1;
	return (res);
}

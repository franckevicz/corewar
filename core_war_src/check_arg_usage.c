/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg_usage.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 14:05:04 by mdubina           #+#    #+#             */
/*   Updated: 2017/03/31 14:05:06 by mdubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core_war.h"

void	ft_save_player_program(int fd, t_data2 *d)
{
	int				i;
	unsigned char	c;

	i = 0;
	while (read(fd, &c, 1))
	{
		if (i == d->p[d->player_count].size_prog)
			exit(ft_printf("Wrong program size\n"));
		else if (i >= CHAMP_MAX_SIZE)
			exit(ft_printf("Too big champion\n"));
		d->p[d->player_count].program[i++] = c;
	}
	if (i != d->p[d->player_count].size_prog)
		exit(ft_printf("Wrong program size\n"));
	if (i == 0)
		exit(ft_printf("No code for champion\n"));
	if (!d->p[d->player_count].name[0])
		exit(ft_printf("Error: empty name\n"));
	if (!d->p[d->player_count].comment[0])
		exit(ft_printf("Error: empty comment\n"));
}

void	ft_save_player(t_data2 *d, char *name_file, int i, int count)
{
	int				fd;
	unsigned char	c;

	if ((fd = open(name_file, O_RDONLY)) < 0)
		exit(ft_printf("Error: some problem to open file \"%s\"\n", name_file));
	lseek(fd, 4, SEEK_SET);
	while (++i != PROG_NAME_LENGTH && read(fd, &c, 1))
		d->p[d->player_count].name[i] = c;
	if (i != PROG_NAME_LENGTH)
		exit(ft_printf("file is not complete\n"));
	lseek(fd, 4, SEEK_CUR);
	i = 32;
	while ((i -= 8) >= 0 && read(fd, &c, 1))
		d->p[count].size_prog = d->p[count].size_prog + ((int)c << i);
	i = -1;
	while (++i != COMMENT_LENGTH && read(fd, &c, 1))
		d->p[d->player_count].comment[i] = c;
	lseek(fd, 4, SEEK_CUR);
	d->p[d->player_count].program = (unsigned char *)malloc(
			sizeof(char) * (d->p[d->player_count].size_prog));
	ft_save_player_program(fd, d);
	if (!d->p[d->player_count].id && !d->p[d->player_count].id_flag)
		set_player_id(d, d->player_count, d->player_count + 1);
	d->p[d->player_count].nb = d->player_count + 1;
	d->player_count++;
}

void	ft_usage(void)
{
	exit(ft_printf(
			"Usage: ./core_war_src [-v] [-a] [-s] [-l] [-dump nbr_cycles]"
				" [[-n number] champion1.cor] ...\n"
				"-v     : Turns on visualizer\n"
				"-dump  : Dumps memory after nbr_cycles, "
				"then reads another nbr_cycles from standard input\n"
				"-n     : Sets the number of the next player\n"
				"-a     : Prints output from \"aff\"\n"
				"-s     : Turns on sound effect\n"
				"-l     : Reports executions of command live\n"));
}

void	ft_check_flags(char **flag, t_data2 *d, int ac, int *i)
{
	int		j;
	long	num;

	if (ft_strcmp(flag[*i], "-n") == 0 && (*i) + 2 < ac &&
		ft_line_is_digit(&flag[*i + 1][1]) &&
		(flag[*i + 1][0] == '-' || ft_isdigit(flag[*i + 1][0])))
	{
		num = ft_atoi(flag[*i + 1]);
		check_player_id(d, d->player_count, num);
		d->p[d->player_count].id = (int)num;
		d->p[d->player_count].id_flag = 1;
		*i += 2;
		j = ft_strlen(flag[*i]);
		if (j > 4 && ft_strncmp(&flag[*i][j - 4], ".cor", 4) == 0)
			ft_save_player(d, flag[*i], -1, d->player_count);
		else
			exit(ft_printf("Wrong player's name or attribute of flag \"n\"\n"));
	}
	else if (ft_strcmp(flag[*i], "-v") == 0)
		d->f->flag_v = 1;
	else if (ft_strcmp(flag[*i], "-dump") == 0 && (*i) + 1 < ac &&
			ft_line_is_digit(flag[*i + 1]))
		d->f->dump = (int)ft_atoi(flag[++(*i)]);
	else
		ft_usage();
}

void	ft_check_arg(int ac, char **av, t_data2 *d)
{
	int i;
	int j;

	i = 0;
	while (++i < ac)
	{
		j = ft_strlen(av[i]);
		if (j > 4 && ft_strncmp(&av[i][j - 4], ".cor", 4) == 0)
			ft_save_player(d, av[i], -1, d->player_count);
		else if (ft_strcmp(av[i], "-a") == 0)
			d->f->aff = 1;
		else if (ft_strcmp(av[i], "-s") == 0)
			d->f->say = 1;
		else if (ft_strcmp(av[i], "-l") == 0)
			d->f->live = 1;
		else
			ft_check_flags(av, d, ac, &i);
		if (d->player_count > MAX_PLAYERS)
			exit(ft_printf("Error: exceeded count of players\n"));
	}
	if (d->player_count == 0)
		ft_usage();
}

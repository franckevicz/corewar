/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_war_src.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 10:00:39 by mdubina           #+#    #+#             */
/*   Updated: 2017/03/31 18:52:28 by mdubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CORE_WAR_H

# define CORE_WAR_H
# include "../libft/libft.h"
# include "../libft/ft_printf/libftprintf.h"
# include "fcntl.h"
# include "../asm_src/op.h"
# include <curses.h>

# define ABS(x) ((x) < 0 ? -(x) : (x))

# define RED   "\x1B[31m"
# define GRN   "\x1B[32m"
# define YEL   "\x1B[33m"
# define BLU   "\x1B[34m"
# define MAG   "\x1B[35m"
# define CYN   "\x1B[36m"
# define WHT   "\x1B[37m"
# define RESET "\x1B[0m"

/*
** r[16]     - масив з регістрами процесу
** alive     - кількість разів, який процес говорив, що він живий
** delay     - затримка перед виконанням команди процесу
** position  - положення каретки
** shift     - на скільки треба змістити каретку, щоб дістатись наступної опер.
** caret     - флажок каретки
** operation - опреайція, яка повинна бути виконана після закінчення delay.
*/

typedef struct		s_process
{
	int					r[REG_NUMBER + 1];
	unsigned int		alive;
	short				delay;
	int					position;
	int					shift;
	int					caret;
	unsigned char		operation;
	int					id;
	struct s_process	*next;
	struct s_process	*prev;
}					t_process;

/*
** Структура для збереження аргументів для функцій ld, and, or і т.д.
** аргументи витягуються із віртуальної пам'яті.
** first    - значення першого аргументу
** second   - значення другого аргументу
** third    - значення третього аргументу
** reg_num  - індекс останнього поданого регістру, так як функції, що записують
** значення в регістр, приймають його останнім аргументом.
*/

typedef struct		s_args
{
	int					first;
	int					second;
	int					third;
	int					reg_num;
}					t_args;

/*
** prc 		- chained list процесів, якими володіє даний гравець
** id  		- порядковий номер гравця
** live_prc - кількість живих процесів
*/

typedef struct		s_player
{
	int					size_prog;
	unsigned char		name[PROG_NAME_LENGTH + 1];
	unsigned char		comment[COMMENT_LENGTH + 1];
	unsigned char		*program;
	int					last_live;
	int					count_liv;
	int					id;
	int					id_flag;
	int					start;
	int					debug;
	int					nb;
}					t_player;

typedef struct		s_arena
{
	unsigned char		elem;
	int					id_player;
	int					caretka;
	int					wrote;
}					t_arena;

typedef struct		s_visual
{
	int					speed;
	int					status;
	int					cycle;
}					t_visual;

typedef struct		s_flags
{
	int					flag_v;
	int					dump;
	int					aff;
	int					say;
	int					live;
}					t_flags;

typedef struct		s_data2
{
	int					player_count;
	int					cur_cycle;
	t_process			*head_process;
	t_player			*p;
	t_arena				arena[MEM_SIZE];
	t_visual			v[1];
	t_flags				f[1];
	int					death_count;
	int					death_delta;
	int					last_decrease;
	int					max_lives;
	WINDOW				*vin;
	int					count_process;
	int					winner;
	int					sound_death;
}					t_data2;

void				make_live(t_data2 *d, t_player *player, t_process *process);
void				make_ld(t_data2 *d, t_player *player, t_process *process);
void				make_st(t_data2 *d, t_player *player, t_process *process);
void				make_add(t_data2 *d, t_player *player, t_process *process);
void				make_sub(t_data2 *d, t_player *player, t_process *process);
void				make_and(t_data2 *d, t_player *player, t_process *process);
void				make_or(t_data2 *d, t_player *player, t_process *process);
void				make_xor(t_data2 *d, t_player *player, t_process *process);
void				make_zjmp(t_data2 *d, t_player *player, t_process *process);
void				make_ldi(t_data2 *d, t_player *player, t_process *process);
void				make_sti(t_data2 *d, t_player *player, t_process *process);
void				make_lld(t_data2 *d, t_player *player, t_process *process);
void				make_lldi(t_data2 *d, t_player *player, t_process *process);
void				make_fork(t_data2 *d, t_player *player, t_process *process);
void				make_lfork(t_data2 *d, t_player *player, \
								t_process *process);
void				make_aff(t_data2 *d, t_player *player, t_process *process);

void				let_the_game_begin(t_data2 *d, int j);
void				kill_death_process(t_data2 *d);
void				del_list_prc(t_process **elem, t_process **head, \
								t_data2 *d, int *items);
void				choose_op(t_data2 *d, t_player *player, t_process *process);
void				push_operation_to_process(t_data2 *d, t_process *process, \
								int *j);
int					player_live(t_player *player, int player_count);
t_process			*init_processes(t_data2 *d);
int					lst_process_len(t_process *head);
int					*read_args(t_arena *mem, t_process *process);
int					get_indirect(t_arena *mem, t_process *process);
int					get_direct(t_arena *mem, t_process *process, int size);
int					get_reg(t_arena *mem, t_process *process);
int					get_indirect_idx(t_arena *mem, t_process *process);
int					ft_reverse_direct(t_arena *mem, t_process *process, \
								int size);
void				ft_show_arena(t_data2 *d);
void				decreasing_count(t_data2 *d, int items);
void				visual();
void				ft_show_map(t_data2 *d);
void				ft_key_ncurses(t_data2 *d);
void				ft_init_color();
int					ft_color_player_1(t_data2 *d, int i);
int					ft_color_player_2(t_data2 *d, int i);
void				ft_init_visual();
void				ft_check_arg(int ac, char **av, t_data2 *d);
void				choose_the_winner(t_data2 *d);
void				erasing_count_lives(t_data2 *d);
void				ft_clear(t_arena *a, int f);
void				ft_init_machine(t_data2 *d);
void				set_player_id(t_data2 *d, int count, int num);
void				check_player_id(t_data2 *d, int count, long num);

#endif

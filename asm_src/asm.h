/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_src.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 17:14:45 by mdubina           #+#    #+#             */
/*   Updated: 2017/03/31 18:52:11 by mdubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H
# include "../libft/libft.h"
# include "../libft/ft_printf/libftprintf.h"
# include "fcntl.h"
# include "op.h"

typedef struct	s_func
{
	char		*label;
	char		*line;
	int			stroka;
	int			type_func;
	int			type_arg;
	int			code_byte;
	char		code_byte_src;
	int			size;
}				t_func;

typedef struct	s_data
{
	char		**array;
	t_header	*h;
	char		*program_name;
	char		*comment;
	t_func		*f;
	int			count;
	int			fd;
	char		*file_name;
}				t_data;

int				ft_parse_head(t_data *s, char *name, int i);
void			ft_fill_zero(t_func *f, int count);
void			ft_parse_body(t_data *s);
void			validation(t_data *s);
void			print_big_endian(const void *ptr, size_t size, int fd);
void			ft_write_ob_code(t_data *s);
void			ft_write_in_file(t_data *s);
int				ft_write_label_help(t_data *s, t_func f, int x, int flag);
void			take_type_arg(t_data *s, int count);
void			ft_check_double_label(t_data *s, int nb, char *label);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/29 15:48:13 by mdubina           #+#    #+#             */
/*   Updated: 2017/02/10 17:54:37 by mdubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <wchar.h>
# include <stdarg.h>

int					g_counter;

void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putnbr(int n);
char				*ft_print_hex(unsigned long long nb, int x);
char				*ft_print_octal_o(unsigned long long nb);
long int			ft_atoi(const char *str);
int					ft_isdigit(int c);
int					ft_is_specifier(char c);
int					ft_is_modificator(char c);
int					ft_isdigit_zero(int c);
char				*ft_itoa(long long int n);
char				*ft_itoa_u(unsigned long long n);
int					ft_strlen_1(const char *str);
int					ft_strlen_int(int *str);
long long int		ft_transform_d(int *array, va_list ap, int count, char c);
void				ft_if_width(int *array, char *s, long long int nb, int tmp);
void				ft_if_min_width(int *array, char *s, long long int nb, \
						int tmp);
void				ft_parse_d(int *array, va_list ap, char c);
void				ft_print_sign(int *array, long long int nb);
unsigned long long	ft_transform_u(int *array, va_list ap, int count, char c);
void				ft_parse_u(int *array, va_list ap, char c);
void				ft_if_width_u(int *array, char *s, int tmp);
void				ft_if_min_width_u(int *array, char *s, int tmp);
void				ft_parse_o(int *array, va_list ap, char c);
void				ft_parse_x(int *array, va_list ap, char c);
void				ft_if_width_x(int *array, char *s, int tmp, char c);
void				ft_if_min_width_x(int *array, char *s, int tmp, char c);
void				ft_if_min_width_x2(int *array, char *s, int tmp);
void				ft_parse_s(int *array, va_list ap, char c);
void				ft_if_width_s(int *array, char *s);
void				ft_if_min_width_s(int *array, char *s);
void				ft_if_width_us(int *array, int *s);
void				ft_if_min_width_us(int *array, int *s);
void				ft_parse_c(int *array, va_list ap, char c);
void				ft_if_width_c(int *array, char s);
void				ft_if_min_width_c(int *array, char s);
void				ft_if_width_uc(int *array, wchar_t s);
void				ft_if_min_width_uc(int *array, wchar_t s);
void				ft_parse_percent(int *array);
void				ft_parse_p(int *array, va_list ap);
void				ft_helper_putchar(char c);
void				ft_parse_modificator2(int *i, const char *format, \
						int *array);
void				ft_parse_modificator(int *i, const char *format, \
						int *array);
int					ft_printf(const char *format, ...);
#endif

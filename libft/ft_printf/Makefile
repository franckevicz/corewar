#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdubina <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/01 14:24:33 by mdubina           #+#    #+#              #
#    Updated: 2017/01/08 13:08:32 by mdubina          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libftprintf.a

CFLAGS = -Wall -Wextra -Werror
SRC =	ft_print_hex.c \
		ft_putstr.c \
		ft_putchar.c \
		ft_putnbr.c \
		ft_print_octal.c \
		ft_atoi.c \
		ft_isdigit.c \
		ft_itoa.c \
		ft_strlen_1.c \
		ft_parse_d.c \
		ft_parse_u.c \
		ft_itoa_u.c \
		ft_parse_o.c \
		ft_parse_s.c \
		ft_parse_c.c \
		ft_parse_percent.c \
		ft_printf.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	gcc $(CFLAGS) -c $(SRC)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

trash: 
	rm *~
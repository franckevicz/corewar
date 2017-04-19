# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ksarnyts <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/16 10:42:36 by ksarnyts          #+#    #+#              #
#    Updated: 2017/03/03 18:01:50 by ksarnyts         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = corewar

CFLAGS = -Wall -Wextra -Werror

SRC =	core_war_src/main.c \
		core_war_src/check_arg_usage.c \
		core_war_src/cycle.c \
		core_war_src/operation_1.c \
		core_war_src/operation_2.c \
		core_war_src/operation_3.c \
		core_war_src/operation_4.c \
		core_war_src/read_arguments.c \
		core_war_src/visual.c \
		core_war_src/visual_bar.c \
		core_war_src/init.c \
		core_war_src/killing_processes.c \
		core_war_src/check_args.c

SRC2 = asm_src/main.c \
		asm_src/parse_body.c \
		asm_src/parse_name.c \
		asm_src/size_code_byte.c \
		asm_src/validation.c \
		asm_src/write.c

FRAME = -lmlx -framework OpenGL -framework AppKit

OBJ = $(SRC:.c=.o)

OBJ2 = $(SRC2:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(OBJ2)
	cd libft/ && $(MAKE)
	cd libft/ft_printf/ && $(MAKE)
	gcc -o $(NAME) $(OBJ) -lncurses libft/ft_printf/libftprintf.a libft/libft.a
	gcc -o asm $(OBJ2) libft/ft_printf/libftprintf.a libft/libft.a

%.o:%.c
	gcc $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJ)
	rm -f $(OBJ2)
	cd libft/ && $(MAKE) clean
	cd libft/ft_printf/ && $(MAKE) clean

fclean: clean
	rm -f corewar
	rm -f asm
	cd libft/ && rm -f libft.a
	cd libft/ft_printf/ && rm -f libftprintf.a

re: fclean all

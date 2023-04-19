# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ldifino <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/19 09:41:05 by ldifino           #+#    #+#              #
#    Updated: 2023/04/19 12:33:21 by ldifino          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SCR = ./ft_printf.c ./ft_putchar.c ./ft_putstr.c ./ft_hexa.c ./ft_putnbr.c ./ft_uns_putnbr.c ./ft_void_hexa.c
LIBFT_D = ./libft/
LIBFT_N = libft.a
FLAGS = -Wall -Wextra -Werror
OBJ = $(SCR:%.c=%.o)
LIBFT	= $(addprefix $(LIBFT_D), $(LIBFT_N))

all: $(NAME)

$(NAME):
		(cd $(LIBFT_D) && make)
		@cp $(LIBFT) .
		@mv $(LIBFT_N) $(NAME)
		gcc -c $(FLAGS) $(SCR)
		ar rcs $(NAME) $(OBJ)

clean:
		(cd $(LIBFT_D) && make clean)
		rm -f $(OBJ) $(LIBFT)

fclean: clean
		(cd $(LIBFT_D) && make clean)
		rm -f $(NAME) $(LIBFT)

re: fclean all

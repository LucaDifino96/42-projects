# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ldifino <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/05 17:02:09 by ldifino           #+#    #+#              #
#    Updated: 2023/07/05 17:02:11 by ldifino          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
NAME_BONUS = checker_bonus
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a
SCR = ./check.c ./check2.c ./check3.c ./check4.c ./check5.c ./main.c ./move.c ./move01.c ./move02.c ./shield.c ./shield02.c 
SCR_BONUS = ./checker/checker.c ./checker/shields.c ./checker/get_next_line.c ./checker/get_next_line_utils.c ./checker/moves.c ./checker/moves2.c ./checker/moves3.c ./checker/checker2.c
OBJ = $(SCR:%.c=%.o)
OBJ_BONUS = $(SCR_BONUS:%.c=%.o)
FLAGS = -Wall -Wextra -Werror

all: $(NAME)
bonus: $(NAME_BONUS)

$(NAME): $(OBJ)
	gcc -c $(FLAGS) $(SCR)
	@make -C libft
	@make bonus -C libft
	gcc $(OBJ) ${LIBFT} -o $(NAME) 

$(NAME_BONUS): $(OBJ_BONUS) $(OBJ)
	gcc -c $(FLAGS) $(SCR_BONUS)
	@make -C libft
	@make bonus -C libft
	gcc $(OBJ_BONUS) ${LIBFT} -o $(NAME_BONUS) 

clean:
		rm -f $(OBJ) $(OBJS_BONUS)
		@make clean -C libft

fclean: clean
		rm -f $(NAME) $(NAME_BONUS)
		@make fclean -C libft

make re: fclean all

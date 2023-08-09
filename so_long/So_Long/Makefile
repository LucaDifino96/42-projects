# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ldifino <ldifino@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/15 14:57:18 by ldifino           #+#    #+#              #
#    Updated: 2023/07/15 13:05:15 by ldifino          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MINILIBX_PATH	=	./mlx
MINILIBX		=	$(MINILIBX_PATH)/libmlx.a
LIBFT_PATH		=	./libft
LIBFT			=	$(LIBFT_PATH)/libft.a
GNL_PATH		=   ./get_next_line
GNL				=   $(GNL_PATH)/get_next_line.a

SRC				=	./check.c ./create_maps.c ./main.c ./window.c ./moves.c ./imag.c

HEADER			=	./so_long.h

OBJECTS			= 	$(SRC:%.c=%.o)

NAME			=	so_long

MLX				=	./libmlx.dylib

FLAGS			=	-g -Wall -Wextra -Werror

MLX_FLAGS		=	-Lmlx -lmlx -framework OpenGL -framework AppKit

all:			$(NAME)

$(NAME):	$(OBJECTS) $(LIBFT) $(GNL)
				gcc ${FLAGS} -c $(SRC) -Imlx
				gcc $(OBJECTS) $(LIBFT) $(GNL) $(MLX_FLAGS) -o $(NAME)

$(MINILIBX):
				make -C $(MINILIBX_PATH)

$(LIBFT):
				make -C $(LIBFT_PATH)

$(GNL):
				make -C $(GNL_PATH)

clean:
				rm -f ${OBJECTS}
				make clean -C ${LIBFT_PATH}
				make clean -C ${GNL_PATH}
				make clean -C ${MINILIBX_PATH}

fclean:			clean
					rm -f $(NAME)
					rm -f $(MINILIBX)
					rm -f $(LIBFT)
					rm -f $(GNL)

re:				fclean all

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ldifino <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/08 14:47:31 by ldifino           #+#    #+#              #
#    Updated: 2023/05/10 14:42:59 by ldifino          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= minitalk
CFLAGS		= -Wall -Wextra -Werror
INCLUDES	= -I./includes/ -I./libft/includes/
SRC_DIR		= ./src/
OBJ_DIR		= ./obj/
LIBFT_DIR	= ./libft/
LIBFT_NAME	= libft.a
SRC_FILES   	= server.c client.c
OBJ_FILES	= $(SRC_FILES:.c=.o)
SRCS		= $(addprefix $(SRC_DIR), $(SRC_FILES))   
OBJS		= $(addprefix $(OBJ_DIR), $(OBJ_FILES))
LIBFT		= $(addprefix $(LIBFT_DIR), $(LIBFT_NAME))
LIBRARIES	= -L./libft -lft

all: $(NAME)

$(NAME): server client $(LIBFT)

$(LIBFT):
	(cd $(LIBFT_DIR) && make)

server: $(OBJ_DIR)server.o $(LIBFT)
	gcc $(CFLAGS) $(OBJ_DIR)server.o -o server  $(INCLUDES) $(LIBRARIES)

client: $(OBJ_DIR)client.o $(LIBFT)
	gcc $(CFLAGS) $(OBJ_DIR)client.o -o client  $(INCLUDES) $(LIBRARIES)

$(OBJ_DIR)%o: $(SRC_DIR)%c
	gcc $(CFLAGS) -c $< -o $@ $(INCLUDES)

clean:
	(cd $(LIBFT_DIR) && make clean)
	rm -f $(OBJS)

fclean: clean
	(cd $(LIBFT_DIR) && make fclean)
	rm -f server client

re: fclean all

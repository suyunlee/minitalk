# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: suylee <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/22 16:05:56 by suylee            #+#    #+#              #
#    Updated: 2021/06/22 16:06:04 by suylee           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = server
NAME2 = client

FLAGS = -Wall -Wextra -Werror

SERVER_FILE = server.c
CLIENT_FILE = client.c
SERVER_OBJ = server.o
CLIENT_OBJ = client.o

SERVER_BONUS_FILE = server_bonus.c
CLIENT_BONUS_FILE = client_bonus.c
SERVER_BONUS_OBJ = server_bonus.o
CLIENT_BONUS_OBJ = client_bonus.o

all:  $(NAME) $(NAME2)


$(NAME): $(SERVER_OBJ)
	@(make re -C ./libft/)
	gcc $(FLAGS) -o $(NAME) $(SERVER_OBJ) libft/libft.a

$(NAME2): $(CLIENT_OBJ)
	gcc $(FLAGS) -o $(NAME2) $(CLIENT_OBJ) libft/libft.a

bonus: $(SERVER_BONUS_OBJ) $(CLIENT_BONUS_OBJ) all
	gcc $(FLAGS) -o $(NAME) $(SERVER_BONUS_OBJ) libft/libft.a
	gcc $(FLAGS) -o $(NAME2) $(CLIENT_BONUS_OBJ) libft/libft.a

clean:
	@$(MAKE) -C libft clean
	rm -rf server.o client.o
	rm -rf server_bonus.o client_bonus.o

fclean: clean
	@$(MAKE) -C libft fclean
	rm -f $(NAME)
	rm -f $(NAME2)

re: fclean all

.PHONY: all clean fclean re

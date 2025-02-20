CC = gcc
CFLAGS = -Wall -Wextra -Werror

NAME_CLIENT = client
NAME_SERVER = server

NAME_CLIENT_BONUS = client_bonus
NAME_SERVER_BONUS = server_bonus

SRCS_CLIENT = client.c minitalk_utils.c
SRCS_SERVER = server.c minitalk_utils.c

SRCS_CLIENT_BONUS = client_bonus.c minitalk_utils.c
SRCS_SERVER_BONUS = server_bonus.c minitalk_utils.c

all: $(NAME_CLIENT) $(NAME_SERVER)

$(NAME_CLIENT): $(SRCS_CLIENT)
	$(CC) $(CFLAGS) -o $(NAME_CLIENT) $(SRCS_CLIENT)

$(NAME_SERVER): $(SRCS_SERVER)
	$(CC) $(CFLAGS) -o $(NAME_SERVER) $(SRCS_SERVER)

bonus: $(NAME_CLIENT_BONUS) $(NAME_SERVER_BONUS)

$(NAME_CLIENT_BONUS): $(SRCS_CLIENT_BONUS)
	$(CC) $(CFLAGS) -o $(NAME_CLIENT_BONUS) $(SRCS_CLIENT_BONUS)

$(NAME_SERVER_BONUS): $(SRCS_SERVER_BONUS)
	$(CC) $(CFLAGS) -o $(NAME_SERVER_BONUS) $(SRCS_SERVER_BONUS)

clean:
	rm -f $(NAME_CLIENT) $(NAME_SERVER) $(NAME_CLIENT_BONUS) $(NAME_SERVER_BONUS)

fclean: clean

re: fclean all

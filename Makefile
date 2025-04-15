CC = gcc
CFLAGS = -Wall -Wextra -Werror

CLIENT_SRCS = client.c
SERVER_SRCS = server.c

CLIENT_NAME = client
SERVER_NAME = server

LIBFT_PATH = libft
LIBFT = $(LIBFT_PATH)/libft.a
PRINTF_PATH = prinft
PRINTF = $(PRINTF_PATH)/ft_printf.a

all: $(CLIENT_NAME) $(SERVER_NAME)

$(CLIENT_NAME): $(CLIENT_SRCS) $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) $(CLIENT_SRCS) -L$(LIBFT_PATH) -lft -L$(PRINTF_PATH)

$(SERVER_NAME): $(SERVER_SRCS) $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) $(SERVER_SRCS) -L$(LIBFT_PATH) -lft -L$(PRINTF_PATH)

$(LIBFT):
	$(MAKE) -C $(LIBFT_PATH)

clean:
	$(MAKE) -C $(LIBFT_PATH) clean

fclean: clean
	$(MAKE) -C $(LIBFT_PATH) fclean
	rm -f $(CLIENT_NAME) $(SERVER_NAME)

re: fclean all

.PHONY: all clean fclean re
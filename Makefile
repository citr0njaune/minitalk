# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chphan <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/22 14:47:47 by chphan            #+#    #+#              #
#    Updated: 2025/04/22 14:47:48 by chphan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OBJS_CLIENT                = $(CLIENT_SRCS:.c=.o)
OBJS_SERVER                = $(SERVER_SRCS:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror -fPIC

CLIENT_SRCS = client.c
SERVER_SRCS = server.c

CLIENT_NAME = client
SERVER_NAME = server

LIBFT_PATH = libft
LIBFT = $(LIBFT_PATH)/libft.a
PRINTF_PATH = ft_printf
PRINTF = $(PRINTF_PATH)/ft_printf.a

all: $(CLIENT_NAME) $(SERVER_NAME)

$(CLIENT_NAME):  $(OBJS_CLIENT) $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) $(OBJS_CLIENT) $(LIBFT) $(PRINTF) -o $(CLIENT_NAME)

$(SERVER_NAME): $(OBJS_SERVER) $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) $(OBJS_SERVER) $(LIBFT) $(PRINTF) -o $(SERVER_NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_PATH)

$(PRINTF):
	$(MAKE) -C $(PRINTF_PATH)

clean:
	$(MAKE) -C $(LIBFT_PATH) clean
	$(MAKE) -C $(PRINTF_PATH) clean
	rm -f $(OBJS_CLIENT)
	rm -f $(OBJS_SERVER)

fclean: clean
	$(MAKE) -C $(LIBFT_PATH) fclean
	$(MAKE) -C $(PRINTF_PATH) fclean
	rm -f $(CLIENT_NAME) $(SERVER_NAME)

re: fclean all

.PHONY: all clean fclean re

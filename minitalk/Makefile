NAME := minitalk
SERVER_NAME := server
CLIENT_NAME := client

CFLAGS := -Wall -Wextra -Werror
LIBFT := libft

HEADERS := -I$(LIBFT) -I.
LIBS := $(LIBFT)/libft.a

SERVER_SRCS := server.c $(LIBFT)/libft.a
CLIENT_SRCS := client.c $(LIBFT)/libft.a

SERVER_OBJS := $(SERVER_SRCS:.c=.o)
CLIENT_OBJS := $(CLIENT_SRCS:.c=.o)

all: $(SERVER_NAME) $(CLIENT_NAME)

$(LIBFT)/libft.a:
	make -C $(LIBFT)

$(SERVER_NAME): $(SERVER_OBJS) $(LIBFT)/libft.a
	$(CC) $(CFLAGS) -o $(SERVER_NAME) $(SERVER_OBJS) $(LIBS)

$(CLIENT_NAME): $(CLIENT_OBJS) $(LIBFT)/libft.a
	$(CC) $(CFLAGS) -o $(CLIENT_NAME) $(CLIENT_OBJS) $(LIBS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(HEADERS)

clean:
	rm -rf $(SERVER_OBJS) $(CLIENT_OBJS)


fclean: clean
	rm -rf $(SERVER_NAME) $(CLIENT_NAME)

re: fclean all

.PHONY: all clean fclean re

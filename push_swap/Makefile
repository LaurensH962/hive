NAME := push_swap
CFLAGS := -Wall -Wextra -Werror
LIBFT := libft

HEADERS := -I$(LIBFT) -I.
LIBS := $(LIBFT)/libft.a

SRCS := $(shell find . -iname "*.c")
OBJS := $(SRCS:.c=.o)


all: $(NAME)

$(LIBFT)/libft.a:
	make -C $(LIBFT)

$(NAME): $(OBJS) $(LIBFT)/libft.a
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(HEADERS)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re

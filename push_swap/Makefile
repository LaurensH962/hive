NAME 	:= push_swap
CFLAGS  := -Wall -Wextra -Werror
LIBFT	:= libft

HEADERS	:= -I$(LIBFT) -I.
LIBS	:= $(LIBFT)/libft.a
SRCS	:= $(shell find -iname "*.c")
OBJS	:= ${SRCS:.c=.o}

all: libft $(NAME)

libft:
	@make -C $(LIBFT)

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)

clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -rf $(NAME)

re: clean all

.PHONY: all, clean, fclean, re, libft

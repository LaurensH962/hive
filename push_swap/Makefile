NAME := push_swap
CFLAGS := -Wall -Wextra -Werror
LIBFT := libft

HEADERS := -I$(LIBFT) -I.
LIBS := $(LIBFT)/libft.a
#for linux:
#SRCS	:= $(shell find -iname "*.c")

#for macos:
SRCS := $(shell find . -iname "*.c" -not -path "./push_swap_visualizer/*")
OBJS := ${SRCS:.c=.o}

all: $(NAME)

$(LIBFT)/libft.a:
	@make -C $(LIBFT)

$(NAME): $(OBJS) $(LIBFT)/libft.a
	@$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)

clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
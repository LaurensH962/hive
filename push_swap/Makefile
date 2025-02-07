NAME := push_swap
CFLAGS := -Wall -Wextra -Werror -fsanitize=address -g -O1
LIBFT := libft

HEADERS := -I$(LIBFT) -I.
LIBS := $(LIBFT)/libft.a

# For Linux:
SRCS := $(shell find . -iname "*.c" ! -path "./push_swap_visualizer/*")
OBJS := $(SRCS:.c=.o)

#for macOS:
#SRCS := $(shell find . -iname "*.c" -not -path "./push_swap_visualizer/*")
#OBJS := ${SRCS:.c=.o}

all: $(NAME)

$(LIBFT)/libft.a:
	@make -C $(LIBFT)

$(NAME): $(OBJS) $(LIBFT)/libft.a
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBS)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@ $(HEADERS)

clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re

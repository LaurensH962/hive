NAME 	:= so_long
CFLAGS  := -Wall -Wextra -Werror
LIBMLX	:= lib/MLX42
LIBFT	:= lib/libft

HEADERS	:= -I$(LIBMLX)/include -I$(LIBFT) -I.
LIBS	:= $(LIBMLX)/build/libmlx42.a $(LIBFT)/libft.a -g -fsanitize=address -fno-omit-frame-pointer -ldl -lglfw -pthread -lm
SRCS	:= $(shell find ./src -iname "*.c")
OBJS	:= ${SRCS:.c=.o}

all: libmlx $(NAME)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4
	@make -C $(LIBFT)

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)"

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)

clean:
	@rm -rf $(OBJS)
	@rm -rf $(LIBMLX)/build


fclean: clean
	@rm -rf $(NAME)

re: clean all

.PHONY: all, clean, fclean, re, libmlx

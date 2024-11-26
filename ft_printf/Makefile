SRC			= ./ft_printf.c ./ft_printf_utils.c

OBJS		= $(SRC:.c=.o)

NAME		= libftprintf.a

AR			= ar rcs

CC			= cc

CFLAGS		= -Wall -Wextra -Werror

all:		$(NAME)

.c.o:
					$(CC) $(CFLAGS) -c -I. $< -o $@

$(NAME):	$(OBJS)
					$(AR) $(NAME) $(OBJS)

clean:
					rm -f $(OBJS)

fclean:		clean
					rm -f $(NAME)

re:					fclean all

.PHONY:	all clean fclean re bonus

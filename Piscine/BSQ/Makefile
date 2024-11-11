# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atran <atran@student.hive.fi>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/21 11:45:20 by atran             #+#    #+#              #
#    Updated: 2024/08/21 13:33:34 by atran            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = bsq

CC = cc

MY_SOURCES = scan_file.c check_valid.c take_input.c grid_creation.c solve.c 
MY_SOURCES += main.c

MY_OBJECTS = $(MY_SOURCES:.c=.o)

CFLAGS += -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(MY_OBJECTS)
	$(CC) -o $(NAME) $(MY_OBJECTS)

clean:
	rm -f $(MY_OBJECTS)

fclean: clean
	rm -f $(NAME)
	
re: fclean all

.PHONY: all clean fcleann re

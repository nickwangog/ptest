# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nwang <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/17 09:42:04 by nwang             #+#    #+#              #
#    Updated: 2018/02/05 20:18:14 by nwang            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc

FILES = ft*.c

SRC = srcs/$(FILES)

OBJ = $(patsubst %.c, objs/%.o, $(FILES))

all: $(NAME)

$(NAME): $(OBJ) objs
	@ar rcs $(NAME) $(OBJ)

%.o: $(SRC)
	@rm -rf objs
	@$(CC) -Wall -Wextra -Werror -c -I ./srcs/*.c $^
	@mkdir objs
	@mv ft*.o objs/

clean:
	@/bin/rm -f $(OBJ)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

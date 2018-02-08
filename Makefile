NAME = libftprintf.a
LIBFT = ./libft/libft.a
SRCDIR = ./srcs/
LIBDIR = ./libft/
OBJDIR = ./objs/
INCDIR = ./includes/
SRC_FILES = $(wildcard *.c)
SRCS = $(addprefix $(SRCDIR), $(SRC_FILES))
OBJS = $(patsubst %.c, objs/%.o, $(SRC_FILES))
LIB = ./libft/objs/ft*.o
INC = -I$(INCDIR)
FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(OBJS): $(SRCS)
	@mkdir -p objs
	@gcc $(FLAGS) $(INC) -c $^ -o $@

$(LIBFT):
	@make -C $(LIBDIR)

$(NAME): $(LIBFT) $(OBJS)
	@ar rcs $(NAME) $(OBJS) $(LIB)
	@echo "Butterhorn!"

clean:
	@rm -rf $(OBJDIR)
	@make clean -C $(LIBDIR)

fclean:
	@make clean
	@rm -rf $(NAME)
	@make fclean -C $(LIBDIR)

re:	
	@make fclean
	@make all

.PHONY: all clean fclean re

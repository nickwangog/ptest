NAME = libftprintf.a
SRCDIR = ./srcs/
LIBDIR = ./libft/
OBJDIR = ./objs/
INCDIR = ./includes/
SRC_FILES = *.c
SRCS = $(addprefix $(SRCDIR), $(SRC_FILES))
OBJS = $(patsubst %.c, objs/%.o, $(SRC_FILES))
LIB = ./libft/objs/ft*.o
INC = -I$(INCDIR)
FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(OBJS):
	@rm -rf objs
	@mkdir objs
	@make -C $(LIBDIR)
	@gcc -c $(FLAGS) $(INC) $(SRCS)
	@mv *.o objs/

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS) $(LIB)
	@echo "Butterhorn!"

clean:
	@rm -rf $(OBJDIR)
	@make -C $(LIBDIR) clean

fclean:
	@make clean
	@rm -rf $(NAME)
	@make -C $(LIBDIR) fclean

re:	
	@make fclean
	@make all

.PHONY: all clean fclean re

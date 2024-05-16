CC = cc

FLAGS = -Wall -Wextra -Werror

RM = rm -f

SRC = main.c

OBJ = $(SRC:.c=.o)

NAME = philo

DIR_LIB = libft

LIBFT = libft/libft.a

all : $(DIR_LIB) $(NAME) 

%.o : %.c philosopher.h
	@$(CC) $(FLAGS) -c $< -o $@

$(NAME) : $(OBJ)
		@$(CC)  -fsanitize=thread -g -lft -L$(DIR_LIB) $< -o $(NAME)

$(DIR_LIB):
		@make -C $(DIR_LIB)
clean :
	@make -C $(DIR_LIB) clean
	@$(RM) $(OBJ)

fclean : clean
	@make -C $(DIR_LIB) fclean
	@$(RM) $(NAME)

re : fclean all

.PHONY : $(DIR_LIB)
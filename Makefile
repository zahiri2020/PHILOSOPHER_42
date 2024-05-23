CC = cc

FLAGS = -Wall -Wextra -Werror

RM = rm -f

SRC = main.c \
	init_philo.c get_time.c create_philo.c routine.c

OBJ = $(SRC:.c=.o)

NAME = philo

DIR_LIB = libft

LIBFT = libft/libft.a

all : $(DIR_LIB) $(NAME) 

%.o : %.c philosopher.h
	@$(CC) $(FLAGS) -c $<

$(NAME) : $(OBJ)
		@$(CC)  -lft -L$(DIR_LIB) $(OBJ) -o $(NAME)

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
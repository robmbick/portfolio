NAME = fillit

SRC = libft/ft_bzero.c libft/ft_memalloc.c libft/ft_putstr.c libft/ft_putchar.c libft/ft_strlen.c help_put_the_tetra.c best_way.c main.c check_grill.c check_grill_square.c lst_free.c ft_read.c rewrite_tetra.c put_the_tetra.c square.c print_square.c

FLAGS = -Wall -Wextra -Werror

OBJ = ft_bzero.o ft_memalloc.o ft_putstr.o ft_putchar.o ft_strlen.o help_put_the_tetra.o best_way.o main.o check_grill.o check_grill_square.o lst_free.o ft_read.o rewrite_tetra.o put_the_tetra.o square.o print_square.o

all:$(NAME)

$(NAME) :
	@gcc -c $(SRC)
	@gcc  $(FLAGS) $(OBJ) -o $(NAME)

clean :
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

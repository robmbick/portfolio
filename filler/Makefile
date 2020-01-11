NAME = bnetschu.filler

SRC_DIR = ./SRC/

SRC = main.c map_size.c player.c

SRC_U = $(addprefix $(SRC_DIR),$(SRC))

OBJ_DIR = ./OBJ/

OBJ =  $(addprefix $(OBJ_DIR),$(SRC:.c=.o))

FLAG = -Wall -Wextra -Werror

LIB = ./libft/

all: $(NAME)

$(NAME) : $(OBJ)
	@make -C $(LIB)
	@clang -g $(FLAG) $(OBJ) $(LIB)libft.a -o $(NAME)

$(OBJ_DIR)%.o : $(SRC_DIR)%.c ./SRC/filler.h
	@mkdir  -p $(OBJ_DIR)
	clang -g  $(FLAG) -o $@ -c $<

clean :
	@make -C $(LIB) clean
	@rm -rf $(OBJ_DIR)

fclean : clean
	@make -C $(LIB) fclean
	@rm -f $(NAME)
re : fclean all
NAME = lem-in

SRC_DIR = ./SRC/

SRC = ft_h_pars.c ft_pars.c ft_start.c main.c pars_connect.c found_way.c turn.c ini_ft_pars.c create_way.c h_turn.c

SRC_U = $(addprefix $(SRC_DIR),$(SRC))

OBJ_DIR = ./OBJ/

OBJ =  $(addprefix $(OBJ_DIR),$(SRC:.c=.o))

FLAG = -Wall -Wextra -Werror

LIB = ./libft/

all: $(NAME)

$(NAME) : $(OBJ)
	@make -C $(LIB)
	@clang -g $(FLAG) $(OBJ) $(LIB)libft.a -o $(NAME)

$(OBJ_DIR)%.o : $(SRC_DIR)%.c SRC/lem_in.h
	@mkdir  -p $(OBJ_DIR)
	clang -g  $(FLAG) -o $@ -c $<

clean :
	@make -C $(LIB) clean
	@rm -rf $(OBJ_DIR)

fclean : clean
	@make -C $(LIB) fclean
	@rm -f $(NAME)
re : fclean all

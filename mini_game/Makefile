NAME = ft_retro

SRC_DIR = ./

SRC = Bomb.cpp Map.cpp Ship.cpp main.cpp Enemys_part/Enemy.cpp Enemys_part/EnemyManager.cpp

SRC_U = $(addprefix $(SRC_DIR),$(SRC))

OBJ_DIR = ./OBJ/

OBJ =  $(addprefix $(OBJ_DIR),$(SRC:.cpp=.o))

FLAG = -Wall -Wextra -Werror

all: $(NAME)

$(NAME) : $(OBJ)
	clang++ -lncurses $(FLAG) $(OBJ) -o $(NAME)

$(OBJ_DIR)%.o : $(SRC_DIR)%.cpp
	@mkdir  -p $(OBJ_DIR)
	@mkdir  -p $(OBJ_DIR)/Enemys_part
	clang++   $(FLAG) -o $@ -c $<

clean :
	@rm -rf $(OBJ_DIR)

fclean : clean
	@rm -f $(NAME)
re : fclean all
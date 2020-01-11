NAME = fdf

SRC_DIR = ./SRC/

SRC = main.c ch_col.c key_release.c ft_cast.c check_tab.c color_found.c resolution.c draw.c line.c file_read.c move.c

SRC_U = $(addprefix $(SRC_DIR),$(SRC))

OBJ_DIR = ./OBJ/

OBJ =  $(addprefix $(OBJ_DIR),$(SRC:.c=.o))

FLAG = -Wall -Wextra -Werror

FLAG_MLX = -L /usr/local/lib/ -lmlx -framework OpenGl -framework AppKit

MLX = ./miniLibx_macos/

LIB = ./libft/

all: $(NAME)

$(NAME) : $(OBJ)
	@make -C $(LIB)
	@make -C $(MLX)
	@clang -g $(FLAG) -I /usr/local/include $(OBJ) $(LIB)libft.a $(FLAG_MLX) -o $(NAME)

$(OBJ_DIR)%.o : $(SRC_DIR)%.c
	@mkdir  -p $(OBJ_DIR)
	clang -g  $(FLAG) -o $@ -c $<

clean :
	@make -C $(LIB) clean
	@make -C $(MLX) clean
	@rm -rf $(OBJ_DIR)

fclean : clean
	@make -C $(LIB) fclean
	@rm -f $(NAME)
re : fclean all
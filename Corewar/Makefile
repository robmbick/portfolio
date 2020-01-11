NAME = corewar

SRC_DIR = ./vm_my/SRC/

SRC = read_wr.c op_help.c pars_bot.c main.c check_file.c read_beats.c map.c carriage.c cycle.c live.c sub.c zjmp.c fork.c lfork.c pars_bot2.c visualisator.c visual1.c visual2.c

SRC_U = $(addprefix $(SRC_DIR),$(SRC))

OBJ_DIR = vm_my/OBJ/

OBJ =  $(addprefix $(OBJ_DIR),$(SRC:.c=.o))

FLAG = -Wall -Wextra -Werror

FSPEED = -flto -ofast -pipe

FSAN = -fsanitize=address

LIB = vm_my/libft/

NCU = -lncurses

ASM = asm_my

all: $(NAME)

$(NAME) : $(OBJ)
	@make -C $(ASM)
	@make -C $(LIB)
	@clang -g $(FLAG) $(OBJ) $(LIB)libft.a $(NCU) -o $(NAME)

$(OBJ_DIR)%.o : $(SRC_DIR)%.c
	@mkdir  -p $(OBJ_DIR)
	clang $(FLAG) -g -o $@ -c $<

s :
	clang -g $(FLAG) $(NCU) $(FSAN) $(SRC_U) $(LIB)libft.a -o $(NAME)

speed :
	clang -g $(FLAG) $(FSPEED) $(SRC_U) $(LIB)libft.a -o $(NAME)

clean :
	@make -C $(ASM) clean
	@make -C $(LIB) clean
	@rm -rf $(OBJ_DIR)

fclean : clean
	@make -C $(ASM) fclean
	@make -C $(LIB) fclean
	@rm -f $(NAME)
re : fclean all

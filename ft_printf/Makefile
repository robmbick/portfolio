NAME := libftprintf.a

SRC = ft_atoi.c ft_printf.c flag_c.c ft_putchar.c ft_bzero.c flag_s.c ft_strjoin.c non_flag.c flag_u.c ft_itoa_ulong.c ft_itoa_base.c flag_x.c flag_p.c flag_o.c flag_i.c flag_f.c ft_round_f.c ft_round_hf.c cop_from_str_c.c cop_from_str_s.c found_line_up_s.c write_s.c hh_pars.c found_line_up_non.c cop_from_str_o.c cop_from_str_p.c found_line_up_p.c cop_from_str_u.c cop_from_str_x.c found_line_up_x.c found_line_up_i.c cop_from_str_i.c ft_cast_i.c found_line_up_i_h.c found_line_up_f.c cop_from_str_f.c found_line_up_f_h.c dod_f.c

OBJ = ft_atoi.o ft_printf.o flag_c.o ft_putchar.o ft_bzero.o flag_s.o ft_strjoin.o non_flag.o flag_u.o ft_itoa_ulong.o ft_itoa_base.o flag_x.o flag_p.o flag_o.o flag_i.o flag_f.o ft_round_f.o ft_round_hf.o cop_from_str_c.o cop_from_str_s.o found_line_up_s.o write_s.o hh_pars.o found_line_up_non.o cop_from_str_o.o cop_from_str_p.o found_line_up_p.o cop_from_str_u.o cop_from_str_x.o found_line_up_x.o found_line_up_i.o cop_from_str_i.o ft_cast_i.o found_line_up_i_h.o found_line_up_f.o cop_from_str_f.o found_line_up_f_h.o dod_f.o

CFLAGS := -Wall -Wextra -Werror

all : $(NAME)

$(NAME):
	@gcc -c $(CFLAGS) $(SRC)
	@ar rc $(NAME) $(OBJ)
clean:
	@rm -rf $(OBJ)
fclean: clean
	@rm -rf $(NAME)
re: fclean all

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lfork.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnetschu <bnetschu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 20:22:27 by bnetschu          #+#    #+#             */
/*   Updated: 2019/09/29 15:08:14 by bnetschu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		next_position(int value, int offset)
{
	value += offset;
	if (value > MEM_SIZE - 1)
		value = 0 + value % MEM_SIZE;
	else if (value < 0)
		value = MEM_SIZE - ft_abs(value) % MEM_SIZE;
	return (value);
}

int		read_4bytes(int adr)
{
	int			res;
	uint8_t		buf[4];
	int			i;

	res = 0;
	i = 0;
	while (i < 4)
	{
		buf[i] = g_map[next_position(adr, i)];
		i++;
	}
	res = buf[0] << 24;
	res = res | (buf[1] << 16);
	res = res | (buf[2] << 8);
	res = res | buf[3];
	return (res);
}

void	lfork(t_carriage *car)
{
	int		tdir;
	int		adr;

	tdir = read_tdir(2, car->i);
	create_carriage(car->num, 0, car->own);
	adr = car->i + tdir;
	copy_carriage(car, adr);
	car->i = next_position(car->i, 3);
	if (g_print == 4 || g_print == 6)
		ft_printf("P %4d | lfork %d (%d)\n", car->num, tdir, adr);
}

void	aff(t_carriage *car)
{
	char	*next_arg;
	int		pos;

	car->i = next_position(car->i, 1);
	pos = car->i;
	next_arg = ft_itoa_basex(g_map[pos], 2, 'a');
	if (next_arg[0] == '0' && next_arg[1] == '1')
	{
		pos = next_position(pos, 1);
		ft_printf("Aff: %c\n", (char)car->r[g_map[pos] - 1]);
	}
	car->i = next_position(car->i, get_offset(1, next_arg, 4) + 1);
	free(next_arg);
}

char	*ft_itoa_basex(unsigned long long int nbr, int base, int x)
{
	char					*str;
	int						i;
	unsigned long long int	n;
	int						j;
	int						k;

	i = 1;
	n = nbr;
	while (n >= (unsigned long long)base)
	{
		i++;
		n /= base;
	}
	str = (char*)malloc(sizeof(char) * (9));
	ft_bzero1(str, i + 2);
	j = 8 - i;
	k = j;
	while (j-- > 0)
		str[j] = '0';
	while (i-- > 0)
	{
		str[i + k] = (nbr % base) + (nbr % base > 9 ? x - 10 : '0');
		nbr /= base;
	}
	return (str);
}

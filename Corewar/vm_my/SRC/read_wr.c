/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_wr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnetschu <bnetschu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 16:46:57 by bnetschu          #+#    #+#             */
/*   Updated: 2019/09/29 16:47:16 by bnetschu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	write_to_map(unsigned int data, int pos)
{
	uint8_t		buf[4];
	int			i;

	buf[0] = (data >> 24) & 0xff;
	buf[1] = (data >> 16) & 0xff;
	buf[2] = (data >> 8) & 0xff;
	buf[3] = data & 0xff;
	i = 0;
	while (i < 4)
	{
		g_map[next_position(pos, 0)] = buf[i];
		i++;
		pos++;
	}
}

int		read_tdir(int size, int adr)
{
	uint8_t		buf[4];
	int			rez;
	int			i;

	rez = 0;
	i = 0;
	while (i < 4)
	{
		buf[i] = g_map[next_position(adr + 1, i)];
		i++;
	}
	if (size == 4)
	{
		rez = buf[0] << 24;
		rez = rez | (buf[1] << 16);
		rez = rez | (buf[2] << 8);
		rez = rez | buf[3];
	}
	else
	{
		rez |= buf[0] << 8;
		rez = rez | buf[1];
		return ((short)rez);
	}
	return (rez);
}

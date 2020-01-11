/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_beats.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnetschu <bnetschu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 13:55:14 by vkuchins          #+#    #+#             */
/*   Updated: 2019/09/29 14:07:13 by bnetschu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		read_magic_header(int fd)
{
	int			size;
	uint8_t		buf[4];
	int			rez;

	size = read(fd, &buf, 4);
	if (size == -1 || size < 4)
	{
		ft_printf(RED"ERROR READING BYTES %d\n"RESET, size);
		exit(0);
	}
	rez = buf[0] << 24;
	rez = rez | (buf[1] << 16);
	rez = rez | (buf[2] << 8);
	rez = rez | buf[3];
	return (rez);
}

void	read_name(t_deskriptor *des)
{
	des->name_bot = (char*)malloc(sizeof(char) * PROG_NAME_LENGTH + 1);
	if (read(des->fd, des->name_bot, PROG_NAME_LENGTH) != PROG_NAME_LENGTH)
	{
		ft_printf(RED"ERROR PROBLEM WITH READ NAME\n"RESET);
		exit(1);
	}
	des->name_bot[PROG_NAME_LENGTH] = '\0';
}

void	read_comment(t_deskriptor *des)
{
	des->comment = (char*)malloc(sizeof(char) * COMMENT_LENGTH + 1);
	if (read(des->fd, des->comment, COMMENT_LENGTH) != COMMENT_LENGTH)
	{
		ft_printf(RED"ERROR PROBLEM WITH READ COMMENT\n"RESET);
		exit(1);
	}
	des->comment[COMMENT_LENGTH] = '\0';
}

void	read_code(t_deskriptor *des)
{
	des->code = (uint8_t*)malloc(sizeof(uint8_t) * des->bot_size);
	if (read(des->fd, des->code, des->bot_size) != des->bot_size)
	{
		ft_printf(RED"ERROR size of exutable code incorect\n"RESET);
		exit(1);
	}
}

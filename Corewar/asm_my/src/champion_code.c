/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   champion_code.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuchina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 15:50:36 by akuchina          #+#    #+#             */
/*   Updated: 2019/09/27 17:20:56 by akuchina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void			write_code_type(int fd, char **param)
{
	uint8_t	code;
	int		i;
	int		j;
	int		d;

	code = 0;
	d = 6;
	i = -1;
	while (param[++i])
	{
		j = 0;
		while (param[i][j] == ' ')
			j++;
		if (param[i][j] == DIRECT_CHAR)
			code |= DIR_CODE << d;
		else if (param[i][j] == 'r')
			code |= REG_CODE << d;
		else
			code |= IND_CODE << d;
		d -= 2;
	}
	write(fd, (char *)&code, 1);
}

unsigned int	find_marker(t_list *list, char *name_m)
{
	char	*space;

	space = ft_strchr(name_m, ' ');
	(space) ? *space = '\0' : 0;
	while (list)
	{
		if (!ft_strcmp(GET_MARK(list)->marker, name_m))
			return (GET_MARK(list)->size);
		list = list->next;
	}
	return (0);
}

void			write_param(t_asm *all, char *param, unsigned int size,
	int flag)
{
	unsigned int	code;
	uint8_t			*result;
	unsigned int	res_size;

	while (*param == ' ')
		param++;
	code = take_param(param, size, all);
	if (param[0] == 'r')
		res_size = 1;
	else if (param[0] == DIRECT_CHAR)
		res_size = (flag) ? 2 : 4;
	else
		res_size = 2;
	result = malloc(res_size);
	writenbyte(result, code, res_size);
	write(all->fd, result, res_size);
	free(result);
}

void			add_champion_code(t_asm *all)
{
	t_command		*comm;
	t_list			*l;
	unsigned int	size;
	int				i;

	l = all->command_start;
	size = 0;
	while (l)
	{
		comm = GET_COMM(l);
		write(all->fd, (char *)&g_op_tab[comm->command].index, 1);
		if (g_op_tab[comm->command].type_code)
			write_code_type(all->fd, comm->param);
		i = -1;
		while (comm->param[++i])
			write_param(all, comm->param[i], size,
					g_op_tab[comm->command].dir_ind);
		size += comm->size;
		l = l->next;
	}
}

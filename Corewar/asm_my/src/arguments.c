/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpalamar <vpalamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 16:12:37 by vpalamar          #+#    #+#             */
/*   Updated: 2019/09/28 17:00:07 by vpalamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	check_evidence_in_arr(t_operation *oper, int arg, int number_arg)
{
	int		i;
	bool	marker;

	i = -1;
	marker = false;
	while (++i < 3)
	{
		if (oper->arr[number_arg][i] == arg)
		{
			marker = true;
			break ;
		}
	}
	if (!marker)
	{
		ft_printf(RED"Invalid parameter %d type indirect ", number_arg);
		ft_printf("for instruction %s\n"RESET, oper->name);
		exit(1);
	}
}

int			check_reg(char *line, t_operation *oper, int arg, int number_arg)
{
	int		value;
	int		i;

	check_evidence_in_arr(oper, arg, number_arg);
	value = ft_atoi(&line[1]);
	if (ft_intlen(value) > 2)
		error_exit("Syntax error");
	if (line[2] == '0')
	{
		i = 1;
		while (line[i] == '0')
			i++;
		if (!line[i])
			return (i);
		return (ft_intlen((ssize_t)value) + i);
	}
	return (ft_intlen((ssize_t)value) + 1);
}

static int	check_point(char *l)
{
	unsigned int	i;
	t_list			*list;
	bool			marker;

	i = 0;
	while (l[i] && l[i] != SEPARATOR_CHAR && l[i] != ' ')
		i++;
	marker = false;
	list = g_head;
	while (list)
	{
		if (((char *)list->content)[0] != ' ')
			if ((!ft_strncmp(l, list->content, i) &&
			i == (ft_strlen(list->content) - 1)) ||
			!ft_strncmp(l, "live", i))
				marker = true;
		list = list->next;
	}
	if (marker)
		return (i);
	l[i] = '\0';
	ft_printf(RED"No such label %s while attempting", l);
	ft_printf(" to dereference token [TOKEN][%d]", g_clist->number);
	ft_printf(" DIRECT_LABEL \"%s\"\n"RESET, &l[-2]);
	exit(1);
}

int			check_dir(char *line, t_operation *oper, int arg, int number_arg)
{
	int	i;

	check_evidence_in_arr(oper, arg, number_arg);
	if ((line[1] >= '0' && line[1] <= '9') || line[1] == '-')
	{
		if (line[1] == '0' && line[2] >= '0' && line[2] <= '9')
		{
			i = 1;
			while (line[i] == '0')
				i++;
			return (ft_intlen((ssize_t)ft_atoi(&line[i])) + i);
		}
		if (line[1] == '-')
			return (ft_intlen((ssize_t)ft_atoi(&line[2])) + 2);
		return (ft_intlen((ssize_t)ft_atoi(&line[1])) + 1);
	}
	else if (line[1] == LABEL_CHAR)
		return (check_point(&line[2]) + 2);
	else
		error_exit("Lexical error");
	return (0);
}

int			check_ind(char *line, t_operation *oper, int arg, int number_arg)
{
	check_evidence_in_arr(oper, arg, number_arg);
	if ((line[0] >= '0' && line[0] <= '9') || line[0] == '-')
		return (ft_intlen((ssize_t)ft_atoi(&line[0])));
	else if (line[0] == LABEL_CHAR)
		return (check_point(&line[1]) + 1);
	else
		error_exit("Syntax error");
	return (0);
}

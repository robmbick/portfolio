/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpalamar <vpalamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 18:59:55 by vpalamar          #+#    #+#             */
/*   Updated: 2019/09/27 18:15:55 by vpalamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static char	*put_endline(char *line)
{
	int		i;

	i = 0;
	while (line[i] && line[i] != ' ' && line[i] != SEPARATOR_CHAR)
		i++;
	if (i + 1 != ft_strlen(line))
		line[i] = '\0';
	return (line);
}

void		check_amount(char *line, t_operation *oper)
{
	int	count;
	int	i;

	count = 0;
	i = -1;
	while (line[++i])
		if (line[i] == SEPARATOR_CHAR)
			count++;
	if (oper->num_arg != count + 1)
	{
		ft_printf(RED"Invalid parameter 0 type indirect ");
		ft_printf("for instruction %s\n"RESET, oper->name);
		exit(1);
	}
}

void		check_argument(char *line, t_operation *oper, int number_arg, int i)
{
	check_amount(line, oper);
	i = ft_strlen(oper->name);
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != SEPARATOR_CHAR)
		{
			if (line[i] == 'r')
				i += check_reg(&line[i], oper, 1, number_arg);
			else if (line[i] == DIRECT_CHAR)
				i += check_dir(&line[i], oper, 2, number_arg);
			else if (line[i] == LABEL_CHAR ||
			(line[i] >= '0' && line[i] <= '9') || line[i] == '-')
				i += check_ind(&line[i], oper, 3, number_arg);
			else
			{
				ft_printf(RED"Invalid instruction at token [TOKEN]");
				ft_printf("[%d] ", g_clist->number);
				ft_printf("INSTRUCTION \"%s\"\n"RESET, put_endline(&line[i]));
				exit(1);
			}
			number_arg++;
			continue ;
		}
		i++;
	}
}

void		check_command(char *line, t_operation *oper)
{
	bool			correct;
	unsigned int	len;

	len = 0;
	while (line[len] && line[len] != ' ' && line[len] != DIRECT_CHAR)
		len++;
	correct = false;
	while (oper)
	{
		if (!ft_strncmp(oper->name, line, len) && len == ft_strlen(oper->name))
		{
			correct = true;
			break ;
		}
		oper = oper->next;
	}
	if (!correct || (correct && line[len] != ' ' && line[len] != DIRECT_CHAR))
	{
		line[len] = '\0';
		ft_printf(RED"Invalid instruction at token [TOKEN]");
		ft_printf("[%d] INSTRUCTION \"%s\"\n"RESET, g_clist->number, line);
		exit(1);
	}
	check_argument(line, oper, 0, 0);
}

void		operations(void)
{
	t_operation	*operation;
	char		*line;

	g_clist = g_head;
	operation = parse_operation(NULL);
	while (g_clist)
	{
		line = g_clist->content;
		if (line[0] == ' ')
			check_command(&line[1], operation);
		g_clist = g_clist->next;
	}
	operation_free(operation);
}

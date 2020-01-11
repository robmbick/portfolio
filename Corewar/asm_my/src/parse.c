/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpalamar <vpalamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 18:49:08 by vpalamar          #+#    #+#             */
/*   Updated: 2019/09/28 13:06:47 by vpalamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	error_exit(char *line)
{
	if (ft_atoi(line) == 777)
	{
		ft_printf(RED"Syntax error - unexpected end of input ");
		ft_printf("(Perhaps you forgot to end with a newline ?)\n"RESET);
	}
	else if (g_clist)
		ft_printf(RED"%s at %d line\n"RESET, line, g_clist->number);
	else
	{
		g_clist = g_head;
		while (g_clist->next)
			g_clist = g_clist->next;
		ft_printf(RED"%s at %d line\n"RESET, line, g_clist->number);
	}
	exit(1);
}

bool	delete_empty_lines(char *line)
{
	int		i;
	int		counter;

	counter = 0;
	i = 0;
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '\t')
			counter++;
		i++;
	}
	return ((counter) ? false : true);
}

int		parse2(t_list *list)
{
	if (delete_empty_lines(list->content))
		return (1);
	delete_comment(list->content);
	delete_tabs(list->content);
	delete_spaces(list->content);
	if (!ft_strlen(list->content))
		return (1);
	if (handle_point(list, list->content, 0, false))
		return (2);
	return (0);
}

t_list	*parse(void)
{
	int		i;

	while (g_clist)
	{
		if (!g_name.end || !g_comment.end)
		{
			handle_name_comment(g_clist->content, 0);
			if (!g_clist->next)
				error_exit("Syntax error");
			g_clist = list_free(g_clist);
			continue ;
		}
		else if ((i = parse2(g_clist)) > 0)
		{
			if (!g_clist->prev && !g_clist->next)
				error_exit("Syntax error at token");
			g_clist = (i == 1) ? list_free(g_clist) : g_clist;
			continue ;
		}
		g_clist = g_clist->next;
	}
	if (!g_name.end || !g_comment.end)
		error_exit("Syntax error");
	put_space_after_operation(g_head);
	return (g_head);
}

t_list	*get_content(t_list *list, char *file, char *line)
{
	int		fd;
	char	*free_line;
	int		i;

	FILE_OPEN((fd = open(file, O_RDONLY)));
	while (get_next_line(fd, &line))
		list = list_add_data(list, line);
	free_line = line;
	g_head = list;
	E_FILE(list);
	if (line == NULL)
	{
		while (list->next)
			list = list->next;
		line = list->content;
	}
	if ((i = -1) == -1 && !line)
		error_exit("777newline");
	while (line[++i])
		if (line[i] != ' ' && line[i] != '\t')
			if (line[i] != COMMENT_CHAR && line[i] != ALT_COMMENT_CHAR)
				error_exit("777newline");
	free(free_line);
	return (g_head);
}

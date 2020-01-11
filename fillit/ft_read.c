/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnetschu <bnetschu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 10:04:30 by bnetschu          #+#    #+#             */
/*   Updated: 2019/01/30 17:31:11 by bnetschu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static	int		ft_cpy(char **matrix, char *buf)
{
	int j;
	int i;
	int s;

	s = 0;
	j = 0;
	while (j != 4)
	{
		i = 0;
		matrix[j] = ft_memalloc(5);
		while (i != 4)
		{
			matrix[j][i] = *buf;
			if (*buf != '.' && *buf != '#')
				s = -1;
			buf++;
			i++;
		}
		buf++;
		j++;
	}
	if (s == -1)
		return (-1);
	return (0);
}

void			fr(char **s)
{
	int i;

	i = 0;
	while (i != 4)
	{
		s[i] = NULL;
		i++;
	}
}

static	int		ft_help_ch(char *buf, int i)
{
	if ((buf[19] == '\n' && buf[20] == '\n'))
		return (-1);
	if (i == 0)
		return (-2);
	return (0);
}

static	int		ft_ch_and_rd(t_lst *list, int fd)
{
	char	buf[22];
	int		ct;
	int		i;

	i = 0;
	while ((ct = read(fd, buf, 21)))
	{
		if (i != 0)
		{
			list->next = malloc(sizeof(t_lst));
			list->next->num = list->num + 1;
			list = list->next;
			fr(list->matrix);
		}
		if (ct == -1 || (ct < 21 && buf[ct - 1] != '\n'))
			return (-1);
		else if ((buf[ct - 1] != '\n' && buf[ct - 2] != '\n'))
			return (-1);
		buf[ct] = '\0';
		if (ft_cpy(list->matrix, buf) == -1 || list->num >= 26)
			return (-1);
		i++;
	}
	return (ft_help_ch(buf, i));
}

t_lst			*ft_read(int fd)
{
	t_lst	*list;
	int		test;

	list = malloc(sizeof(t_lst));
	fr(list->matrix);
	list->next = NULL;
	list->num = 0;
	if (fd <= 0)
		return (NULL);
	if ((test = ft_ch_and_rd(list, fd)) != 0)
	{
		if (test == -2)
		{
			free(list);
			return (NULL);
		}
		lst_free(list);
		return (NULL);
	}
	return (list);
}

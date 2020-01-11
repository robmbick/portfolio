/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_the_tetra.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnetschu <bnetschu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 15:35:21 by bnetschu          #+#    #+#             */
/*   Updated: 2019/01/30 17:35:00 by bnetschu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		ft_ss(int *ss)
{
	int i;

	i = 0;
	while (i < 30)
	{
		ss[i] = 0;
		i++;
	}
}

int				tetra_step(int ss, char **square, t_lst *s, t_lst *list)
{
	int		n;

	n = ft_strlen(square[0]);
	if (list->num != s->num)
		while ((list->num - 1) != (s->num))
			s = s->next;
	else
		while (s->next != NULL)
			s = s->next;
	if (help_put_the_tetra(square, s, ss, n) == 0)
	{
		clear_sq(square, s->num + 'A');
		help_put_the_tetra(square, s, 0, n);
		return (0);
	}
	return (1);
}

t_lst			*tetra_prev(int ss, char **square, t_lst *s, t_lst *norm)
{
	t_lst	*list;
	int		n;

	n = ft_strlen(square[0]);
	list = s;
	if (ss > -1)
		while (list->num != ss)
		{
			list = list->next;
			if (list == NULL)
				return (NULL);
		}
	while (list != NULL)
	{
		clear_sq(square, list->num + 'A');
		list = list->next;
	}
	help_put_the_tetra(square, norm, 0, n);
	return (s);
}

int				put_the_tetra(char **square, t_lst *list, int n)
{
	t_lst	*s;
	int		ss[30];

	s = list;
	ft_ss(ss);
	while (check_in_tetra(s, square) == 0)
	{
		list = (list == NULL) ? s : list;
		if (ss[list->num] > n)
			return (0);
		if (help_check(list->num + 'A', square) == 0)
			if (help_put_the_tetra(square, list, 0, n) == 0)
			{
				if (tetra_step(++ss[29], square, s, list) == 0)
				{
					if ((tetra_prev(list->num - ++ss[list->num],
					square, s, list)) == NULL)
						return (0);
				}
				continue ;
			}
		ss[29] = 0;
		list = list->next;
	}
	return (1);
}

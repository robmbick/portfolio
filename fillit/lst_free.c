/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnetschu <bnetschu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 15:10:56 by bnetschu          #+#    #+#             */
/*   Updated: 2019/01/30 15:15:13 by bnetschu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	lst_free(t_lst *list)
{
	int		i;
	t_lst	*s;

	s = list;
	i = 0;
	while (list)
	{
		while (list->matrix[i] != NULL && i != 4)
		{
			free(list->matrix[i]);
			list->matrix[i] = NULL;
			i++;
		}
		i = 0;
		free(s);
		s = NULL;
		list = list->next;
		s = list;
	}
}

char	**ft_square_malloc(char **square, int n)
{
	int i;

	i = n;
	square = (char**)malloc(sizeof(char*) * (n + 1));
	while (n >= 0)
	{
		square[n] = (char*)malloc(sizeof(char) * (i + 1));
		ft_bzero(square[n], i + 1);
		n--;
	}
	square[i] = NULL;
	return (square);
}

void	ft_free_square(char **s, int n)
{
	while (n >= 0)
	{
		free(s[n]);
		n--;
	}
	free(s);
}

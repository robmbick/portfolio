/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnetschu <bnetschu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 10:21:28 by bnetschu          #+#    #+#             */
/*   Updated: 2019/01/30 17:34:04 by bnetschu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int				ch(char **square)
{
	int x;
	int y;

	y = 0;
	while (square[y])
	{
		x = 0;
		while (square[y][x])
		{
			if (square[y][x] == 'A')
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}

int				check_minus(t_lst *list, char **square)
{
	int i;

	i = 0;
	while (list != NULL)
	{
		if (list->num > 0)
			return (0);
		list = list->next;
		i++;
	}
	if (i == 1)
	{
		if ((ch(square)) == 0)
			return (0);
	}
	return (1);
}

void			back_minus(t_lst *list)
{
	while (list != NULL)
	{
		if (list->num < 0)
		{
			if (list->num == -42)
				list->num = 0;
			list->num = list->num * (-1);
		}
		list = list->next;
	}
}

int				ft_build_square(t_lst *list, char **square, int n)
{
	t_lst	*s;
	int		y;

	y = 0;
	s = list;
	while (list)
	{
		y = 0;
		while (list->tetra[y])
			y++;
		if (y > n)
			return (0);
		list = list->next;
	}
	return (put_the_tetra(square, s, n));
}

void			square(t_lst *list, int num)
{
	int		n;
	char	**square;

	square = NULL;
	n = 2;
	while (n * n < 4 * num)
		n++;
	square = ft_square_malloc(square, n);
	ft_point_square(square, n);
	while ((ft_build_square(list, square, n)) == 0)
	{
		ft_free_square(square, n);
		n++;
		square = ft_square_malloc(square, n);
		ft_point_square(square, n);
		ft_build_square(list, square, n);
	}
	ft_print_square(square, n);
	ft_free_square(square, n);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_square.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnetschu <bnetschu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 17:40:39 by bnetschu          #+#    #+#             */
/*   Updated: 2019/01/30 15:19:38 by bnetschu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_point_square(char **square, int n)
{
	int i;
	int y;

	y = 0;
	while (y < n)
	{
		i = 0;
		while (i < n)
		{
			square[y][i] = '.';
			i++;
		}
		y++;
	}
	square[n + 1] = NULL;
}

void	ft_print_square(char **square, int n)
{
	int i;

	i = 0;
	while (i < n)
	{
		ft_putstr(square[i]);
		ft_putstr("\n");
		i++;
	}
}

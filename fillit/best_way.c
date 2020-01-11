/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_way.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnetschu <bnetschu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 14:49:53 by bnetschu          #+#    #+#             */
/*   Updated: 2019/01/30 14:54:12 by bnetschu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int				best_way(char **square, int *ideal)
{
	int		y;
	int		x;

	y = ideal[0];
	while (square[y] != NULL)
	{
		x = ideal[1];
		while (square[y][x])
		{
			ideal[0] = y;
			ideal[1] = x;
			return (1);
		}
		y++;
	}
	return (0);
}

static int		help_ft_help_write(char **square, int *ideal, char t, int *yxs)
{
	if (square[ideal[0] + (yxs[0] - ideal[2])][ideal[1] + (yxs[1] - ideal[3])]
	&& square[ideal[0] + (yxs[0] - ideal[2])][ideal[1] +
	(yxs[1] - ideal[3])] == '.')
	{
		yxs[2]++;
		square[ideal[0] + (yxs[0] - ideal[2])][ideal[1]
		+ (yxs[1] - ideal[3])] = t;
		return (1);
	}
	return (0);
}

int				ft_help_write(char **square, char **tetra, int *ideal, char t)
{
	int yxs[3];

	yxs[2] = 0;
	yxs[1] = ideal[3];
	yxs[0] = ideal[2];
	while (tetra[yxs[0]] && square[ideal[0] + (yxs[0] - ideal[2])])
	{
		yxs[1] = 0;
		while (tetra[yxs[0]][yxs[1]] && square[ideal[0] +
		(yxs[0] - ideal[2])][ideal[1] + (yxs[1] - ideal[3])])
		{
			if (tetra[yxs[0]][yxs[1]] == '#')
			{
				if (help_ft_help_write(square, ideal, t, yxs) == 0)
					return (0);
			}
			yxs[1]++;
		}
		yxs[0]++;
	}
	if (yxs[2] != 4)
		return (0);
	return (1);
}

int				write_in_sq(char **square, char **tetra, int *ideal, char t)
{
	int x;
	int y;

	y = 0;
	while (tetra[y] && square[ideal[0]])
	{
		x = 0;
		while (tetra[y][x])
		{
			if (tetra[y][x] == '#' && square[ideal[0]][ideal[1]])
				if (square[ideal[0]][ideal[1]] == '.')
				{
					ideal[2] = y;
					ideal[3] = x;
					return (ft_help_write(square, tetra, ideal, t));
				}
			x++;
		}
		y++;
	}
	return (0);
}

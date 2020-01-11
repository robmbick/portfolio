/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_grill_square.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnetschu <bnetschu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 13:38:15 by okherson          #+#    #+#             */
/*   Updated: 2019/01/30 15:28:59 by bnetschu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	clear_square(char **square, char t, int n)
{
	int		x;
	int		y;

	x = 0;
	while (x < n)
	{
		y = 0;
		while (y < n)
		{
			if (square[x][y] == t)
				square[x][y] = '.';
			y++;
		}
		x++;
	}
}

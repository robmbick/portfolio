/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnetschu <bnetschu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 14:25:17 by bnetschu          #+#    #+#             */
/*   Updated: 2019/06/06 16:26:35 by bnetschu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		r_point(int *point, t_filler *fill)
{
	point[2]++;
	point[1]++;
	while (fill->map_piece[point[0]] != NULL)
	{
		while (fill->map_piece[point[0]][point[1]])
		{
			if (fill->map_piece[point[0]][point[1]] == '*')
				return ;
			point[1]++;
		}
		point[1] = 0;
		point[0]++;
	}
}

int			h_check_piece(t_filler *fill, int *m_p, int i, int j)
{
	if (fill->map_piece[m_p[0]][m_p[1]] == '*')
	{
		if (m_p[0] == g_point[0] && m_p[1] == g_point[1])
			m_p[2] = 1;
		else if ((fill->high <= (i + m_p[0] - g_point[0]) ||
				fill->width <= (j + m_p[1] - g_point[1])) ||
		(0 > (i + m_p[0] - g_point[0]) || 0 > (j + m_p[1] - g_point[1])))
			return (0);
		else if ((fill->map[i + m_p[0] - g_point[0]]
					[j + m_p[1] - g_point[1]] != '.'))
		{
			if (g_point[2] < 100)
			{
				m_p[2] = 0;
				r_point(g_point, fill);
				m_p[0] = -1;
				return (-1);
			}
			return (0);
		}
	}
	return (1);
}

static void	create_map(char *line, t_filler *fill, int i)
{
	int z;

	z = 0;
	if (fill->cr_map == 0)
	{
		fill->map[i] = (char*)malloc(sizeof(char) * (fill->width + 1));
		fill->map[i][fill->width] = '\0';
	}
	while (z < fill->width)
	{
		fill->map[i][z] = line[z + 4];
		if (fill->map[i][z] == 'X')
			fill->map[i][z] = 'x';
		else if (fill->map[i][z] == 'O')
			fill->map[i][z] = 'o';
		z++;
	}
}

void		map_size(t_filler *fill, char *line)
{
	int		i;

	if (fill->cr_map == 0)
	{
		fill->high = ft_atoi(&line[8]);
		i = 8;
		while (line[i] != ' ')
			i++;
		fill->width = ft_atoi(&line[i]);
		fill->map = (char**)malloc(sizeof(char*) * (fill->high + 1));
		fill->map[fill->high] = NULL;
	}
	i = 0;
	free(line);
	get_next_line(0, &line);
	free(line);
	while (i < fill->high)
	{
		get_next_line(0, &line);
		create_map(line, fill, i);
		free(line);
		line = NULL;
		i++;
	}
	fill->cr_map = 1;
}

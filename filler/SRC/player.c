/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnetschu <bnetschu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 13:32:44 by bnetschu          #+#    #+#             */
/*   Updated: 2019/06/06 16:26:36 by bnetschu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		check_piece(t_filler *fill, int i, int j)
{
	int		m_p[4];

	m_p[2] = 0;
	g_point[2] = 0;
	g_point[0] = 0;
	g_point[1] = -1;
	r_point(g_point, fill);
	m_p[0] = 0;
	while (fill->map_piece[m_p[0]] != NULL)
	{
		m_p[1] = 0;
		while (fill->map_piece[m_p[0]][m_p[1]])
		{
			if ((m_p[3] = h_check_piece(fill, m_p, i, j)) == 0)
				return (0);
			else if (m_p[3] == -1)
				break ;
			m_p[1]++;
		}
		m_p[0]++;
	}
	return (m_p[2]);
}

void	short_way(t_filler *fill, int i, int j)
{
	int		z;
	int		k;

	z = 0;
	while (fill->map[z] != NULL)
	{
		k = 0;
		while (fill->map[z][k])
		{
			if ((fill->map[z][k] == 'x' || fill->map[z][k] == 'o')
			&& fill->map[z][k] != fill->player)
			{
				if (g_res > (ft_abs(i - z) + ft_abs(j - k)))
				{
					g_res = ft_abs(i - z) + ft_abs(j - k);
					g_x = j;
					g_y = i;
				}
			}
			k++;
		}
		z++;
	}
}

void	check(t_filler *fill)
{
	int		i;
	int		j;

	g_res = 100000;
	g_x = 0;
	g_y = 0;
	i = 0;
	while (fill->map[i] != NULL)
	{
		j = 0;
		while (fill->map[i][j])
		{
			if (fill->map[i][j] == fill->player)
			{
				if (check_piece(fill, i, j) == 1)
					short_way(fill, i, j);
			}
			j++;
		}
		i++;
	}
}

void	write_fill(t_filler *fill)
{
	char *s;

	check_piece(fill, g_y, g_x);
	s = ft_itoa(g_y - g_point[0]);
	write(1, s, ft_strlen(s));
	free(s);
	s = ft_itoa(g_x - g_point[1]);
	write(1, " ", 1);
	write(1, s, ft_strlen(s));
	free(s);
	write(1, "\n", 1);
}

void	player(char *line, t_filler *fill)
{
	int		i;

	i = 6;
	fill->high_piece = ft_atoi(&line[6]);
	while (line[i] != ' ')
		i++;
	fill->width_piece = ft_atoi(&line[i]);
	fill->map_piece = (char**)malloc(sizeof(char*) * (fill->high_piece + 1));
	fill->map_piece[fill->high_piece] = NULL;
	i = 0;
	free(line);
	while (fill->high_piece > i)
	{
		get_next_line(0, &line);
		fill->map_piece[i++] = line;
	}
	check(fill);
	write_fill(fill);
	i = 0;
	while (fill->map_piece[i])
	{
		free(fill->map_piece[i]);
		i++;
	}
	free(fill->map_piece);
}

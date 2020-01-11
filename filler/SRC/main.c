/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnetschu <bnetschu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 11:41:58 by bnetschu          #+#    #+#             */
/*   Updated: 2019/06/06 15:43:10 by bnetschu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	who_i_am(t_filler *fill)
{
	char *line;

	get_next_line(0, &line);
	if (ft_strncmp(line, "$$$ exec p", 9) == 0)
	{
		if (line[10] == '1')
			fill->player = 'o';
		else if (line[10] == '2')
			fill->player = 'x';
		else
			fill->player = 0;
	}
	free(line);
}

void	map_fr(t_filler *fill)
{
	int i;

	i = 0;
	while (i < fill->high)
	{
		free(fill->map[i]);
		i++;
	}
	free(fill->map);
	free(fill);
}

int		main(void)
{
	char		*line;
	t_filler	*fill;

	fill = (t_filler*)malloc(sizeof(t_filler));
	who_i_am(fill);
	fill->cr_map = 0;
	fill->high = 0;
	fill->width = 0;
	while (get_next_line(0, &line))
	{
		if (ft_strncmp(line, "Piece", 5) == 0)
			player(line, fill);
		else if ((ft_strncmp(line, "Plateau", 7) == 0))
			map_size(fill, line);
		else
			free(line);
	}
	map_fr(fill);
	return (0);
}

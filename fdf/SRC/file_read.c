/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_read.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnetschu <bnetschu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 18:08:03 by bnetschu          #+#    #+#             */
/*   Updated: 2019/03/29 09:15:04 by bnetschu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		check_line(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ',' && str[i + 1] == ',')
			return (0);
		i++;
	}
	return (1);
}

static void		*ret_nul(char *str, char *line)
{
	free(str);
	free(line);
	return (NULL);
}

static char		*help_file_read(char *str, char *line)
{
	char	*fr;

	fr = ft_strjoin(str, line);
	free(str);
	str = ft_strjoin(fr, " ");
	free(fr);
	free(line);
	return (str);
}

t_fdf			**file_read(int fd)
{
	t_fdf	**fdf;
	t_tab	tab;
	char	*line;
	char	*str;

	tab.y_max = 0;
	str = malloc(sizeof(char));
	str[0] = '\0';
	while (get_next_line(fd, &line) > 0)
	{
		delete_t_in_line(line);
		if (tab.y_max == 0)
			tab.x_max = ft_lentab(line, ' ');
		if (check_line(line) == 0 || tab.x_max != (ft_lentab(line, ' ')))
			return (ret_nul(str, line));
		str = help_file_read(str, line);
		tab.y_max++;
	}
	if (tab.y_max == 0)
		return (ret_nul(str, line));
	free(line);
	fdf = (t_fdf**)malloc(sizeof(t_fdf*) * tab.y_max);
	fdf = ft_cast(ft_strsplit(str, ' '), fdf, tab.y_max, tab.x_max);
	free(str);
	return (fdf);
}

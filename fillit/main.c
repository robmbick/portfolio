/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnetschu <bnetschu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 09:35:33 by bnetschu          #+#    #+#             */
/*   Updated: 2019/01/30 15:53:45 by bnetschu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			start(t_lst *list, int i, int num)
{
	t_lst *s;

	s = list;
	while (list != NULL)
	{
		i = 0;
		if (check_grill(list->matrix) != 1)
		{
			ft_putstr("error\n");
			lst_free(s);
			return (0);
		}
		rewrite_tetra(list);
		i = 0;
		list = list->next;
		num++;
	}
	square(s, num);
	return (1);
}

int			main(int argc, char **argv)
{
	int		i;
	t_lst	*list;
	int		num;

	i = 0;
	num = 0;
	if (argc == 2)
	{
		if ((list = ft_read(open(argv[1], O_RDONLY))) == NULL)
			ft_putstr("error\n");
		else
		{
			if (start(list, i, num) == 0)
				return (0);
		}
	}
	else
		ft_putstr("error\n");
	return (0);
}

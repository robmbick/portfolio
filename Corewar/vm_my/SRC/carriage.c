/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   carriage.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuchins <vkuchins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 11:38:47 by vkuchins          #+#    #+#             */
/*   Updated: 2019/09/28 17:55:15 by vkuchins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	init_reg(t_carriage *car)
{
	int	i;

	i = 1;
	while (i < REG_NUMBER)
	{
		car->r[i] = 0;
		i++;
	}
}

void	create_carriage(int num, int pos, int own)
{
	t_carriage	*new;

	new = (t_carriage *)malloc(sizeof(t_carriage));
	if (!new)
	{
		ft_printf(RED"ERROR CARRIAGES NOT ADDED -n\n"RESET);
		exit(1);
	}
	init_reg(new);
	new->next = g_carriages;
	new->carry = 0;
	new->live = 0;
	g_carriages_alive++;
	new->own = own;
	new->wait = 0;
	new->code_oper = 0;
	new->r[0] = num * (-1);
	g_created_car++;
	new->num = g_created_car;
	new->i = pos;
	g_carriages = new;
}

void	set_carriages(void)
{
	t_deskriptor	*des;
	int				pos;
	int				offset;

	des = g_deskript;
	offset = MEM_SIZE / g_players_in_game;
	pos = 0;
	g_carriages = NULL;
	while (des)
	{
		create_carriage(des->num, pos, des->num);
		pos += offset;
		des = des->next;
	}
}

void	clear_live(void)
{
	t_carriage		*tmp;
	t_deskriptor	*des;

	tmp = g_carriages;
	while (tmp)
	{
		tmp->live = 0;
		tmp = tmp->next;
	}
	des = g_deskript;
	while (des)
	{
		des->live = 0;
		des = des->next;
	}
}

void	check_carriages_live(void)
{
	t_carriage	*tmp;
	t_carriage	*prev;

	prev = NULL;
	tmp = g_carriages;
	while (tmp)
	{
		if (tmp->live == 0)
		{
			if (g_carriages == tmp)
				g_carriages = g_carriages->next;
			else
				prev->next = tmp->next;
			free(tmp);
			g_carriages_alive--;
			tmp = g_carriages;
			prev = NULL;
			continue ;
		}
		prev = tmp;
		tmp = tmp->next;
	}
	tmp = g_carriages;
	clear_live();
}

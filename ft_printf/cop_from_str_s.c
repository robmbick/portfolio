/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cop_from_str_s.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnetschu <bnetschu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 13:45:03 by bnetschu          #+#    #+#             */
/*   Updated: 2019/05/06 11:07:54 by bnetschu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		dod(char *fr, int num, int *n, char *string)
{
	int i[2];

	i[0] = 0;
	i[1] = 0;
	num = ret_dod_s(num, string, i);
	if (n[1] - i[1] <= 0)
		while (i[0] <= i[1])
		{
			fr[n[2]] = string[i[0]];
			i[0]++;
			n[2]++;
		}
	else
	{
		while (i[0] < i[1])
		{
			fr[n[1] - i[1] + n[2]] = string[i[0]];
			i[0]++;
			n[2]++;
		}
		return (n[1] - i[1] + n[2]);
	}
	return (n[2] - 1);
}

int				cop_from_str_s(char *fr, char *string, int *n, char *str)
{
	int i[3];

	i[0] = n[2];
	i[1] = -100;
	i[2] = 0;
	while (str[i[2]] != '%')
		i[2]++;
	while (str[i[2]] != 's')
	{
		if (str[i[2]] == '.' && (str[i[2] + 1] >= '0' && str[i[2] + 1] <= '9'))
			i[1] = ft_atoi(&str[i[2] + 1]);
		i[2]++;
	}
	i[0] = dod(fr, i[1], n, string);
	return (i[0]);
}

static void		dod2(int *i, char *str)
{
	while (str[i[1]] != '%')
		i[1]++;
	while (str[i[1]] != 's' && str[i[1]])
	{
		if (str[i[1]] == '.' && (str[i[1] + 1] >= '0' && str[i[1] + 1] <= '9'))
			i[2] = nons_minus(ft_atoi(&str[i[1] + 1]));
		i[1]++;
	}
	i[1] = 0;
}

int				cop_from_str2_s(char *fr, char *string, int *n, char *str)
{
	int i[3];

	i[0] = 0;
	i[1] = 0;
	i[2] = -100;
	dod2(i, str);
	while (string[i[1]] && i[2] != 0)
	{
		i[1]++;
		i[2]--;
	}
	while (i[0] < i[1])
	{
		fr[n[2]] = string[i[0]];
		i[0]++;
		n[2]++;
	}
	while (fr[n[2]] == ' ' && fr[n[2]])
		n[2]++;
	return (n[2]);
}

int				cop_from_str_non(char *fr, int *n, int i)
{
	if (i == 0)
	{
		fr[n[2] - 1] = '%';
		return (n[2]);
	}
	else if (i == 1)
	{
		fr[n[2]] = '%';
		return (n[2] + 1);
	}
	fr[n[2]] = '%';
	return (n[2]);
}

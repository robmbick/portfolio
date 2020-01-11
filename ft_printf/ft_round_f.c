/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_round_f.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnetschu <bnetschu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 14:42:55 by bnetschu          #+#    #+#             */
/*   Updated: 2019/05/03 12:08:03 by bnetschu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		nine_to_nul(char *str, int i)
{
	while (str[i])
	{
		str[i] = '0';
		i++;
	}
}

char		*h_nul_rigor(char *str)
{
	char	*s;
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(str);
	while (len - 1 - i > 0 && str[len - 1 - i] == '9')
		i++;
	if (str[len - 1 - i] >= '0' && str[len - 1 - i] < '9')
	{
		str[len - 1 - i]++;
		nine_to_nul(str, len - i);
	}
	else
	{
		s = str;
		str = (char*)malloc(sizeof(char) * (len + 2));
		ft_bzero(str, len + 2);
		str[0] = '1';
		nine_to_nul(str, len);
		free(s);
	}
	return (str);
}

static char	*h_rig(char *str)
{
	if (str[ft_strlen(str) - 1] == '9')
		str = h_nul_rigor(str);
	else
		str[ft_strlen(str) - 1]++;
	return (str);
}

static char	*nul_rigor(char *str, char *str_else)
{
	int i;
	int ch;

	i = 0;
	while (str_else[i])
	{
		ch = 0;
		while (str_else[i + ch] == '9')
			ch++;
		if (ch > 6 || (ch >= 6 && i != 0))
		{
			if (i == 0)
				str = h_rig(str);
			else
				str_else[i - 1]++;
			nine_to_nul(str_else, i);
			break ;
		}
		i++;
	}
	str_else[6] = '\0';
	return (str);
}

char		*ft_round_f(char *str, char *str_else, int n)
{
	if (n == -2)
		str = nul_rigor(str, str_else);
	else if (n == -1 || n == 0)
	{
		if (str_else[0] <= '9' && str_else[0] >= '6')
			str = h_nul_rigor(str);
		else if (str_else[0] == '5' && (str[ft_strlen(str) - 1] % 2 != 0
						|| str[ft_strlen(str) - 1] == '0'))
			str = h_nul_rigor(str);
		str_else[0] = '\0';
	}
	else
	{
		if (str_else[n] <= '9' && str_else[n] >= '6')
			str = ft_round_hf(str, str_else, n);
		else if (str_else[n] == '5' && ((str_else[n - 1] % 2 != 0)
						|| str_else[n - 1] == '0'))
			str = ft_round_hf(str, str_else, n);
		ft_ever_nul(str_else, 36, n);
		str_else[n] = '\0';
	}
	return (str);
}

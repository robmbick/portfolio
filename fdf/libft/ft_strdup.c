/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnetschu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 16:10:59 by bnetschu          #+#    #+#             */
/*   Updated: 2018/11/07 13:04:57 by bnetschu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*dest;
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (src[len])
		len++;
	dest = (char*)malloc(sizeof(*dest) * (len + 1));
	if (dest == NULL)
		return (0);
	dest[len] = '\0';
	while (i < len)
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}

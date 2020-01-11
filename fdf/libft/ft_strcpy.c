/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnetschu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 13:29:01 by bnetschu          #+#    #+#             */
/*   Updated: 2018/10/29 15:31:10 by bnetschu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dest, const char *source)
{
	unsigned int i;

	i = 0;
	while (source[i] != '\0')
	{
		dest[i] = (char)source[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

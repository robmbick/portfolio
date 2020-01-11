/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writenbyte.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuchina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 15:22:20 by akuchina          #+#    #+#             */
/*   Updated: 2019/09/28 15:22:21 by akuchina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			writenbyte(uint8_t *result, unsigned int code,
								unsigned int size)
{
	uint16_t	val16;

	if (size == 4)
		while (size--)
			*result++ = (uint8_t)(code >> (size * 8));
	else
	{
		val16 = (uint16_t)code;
		while (size--)
			*result++ = (uint8_t)(val16 >> (size * 8));
	}
}

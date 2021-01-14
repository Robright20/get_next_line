/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bob <bob@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 04:48:06 by bob               #+#    #+#             */
/*   Updated: 2021/01/14 09:34:43 by fokrober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>

ssize_t	index_of(void *str, int c, size_t size)
{
	unsigned char	*haystack;
	size_t			i;

	haystack = (unsigned char*)str;
	if (!haystack)
		return (-1);
	i = 0;
	while (haystack[i] && i < size)
	{
		if (haystack[i] == (unsigned char)c)
			return (i);
		i++;
	}
	if (haystack[i] == (unsigned char)c)
		return (i);
	return (-1);
}

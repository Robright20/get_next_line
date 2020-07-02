/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fokrober <fokrober@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 05:41:28 by fokrober          #+#    #+#             */
/*   Updated: 2019/04/23 14:44:58 by fokrober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char	*tmp;
	size_t			prev_n;

	if (!(prev_n = n))
		return (dst);
	if (!(tmp = malloc(n)))
		return (NULL);
	while (n--)
		tmp[n] = ((unsigned char*)src)[n];
	while (prev_n--)
		((unsigned char *)dst)[prev_n] = tmp[prev_n];
	free(tmp);
	return (dst);
}

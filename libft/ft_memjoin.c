/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fokrober <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 03:14:42 by fokrober          #+#    #+#             */
/*   Updated: 2019/05/26 10:44:13 by fokrober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memjoin(void *s1, void const *s2,
		size_t s_size, size_t b_size)
{
	void	*tmp;

	if (!s2 || !b_size)
	{
		if (!s1)
		{
			if (!(tmp = ft_memalloc(1)))
				return (NULL);
			return (tmp);
		}
		return (s1);
	}
	if (!s1 || !s_size)
		return (ft_memdupz(s2, b_size));
	tmp = ft_memalloc(s_size + b_size + 1);
	(void)ft_memcpy(tmp, s1, s_size);
	(void)ft_memcpy(&tmp[s_size], s2, b_size);
	ft_memdel(&s1);
	return (tmp);
}

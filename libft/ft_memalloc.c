/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bob <bob@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 18:25:21 by fokrober          #+#    #+#             */
/*   Updated: 2021/01/05 20:02:44 by bob              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	void	*ptr;

	if ((ptr = malloc(size)))
	{
		while (size--)
			((char*)ptr)[size] = (unsigned char)0;
	}
	return (ptr);
}

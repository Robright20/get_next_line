/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bob <bob@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 17:19:20 by bob               #+#    #+#             */
/*   Updated: 2021/01/13 09:54:39 by bob              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void		*ft_memdup(void const *ptr, size_t size)
{
	void	*result;
	size_t	i;

	if (!size || !ptr)
		return (NULL);
	result = malloc(size);
	i = -1;
	while (++i < size)
		((unsigned char*)result)[i] = ((unsigned char*)ptr)[i];
	return (result);
}

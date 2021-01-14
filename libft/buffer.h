/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bob <bob@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 17:09:27 by bob               #+#    #+#             */
/*   Updated: 2021/01/13 09:33:47 by bob              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUFFER_H
# define BUFFER_H
# include <stdlib.h>
# include "libft.h"
# include <sys/types.h>

typedef struct	s_buffer
{
	void			*ptr;
	ssize_t			pos;
	ssize_t			size;
}				t_buffer;

int				del_buffer(t_buffer **ptr);
int				reset_buffer(t_buffer *ptr);
void			*buf_realloc(t_buffer *ptr, size_t new_size);
int				buf_dup(t_buffer *dst, t_buffer *src, size_t begin);
int				buf_set(t_buffer *buf, void *str, size_t size, ssize_t pos);
#endif

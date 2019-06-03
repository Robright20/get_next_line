/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fokrober <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 15:55:41 by fokrober          #+#    #+#             */
/*   Updated: 2019/06/02 22:42:32 by fokrober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _GET_NEXT_LINE_H
# define _GET_NEXT_LINE_H
# define BUFF_SIZE 2
# include "libft/libft.h"
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <fcntl.h>

int		get_next_line(int fd, char **line);
#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fokrober <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 15:53:32 by fokrober          #+#    #+#             */
/*   Updated: 2019/05/26 23:06:37 by fokrober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

ssize_t		findn(char *s, size_t n)
{
	size_t			i;
	unsigned char	*p;

	p = (unsigned char*)s;
	i = 0;
	while (i < n)
	{
		if (p[i] == '\n')
			return ((ssize_t)i);
		i++;
	}
	return (-1);
}

ssize_t		fo_read(int fd, t_openfile *f, char **line)
{
	char	buf[BUFF_SIZE];
	ssize_t len;
	ssize_t	r;
	ssize_t	i;

	len = f->n;
	while ((r = read(fd, buf, BUFF_SIZE)) > 0)
	{
		if (!((i = findn(buf, r)) == -1))
		{
			*line = (char*)ft_memjoin(*line, buf, len, i);
			f->n = r - (i + 1);
			ft_strdel(&(f->s));
			f->s = (char*)ft_memdupz(buf + i + 1, f->n);
			return (1);
		}
		*line = (char*)ft_memjoin(*line, buf, len, r);
		len += r;
	}
	ft_strdel(&(f->s));
	f->n = 0;
	return (r);
}

int			chk_last(int fd, t_openfile *f, char **line)
{
	ssize_t	r;
	size_t	i;
	char	*tmp;

	i = 0;
	while ((f->s)[i] != '\n' && i < f->n)
		i++;
	*line = (char*)ft_memdupz(f->s, i);
	if (i < f->n)
	{
		if (!(tmp = (char*)ft_memdupz(f->s + i + 1, f->n)))
			return (-1);
		ft_strdel(&(f->s));
		f->s = tmp;
		f->n -= i + 1;
		return (1);
	}
	if ((r = fo_read(fd, f, line)) == -1)
		return (-1);
	return (1);
}

int			get_next_line(int fd, char **line)
{
	static t_openfile	f[4864];
	ssize_t				r;

	if (fd < 0 || BUFF_SIZE < 0 || !line)
		return (-1);
	*line = NULL;
	if (f[fd].s && f[fd].n)
		return (chk_last(fd, &f[fd], line));
	if ((r = fo_read(fd, &f[fd], line)) == 0)
		return (f[fd].n == 0 && *line);
	return (r);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fokrober <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 15:53:32 by fokrober          #+#    #+#             */
/*   Updated: 2019/05/20 21:35:00 by fokrober         ###   ########.fr       */
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

int			resize(t_openfile *f, size_t pos)
{
	char	*tmp;
	size_t	i;

	i = 0;
	f->n -= pos + 1;
	if (f->n > 0)
	{
		if (!(tmp = (char*)ft_memdupz(f->s + pos + 1, f->n)))
			return (-1);
		ft_strdel(&(f->s));
		f->s = tmp;
	}
	else if (f->n == 0)
		ft_strdel(&(f->s));
	return (f->n);
}

int			chk_last(t_openfile *f, char **line)
{
	size_t	i;

	i = 0;
	while ((f->s)[i] != '\n' && i < f->n)
		i++;
	*line = (char*)ft_memdupz(f->s, i);
	if (i < f->n)
	{
		resize(f, i);
		return (1);
	}
	return (0);
}

int			get_next_line(int fd, char **line)
{
	static t_openfile	f[64];
	char				buf[BUFF_SIZE];
	ssize_t				r;
	ssize_t				i;

	if (fd < 0 || BUFF_SIZE < 0 || !line)
		return (-1);
	if (fd > 0 && f[fd].fd == 0)
		f[fd].fd = fd;
	else if (fd >= 0 && f[fd].s)
	{
		if (chk_last(&f[fd], line))
			return (1);
		resize(f, f->n - 1);
	}
	while ((r = read(f[fd].fd, buf, BUFF_SIZE)) > 0)
	{
		if (!((i = findn(buf, r)) == -1))
		{
			*line = (char*)ft_memjoin(*line, buf, f[fd].n, i);
			f[fd].n = r - (i + 1);
			ft_strdel(&(f[fd].s));
			return ((f[fd].s = (char*)ft_memdupz(buf + i + 1, f[fd].n)) != buf);
		}
		*line = (char*)ft_memjoin(*line, buf, f[fd].n, r);
		f[fd].n += r;
	}
	return (r);
}

int			main(int argc, char **argv)
{
	int		fd2;
	char	*line;
	int		i;

	line = NULL;
	i = 1;

	//fd2 = open(argv[1], O_RDONLY);
	fd2 = 0;
	while (get_next_line(fd2, &line))
	{
		printf("line %s\n", line);
		ft_strdel(&line);
		i++;
	}
	close(fd2);
	return (0);
}

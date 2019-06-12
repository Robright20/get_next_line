/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fokrober <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/02 22:44:28 by fokrober          #+#    #+#             */
/*   Updated: 2019/06/12 13:02:20 by fokrober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"

void	ft_putline(char **line, int n)
{
	int		i;

	i = 0;
	while (i < n)
		ft_putchar(*line[i++]);
	ft_putchar('\n');
}

int		main(int ac, char **av)
{
	int		fd;
	char	*line;
	int		ret;

	(void)ac;
	(void)av;
//	fd = open(av[1], O_RDONLY);
	fd = 10000000;
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		printf("%s\n", line);
		ft_strdel(&line);
	}
	printf("ret : %d\n", ret);
	//close(fd);
	return (0);
}

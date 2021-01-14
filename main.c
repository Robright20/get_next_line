/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bob <bob@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/02 22:44:28 by fokrober          #+#    #+#             */
/*   Updated: 2021/01/13 13:14:29 by bob              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"

int		main(int ac, char **av)
{
	int		fd;
	char	*line;
	int		ret;

	fd = 42;
	if (ac == 2)
		fd = open(av[1], O_RDONLY);
	// printf("[%zd]\n", read(fd, line, 0));
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		printf("%s\n", line);
		ft_strdel(&line);
	}
	// printf("ret : %d %s\n", ret, line);
	if (fd)
		close(fd);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iderighe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 16:31:12 by iderighe          #+#    #+#             */
/*   Updated: 2021/02/10 16:48:10 by iderighe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		main(int argc, char **argv)
{
	int		fd;
	int 	end;
	int		ret = 0;
	int		y = 1;
	int		n = 1000;
	char	*line;

	if (argc != 2)
		return (1);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (1);
	printf("\nvaleur de fd = %d\n", fd);
	while (n > 0 && (ret = get_next_line(fd, &line)) == 1)
	{
		printf("\n|-[%d] : [%s]\n", y, line);
		y++;
		n--;
		free(line);
	}
	printf("\nRETOUR GNL = %d\nTOUR = %d\n", ret, y);
	end = close(fd);
	if (end == -1)
		printf("close error !");
	else
		printf("close succes ! close value = %d\n", end);
	return (0);
}

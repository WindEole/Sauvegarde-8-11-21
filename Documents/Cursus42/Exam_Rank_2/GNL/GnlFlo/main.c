/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iderighe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/05 12:21:33 by iderighe          #+#    #+#             */
/*   Updated: 2021/06/07 11:13:10 by iderighe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include "get_next_line.h"

//#include <unistd.h>
//#include <stdlib.h>
//#include <fcntl.h>
//#include <stdio.h>

int	main(int argc, char **argv)
{
	int		fd;
	int		end;
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
	while (n > 0 && (ret = get_next_line(&line)) == 1)
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
}*/

#include "get_next_line.h"

int	main(void)
{
	int	r;
	char	*line;
	printf("***********************************************\n");
	while ((r = get_next_line(&line)) > 0)
	{
		printf("%s\n", line);
		free(line);
		line = NULL;
	}
//	printf("%s", line);
//	free(line);
//	line = NULL;
	printf("***********************************************\n");
}

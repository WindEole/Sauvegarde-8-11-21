/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iderighe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 16:31:12 by iderighe          #+#    #+#             */
/*   Updated: 2021/02/11 17:09:23 by iderighe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int		main(int argc, char **argv)
{
	int		fd[argc - 1];
	int		end[argc - 1];
	int		i = 0;
	int		x = argc - 1;
	char	*line;
	int		ret = 0;
	int		y = 1;
	int		n = 1000;

	while (x != 0)
	{
		fd[i] = open(argv[i + 1], O_RDONLY);
		if (fd[i] == -1)
		{
			printf("open error on file %s\n", argv[i + 1]);
			return (1);
		}
		printf("fd du fichier %s = %d\n", argv[i + 1], fd[i]);
		while (n > 0 && (ret = get_next_line(fd[i], &line)) == 1)
		{
			printf("|-[%d] : [%s]\n", y, line);
			y++;
			n--;
			free(line);
		}
		printf("\nRETOUR GNL = %d\nTOUR = %d\n", ret, y);
		i++;
		x--;
	}
	i = 0;
	x = argc - 1;
	while (x != 0)
	{
		fd[i] = close(fd[i]);
		if (end[i] == -1)
			printf("close error !");
		printf("succes ! close value of file %s = %d\n", argv[i + 1], fd[i]);
		i++;
		x--;
	}
	return (0);
}

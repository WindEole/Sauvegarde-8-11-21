/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_recursive.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iderighe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 15:38:07 by iderighe          #+#    #+#             */
/*   Updated: 2021/06/03 11:08:49 by iderighe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

static int	recursive(char **line, int index, int fd)
{
	char	buf;
	int		ret;

	ret = read(fd, &buf, 1);
	if (ret == 1 && buf != '\n')
	{
		ret = recursive(line, index + 1, fd);
		if (ret != -1)
			(*line)[index] = buf;
	}
	else if (ret != -1)
	{
		*line = (char *)malloc(sizeof(char) * (index + 1));
printf("valeur de line : %s\n", *line);
		if (*line != NULL)
			(*line)[index] = '\0';
		else
			ret = -1;
	}
	return (ret);
}

int	get_next_line(int fd, char **line)
{
	return (recursive(line, 0, fd));
}

/*int        main(void)
{
    int        flag;
    char    *line;

    int fd;
    fd = open("test.txt", O_RDONLY);
    while ((flag = get_next_line(&line) != 0))//, fd)) != 0)
    {
        printf("%d - ", flag);
        printf("%s\n", line);
        free(line);
        line = NULL;
    }
    printf("%d - ", flag);
    printf("%s", line);
    free(line);
    line = NULL;
    return (0);
}*/

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

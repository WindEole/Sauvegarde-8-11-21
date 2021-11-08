/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humanfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 00:09:11 by humanfou          #+#    #+#             */
/*   Updated: 2021/03/30 00:09:20 by humanfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>

size_t	ft_strlen(char *str);
char	*ft_strcpy(char *dest, char *src);
int		ft_strcmp(char *s1, char *s2);
ssize_t	ft_write(int fd, const void *buf, size_t count);
ssize_t	ft_read(int fd, void *buf, size_t count);
char	*ft_strdup(char *str);

int	main(int ac, char **av)
{
	int		fd;
	int		ret1;
	int		ret2;
	char	d1[64];
	char	d2[64];
	char	*line1;
	char	*line2;

	if (ac == 3)
	{
		printf("\n argv[1] = %s \targv[2] = %s\n\n", av[1], av[2]);
		printf("=========================================\n");
		printf("#\tx64 ft_strlen VS std strlen\t#\n");
		printf("=========================================\n");
		ret1 = ft_strlen(av[1]);
		ret2 = ft_strlen(av[1]);
		printf("\tret x64 ==> %d\n", ret1);
		printf("\tret std ==> %d\n", ret2);
		if (ret1 == ret2)
		{
			printf("\033[32m");
			printf("\tStatus  [ Ok ]\n");
			printf("\033[0m");
		}
		else
		{
			printf("\033[31m");
			printf("\tStatus  [ Ok ]\n");
			printf("\033[0m");
		}

		printf("\n=========================================\n");
		printf("#\tx64 ft_strcpy VS std strcpy\t#\n");
		printf("=========================================\n");
		ft_strcpy(d1, av[1]);
		ft_strcpy(d2, av[1]);
		printf("==> Ret x64 [ dest : %s ]\n", ft_strcpy(d1, av[1]));
		printf("==> Ret std [ dest : %s ]\n", strcpy(d2, av[1]));
		if (strcmp(d1, d2) == 0)
		{
			printf("\033[32m");
			printf("\tStatus  [ Ok ]\n");
			printf("\033[0m");
		}
		else
		{
			printf("\033[31m");
			printf("\tStatus  [ Ok ]\n");
			printf("\033[0m");
		}

		printf("\n=========================================\n");
		printf("#\tx64 ft_strcmp VS std strcmp\t#\n");
		printf("=========================================\n");
		ret1 = ft_strcmp(av[1], av[2]);
		ret2 = strcmp(av[1], av[2]);
		printf("==> Ret x64 [ %d ]\n", ret1);
		printf("==> Ret std [ %d ]\n", ret2);
		if (ret1 == ret2)
		{
			printf("\033[32m");
			printf("\tStatus  [ Ok ]\n");
			printf("\033[0m");
		}
		else
		{
			printf("\033[31m");
			printf("\tStatus  [ Ok ]\n");
			printf("\033[0m");
		}

		printf("\n=========================================\n");
		printf("#\tx64 ft_write VS std write (2)\t#\n");
		printf("=========================================\n");
		ret1 = ft_write(1, av[1], ft_strlen(av[1]));
		printf("\n");
		ret2 = write(1, av[1], strlen(av[1]));
		printf("\n");
		printf("errno = %d\n", errno);
		if (ret1 == ret2)
		{
			printf("\033[32m");
			printf("\tStatus  [ Ok ]\n");
			printf("\033[0m");
		}
		else
		{
			printf("\033[31m");
			printf("\tStatus  [ Ok ]\n");
			printf("\033[0m");
		}
		printf("\n=========================================\n");
		printf("#\tx64 ft_read VS std read (2)\t#\n");
		printf("=========================================\n");

		printf("\n=========================================\n");
		printf("#\tx64 ft_strdup VS std strdup (3)\t#\n");
		printf("=========================================\n");
		fd = open("./main.c", O_RDONLY);
		line1 = ft_strdup(av[1]);
		line2 = strdup(av[1]);
		printf("==> ret x64 [ %s ]\n", line1);
		printf("==> ret std [ %s ]\n", line2);
		if (ft_strlen(line1) == ft_strlen(line2))
		{
			printf("\033[32m");
			printf("\tStatus  [ Ok ]\n");
			printf("\033[0m");
		}
		else
		{
			printf("\033[31m");
			printf("\tStatus  [ Ok ]\n");
			printf("\033[0m");
		}
		printf("errno = %d\n", errno);
		free(line1);
		free(line2);
	}
	return (0);
}

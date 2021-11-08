/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebarguil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 14:40:03 by ebarguil          #+#    #+#             */
/*   Updated: 2021/06/25 14:45:56 by iderighe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_strchr(char *s, char c)
{
	int	i;

	i = 0;
	while (s && s[i])
		if (s[i++] == c)
			return (1);
	return (0);
}

int		main(int ac, char **av)
{
	char	buf[16384];
	int		i;
	int		j;

	if (ac == 3)
	{
		i = 0;
		j = 0;
		while (av[1] && av[1][i])
			if (ft_strchr(buf, av[1][i++]) == 0)
				if (ft_strchr(av[2], av[1][i - 1]) == 1)
					buf[j++] = av[1][i - 1];
		buf[j] = '\0';
		j = 0;
		while (buf[j])
			write(1, &buf[j++], 1);
	}
	write(1, "\n", 1);
	return (0);
}

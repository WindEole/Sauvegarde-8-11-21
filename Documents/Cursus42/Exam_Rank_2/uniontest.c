/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uniontest.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iderighe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 10:19:12 by iderighe          #+#    #+#             */
/*   Updated: 2021/06/14 10:39:06 by iderighe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	int	cara[255] = {0};
	int	i;
	int	j;

	if (argc == 3)
	{
		i = 1;
		while (i < 3)
		{
			j = 0;
			while (argv[i][j])
			{
				if (!cara[(unsigned char)argv[i][j]])
				{
					cara[(unsigned char)argv[i][j]] = 1;
					write(1, &argv[i][j], 1);
				}
				j++;
			}
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}

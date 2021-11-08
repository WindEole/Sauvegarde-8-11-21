/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iderighe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 15:36:24 by iderighe          #+#    #+#             */
/*   Updated: 2021/05/27 16:01:09 by iderighe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	int	cara[255];
	int	i;
	int	j;

	if (argc == 3)
	{
		i = 2;
		while (i > 0)
		{
			j = 0;
			while (argv[i][j])
			{
				if (i == 2 && !cara[(unsigned char)argv[i][j]])
					cara[(unsigned char)argv[i][j]] = 1;
				else if (i == 1 && cara[(unsigned char)argv[i][j]] == 1)
				{
					write(1, &argv[i][j], 1);
					cara[(unsigned char)argv[i][j]] = 2;
				}
				j++;
			}
			i--;
		}
	}
	write(1, "\n", 1);
	return (0);
}

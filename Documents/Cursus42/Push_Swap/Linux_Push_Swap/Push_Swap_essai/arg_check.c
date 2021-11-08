/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iderighe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 14:52:12 by iderighe          #+#    #+#             */
/*   Updated: 2021/10/21 12:28:40 by iderighe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_varlen	ft_init_varlen(int max_len)
{
	t_varlen	varlen;

	varlen.len_a = max_len;
	varlen.len_b = 0;
	varlen.add = 0;
	varlen.min = 0;
	varlen.max = 0;
	varlen.pos_first = -1;
	varlen.pos_second = -1;
	varlen.max_len = max_len;
	varlen.count = 0;
	return (varlen);
}

int	ft_check_uarg(int argc, char **argv)
{
	const char	*arg_initial;
	int			j;

	arg_initial = ft_strdup(argv[1]);
	j = 0;
	while (argv[1][j] != '\0')
	{
		if (argv[1][j] <= 31 || (argv[1][j] >= '!' && argv[1][j] <= '*')
			|| argv[1][j] == ',' || argv[1][j] == '.' || argv[1][j] == '/'
			|| argv[1][j] >= ':' || ((argv[1][j] == '-' || argv[1][j] == '+')
			&& (argv[1][j + 1] == '-' || argv[1][j + 1] == '+')))
		{
			write(2, "Error\n", 6);
			return (0);
		}
		else
			j++;
	}
	argv = (char **)ft_split(arg_initial, ' ');
	if (argv == NULL)
		return (0);
	ft_check_uarg_suite(argc, argv);
	return (1);
}

int	ft_check_uarg_suite(int argc, char **argv)
{
	int	j;

	j = 0;
	if (argv[j] == NULL)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	j = 0;
	while (argv[j] != NULL)
		j++;
	argc = j;
	if (argc < 2)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	ft_check_dupl(argc, argv);
	return (1);
}

int	ft_check_narg(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (*argv[i] == '\0')
		{
			write(2, "Error\n", 6);
			return (0);
		}
		else
			i++;
	}
	ft_check_narg_suite(argc, argv);
	return (1);
}

int	ft_check_narg_suite(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			if (argv[i][j] <= 31 || (argv[i][j] > 32 && argv[i][j] <= '*')
				|| argv[i][j] == ',' || argv[i][j] == '.'
				|| argv[i][j] == '/' || argv[i][j] >= ':' || j > 10
				|| ((argv[i][j] == '-' || argv[i][j] == '+')
				&& (argv[i][j + 1] == '-' || argv[i][j + 1] == '+')))
			{
				write(2, "Error\n", 6);
				return (0);
			}
			else
				j++;
		}
		i++;
	}
	ft_check_dupl(argc, argv);
	return (1);
}

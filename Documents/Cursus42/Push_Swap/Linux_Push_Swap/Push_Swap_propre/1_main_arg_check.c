/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_main_arg_check.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iderighe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 14:52:12 by iderighe          #+#    #+#             */
/*   Updated: 2021/11/10 11:46:54 by iderighe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_uarg_suite(t_arg *arg)
{
	int	j;

	j = 0;
	if (arg->av[j] == NULL)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	j = 0;
	while (arg->av[j] != NULL)
		j++;
	arg->ac = j;
	if (arg->ac < 2)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	return (1);
}

int	ft_check_uarg(t_arg *arg)
{
	const char	*arg_initial;
	int			j;

	arg_initial = ft_strdup(arg->av[1]);
	j = 0;
	while (arg->av[1][j] != '\0')
	{
		if (arg->av[1][j] <= 31 || (arg->av[1][j] >= '!'
			&& arg->av[1][j] <= '*') || arg->av[1][j] == ','
			|| arg->av[1][j] == '.' || arg->av[1][j] == '/'
			|| arg->av[1][j] >= ':' || ((arg->av[1][j] == '-'
			|| arg->av[1][j] == '+') && (arg->av[1][j + 1] == '-'
			|| arg->av[1][j + 1] == '+')))
		{
			write(2, "Error\n", 6);
			return (0);
		}
		else
			j++;
	}
	arg->av = (char **)ft_split(arg_initial, ' ');
	if (arg->av == NULL)
		return (0);
	free((void *)arg_initial);
	return (ft_check_uarg_suite(arg));
}

int	ft_check_narg_suite(t_arg *arg)
{
	int	i;
	int	j;

	i = 1;
	while (i < arg->ac)
	{
		j = 0;
		while (arg->av[i][j] != '\0')
		{
			if (arg->av[i][j] <= 31 || (arg->av[i][j] > 32
				&& arg->av[i][j] <= '*') || arg->av[i][j] == ','
				|| arg->av[i][j] == '.' || arg->av[i][j] == '/'
				|| arg->av[i][j] >= ':' || j > 10 || ((arg->av[i][j] == '-'
				|| arg->av[i][j] == '+') && (arg->av[i][j + 1] == '-'
				|| arg->av[i][j + 1] == '+')))
			{
				write(2, "Error\n", 6);
				return (0);
			}
			else
				j++;
		}
		i++;
	}
	return (1);
}

int	ft_check_narg(t_arg *arg)
{
	int	i;

	i = 1;
	while (i < arg->ac)
	{
		if (*arg->av[i] == '\0')
		{
			write(2, "Error\n", 6);
			return (0);
		}
		else
			i++;
	}
	return (ft_check_narg_suite(arg));
}

int	main(int argc, char **argv)
{
	t_arg	arg;
	int		check;
	t_var	var;

	arg.ac = argc;
	arg.av = argv;
	if (argc <= 1)
		return (1);
	else if (argc == 2)
		check = ft_check_uarg(&arg);
	else
		check = ft_check_narg(&arg);
	if (check == 0)
		return (1);
	if (!(ft_check_dupl(&arg)))
		return (1);
	if (arg.av[0][0] == '.' || arg.av[0][0] == '/')
		arg.ac = arg.ac - 1;
	var = ft_init_var(arg.ac);
	if (!(ft_check_minmax(&arg)))
		return (1);
	if (!(ft_create_stack(&arg, &var)))
		return (1);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iderighe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 14:52:12 by iderighe          #+#    #+#             */
/*   Updated: 2021/11/04 14:19:14 by iderighe         ###   ########.fr       */
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

//int	ft_check_uarg(int argc, char **argv)
int	ft_check_uarg(t_arg *arg)
{
	const char	*arg_initial;
	int			j;
printf(RED"On entre ici ? argc = %d"RESET"\n", arg->new_argc);
	arg_initial = ft_strdup(arg->tab_argv[1]);
	j = 0;
	while (arg->tab_argv[1][j] != '\0')
	{
		if (arg->tab_argv[1][j] <= 31 || (arg->tab_argv[1][j] >= '!' && arg->tab_argv[1][j] <= '*')
			|| arg->tab_argv[1][j] == ',' || arg->tab_argv[1][j] == '.' || arg->tab_argv[1][j] == '/'
			|| arg->tab_argv[1][j] >= ':' || ((arg->tab_argv[1][j] == '-' || arg->tab_argv[1][j] == '+')
			&& (arg->tab_argv[1][j + 1] == '-' || arg->tab_argv[1][j + 1] == '+')))
		{
			write(2, "Error\n", 6);
			return (0);
		}
		else
			j++;
	}
	arg->tab_argv = (char **)ft_split(arg_initial, ' ');
	if (arg->tab_argv == NULL)
		return (0);
	return (ft_check_uarg_suite(arg));
//	return (1);
}

//int	ft_check_uarg_suite(int argc, char **argv)
int	ft_check_uarg_suite(t_arg *arg)
{
	int	j;
//printf(CYAN"On entre ici ? argc = %d"RESET"\n", argc);
	j = 0;
	if (arg->tab_argv[j] == NULL)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	j = 0;
	while (arg->tab_argv[j] != NULL)
		j++;
	arg->new_argc = j;
	if (arg->new_argc < 2)
	{
		write(2, "Error\n", 6);
		return (0);
	}
printf("argc = %d\n", arg->new_argc);
//	ft_check_dupl(argc, argv);
//	if (!(ft_check_dupl(argc, argv)))
//		return (0);
	return (1);
}

//int	ft_check_narg(int argc, char **argv)
int		ft_check_narg(t_arg *arg)
{
	int	i;

	i = 1;
	while (i < arg->new_argc)
	{
		if (*arg->tab_argv[i] == '\0')
		{
			write(2, "Error\n", 6);
			return (0);
		}
		else
			i++;
	}
	return (ft_check_narg_suite(arg));
//	return (ft_check_narg_suite(argc, argv));
//	return (1);
}

//int	ft_check_narg_suite(int argc, char **argv)
int	ft_check_narg_suite(t_arg *arg)
{
	int	i;
	int	j;

	i = 1;
	while (i < arg->new_argc)
	{
		j = 0;
		while (arg->tab_argv[i][j] != '\0')
		{
			if (arg->tab_argv[i][j] <= 31 || (arg->tab_argv[i][j] > 32 && arg->tab_argv[i][j] <= '*')
				|| arg->tab_argv[i][j] == ',' || arg->tab_argv[i][j] == '.'
				|| arg->tab_argv[i][j] == '/' || arg->tab_argv[i][j] >= ':' || j > 10
				|| ((arg->tab_argv[i][j] == '-' || arg->tab_argv[i][j] == '+')
				&& (arg->tab_argv[i][j + 1] == '-' || arg->tab_argv[i][j + 1] == '+')))
			{
				write(2, "Error\n", 6);
				return (0);
			}
			else
				j++;
		}
		i++;
	}
//	ft_check_dupl(argc, argv);
//	if (!(ft_check_dupl(argc, argv)))
//		return (0);
	return (1);
}

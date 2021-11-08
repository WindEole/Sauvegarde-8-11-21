/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iderighe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 12:48:58 by iderighe          #+#    #+#             */
/*   Updated: 2021/10/19 16:33:57 by iderighe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_define_var(int argc, char **argv)
{
	int			i;
	int			max_len_tmp;
	t_varlen	varlen;

	i = 0;
	max_len_tmp = argc;
	if (argv[0][0] == '.' || argv[0][0] == '/')
	{
		i = 1;
		max_len_tmp = argc - 1;
	}
	varlen = ft_init_varlen(max_len_tmp);
	ft_check_minmax(argc, argv, i, &varlen);
	return (1);
}

int	ft_check_minmax(int argc, char **argv, int i, t_varlen *varlen)
{
	long		*tmp;
	int			j;
	int			k;

	tmp = malloc(sizeof(long) * (argc));
	if (tmp == NULL)
		return (0);
	j = 0;
	k = i;
	while (k < argc)
	{
		tmp[j] = ft_atoi(argv[k]);
		if (tmp[j] > 2147483647 || tmp[j] < -2147483648)
		{
			write(2, "Error\n", 6);
			return (0);
		}
		j++;
		k++;
	}
	free(tmp);
	ft_create_stack(argc, argv, i, varlen);
	return (1);
}

int	ft_create_stack(int argc, char **argv, int i, t_varlen *varlen)
{
	int			*s_a;
	int			*s_b;
	int			j;
	int			init_sort;

	s_a = malloc(sizeof(int) * (argc));
	if (s_a == NULL)
		return (0);
	s_b = malloc (sizeof(int) * (argc));
	if (s_b == NULL)
		return (0);
	j = 0;
	while (i < argc)
	{
		s_a[j] = ft_atoi(argv[i]);
		s_b[j] = 0;
		j++;
		i++;
	}
	init_sort = ft_check_init_sort(s_a, *varlen);
	if (init_sort == 0)
		return (0);
	ft_parsing(s_a, s_b, varlen);
	return (1);
}

int	ft_parsing(int *s_a, int *s_b, t_varlen *varlen)
{
	if (varlen->len_a <= 3)
		ft_algo_2_3(s_a, varlen);
	else if (varlen->len_a > 3 && varlen->len_a <= 5)
		ft_algo_4_5(s_a, s_b, varlen);
	else
		ft_algo_big_numbers(s_a, s_b, varlen);
	ft_check_sort(s_a, *varlen);
	free(s_a);
	free(s_b);
	return (1);
}

int	main(int argc, char **argv)
{
	int	check;

	if (argc <= 1)
		return (0);
	else if (argc == 2)
		check = ft_check_uarg(argc, argv);
	else
		check = ft_check_narg(argc, argv);
	if (check == 0)
		return (0);
	return (0);
}

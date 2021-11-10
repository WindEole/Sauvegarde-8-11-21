/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_stack_parse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iderighe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 12:48:58 by iderighe          #+#    #+#             */
/*   Updated: 2021/11/10 12:23:26 by iderighe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_var	ft_init_var(int max_len)
{
	t_var	var;

	var.len_a = max_len;
	var.len_b = 0;
	var.add = 0;
	var.min = 0;
	var.max = 0;
	var.pos_first = -1;
	var.pos_second = -1;
	var.max_len = max_len;
	return (var);
}

void	ft_free_split(char **str)
{
	int	i;

	i = 0;
	if (str)
	{
		while (str[i])
		{
			free(str[i]);
			i++;
		}
		free(str);
	}
}

int	ft_create_stack(t_arg *arg, t_var *var)
{
	int	*s_a;
	int	*s_b;
	int	t[2];

	s_a = malloc(sizeof(int) * var->max_len);
	s_b = malloc (sizeof(int) * var->max_len);
	if (s_a == NULL || s_b == NULL)
		return (0);
	t[1] = 0;
	t[0] = 0;
	if (arg->av[0][0] == '.' || arg->av[0][0] == '/')
	{
		t[0] = 1;
		arg->ac = arg->ac + 1;
	}
	while (t[0] < arg->ac)
	{
		s_a[t[1]] = ft_atoi(arg->av[t[0]]);
		s_b[t[1]] = 0;
		t[1]++;
		t[0]++;
	}
	if (!(ft_parsing(s_a, s_b, arg, var)))
		return (0);
	return (1);
}

int	ft_parsing(int *s_a, int *s_b, t_arg *arg, t_var *var)
{
	if (!(ft_check_init_sort(s_a, *var)))
		return (0);
	if (arg->av[0][0] != '.' && arg->av[0][0] != '/')
		ft_free_split(arg->av);
	if (var->len_a <= 3)
		ft_algo_2_3(s_a, var);
	else if (var->len_a > 3 && var->len_a <= 5)
		ft_algo_4_5(s_a, s_b, var);
	else
		ft_algo_big_numbers(s_a, s_b, var);
	free(s_a);
	free(s_b);
	return (1);
}

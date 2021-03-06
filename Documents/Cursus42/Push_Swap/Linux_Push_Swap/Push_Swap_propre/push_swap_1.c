/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iderighe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 12:48:58 by iderighe          #+#    #+#             */
/*   Updated: 2021/11/05 14:05:05 by iderighe         ###   ########.fr       */
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

int	ft_check_minmax(t_arg *arg)
{
	long		*tmp;
	int			j;
	int			k;

	tmp = malloc(sizeof(long) * (arg->ac));
	if (tmp == NULL)
		return (0);
	j = 0;
	k = 0;
	if (arg->av[0][0] == '.' || arg->av[0][0] == '/')
		k = 1;
	while (k < arg->ac)
	{
		tmp[j] = ft_atoi(arg->av[k]);
		if (tmp[j] > 2147483647 || tmp[j] < -2147483648)
		{
			write(2, "Error\n", 6);
			return (0);
		}
		j++;
		k++;
	}
	free(tmp);
	return (1);
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
	int	i;
	int	j;

	s_a = malloc(sizeof(int) * var->max_len);
	s_b = malloc (sizeof(int) * var->max_len);
	if (s_a == NULL || s_b == NULL)
		return (0);
	j = 0;
	i = 0;
	if (arg->av[0][0] == '.' || arg->av[0][0] == '/')
	{
		i = 1;
		arg->ac = arg->ac + 1;
	}
	while (i < arg->ac)
	{
		s_a[j] = ft_atoi(arg->av[i]);
		s_b[j] = 0;
		j++;
		i++;
	}
	if (ft_check_init_sort(s_a, *var))
		return (0);
	ft_parsing(s_a, s_b, var);
	if (arg->av[0][0] != '.' && arg->av[0][0] != '/')
		ft_free_split(arg->av);
	return (1);
}

int	ft_parsing(int *s_a, int *s_b, t_var *var)
{
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

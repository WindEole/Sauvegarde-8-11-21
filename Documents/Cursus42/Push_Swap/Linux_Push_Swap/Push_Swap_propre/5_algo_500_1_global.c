/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5_algo_500_1_global.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iderighe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 16:58:59 by iderighe          #+#    #+#             */
/*   Updated: 2021/11/10 11:18:34 by iderighe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_algo_big_numbers(int *s_a, int *s_b, t_var *var)
{
	int	i;
	int	j;
	int	reverse_sort;

	reverse_sort = ft_check_reverse_sort(s_a, var);
	if (reverse_sort == 1)
	{
		i = var->len_a;
		while (i-- > 1)
		{
			ft_revrotate_a(s_a, var);
			ft_push_b(s_a, s_b, var);
		}
		j = var->len_b;
		while (j-- > 0)
			ft_push_a(s_a, s_b, var);
	}
	if (reverse_sort == 0)
	{
		ft_define_min_max(s_a, var);
		ft_create_index(s_a, s_b, var);
	}
	return (1);
}

void	ft_define_min_max(int *s_a, t_var *var)
{
	int	i;

	i = 0;
	var->min = s_a[0];
	while (i < var->max_len)
	{
		if (s_a[i] < var->min)
			var->min = s_a[i];
		i++;
	}
	i = 0;
	var->max = s_a[0];
	while (i < var->max_len)
	{
		if (s_a[i] > var->max)
			var->max = s_a[i];
		i++;
	}
}

void	ft_loop_browse(int *s_a, int *s_b, int *index_sa, t_var *var)
{
	int	i;
	int	pos_max;

	i = 0;
	free(index_sa);
	while (var->len_b != 0 && var->len_b < var->max_len)
	{
		ft_create_new_index(s_a, var);
		ft_move_to_top_a(s_a, s_b, var);
		i++;
	}
	i = 0;
	pos_max = 0;
	while (i < var->len_b)
	{
		if (s_b[i] == var->max)
			pos_max = i;
		i++;
	}
	ft_finish_sort(s_a, s_b, var, pos_max);
}

void	ft_finish_sort(int *s_a, int *s_b, t_var *var, int pos_max)
{
	int	j;

	while (!(s_b[0] == var->max))
	{
		if (pos_max <= var->len_b / 2)
			ft_rotate_b(s_b, var);
		else if (pos_max > var->len_b / 2)
			ft_revrotate_b(s_b, var);
	}
	j = 0;
	while (j < var->max_len)
	{
		if (s_b[0] < s_b[1])
			ft_swap_b(s_b, var);
		ft_push_a(s_a, s_b, var);
		j++;
	}
}

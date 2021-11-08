/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithme_to500_1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iderighe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 16:58:59 by iderighe          #+#    #+#             */
/*   Updated: 2021/10/23 15:34:37 by iderighe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_algo_big_numbers(int *s_a, int *s_b, t_varlen *varlen)
{
	int	i;
	int	j;
	int	reverse_sort;

	reverse_sort = ft_check_reverse_sort(s_a, varlen);
	if (reverse_sort == 1)
	{
		i = varlen->len_a;
		while (i-- > 1)
		{
			ft_revrotate_a(s_a, varlen);
			ft_push_b(s_a, s_b, varlen);
		}
		j = varlen->len_b;
		while (j-- > 0)
			ft_push_a(s_a, s_b, varlen);
	}
	if (reverse_sort == 0)
	{
		ft_define_min_max(s_a, varlen);
		ft_create_index(s_a, s_b, varlen);
	}
	return (1);
}

void	ft_define_min_max(int *s_a, t_varlen *varlen)
{
	int	i;

	i = 0;
	varlen->min = s_a[0];
	while (i < varlen->max_len)
	{
		if (s_a[i] < varlen->min)
			varlen->min = s_a[i];
		i++;
	}
	i = 0;
	varlen->max = s_a[0];
	while (i < varlen->max_len)
	{
		if (s_a[i] > varlen->max)
			varlen->max = s_a[i];
		i++;
	}
}

void	ft_loop_browse(int *s_a, int *s_b, int *index_sa, t_varlen *varlen)
{
	int	i;
	int	j;
	int	pos_max;

	i = 0;
	free(index_sa);
	while (varlen->len_b != 0 && varlen->len_b < varlen->max_len)
	{
		ft_create_new_index(s_a, varlen);
		ft_fill_sort_stack_b(s_a, s_b, varlen);
		i++;
	}
	i = 0;
	pos_max = 0;
	while (i < varlen->len_b)
	{
		if (s_b[i] == varlen->max)
			pos_max = i;
		i++;
	}
	while (!(s_b[0] == varlen->max))
	{
		if (pos_max <= varlen->len_b / 2)
			ft_rotate_b(s_b, varlen);
		else if (pos_max > varlen->len_b / 2)
			ft_revrotate_b(s_b, varlen);
	}
	j = 0;
	while (j < varlen->max_len)
	{
		if (s_b[0] < s_b[1])
			ft_swap_b(s_b, varlen);
		ft_push_a(s_a, s_b, varlen);
		j++;
	}
}

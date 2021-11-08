/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithme_to500_3.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iderighe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 11:32:35 by iderighe          #+#    #+#             */
/*   Updated: 2021/10/07 10:47:55 by iderighe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_fill_sort_stack_b(int *s_a, int *s_b, t_varlen *varlen)
{
	int	pos_second;

	pos_second = varlen->len_a - varlen->pos_second;
	if (varlen->pos_first < pos_second)
		ft_loop_rotate_a(s_a, varlen);
	else if (varlen->pos_first > pos_second)
		ft_loop_revrotate_a(s_a, varlen, pos_second);
	else if (varlen->pos_first == pos_second)
	{
		if (s_a[varlen->pos_first] < s_a[varlen->pos_second])
			ft_loop_rotate_a(s_a, varlen);
		else if (s_a[varlen->pos_first] > s_a[varlen->pos_second])
			ft_loop_revrotate_a(s_a, varlen, pos_second);
	}
	ft_sort_b(s_a, s_b, varlen);
}

void	ft_loop_rotate_a(int *s_a, t_varlen *varlen)
{
	int	i;

	i = 0;
	while (i < varlen->pos_first)
	{
		ft_rotate_a(s_a, varlen);
		i++;
	}
}

void	ft_loop_revrotate_a(int *s_a, t_varlen *varlen, int pos_second)
{
	int	i;

	i = 0;
	while (i < pos_second)
	{
		ft_revrotate_a(s_a, varlen);
		i++;
	}
}

void	ft_sort_b(int *s_a, int *s_b, t_varlen *varlen)
{
	int	i;

	i = 0;
	if (s_a[0] == varlen->min)
	{
		ft_push_b(s_a, s_b, varlen);
		ft_rotate_b(s_b, varlen);
	}
	else if (varlen->len_b > 1 && s_a[0] < s_b[0]
		&& s_a[0] > s_b[varlen->len_b - 1])
		ft_insert_in_b(s_a, s_b, varlen);
	else
	{
		ft_push_b(s_a, s_b, varlen);
		if (s_b[0] < s_b[1] && ((varlen->len_b - 1) != 0)
			&& s_b[0] > s_b[varlen->len_b - 1])
			ft_swap_b(s_b, varlen);
		if (s_b[0] < s_b[varlen->len_b - 1])
			ft_rotate_b(s_b, varlen);
	}
	return ;
}

void	ft_insert_in_b(int *s_a, int *s_b, t_varlen *varlen)
{
	int	i;

	i = 0;
	while (!(s_a[0] > s_b[0]))
	{
		ft_rotate_b(s_b, varlen);
		i++;
	}
	ft_push_b(s_a, s_b, varlen);
	while (i > 0)
	{
		ft_revrotate_b(s_b, varlen);
		i--;
	}
}

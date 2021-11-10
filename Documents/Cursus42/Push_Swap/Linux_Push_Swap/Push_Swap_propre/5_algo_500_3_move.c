/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5_algo_500_3_move.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iderighe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 11:32:35 by iderighe          #+#    #+#             */
/*   Updated: 2021/11/10 12:01:41 by iderighe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_move_to_top_a(int *s_a, int *s_b, t_var *var)
{
	int	pos_second;
	int	pos_in_b_first;
	int	pos_in_b_second;

	pos_second = var->len_a - var->pos_second;
	pos_in_b_first = ft_define_pos_in_b(s_a[var->pos_first], s_b, var);
	pos_in_b_second = ft_define_pos_in_b(s_a[var->pos_second], s_b, var);
	if (var->len_b == 2 && s_b[1] > s_b[0])
		ft_swap_b(s_b, var);
	if (var->pos_first < pos_second)
		ft_move_pos_first(s_a, s_b, var, pos_in_b_first);
	else if (var->pos_first > pos_second)
		ft_move_pos_second(s_a, s_b, var, pos_in_b_second);
	else if (var->pos_first == pos_second)
	{
		if (s_a[var->pos_first] < s_a[var->pos_second])
			ft_loop_rotate_a(s_a, var);
		else if (s_a[var->pos_first] > s_a[var->pos_second])
			ft_loop_revrotate_a(s_a, var, pos_second);
	}
	ft_insert_in_b(s_a, s_b, var);
}

void	ft_move_pos_first(int *s_a, int *s_b, t_var *var,
		int pos_in_b_first)
{
	if (pos_in_b_first >= var->pos_first && var->pos_first > 0)
		ft_loop_rotate_ab(s_a, s_b, var, var->pos_first);
	else if (var->pos_first > pos_in_b_first && pos_in_b_first > 0
		&& var->len_b > 1)
	{
		ft_loop_rotate_ab(s_a, s_b, var, pos_in_b_first);
		var->pos_first = var->pos_first - pos_in_b_first;
		ft_loop_rotate_a(s_a, var);
	}
	else
		ft_loop_rotate_a(s_a, var);
}

void	ft_move_pos_second(int *s_a, int *s_b, t_var *var,
		int pos_in_b_second)
{
	int	pos_second;

	pos_second = var->len_a - var->pos_second;
	if (pos_in_b_second > (var->len_b / 2) && pos_in_b_second > pos_second)
		ft_loop_revrotate_ab(s_a, s_b, var, pos_second);
	else
		ft_loop_revrotate_a(s_a, var, pos_second);
}

void	ft_insert_in_b(int *s_a, int *s_b, t_var *var)
{
	int	i;
	int	pos_in_b;

	i = 0;
	pos_in_b = ft_define_pos_in_b(s_a[0], s_b, var);
	if (pos_in_b <= (var->len_b / 2))
		ft_loop_rotate_b(pos_in_b, s_b, var);
	else if (pos_in_b > (var->len_b / 2))
	{
		i = 0;
		pos_in_b = var->len_b - pos_in_b;
		if (s_a[0] != var->min)
		{
			while (i < pos_in_b)
			{
				ft_revrotate_b(s_b, var);
				i++;
			}
		}
	}
	ft_push_b(s_a, s_b, var);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithme_to500_3.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iderighe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 11:32:35 by iderighe          #+#    #+#             */
/*   Updated: 2021/11/05 10:54:29 by iderighe         ###   ########.fr       */
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
	{
		ft_loop_rotate_ab(s_a, s_b, var, var->pos_first);
	}
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
	if (pos_in_b_second > (var->len_b / 2))
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

int	ft_define_pos_in_b(int xa, int *s_b, t_var *var)
{
	int	i;
	int	pos_in_b;

	i = 0;
	pos_in_b = 0;
	while (i < var->len_b)
	{
		if (xa > s_b[i])
			break ;
		else
			i++;
	}
	if (i == var->len_b || xa == var->min)
		pos_in_b = ft_define_pos_in_b_min(xa, s_b, var);
	else
		pos_in_b = ft_define_pos_in_b_middle(xa, s_b, var);
	return (pos_in_b);
}

int	ft_define_pos_in_b_min(int xa, int *s_b, t_var *var)
{
	int	i;
	int	pos_in_b;

	i = 0;
	pos_in_b = 0;
	while (i < var->len_b)
	{
		if (xa < s_b[i] && s_b[i] < s_b[i + 1])
		{
			if (xa == var->min)
				pos_in_b = i;
			else
				pos_in_b = i + 1;
		}
		i++;
	}
	return (pos_in_b);
}

int	ft_define_pos_in_b_middle(int xa, int *s_b, t_var *var)
{
	int	i;
	int	j;
	int	pos_in_b;
	int	pos_in_b_value;

	i = 0;
	pos_in_b = 0;
	pos_in_b_value = var->min - 1;
	while (i < var->len_b)
	{
		j = 0;
		while (j < var->len_b)
		{
			if (s_b[j] >= s_b[i] && s_b[j] < xa && s_b[j] > pos_in_b_value
				&& s_b[i] < xa)
			{
				pos_in_b = j;
				pos_in_b_value = s_b[j];
			}
			j++;
		}
		i++;
	}
	return (pos_in_b);
}

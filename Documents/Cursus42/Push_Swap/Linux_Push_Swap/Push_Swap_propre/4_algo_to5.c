/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_algo_to5.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iderighe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 12:24:06 by iderighe          #+#    #+#             */
/*   Updated: 2021/11/10 11:21:11 by iderighe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_algo_2_3(int *s_a, t_var *var)
{
	if (var->len_a == 2)
	{
		if (s_a[0] > s_a[1])
			ft_swap_a(s_a, var);
		else
			return ;
	}
	else
		ft_algo_3(s_a, var);
	return ;
}

void	ft_algo_3(int *s_a, t_var *var)
{
	if (s_a[0] < s_a[1])
	{
		ft_revrotate_a(s_a, var);
		if (s_a[0] > s_a[1])
			ft_swap_a(s_a, var);
		else
			return ;
	}
	if (s_a[0] > s_a[1])
	{
		if (s_a[0] < s_a[2])
			ft_swap_a(s_a, var);
		else
		{
			ft_rotate_a(s_a, var);
			if (s_a[0] > s_a[1])
				ft_swap_a(s_a, var);
		}
		return ;
	}
	return ;
}

void	ft_algo_common_4_5(int *s_a, int *s_b, t_var *var)
{
	if (s_b[0] < s_a[0])
		ft_push_a(s_a, s_b, var);
	else if (s_b[0] > s_a[var->len_a - 1])
	{
		ft_push_a(s_a, s_b, var);
		ft_rotate_a(s_a, var);
	}
	else if (s_b[0] > s_a[0] && s_b[0] < s_a[1])
	{
		ft_rotate_a(s_a, var);
		ft_push_a(s_a, s_b, var);
		ft_revrotate_a(s_a, var);
	}
	return ;
}

void	ft_algo_4_5(int *s_a, int *s_b, t_var *var)
{
	if (var->len_a == 4)
	{
		ft_push_b(s_a, s_b, var);
		if (!((s_a[0] < s_a[1]) && (s_a[1] < s_a[2])))
			ft_algo_3(s_a, var);
		if (s_b[0] < s_a[0] || s_b[0] > s_a[var->len_a - 1]
			|| (s_b[0] > s_a[0] && s_b[0] < s_a[1]))
			ft_algo_common_4_5(s_a, s_b, var);
		else if (s_b[0] > s_a[0] && s_b[0] > s_a[1])
		{
			ft_revrotate_a(s_a, var);
			ft_push_a(s_a, s_b, var);
			ft_rotate_a(s_a, var);
			ft_rotate_a(s_a, var);
		}
		return ;
	}
	else
		ft_algo_5(s_a, s_b, var);
	return ;
}

void	ft_algo_5(int *s_a, int *s_b, t_var *var)
{
	if (s_a[0] > s_a[1])
		ft_swap_a(s_a, var);
	ft_push_b(s_a, s_b, var);
	ft_algo_4_5(s_a, s_b, var);
	if (s_b[0] < s_a[0] || s_b[0] > s_a[var->len_a - 1]
		|| (s_b[0] > s_a[0] && s_b[0] < s_a[1]))
		ft_algo_common_4_5(s_a, s_b, var);
	else if (s_b[0] > s_a[0] && s_b[0] > s_a[1] && s_b[0] > s_a[2])
	{
		ft_revrotate_a(s_a, var);
		ft_push_a(s_a, s_b, var);
		ft_rotate_a(s_a, var);
		ft_rotate_a(s_a, var);
	}
	else if (s_b[0] > s_a[0] && s_b[0] > s_a[1] && s_b[0] < s_a[2])
	{
		ft_revrotate_a(s_a, var);
		ft_revrotate_a(s_a, var);
		ft_push_a(s_a, s_b, var);
		ft_revrotate_a(s_a, var);
		ft_revrotate_a(s_a, var);
	}
	return ;
}

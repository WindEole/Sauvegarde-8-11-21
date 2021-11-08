/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithme.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iderighe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 12:24:06 by iderighe          #+#    #+#             */
/*   Updated: 2021/08/23 14:44:00 by iderighe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_algo_2_3(int *s_A, t_varlen varlen)
{
	if (varlen.len_a == 2)
	{
		if (s_A[0] > s_A[1])
			ft_swap_a(s_A, varlen);
		else
			return ;
	}
	else
		ft_algo_3(s_A, varlen);
	return ;
}

void	ft_algo_3(int *s_A, t_varlen varlen)
{
	if (s_A[0] < s_A[1])
	{
		ft_revrotate_a(s_A, varlen);
		if (s_A[0] > s_A[1])
			ft_swap_a(s_A, varlen);
		else
			return ;
	}
	if (s_A[0] > s_A[1])
	{
		if (s_A[0] < s_A[2])
			ft_swap_a(s_A, varlen);
		else
		{
			ft_rotate_a(s_A, varlen);
			if (s_A[0] > s_A[1])
				ft_swap_a(s_A, varlen);
		}
		return ;
	}
	return ;
}

void	ft_algo_common_4_5(int *s_A, int *s_B, int max_len, t_varlen *varlen)
{
	if (s_B[0] < s_A[0])
		ft_push_a(s_A, s_B, max_len, varlen);
	else if (s_B[0] > s_A[varlen->len_a - 1])
	{
		ft_push_a(s_A, s_B, max_len, varlen);
		ft_rotate_a(s_A, *varlen);
	}
	else if (s_B[0] > s_A[0] && s_B[0] < s_A[1])
	{
		ft_rotate_a(s_A, *varlen);
		ft_push_a(s_A, s_B, max_len, varlen);
		ft_revrotate_a(s_A, *varlen);
	}
	return ;
}

void	ft_algo_4_5(int *s_A, int *s_B, int max_len, t_varlen *varlen)
{
	if (varlen->len_a == 4)
	{
		ft_push_b(s_A, s_B, max_len, varlen);
		if (!((s_A[0] < s_A[1]) && (s_A[1] < s_A[2])))
			ft_algo_3(s_A, *varlen);
		if (s_B[0] < s_A[0] || s_B[0] > s_A[varlen->len_a - 1]
			|| (s_B[0] > s_A[0] && s_B[0] < s_A[1]))
			ft_algo_common_4_5(s_A, s_B, max_len, varlen);
		else if (s_B[0] > s_A[0] && s_B[0] > s_A[1])
		{
			ft_revrotate_a(s_A, *varlen);
			ft_push_a(s_A, s_B, max_len, varlen);
			ft_rotate_a(s_A, *varlen);
			ft_rotate_a(s_A, *varlen);
		}
		return ;
	}
	else
		ft_algo_5(s_A, s_B, max_len, varlen);
	return ;
}

void	ft_algo_5(int *s_A, int *s_B, int max_len, t_varlen *varlen)
{
	ft_push_b(s_A, s_B, max_len, varlen);
	ft_algo_4_5(s_A, s_B, max_len, varlen);
	if (s_B[0] < s_A[0] || s_B[0] > s_A[varlen->len_a - 1]
		|| (s_B[0] > s_A[0] && s_B[0] < s_A[1]))
		ft_algo_common_4_5(s_A, s_B, max_len, varlen);
	else if (s_B[0] > s_A[0] && s_B[0] > s_A[1] && s_B[0] > s_A[2])
	{
		ft_revrotate_a(s_A, *varlen);
		ft_push_a(s_A, s_B, max_len, varlen);
		ft_rotate_a(s_A, *varlen);
		ft_rotate_a(s_A, *varlen);
	}
	else if (s_B[0] > s_A[0] && s_B[0] > s_A[1] && s_B[0] < s_A[2])
	{
		ft_revrotate_a(s_A, *varlen);
		ft_revrotate_a(s_A, *varlen);
		ft_push_a(s_A, s_B, max_len, varlen);
		ft_revrotate_a(s_A, *varlen);
		ft_revrotate_a(s_A, *varlen);
	}
	return ;
}

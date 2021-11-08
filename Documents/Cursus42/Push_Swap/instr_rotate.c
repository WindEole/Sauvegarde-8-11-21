/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iderighe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 11:02:30 by iderighe          #+#    #+#             */
/*   Updated: 2021/10/05 11:51:34 by iderighe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate_a(int *s_A, t_varlen *varlen)
{
	int	i;
	int	tmp;

	if (varlen->len_a <= 1)
		return ;
	else
	{
		write(1, "ra\n", 3);
		i = 0;
		tmp = s_A[0];
		while (i < varlen->len_a)
		{
			s_A[i] = s_A[i + 1];
			i++;
		}
		s_A[i - 1] = tmp;
		varlen->add = varlen->add + 1;
		return ;
	}
}

void	ft_rotate_b(int *s_B, t_varlen *varlen)
{
	int	i;
	int	tmp;

	if (varlen->len_b <= 1)
		return ;
	else
	{
		write(1, "rb\n", 3);
		i = 0;
		tmp = s_B[0];
		while (i < varlen->len_b)
		{
			s_B[i] = s_B[i + 1];
			i++;
		}
		s_B[i - 1] = tmp;
		varlen->add = varlen->add + 1;
		return ;
	}
}

void	ft_rotate_ab(int *s_A, int *s_B, t_varlen *varlen)
{
	int	i;
	int	tmp;

	if (varlen->len_a <= 1 || varlen->len_b <= 1)
		return ;
	else
	{
		write(1, "rr\n", 3);
		i = 0;
		tmp = s_A[0];
		while (i++ < varlen->len_a)
			s_A[i] = s_A[i + 1];
		s_A[i - 1] = tmp;
		i = 0;
		tmp = s_B[0];
		while (i++ < varlen->len_b)
			s_B[i] = s_B[i + 1];
		s_B[i - 1] = tmp;
		varlen->add = varlen->add + 1;
		return ;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iderighe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 11:02:30 by iderighe          #+#    #+#             */
/*   Updated: 2021/11/04 13:34:52 by iderighe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//////////////     1 IN BUFFER     ///////////////////////////////

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
			if (i + 1 < varlen->len_a)
				s_A[i] = s_A[i + 1];
			i++;
		}
		s_A[i - 1] = tmp;
		varlen->add = varlen->add + 1;
		return ;
	}
}

//////////////     2 IN BUFFER     ///////////////////////////////

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

//////////////     3 IN BUFFER     ///////////////////////////////

void	ft_rotate_ab(int *s_a, int *s_b, t_varlen *varlen)
{
	int	i;
	int	tmp;

	if (varlen->len_a <= 1 || varlen->len_b <= 1)
		return ;
	else
	{
//printf(CYAN"varlen->len_a = %d, varlen->len_b = %d"RESET"\n", varlen->len_a, varlen->len_b);
		write(1, "rr\n", 3);
		i = 0;
		tmp = s_a[0];
//		while (i++ < varlen->len_a)
//			s_a[i] = s_a[i + 1];
		while (i < varlen->len_a)
		{
			s_a[i] = s_a[i + 1];
			i++;
		}
		s_a[i - 1] = tmp;
		i = 0;
		tmp = s_b[0];
		while (i < varlen->len_b)
		{
			s_b[i] = s_b[i + 1];
			i++;
		}
		s_b[i - 1] = tmp;
		varlen->add = varlen->add + 1;
/*	i = 0;
	while (i < varlen->len_a)
	{
printf(YELLOW"s_a[%d] = %d"RESET"\n", i, s_a[i]);
		i++;
	}
	i = 0;
	while (i < varlen->len_b)
	{
printf(BLUE"s_b[%d] = %d"RESET"\n", i, s_b[i]);
		i++;
	}*/

		return ;
	}
}

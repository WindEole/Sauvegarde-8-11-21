/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iderighe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 11:02:30 by iderighe          #+#    #+#             */
/*   Updated: 2021/08/23 11:57:54 by iderighe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_revrotate_a(int *s_A, t_varlen varlen)
{
	int	i;
	int	j;
	int	tmp;

printf("\nREVERSE ROTATE A\n");
	if (varlen.len_a <= 1)
		return ;
	else
	{
		i = varlen.len_a - 1;
		tmp = s_A[i];
		while (i > 0)
		{
			s_A[i] = s_A[i - 1];
			i--;
		}
		s_A[0] = tmp;
		j = 0;
		while (j < varlen.len_a)
		{
printf(YELLOW"s_A[%d] = %d" RESET "\n", j, s_A[j]);
			j++;
		}
		return ;
	}
}

void	ft_revrotate_b(int *s_B, t_varlen varlen)
{
	int	i;
	int	j;
	int	tmp;

printf("\nREVERSE ROTATE B\n");
	if (varlen.len_b <= 1)
		return ;
	else
	{
		i = varlen.len_b - 1;
		tmp = s_B[i];
		while (i > 0)
		{
			s_B[i] = s_B[i - 1];
			i--;
		}
		s_B[0] = tmp;
		j = 0;
		while (j < varlen.len_b)
		{
printf(BLUE"s_B[%d] = %d" RESET "\n", j, s_B[j]);
			j++;
		}
		return ;
	}
}

void	ft_revrotate_ab(int *s_A, int *s_B, t_varlen varlen)
{
	int	i;
	int	j;
	int	tmp;

printf("\nREVERSE ROTATE A ET B\n");
	if (varlen.len_a <= 1 || varlen.len_b <= 1)
		return ;
	else
	{
		i = varlen.len_a - 1;
		tmp = s_A[i];
		while (i > 0)
		{
			s_A[i] = s_A[i - 1];
			i--;
		}
		s_A[0] = tmp;
		i = varlen.len_b - 1;
		tmp = s_B[i];
		while (i > 0)
		{
			s_B[i] = s_B[i - 1];
			i--;
		}
		s_B[0] = tmp;
		j = 0;
		while (j < varlen.len_a)
		{
printf(YELLOW"s_A[%d] = %d" RESET "\n", j, s_A[j]);
			j++;
		}
		j = 0;
		while (j < varlen.len_b)
		{
printf(BLUE"s_B[%d] = %d" RESET "\n", j, s_B[j]);
			j++;
		}
		return ;
	}
}

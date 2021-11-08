/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iderighe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 12:11:54 by iderighe          #+#    #+#             */
/*   Updated: 2021/08/24 12:31:31 by iderighe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_a(int *s_A, int *s_B, int max_len, t_varlen *varlen)
{
	int	i;
	int	j;
	int	k;
	int	temp;

	if (varlen->len_a == max_len)
		return ;
	else
	{
		i = varlen->len_a;
		j = 0;
printf("\nPUSH_A : \n");
		temp = s_B[0];
		varlen->len_a = varlen->len_a + 1;
		varlen->len_b = varlen->len_b - 1;
		while (j < varlen->len_b)
		{
			s_B[j] = s_B[j + 1];
printf(BLUE "s_B[%d] apres push_a = %d" RESET "\n", j, s_B[j]);
			j++;
		}
		while (i > 0)
		{
			s_A[i] = s_A[i - 1];
			i--;
		}
		s_A[0] = temp;
		k = 0;
		while (k < varlen->len_a)
		{
printf(YELLOW "s_A[%d] apres push_a = %d" RESET "\n", k, s_A[k]);
			k++;
		}
	}
}

void	ft_push_b(int *s_A, int *s_B, int max_len, t_varlen *varlen)
{
	int	i;
	int	j;
	int	k;
	int	temp;

	if (varlen->len_b == max_len)
		return ;
	else
	{
		i = varlen->len_b;
		j = 0;
printf("\nPUSH_B : \n");
		temp = s_A[0];
		varlen->len_a = varlen->len_a - 1;
		varlen->len_b = varlen->len_b + 1;
		while (j < varlen->len_a)
		{
			s_A[j] = s_A[j + 1];
printf(YELLOW "s_A[%d] apres push_b = %d" RESET "\n", j, s_A[j]);
			j++;
		}
		while (i > 0)
		{
			s_B[i] = s_B[i - 1];
			i--;
		}
		s_B[0] = temp;
		k = 0;
		while (k < varlen->len_b)
		{
printf(BLUE "s_B[%d] apres push_b = %d" RESET "\n", k, s_B[k]);
			k++;
		}
	}
}

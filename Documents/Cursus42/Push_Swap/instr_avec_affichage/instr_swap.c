/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iderighe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 17:26:04 by iderighe          #+#    #+#             */
/*   Updated: 2021/08/23 11:55:31 by iderighe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap_a(int *s_A, t_varlen varlen)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	temp = s_A[i];
	s_A[i] = s_A[i + 1];
	s_A[i + 1] = temp;
	j = 0;
printf("\nSWAP_A : \n");
	while (j < varlen.len_a)
	{
printf(YELLOW"s_A[%d] apres swap_a = %d" RESET "\n", j, s_A[j]);
		j++;
	}
}

void	ft_swap_b(int *s_B, t_varlen varlen)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	temp = s_B[i];
	s_B[i] = s_B[i + 1];
	s_B[i + 1] = temp;
	j = 0;
printf("\nSWAP_B : \n");
	while (j < varlen.len_b)
	{
printf(BLUE"s_B[%d] apres swap_b = %d" RESET "\n", j, s_B[j]);
		j++;
	}
}

void	ft_swap_ab(int *s_A, int *s_B, t_varlen varlen)
{
	int	i;
	int	j;
	int	k;
	int	temp_a;
	int	temp_b;

	i = 0;
	temp_a = s_A[i];
	s_A[i] = s_A[i + 1];
	s_A[i + 1] = temp_a;
	j = 0;
	temp_b = s_B[j];
	s_B[j] = s_B[j + 1];
	s_B[j + 1] = temp_b;
	k = 0;
printf("\nSWAP_AB : \n");
	while (k < varlen.len_a)
	{
printf(YELLOW"s_A[%d] apres swap_ab = %d"RESET"\n", k, s_A[k]);
		k++;
	}
	k = 0;
	while (k < varlen.len_b)
	{
printf(BLUE"s_B[%d] apres swap_ab = %d" RESET"\n", k, s_B[k]);
		k++;
	}
}

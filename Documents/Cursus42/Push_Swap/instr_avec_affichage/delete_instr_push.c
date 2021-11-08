/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iderighe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 12:11:54 by iderighe          #+#    #+#             */
/*   Updated: 2021/09/21 13:27:13 by iderighe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_a(int *s_a, int *s_b, int max_len, t_varlen *varlen)
{
	int	i;
	int	j;
	int	temp;

	if (varlen->len_a == max_len)
		return ;
	else
	{
		i = varlen->len_a;
		j = 0;
		printf("pa\n");
		temp = s_b[0];
		varlen->len_a = varlen->len_a + 1;
		varlen->len_b = varlen->len_b - 1;
		while (j < varlen->len_b)
		{
			s_b[j] = s_b[j + 1];
			j++;
		}
		while (i > 0)
		{
			s_a[i] = s_a[i - 1];
			i--;
		}
		s_a[0] = temp;
		varlen->add = varlen->add + 1;
		return ;
	}
}

void	ft_push_b(int *s_a, int *s_b, int max_len, t_varlen *varlen)
{
	int	i;
	int	j;
	int	temp;

	if (varlen->len_b == max_len)
		return ;
	else
	{
		i = varlen->len_b;
		j = 0;
		printf("pb\n");
		temp = s_a[0];
		varlen->len_a = varlen->len_a - 1;
		varlen->len_b = varlen->len_b + 1;
		while (j < varlen->len_a)
		{
			s_a[j] = s_a[j + 1];
			j++;
		}
		while (i > 0)
		{
			s_b[i] = s_b[i - 1];
			i--;
		}
		s_b[0] = temp;
		varlen->add = varlen->add + 1;
		return ;
	}
}

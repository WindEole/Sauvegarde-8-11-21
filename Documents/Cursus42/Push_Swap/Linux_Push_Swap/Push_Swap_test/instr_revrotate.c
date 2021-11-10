/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iderighe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 11:02:30 by iderighe          #+#    #+#             */
/*   Updated: 2021/11/09 12:23:15 by iderighe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//////////////     4 IN BUFFER     ///////////////////////////////

void	ft_revrotate_a(int *s_a, t_varlen *varlen)
{
	int	i;
	int	tmp;

	if (varlen->len_a <= 1)
		return ;
	else
	{
		write(1, "rra\n", 4);
		i = varlen->len_a - 1;
		tmp = s_a[i];
		while (i > 0)
		{
			s_a[i] = s_a[i - 1];
			i--;
		}
		s_a[0] = tmp;
		varlen->add = varlen->add + 1;
		return ;
	}
}

//////////////     5 IN BUFFER     ///////////////////////////////

void	ft_revrotate_b(int *s_b, t_varlen *varlen)
{
	int	i;
	int	tmp;

	if (varlen->len_b <= 1)
		return ;
	else
	{
		write(1, "rrb\n", 4);
		i = varlen->len_b - 1;
		tmp = s_b[i];
		while (i > 0)
		{
			s_b[i] = s_b[i - 1];
			i--;
		}
		s_b[0] = tmp;
		varlen->add = varlen->add + 1;
		return ;
	}
}

//////////////     6 IN BUFFER     ///////////////////////////////

void	ft_revrotate_ab(int *s_a, int *s_b, t_varlen *varlen)
{
	int	i;
	int	tmp;
printf("revrotate ab ?\n");
	if (varlen->len_a <= 1 || varlen->len_b <= 1)
		return ;
	else
	{
		write(1, "rrr\n", 4);
		i = varlen->len_a - 1;
		tmp = s_a[i];
		while (i > 0)
		{
			s_a[i] = s_a[i - 1];
			i--;
		}
		s_a[0] = tmp;
		i = varlen->len_b - 1;
		tmp = s_b[i];
		while (i > 0)
		{
			s_b[i] = s_b[i - 1];
			i--;
		}
		s_b[0] = tmp;
		varlen->add = varlen->add + 1;
		return ;
	}
}

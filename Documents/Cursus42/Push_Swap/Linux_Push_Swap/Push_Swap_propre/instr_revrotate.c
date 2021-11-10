/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr_revrotate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iderighe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 11:02:30 by iderighe          #+#    #+#             */
/*   Updated: 2021/11/10 11:22:15 by iderighe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_revrotate_a(int *s_a, t_var *var)
{
	int	i;
	int	tmp;

	if (var->len_a <= 1)
		return ;
	else
	{
		write(1, "rra\n", 4);
		i = var->len_a - 1;
		tmp = s_a[i];
		while (i > 0)
		{
			s_a[i] = s_a[i - 1];
			i--;
		}
		s_a[0] = tmp;
		var->add = var->add + 1;
		return ;
	}
}

void	ft_revrotate_b(int *s_b, t_var *var)
{
	int	i;
	int	tmp;

	if (var->len_b <= 1)
		return ;
	else
	{
		write(1, "rrb\n", 4);
		i = var->len_b - 1;
		tmp = s_b[i];
		while (i > 0)
		{
			s_b[i] = s_b[i - 1];
			i--;
		}
		s_b[0] = tmp;
		var->add = var->add + 1;
		return ;
	}
}

void	ft_revrotate_ab(int *s_a, int *s_b, t_var *var)
{
	int	i;
	int	tmp;

	if (var->len_a <= 1 || var->len_b <= 1)
		return ;
	else
	{
		write(1, "rrr\n", 4);
		i = var->len_a - 1;
		tmp = s_a[i];
		while (i > 0)
		{
			s_a[i] = s_a[i - 1];
			i--;
		}
		s_a[0] = tmp;
		ft_revrotate_ab_suite(s_b, var);
		return ;
	}
}

void	ft_revrotate_ab_suite(int *s_b, t_var *var)
{
	int	i;
	int	tmp;

	i = var->len_b - 1;
	tmp = s_b[i];
	while (i > 0)
	{
		s_b[i] = s_b[i - 1];
		i--;
	}
	s_b[0] = tmp;
	var->add = var->add + 1;
}

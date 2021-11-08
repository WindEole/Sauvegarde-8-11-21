/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iderighe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 11:02:30 by iderighe          #+#    #+#             */
/*   Updated: 2021/11/05 10:26:16 by iderighe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate_a(int *s_a, t_var *var)
{
	int	i;
	int	tmp;

	if (var->len_a <= 1)
		return ;
	else
	{
		write(1, "ra\n", 3);
		i = 0;
		tmp = s_a[0];
		while (i < var->len_a)
		{
			if (i + 1 < var->len_a)
				s_a[i] = s_a[i + 1];
			i++;
		}
		s_a[i - 1] = tmp;
		var->add = var->add + 1;
		return ;
	}
}

void	ft_rotate_b(int *s_b, t_var *var)
{
	int	i;
	int	tmp;

	if (var->len_b <= 1)
		return ;
	else
	{
		write(1, "rb\n", 3);
		i = 0;
		tmp = s_b[0];
		while (i < var->len_b)
		{
			s_b[i] = s_b[i + 1];
			i++;
		}
		s_b[i - 1] = tmp;
		var->add = var->add + 1;
		return ;
	}
}

void	ft_rotate_ab(int *s_a, int *s_b, t_var *var)
{
	int	i;
	int	tmp;

	if (var->len_a <= 1 || var->len_b <= 1)
		return ;
	else
	{
		write(1, "rr\n", 3);
		i = 0;
		tmp = s_a[0];
		while (i < var->len_a)
		{
			s_a[i] = s_a[i + 1];
			i++;
		}
		s_a[i - 1] = tmp;
		ft_rotate_ab_suite(s_b, var);
		return ;
	}
}

void	ft_rotate_ab_suite(int *s_b, t_var *var)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = s_b[0];
	while (i < var->len_b)
	{
		s_b[i] = s_b[i + 1];
		i++;
	}
	s_b[i - 1] = tmp;
	var->add = var->add + 1;
}

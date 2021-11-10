/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr_swap_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iderighe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 17:26:04 by iderighe          #+#    #+#             */
/*   Updated: 2021/11/10 11:22:44 by iderighe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap_a(int *s_a, t_var *var)
{
	int	i;
	int	temp;

	write(1, "sa\n", 3);
	i = 0;
	temp = s_a[i];
	s_a[i] = s_a[i + 1];
	s_a[i + 1] = temp;
	var->add = var->add + 1;
	return ;
}

void	ft_swap_b(int *s_b, t_var *var)
{
	int	i;
	int	temp;

	write(1, "sb\n", 3);
	i = 0;
	temp = s_b[i];
	s_b[i] = s_b[i + 1];
	s_b[i + 1] = temp;
	var->add = var->add + 1;
	return ;
}

void	ft_swap_ab(int *s_a, int *s_b, t_var *var)
{
	int	i;
	int	j;
	int	temp_a;
	int	temp_b;

	write(1, "ss\n", 3);
	i = 0;
	temp_a = s_a[i];
	s_a[i] = s_a[i + 1];
	s_a[i + 1] = temp_a;
	j = 0;
	temp_b = s_b[j];
	s_b[j] = s_b[j + 1];
	s_b[j + 1] = temp_b;
	var->add = var->add + 1;
	return ;
}

void	ft_push_a(int *s_a, int *s_b, t_var *var)
{
	int	i;
	int	j;
	int	temp;

	if (var->len_a == var->max_len)
		return ;
	else
	{
		i = var->len_a + 1;
		j = 0;
		write(1, "pa\n", 3);
		temp = s_b[0];
		var->len_a = var->len_a + 1;
		var->len_b = var->len_b - 1;
		while (j < var->len_b)
		{
			s_b[j] = s_b[j + 1];
			j++;
		}
		while (--i > 0)
			s_a[i] = s_a[i - 1];
		s_a[0] = temp;
		var->add = var->add + 1;
		return ;
	}
}

void	ft_push_b(int *s_a, int *s_b, t_var *var)
{
	int	i;
	int	j;
	int	temp;

	if (var->len_b == var->max_len)
		return ;
	else
	{
		i = var->len_b + 1;
		j = 0;
		write(1, "pb\n", 3);
		temp = s_a[0];
		var->len_a = var->len_a - 1;
		var->len_b = var->len_b + 1;
		while (j < var->len_a)
		{
			s_a[j] = s_a[j + 1];
			j++;
		}
		while (--i > 0)
			s_b[i] = s_b[i - 1];
		s_b[0] = temp;
		var->add = var->add + 1;
		return ;
	}
}

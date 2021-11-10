/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr_loops.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iderighe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 15:54:14 by iderighe          #+#    #+#             */
/*   Updated: 2021/11/10 11:21:33 by iderighe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_loop_rotate_a(int *s_a, t_var *var)
{
	int	i;

	i = 0;
	while (i < var->pos_first)
	{
		ft_rotate_a(s_a, var);
		i++;
	}
}

void	ft_loop_revrotate_a(int *s_a, t_var *var, int pos_second)
{
	int	i;

	i = 0;
	while (i < pos_second)
	{
		ft_revrotate_a(s_a, var);
		i++;
	}
}

void	ft_loop_rotate_ab(int *s_a, int *s_b, t_var *var, int x)
{
	int	i;

	i = 0;
	while (i < x)
	{
		ft_rotate_ab(s_a, s_b, var);
		i++;
	}
}

void	ft_loop_revrotate_ab(int *s_a, int *s_b, t_var *var, int x)
{
	int	i;

	i = 0;
	while (i < x)
	{
		ft_revrotate_ab(s_a, s_b, var);
		i++;
	}
}

void	ft_loop_rotate_b(int pos_in_b, int *s_b, t_var *var)
{
	while (pos_in_b != 0)
	{
		ft_rotate_b(s_b, var);
		pos_in_b--;
	}
}

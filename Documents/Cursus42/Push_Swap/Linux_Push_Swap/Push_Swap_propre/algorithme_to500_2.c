/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithme_to500_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iderighe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 11:29:56 by iderighe          #+#    #+#             */
/*   Updated: 2021/11/08 10:29:20 by iderighe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_create_index(int *s_a, int *s_b, t_var *var)
{
	int	i;
	int	j;
	int	index;
	int	*index_sa;

	index_sa = malloc(sizeof(int) * (var->len_a));
	if (index_sa == NULL)
		return (0);
	j = 0;
	while (j < var->len_a)
	{
		i = 0;
		index = 0;
//		if (var->len_a != 500)
//			dprintf(2, RED"changed %d\n"RESET, var->len_a);
		while (++i < var->len_a)
//		while (i < var->len_a)
//		{
			if (s_a[j] > s_a[i])
				index++;
//			i++;
//		}
		index_sa[j] = index;
printf(CYAN"index_sa[%d] = %d"RESET"\n", j, index_sa[j]);
		j++;
	}
//printf(RED"j = %d, i = %d"RESET"\n", j, i);
	ft_define_first_hold(index_sa, var);
	ft_define_second_hold(index_sa, var);
	ft_move_to_top_a(s_a, s_b, var);
	ft_loop_browse(s_a, s_b, index_sa, var);
	return (1);
}

int	ft_create_new_index(int *s_a, t_var *var)
{
	int	t[2];
	int	index;
	int	*index_sa;

	index_sa = malloc(sizeof(int) * (var->len_a));
	if (index_sa == NULL)
		return (0);
	t[1] = 0;
	while (t[1] < var->len_a)
	{
		t[0] = 0;
		index = 0;
		while (t[0] < var->len_a)
		{
			if (s_a[t[1]] > s_a[t[0]])
				index++;
			t[0]++;
		}
		index_sa[t[1]] = index;
		t[1]++;
	}
	ft_define_first_hold(index_sa, var);
	ft_define_second_hold(index_sa, var);
	free(index_sa);
	return (1);
}

void	ft_define_first_hold(int *index_sa, t_var *var)
{
	int	i;

	i = 0;
	while (i < var->len_a)
	{
		if (var->max_len <= 100)
		{
			if (index_sa[i] >= 0 && index_sa[i] <= 4)
			{
				var->pos_first = i;
				return ;
			}
			i++;
		}
		else if (var->max_len > 100)
		{
			if (index_sa[i] >= 0 && index_sa[i] <= 11)
			{
				var->pos_first = i;
				return ;
			}
			i++;
		}
	}
}

void	ft_define_second_hold(int *index_sa, t_var *var)
{
	int	i;

	i = var->len_a - 1;
	while (i > 0)
	{
		if (var->max_len <= 100)
		{
			if (index_sa[i] >= 0 && index_sa[i] <= 4)
			{
				var->pos_second = i;
				return ;
			}
			i--;
		}
		else if (var->max_len > 100)
		{
			if (index_sa[i] >= 0 && index_sa[i] <= 11)
			{
				var->pos_second = i;
				return ;
			}
			i--;
		}
	}
}

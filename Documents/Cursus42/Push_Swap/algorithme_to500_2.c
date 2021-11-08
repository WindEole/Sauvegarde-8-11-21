/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithme_to500_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iderighe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 11:29:56 by iderighe          #+#    #+#             */
/*   Updated: 2021/10/16 14:07:17 by iderighe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_create_index(int *s_a, int *s_b, t_varlen *varlen)
{
	int	i;
	int	j;
	int	index;
	int	*index_sa;

	index_sa = malloc(sizeof(int) * (varlen->len_a));
	if (index_sa == NULL)
		return (0);
	j = 0;
	while (j < varlen->len_a)
	{
		i = 0;
		index = 0;
		while (i++ < varlen->len_a)
			if (s_a[j] > s_a[i])
				index++;
		index_sa[j] = index;
		j++;
	}
	ft_define_first_hold(index_sa, varlen);
	ft_define_second_hold(index_sa, varlen);
	ft_fill_sort_stack_b(s_a, s_b, varlen);
	ft_loop_browse(s_a, s_b, index_sa, varlen);
	return (1);
}

int	ft_create_new_index(int *s_a, t_varlen *varlen)
{
	int	i;
	int	j;
	int	index;
	int	*index_sa;

	index_sa = malloc(sizeof(int) * (varlen->len_a));
	if (index_sa == NULL)
		return (0);
	j = 0;
	while (j < varlen->len_a)
	{
		i = 0;
		index = 0;
		while (i < varlen->len_a)
		{
			if (s_a[j] > s_a[i])
				index++;
			i++;
		}
		index_sa[j] = index;
		j++;
	}
	ft_define_first_hold(index_sa, varlen);
	ft_define_second_hold(index_sa, varlen);
	return (1);
}

void	ft_define_first_hold(int *index_sa, t_varlen *varlen)
{
	int	i;

	i = 0;
	while (i < varlen->len_a)
	{
		if (varlen->max_len <= 100)
		{
			if (index_sa[i] >= 0 && index_sa[i] <= 4)
			{
				varlen->pos_first = i;
				return ;
			}
			i++;
		}
		else if (varlen->max_len > 100)
		{
			if (index_sa[i] >= 0 && index_sa[i] <= 11)
			{
				varlen->pos_first = i;
				return ;
			}
			i++;
		}
	}
}

void	ft_define_second_hold(int *index_sa, t_varlen *varlen)
{
	int	i;

	i = varlen->len_a - 1;
	while (i > 0)
	{
		if (varlen->max_len <= 100)
		{
			if (index_sa[i] >= 0 && index_sa[i] <= 4)
			{
				varlen->pos_second = i;
				return ;
			}
			i--;
		}
		else if (varlen->max_len > 100)
		{
			if (index_sa[i] >= 0 && index_sa[i] <= 11)
			{
				varlen->pos_second = i;
				return ;
			}
			i--;
		}
	}
}

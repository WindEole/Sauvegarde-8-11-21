/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithme_to500.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iderighe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 16:58:59 by iderighe          #+#    #+#             */
/*   Updated: 2021/09/10 13:37:21 by iderighe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_algo_big_numbers(int *s_A, int *s_B, int max_len, t_varlen *varlen)
{
	int	i;
	int	total;
	int	n_pivot;
	int	pivot;

	total = 0;
	i = 0;
	while (i < max_len)
		total = total + s_A[i++];
printf(RED"total = %d, len_a = %d, s_B[0] = %d"RESET"\n", total, varlen->len_a, s_B[0]);
	pivot = 0;
	if (max_len <= 100)
	{
//		n_pivot = 3;
		n_pivot = (max_len / 5) - 1;
//		n_pivot = (max_len / 5) - 2;
//		n_pivot = 1;
//		pivot = total / (max_len * 2);
		pivot = total / (max_len * (n_pivot - 1));
//		pivot = total / max_len;
//		pivot = total / max_len / n_pivot;
printf(RED"nb de pivots = %d, pivot = %d\nfct algo_big_number"RESET"\n", n_pivot, pivot);
	}
	if (max_len > 100 && max_len <= 500)
	{
//		n_pivot = 11;
		n_pivot = (max_len / 5) - 1;
//		pivot = total / (max_len * 10);
		pivot = total / (max_len * (n_pivot -1));
	}
	ft_search_pivot_values(s_A, s_B, max_len, varlen, n_pivot, pivot);
	return (pivot);
}

int		ft_search_pivot_values(int *s_A, int *s_B, int max_len, t_varlen *varlen, int n_pivot, int pivot)
{
	int	i;
	int	j;
	int	pivot_value;
	int	gap;

	i = 1;
	while (i <= n_pivot)
	{
printf(GREEN"\n-----search_pivot_values-----\n%d\nnb de pivots = %d, pivot = %d"RESET"\n", i, n_pivot, pivot);
		j = 0;
		pivot_value = pivot * i;
printf(GREEN"n pivot = %d, i = %d, pivot = %d, pivot_value = %d"RESET"\n", n_pivot, i, pivot, pivot_value);
		if (s_A[0] > pivot_value)
			gap = s_A[0] - pivot_value;
		else if (s_A[0] < pivot_value)
			gap = pivot_value  - s_A[0];
		while (j < max_len)
		{
			if (s_A[j] > pivot_value  && ((s_A[j] - pivot_value) < gap))
				gap = s_A[j] - pivot_value;
			else if (s_A[j] < pivot_value && ((pivot_value - s_A[j]) < gap))
				gap = pivot_value - s_A[j];
			j++;
		}
printf(GREEN"gap = %d"RESET"\n", gap);
		j = 0;
		while (j < varlen->len_a)
		{
printf(GREEN"On entre ici ? j = %d, varlen->len_a = %d, pivot = %d,"RESET"\n", j, varlen->len_a, pivot);
			if (s_A[j] - pivot_value == gap || pivot_value - s_A[j] == gap)
			{
printf(RED"j = %d, pivot en cours : s_A[j] = %d, s_B[0] = %d"RESET"\n", j, s_A[j], s_B[0]);
printf(BLUE"s_A[j] (%d) - pivot_value (%d) == gap (%d)"RESET"\n", s_A[j], pivot_value, gap);
printf(GREEN"ici, on fait tourner la fct fill_stack_B"RESET"\n\n");
				ft_fill_stack_B(s_A, s_B, max_len, varlen, s_A[j], n_pivot);
				if (s_A[j] - pivot_value == gap || pivot_value - s_A[j] == gap)
					break ;
			}
			j++;
		}
		i++;
	}
	return (1);
}


void	ft_fill_stack_B(int *s_A, int *s_B, int max_len, t_varlen *varlen, int pivot_value, int n_pivot)
{
	int	i;
	int	end_loop;

	i = 0;
printf(PURPLE"\n-----fill_stack_B-----\non entre ici ? i = %d, len_a = %d, pivot = %d"RESET"\n", i, varlen->len_a, pivot_value);
//	end_loop = s_A[max_len - 1];
	end_loop = s_A[varlen->len_a - 1];
	if (s_A[varlen->len_a - 1] <= pivot_value)
	{
		ft_revrotate_a(s_A, *varlen);
		end_loop = s_A[varlen->len_a - 1];
	}
printf(PURPLE"end_loop = %d"RESET"\n", end_loop);
	if (s_A[0] > s_A[1])
		ft_swap_a(s_A, *varlen);
	if (s_A[0] == end_loop && s_A[0] <= pivot_value)
	{
		end_loop = s_A[varlen->len_a - 1];
		ft_sort_B(s_A, s_B, max_len, varlen);
	}
	while (s_A[0] != end_loop)
	{
		if (s_A[0] <= pivot_value)
		{
printf(PURPLE"len_b = %d, on lance ft_sort_B ! "RESET"\n", varlen->len_b);
			ft_sort_B(s_A, s_B, max_len, varlen);
		}
		else
		{
printf(RED"C'est celui-ci qui pose probleme maintenant ? s_A[0] = %d, end_loop = %d pivot_value = %d"RESET"\n", s_A[0], end_loop, pivot_value);
			ft_rotate_a(s_A, *varlen);
		}
		i++;
	}
/*	if (s_A[0] == end_loop && s_A[0] <= pivot)
	{
		end_loop = s_A[varlen->len_a - 1];
		ft_sort_B(s_A, s_B, max_len, varlen);
	}*/
	ft_sort_A(s_A, s_B, max_len, varlen);
printf(PURPLE"i = %d, varlen->len_a = %d, max_len = %d, n_pivot = %d"RESET"\n", i, varlen->len_a, max_len, n_pivot);
	return ;
}

void	ft_sort_A(int *s_A, int *s_B, int max_len, t_varlen *varlen)
{
	int	i;
	int	j;
//	int	k;
//	int	l;

printf(CYAN"\n-----fct ft_sort_A-----"RESET"\n");
	i = 0;
	j = varlen->len_a;
	while (i < varlen->len_a)
	{
		while (j > 0)
		{
printf(CYAN"len_a = %d"RESET"\n", varlen->len_a);
			if (s_A[0] > s_A[1] && !(s_A[0] > s_A[varlen->len_a - 1]))
				ft_swap_a(s_A, *varlen);
			if (s_A[0] > s_A[1] && s_A[0] > s_A[varlen->len_a - 1])
				ft_rotate_a(s_A, *varlen);
			if (s_A[0] < s_A[1] && s_A[0] > s_A[varlen->len_a - 1])
				ft_rotate_a(s_A, *varlen);
			if (s_A[0] < s_A[1] && s_A[0] < s_A[varlen->len_a - 1])
			{
				ft_push_b(s_A, s_B, max_len, varlen);
/*				k = 1;
				if (s_A[0] > s_A[1])
					ft_swap_a(s_A, *varlen);
printf(CYAN"verifions si on entre la dedans !"RESET"\n");
//				k = 0;
				while (s_A[0] < s_A[1] && k < varlen->len_a)
				{
printf(RED"verifions si on entre la dedans !"RESET"\n");
//					ft_rotate_b(s_B, *varlen);
					if (s_A[0] > s_B[0])
						ft_push_b(s_A, s_B, max_len, varlen);
					else if (s_A[0] < s_B[0])
					{
						ft_rotate_b(s_B, *varlen);
						ft_push_b(s_A, s_B, max_len, varlen);
//						ft_revrotate_b(s_B, *varlen);
					}
					k++;
				}
//				l = k;
				while (k != 0)
				{
					ft_revrotate_b(s_B, *varlen);
					k--;
				}
//				ft_push_a(s_A, s_B, max_len, varlen);*/
			}
			j--;
		}
		i++;
	}
printf(CYAN"s_A[0] = %d, s_B[0] = %d, max_len = %d"RESET"\n", s_A[0], s_B[0], max_len);
/*	i = 0;
	while (i < varlen->len_a - 1)
	{
		if (s_A[i] > s_A[i + 1])
printf(RED"check your stack A !"RESET"\n");
		else
		{
			j = varlen->len_b;
			while (j > 0)
			{
				ft_revrotate_b(s_B, *varlen);
				ft_push_a(s_A, s_B, max_len, varlen);
				j--;
			}
		}
	}*/
/*	if (s_A[0] < s_A[1] && s_A[0] < s_A[varlen->len_a - 1])
	{
		ft_push_b(s_A, s_B, max_len, varlen);
		i = 0;
		while (s_A[varlen->len_a - 1] < s_A[0])
		{
			ft_revrotate_a(s_A, *varlen);
			i++;
		}
		ft_push_a(s_A, s_B, max_len, varlen);
		if (s_A[0] > s_A[1])
			ft_swap_a(s_A, *varlen);
	}
	else if (s_A[0] < s_A[1] && s_A[0] > s_A[varlen->len_a -1])
		ft_revrotate_a(s_A, *varlen);*/
	i = varlen->len_b;
	while (i > 0)
	{
		if (s_B[0] < s_B[1])
			ft_swap_b(s_B, *varlen);
		ft_push_a(s_A, s_B, max_len, varlen);
		i--;
	}
}

void	ft_sort_B(int *s_A, int *s_B, int max_len, t_varlen *varlen)
{
	int	i;

	i = 0;
printf(CYAN"Est-ce qu'on entre ici ?"RESET"\n");
	if (s_A[0] > s_A[1])
		ft_swap_a(s_A, *varlen);
	while (s_A[0] < s_B[0] && s_B[0] < s_B[1])
	{
printf(CYAN"C'est celui-ci qui pose probleme ? s_A[0] = %d"RESET"\n", s_A[0]);
		ft_rotate_b(s_B, *varlen);
		break ;
		i++;
	}
	ft_push_b(s_A, s_B, max_len, varlen);
	if (s_B[0] < s_B[varlen->len_b - 1])
		ft_revrotate_b(s_B, *varlen);
	return ;
}

/*void	ft_sort_B(int *s_A, int *s_B, int max_len, t_varlen *varlen)
{
	int	i;

	i = 0;
	if (s_A[0] > s_A[1])
		ft_swap_a(s_A, *varlen);
	while (s_A[0] < s_B[0])
	{
		ft_rotate_b(s_B, *varlen);
		i++;
	}
//	ft_push_b(s_A, s_B, max_len, varlen);
	if (s_A[0] > s_B[varlen->len_b] && varlen->len_b > 1)
		ft_rotate_b(s_B, *varlen);
	ft_push_b(s_A, s_B, max_len, varlen);
	if (s_B[0] > s_B[1] && varlen->len_b > 1)
		ft_swap_b(s_B, *varlen);*/
/*	i = varlen->len_b;
printf(CYAN"On entre la trop tot !"RESET"\n");
	if (s_B[0] < s_B[1])
		ft_swap_b(s_B, *varlen);
	while (i > 0)
	{
		ft_push_a(s_A, s_B, max_len, varlen);
		ft_rotate_a(s_A, *varlen);
		i--;
	}*/
/*	return ;
}*/

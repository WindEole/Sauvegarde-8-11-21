/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithme_to500.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iderighe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 16:58:59 by iderighe          #+#    #+#             */
/*   Updated: 2021/09/25 12:16:28 by iderighe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_algo_big_numbers(int *s_a, int *s_b, int max_len, t_varlen *varlen)
{
	int	i;
	int	j;
	int reverse_sort;

	reverse_sort = ft_check_reverse_sort(s_a, max_len);
	if (reverse_sort == 1)
	{
		i = varlen->len_a;
		while (i > 1)
		{
			ft_revrotate_a(s_a, varlen);
			ft_push_b(s_a, s_b, max_len, varlen);
			i--;
		}
		j = varlen->len_b;
		while (j > 0)
		{
			ft_push_a(s_a, s_b, max_len, varlen);
			j--;
		}
	}
	if (reverse_sort == 0)
	{
		ft_define_min_max(s_a, max_len, varlen);
		ft_create_index(s_a, s_b, max_len, varlen);
	}
	return (1);
}

void	ft_define_min_max(int *s_a, int max_len, t_varlen *varlen)
{
	int	i;

	i = 0;
	varlen->min = s_a[0];
	while (i < max_len)
	{
		if (s_a[i] < varlen->min)
			varlen->min = s_a[i];
		i++;
	}
	i = 0;
	varlen->max = s_a[0];
	while (i < max_len)
	{
		if (s_a[i] > varlen->max)
			varlen->max = s_a[i];
		i++;
	}
printf(CYAN"min = %d, max = %d"RESET"\n", varlen->min, varlen->max);
}

int	ft_create_index(int *s_a, int *s_b, int max_len, t_varlen *varlen)
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
printf(PURPLE"index_sa[%d] = %d s_a[%d] = %d"RESET"\n", j, index_sa[j], j, s_a[j]);
		j++;
	}
	ft_define_first_hold(s_a, index_sa, varlen);
	ft_define_second_hold(s_a, index_sa, varlen);
	ft_fill_sort_stack_B(s_a, s_b, max_len, varlen);
	ft_loop_browse(s_a, s_b, index_sa, max_len, varlen);
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
printf(PURPLE"index_sa[%d] = %d"RESET YELLOW" s_a[%d] = %d"RESET"\n", j, index_sa[j], j, s_a[j]);
		j++;
	}
	ft_define_first_hold(s_a, index_sa, varlen);
	ft_define_second_hold(s_a, index_sa, varlen);
	return (1);
}

void	ft_loop_browse(int *s_a, int *s_b, int *index_sa, int max_len, t_varlen *varlen)
{
	int	i;
//	int	j;
printf(GREEN"loop browse ? len_b = %d"RESET"\n", varlen->len_b);
	i = 0;
	free(index_sa);
	while (varlen->len_b != 0 && varlen->len_b < max_len)
	{
		ft_create_new_index(s_a, varlen);
//		varlen->pos_first = 0;
//		ft_define_first_hold(s_a, index_sa, varlen);
//		varlen->pos_second = 0;
//		ft_define_second_hold(s_a, index_sa, varlen);
		ft_fill_sort_stack_B(s_a, s_b, max_len, varlen);
		i++;
	}
}

void	ft_define_first_hold(int *s_a, int *index_sa, t_varlen *varlen)
{
	int	i;

printf(YELLOW"define first hold"RESET"\n");
	i = 0;
	while (i < varlen->len_a)
	{
		if (index_sa[i] >= 0 && index_sa[i] <= 3)
		{
			varlen->pos_first = i;
printf(YELLOW"i = %d, len_a = %d, pos_first = %d, s_a[%d] = %d"RESET"\n", i, varlen->len_a, varlen->pos_first, varlen->pos_first, s_a[varlen->pos_first]);
			return ;
		}
		i++;
	}
}

void	ft_define_second_hold(int *s_a, int *index_sa, t_varlen *varlen)
{
	int	i;

	i = varlen->len_a - 1;
printf(BLUE"define second hold i = %d, len_a = %d"RESET"\n", i, varlen->len_a);
	while (i > 0)
	{
		if (index_sa[i] >= 0 && index_sa[i] <= 3)
		{
			varlen->pos_second = i;
printf(BLUE"i = %d, len_a = %d, pos_second = %d, s_a[%d] = %d"RESET"\n", i, varlen->len_a, varlen->pos_second, varlen->pos_second, s_a[varlen->pos_second]);
			return ;
		}
		i--;
	}
}

void	ft_fill_sort_stack_B(int *s_a, int *s_b, int max_len, t_varlen *varlen)
{
//	int	i;
	int	pos_second;

printf(GREEN"\nfill sort stack B\npos_first = %d, pos_second = %d"RESET"\n", varlen->pos_first, varlen->pos_second);
	pos_second = varlen->len_a - varlen->pos_second;
printf(GREEN"pos_second = %d"RESET"\n", pos_second);
//	if (varlen->pos_first <= max_len - varlen->pos_second)

	if (varlen->pos_first < pos_second)
	{
printf(GREEN"On entre ici ?"RESET"\n");
		ft_loop_rotate_a(s_a, varlen);
	}
/*	{
		i = 0;
		while (i < varlen->pos_first)
		{
			ft_rotate_a(s_a, varlen);
			i++;
		}
	}*/
	else if (varlen->pos_first > pos_second)
		ft_loop_revrotate_a(s_a, varlen, pos_second);
/*	{
		i = 0;
		while (i < pos_second)
		{
			ft_revrotate_a(s_a, varlen);
			i++;
		}
	}*/
	else if (varlen->pos_first == pos_second)
	{
		if (s_a[varlen->pos_first] < s_a[varlen->pos_second])
			ft_loop_rotate_a(s_a, varlen);
/*		{
			i = 0;
			while (i < pos_second)
			{
				ft_revrotate_a(s_a, varlen);
				i++;
			}
		}*/
		else if (s_a[varlen->pos_first] > s_a[varlen->pos_second])
			ft_loop_revrotate_a(s_a, varlen, pos_second);
/*		{
			i = 0;
			while (i < varlen->pos_first)
			{
				ft_rotate_a(s_a, varlen);
				i++;
			}
		}*/
	}
/*	ft_push_b(s_a, s_b, max_len, varlen);
	if (s_a[0] < s_b[0])
		ft_swap_b(s_b, varlen);
	i = 0;
	while (i < varlen->len_b)
	{
printf(CYAN"s_b[%d] = %d"RESET"\n", i, s_b[i]);
		i++;
	}*/
	ft_sort_B(s_a, s_b, max_len, varlen);
}

void	ft_loop_rotate_a(int *s_a, t_varlen *varlen)
{
	int	i;

	i = 0;
	while (i < varlen->pos_first)
	{
		ft_rotate_a(s_a, varlen);
		i++;
	}
}

void	ft_loop_revrotate_a(int *s_a, t_varlen *varlen, int pos_second)
{
	int	i;

	i = 0;
	while (i < pos_second)
	{
		ft_revrotate_a(s_a, varlen);
		i++;
	}
}
/*int	ft_define_nb_pivot(int *s_a, int *s_b, int *index_sa, int max_len, t_varlen *varlen)
{
	int	i;
	int	total;
	int	pivot;

	total = 0;
	i = 0;
	while (i < max_len)
		total = total + s_a[i++];
printf(RED"total = %d, len_a = %d, s_b[0] = %d"RESET"\n", total, varlen->len_a, s_b[0]);
	pivot = 0;
	if (max_len > 5 && max_len <= 10)
	{
		varlen->n_pivot = 1;
		pivot = varlen->max;
	}
	if (max_len > 10 && max_len <= 20)
	{
		varlen->n_pivot = 3;
		pivot = total / 2;
	}
	if (max_len > 20 && max_len <= 100)
	{
//		n_pivot = 3;
		varlen->n_pivot = (max_len / 5) - 1;
//		n_pivot = (max_len / 5) - 2;
//		n_pivot = 1;
//		pivot = total / (max_len * 2);
		pivot = total / (max_len * (varlen->n_pivot - 1));
//		pivot = total / max_len;
//		pivot = total / max_len / n_pivot;
printf(RED"nb de pivots = %d, pivot = %d\nfct algo_big_number"RESET"\n", varlen->n_pivot, pivot);
	}
	if (max_len > 100 && max_len <= 500)
	{
//		n_pivot = 11;
		varlen->n_pivot = (max_len / 5) - 1;
//		pivot = total / (max_len * 10);
		pivot = total / (max_len * (varlen->n_pivot -1));
	}
	ft_search_pivot_values(s_a, s_b, max_len, varlen, pivot);
	return (pivot);
}

int		ft_search_pivot_values(int *s_a, int *s_b, int max_len, t_varlen *varlen, int pivot)
{
	int	i;
	int	j;
	int	pivot_value;
	int	gap;

	i = 1;
	while (i <= varlen->n_pivot)
	{
printf(GREEN"\n-----search_pivot_values-----\n%d\nnb de pivots = %d, pivot = %d"RESET"\n", i, varlen->n_pivot, pivot);
		j = 0;
		pivot_value = pivot * i;
printf(GREEN"n pivot = %d, i = %d, pivot = %d, pivot_value = %d"RESET"\n", varlen->n_pivot, i, pivot, pivot_value);
		if (s_a[0] > pivot_value)
			gap = s_a[0] - pivot_value;
		else if (s_a[0] < pivot_value)
			gap = pivot_value  - s_a[0];
		while (j < max_len)
		{
			if (s_a[j] > pivot_value  && ((s_a[j] - pivot_value) < gap))
				gap = s_a[j] - pivot_value;
			else if (s_a[j] < pivot_value && ((pivot_value - s_a[j]) < gap))
				gap = pivot_value - s_a[j];
			j++;
		}
printf(GREEN"gap = %d"RESET"\n", gap);
		j = 0;
		while (j < varlen->len_a)
		{
printf(GREEN"On entre ici ? j = %d, varlen->len_a = %d, pivot = %d,"RESET"\n", j, varlen->len_a, pivot);
			if (s_a[j] - pivot_value == gap || pivot_value - s_a[j] == gap)
			{
printf(RED"j = %d, pivot en cours : s_b[j] = %d, s_b[0] = %d"RESET"\n", j, s_a[j], s_b[0]);
printf(BLUE"s_a[j] (%d) - pivot_value (%d) == gap (%d)"RESET"\n", s_a[j], pivot_value, gap);
printf(GREEN"ici, on fait tourner la fct fill_stack_B"RESET"\n\n");
				ft_fill_stack_B(s_a, s_b, max_len, varlen, s_a[j]);
				if (s_a[j] - pivot_value == gap || pivot_value - s_a[j] == gap)
					break ;
			}
			j++;
		}
		i++;
	}
	return (1);
}


void	ft_fill_stack_B(int *s_a, int *s_b, int max_len, t_varlen *varlen, int pivot_value)
{
	int	i;
	int	end_loop;

	i = 0;
printf(PURPLE"\n-----fill_stack_B-----\non entre ici ? i = %d, len_a = %d, pivot = %d"RESET"\n", i, varlen->len_a, pivot_value);
//	end_loop = s_a[max_len - 1];
	end_loop = s_a[varlen->len_a - 1];
	if (s_a[varlen->len_a - 1] <= pivot_value)
	{
		ft_revrotate_a(s_a, varlen);
		end_loop = s_a[varlen->len_a - 1];
	}
printf(PURPLE"end_loop = %d"RESET"\n", end_loop);
	if (s_a[0] > s_a[1])
		ft_swap_a(s_a, varlen);
	if (s_a[0] == end_loop && s_a[0] <= pivot_value)
	{
		end_loop = s_a[varlen->len_a - 1];
		ft_sort_B(s_a, s_b, max_len, varlen);
	}
	while (s_a[0] != end_loop)
	{
		if (s_a[0] <= pivot_value)
		{
printf(PURPLE"len_b = %d, on lance ft_sort_B ! "RESET"\n", varlen->len_b);
			ft_sort_B(s_a, s_b, max_len, varlen);
		}
		else
		{
printf(RED"C'est celui-ci qui pose probleme maintenant ? s_a[0] = %d, end_loop = %d pivot_value = %d"RESET"\n", s_a[0], end_loop, pivot_value);
			ft_rotate_a(s_a, varlen);
		}
		i++;
	}
	ft_sort_A(s_a, s_b, max_len, varlen);
printf(PURPLE"i = %d, varlen->len_a = %d, max_len = %d"RESET"\n", i, varlen->len_a, max_len);
	return ;
}*/

void	ft_sort_A(int *s_a, int *s_b, int max_len, t_varlen *varlen)
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
			if (s_a[0] > s_a[1] && !(s_a[0] > s_a[varlen->len_a - 1]))
				ft_swap_a(s_a, varlen);
			if (s_a[0] > s_a[1] && s_a[0] > s_a[varlen->len_a - 1])
				ft_rotate_a(s_a, varlen);
			if (s_a[0] < s_a[1] && s_a[0] > s_a[varlen->len_a - 1])
				ft_rotate_a(s_a, varlen);
			if (s_a[0] < s_a[1] && s_a[0] < s_a[varlen->len_a - 1])
			{
				ft_push_b(s_a, s_b, max_len, varlen);
/*				k = 1;
				if (s_a[0] > s_a[1])
					ft_swap_a(s_a, *varlen);
printf(CYAN"verifions si on entre la dedans !"RESET"\n");
//				k = 0;
				while (s_a[0] < s_a[1] && k < varlen->len_a)
				{
printf(RED"verifions si on entre la dedans !"RESET"\n");
//					ft_rotate_b(s_b, *varlen);
					if (s_a[0] > s_b[0])
						ft_push_b(s_a, s_b, max_len, varlen);
					else if (s_a[0] < s_b[0])
					{
						ft_rotate_b(s_b, *varlen);
						ft_push_b(s_a, s_b, max_len, varlen);
//						ft_revrotate_b(s_b, *varlen);
					}
					k++;
				}
//				l = k;
				while (k != 0)
				{
					ft_revrotate_b(s_b, *varlen);
					k--;
				}
//				ft_push_a(s_a, s_b, max_len, varlen);*/
			}
			j--;
		}
		i++;
	}
printf(CYAN"s_a[0] = %d, s_b[0] = %d, max_len = %d"RESET"\n", s_a[0], s_b[0], max_len);
/*	i = 0;
	while (i < varlen->len_a - 1)
	{
		if (s_a[i] > s_a[i + 1])
printf(RED"check your stack A !"RESET"\n");
		else
		{
			j = varlen->len_b;
			while (j > 0)
			{
				ft_revrotate_b(s_b, *varlen);
				ft_push_a(s_a, s_b, max_len, varlen);
				j--;
			}
		}
	}*/
/*	if (s_a[0] < s_a[1] && s_a[0] < s_a[varlen->len_a - 1])
	{
		ft_push_b(s_a, s_b, max_len, varlen);
		i = 0;
		while (s_a[varlen->len_a - 1] < s_a[0])
		{
			ft_revrotate_a(s_a, *varlen);
			i++;
		}
		ft_push_a(s_a, s_b, max_len, varlen);
		if (s_a[0] > s_a[1])
			ft_swap_a(s_a, *varlen);
	}
	else if (s_a[0] < s_a[1] && s_a[0] > s_a[varlen->len_a -1])
		ft_revrotate_a(s_a, *varlen);*/
	i = varlen->len_b;
	while (i > 0)
	{
		if (s_b[0] < s_b[1])
			ft_swap_b(s_b, varlen);
		ft_push_a(s_a, s_b, max_len, varlen);
		i--;
	}
}

void	ft_sort_B(int *s_a, int *s_b, int max_len, t_varlen *varlen)
{
	int	i;

	i = 0;
printf(CYAN"ft_sort_B ?"RESET"\n");
printf(CYAN"s_a[0] = %d, s_b[0] = %d, s_b[last] = %d"RESET"\n", s_a[0], s_b[0], s_b[varlen->len_b - 1]);

	if (s_a[0] == varlen->min)
	{
		ft_push_b(s_a, s_b, max_len, varlen);
		ft_rotate_b(s_b, varlen);
	}
	else if (varlen->len_b > 1 && s_a[0] < s_b[0] && s_a[0] > s_b[varlen->len_b - 1])
	{
printf(CYAN"on arrive ici ?"RESET"\n");
		ft_insert_in_B(s_a, s_b, max_len, varlen);
	}
	else
	{
		ft_push_b(s_a, s_b, max_len, varlen);
		if (s_b[0] < s_b[1] && ((varlen->len_b - 1) != 0))
			ft_swap_b(s_b, varlen);
		if (s_b[0] < s_b[varlen->len_b - 1])
			ft_rotate_b(s_b, varlen);
		i = 0;
		while (i < varlen->len_b)
		{
printf(CYAN"s_b[%d] = %d"RESET"\n", i, s_b[i]);
			i++;
		}
	}
/*	i = 0;
	while (i < max_len)
	{
		ft_push_a(s_a, s_b, max_len, varlen);
		i++;
	}*/
	return ;
}

void	ft_insert_in_B(int *s_a, int *s_b, int max_len, t_varlen *varlen)
{
	int	i;

	i = 0;
	while (!(s_a[0] > s_b[0]))
	{
		ft_rotate_b(s_b, varlen);
printf(RED"s_a[0] = %d, s_b[0] = %d"RESET"\n", s_a[0], s_b[0]);
		i++;
	}
	ft_push_b(s_a, s_b, max_len, varlen);
	while (i > 0)
	{
		ft_revrotate_b(s_b, varlen);
		i--;
	}
}

/*void	ft_sort_B(int *s_a, int *s_b, int max_len, t_varlen *varlen)
{
	int	i;

	i = 0;
	if (s_a[0] > s_a[1])
		ft_swap_a(s_a, *varlen);
	while (s_a[0] < s_b[0])
	{
		ft_rotate_b(s_b, *varlen);
		i++;
	}
//	ft_push_b(s_a, s_b, max_len, varlen);
	if (s_a[0] > s_b[varlen->len_b] && varlen->len_b > 1)
		ft_rotate_b(s_b, *varlen);
	ft_push_b(s_a, s_b, max_len, varlen);
	if (s_b[0] > s_b[1] && varlen->len_b > 1)
		ft_swap_b(s_b, *varlen);*/
/*	i = varlen->len_b;
printf(CYAN"On entre la trop tot !"RESET"\n");
	if (s_b[0] < s_b[1])
		ft_swap_b(s_b, *varlen);
	while (i > 0)
	{
		ft_push_a(s_a, s_b, max_len, varlen);
		ft_rotate_a(s_a, *varlen);
		i--;
	}*/
/*	return ;
}*/

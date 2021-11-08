/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithme_to100.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iderighe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 16:58:59 by iderighe          #+#    #+#             */
/*   Updated: 2021/08/25 18:03:29 by iderighe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*void	ft_ultra_rotate_a(int *s_A, t_varlen varlen)
{
	int	i;
	int	j;
	int	k;

	i = varlen.len_a;
	while (i > 0)
	{
		j = 0;
		while (!(s_A[0] < s_A[1]))
		{
			ft_rotate_a(s_A, varlen);
			j++;
		}
		
		i--;
	}
	k = 0;
	while (k < varlen.len_a)
	{
printf(YELLOW"s_A[%d] apres ultra_rotate_a = %d"RESET"\n", k, s_A[k]);
		k++;
	}
}

void	ft_ultra_swap_a(int *s_A, t_varlen varlen)
{
	int	i;
	int	j;
	int	k;

	i = varlen.len_a;
	while (i > 0)
	{
		j = 0;
		while (s_A[0] > s_A[1])
		{
			ft_swap_a(s_A, varlen);
			ft_rotate_a(s_A, varlen);
			j++;
		}
		
		i--;
	}
	k = 0;
	while (k < varlen.len_a)
	{
printf(YELLOW"s_A[%d] apres ultra_rotate_a = %d"RESET"\n", k, s_A[k]);
		k++;
	}

}*/

int		ft_search_median_value(int *s_A, int max_len)
{
	int	i;
	int	j;
	int	moyenne;
	int	gap;

	moyenne = 0;
	i = 0;
	while (i < max_len)
	{
		moyenne = moyenne + s_A[i];
		i++;
	}
	moyenne = moyenne / max_len;
printf(RED"moyenne = %d"RESET"\n", moyenne);
	j = 0;
	if (s_A[0] > moyenne)
		gap = s_A[0] - moyenne;
	else if (s_A[0] < moyenne)
		gap = moyenne - s_A[0];
	while (j < max_len)
	{
		if (s_A[j] > moyenne && ((s_A[j] - moyenne) < gap))
			gap = s_A[j] - moyenne;
		else if (s_A[j] < moyenne && ((moyenne - s_A[j]) < gap))
			gap = moyenne - s_A[j];
		j++;
	}
	i = 0;
	while (i < max_len)
	{
		if (s_A[i] - moyenne == gap || moyenne - s_A[i] == gap)
			return (i);
		else
			i++;
	}
	return (i);
}

/*void	ft_fill_stack_B(int *s_A, int *s_B, int max_len, t_varlen *varlen, int pivot)
{
	int	i;
	int	j;

	i = 0;
	while (i < varlen->len_a)
	{
		if (s_A[i] <= pivot)
		{
			j = i;
			while (j > 0)
			{
				if (j < varlen->len_a / 2)
					ft_rotate_a(s_A, *varlen);
				else if (j > varlen->len_a / 2)
					ft_revrotate_a(s_A, *varlen);
				j--;
			}
		}
		if (s_A[0] <= pivot)
		{
printf(PURPLE"s_A[0] <= pivot)"RESET"\n");
			ft_push_b(s_A, s_B, max_len, varlen);
			if (s_B[0] < s_B[1])
				ft_swap_b(s_B, *varlen);
		}
		i++;
	}
printf(GREEN"i = %d, len_a = %d"RESET"\n", i, varlen->len_a);
}*/

void	ft_fill_stack_B(int *s_A, int *s_B, int max_len, t_varlen *varlen, int pivot)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	while (i < varlen->len_a)
	{
printf(PURPLE"on entre ici ? i = %d, len_a = %d"RESET"\n", i, varlen->len_a);
		if (s_A[0] <= pivot)
		{
			ft_push_b(s_A, s_B, max_len, varlen);
			if (s_B[0] < s_B[1])
				ft_swap_b(s_B, *varlen);
		}
		else if (s_A[0] > pivot)
//		{
//printf(PURPLE"et ici?"RESET"\n");
//			j = 0;
//			while (j < varlen->len_a && s_A[0] > pivot)
//			{
				ft_rotate_a(s_A, *varlen);
//				if (s_A
//				ft_fill_stack_B(s_A, s_B, max_len, varlen, pivot);
//				j++;
//			}
//		}
		i++;
	}
	j = 0;
	while (j < varlen->len_a)
	{
		if (s_A[j] <= pivot)
		{
			ft_push_b(s_A, s_B, max_len, varlen);
			if (s_B[0] < s_B[1])
				ft_swap_b(s_B, *varlen);
			k = j;
			while (k > 0)
			{
				ft_rotate_a(s_A, *varlen);
				k--;
			}
			ft_push_b(s_A, s_B, max_len, varlen);
		}
		j++;
	}
printf(RED"Fin de la fct fill_stack_B !\n");
}


void	ft_algo_100(int *s_A, int *s_B, int max_len, t_varlen *varlen)
{
	int	i;
	int	cpt_pivot;
	int pivot;

	cpt_pivot = ft_search_median_value(s_A, max_len);
printf(GREEN"s_A[%d] = %d"RESET"\n", cpt_pivot, s_A[cpt_pivot]);
	pivot = s_A[cpt_pivot];
printf(GREEN"pivot = %d"RESET"\n", pivot);
	ft_fill_stack_B(s_A, s_B, max_len, varlen, pivot);
	i = 0;
	while (i < varlen->len_a)
	{
printf(CYAN"On entre ici ? s_A[%d] = %d; s_B[0] = %d"RESET"\n", i, s_A[i], s_B[0]);
		if (s_A[0] > s_A[1] && s_A[0] > s_A[varlen->len_a - 1])
		{
printf(CYAN"On entre ici ou pas ?"RESET"\n");
			ft_rotate_a(s_A, *varlen);
		}
		if (s_A[0] > s_A[1] && s_A[0] < s_A[varlen->len_a])
		{
			ft_swap_a(s_A, *varlen);
			if (s_A[0] <= pivot)
			{
				ft_push_b(s_A, s_B, max_len, varlen);
				if (varlen->len_b >= 2)
				{
					if (s_B[0] < s_B[1])
						ft_swap_b(s_B, *varlen);
				}
			}
			else
				ft_rotate_a(s_A, *varlen);
		}
/*		if (s_A[0] <= pivot)
		{
printf(CYAN"ici : s_A[%d] = %d; s_B[0] = %d"RESET"\n", i, s_A[i], s_B[0]);
			ft_push_b(s_A, s_B, max_len, varlen);
			if (s_B[0] < s_B[1])
				ft_swap_b(s_B, *varlen);
		}*/
//		ft_sort_A(s_A, s_B, max_len, varlen);
//		ft_sort_BtoA(s_A, s_B, max_len, varlen);
//		else
//		ft_rotate_a(s_A, *varlen);
		i++;
	}
	ft_sort_A(s_A, s_B, max_len, varlen);
	ft_sort_BtoA(s_A, s_B, max_len, varlen);
}

void	ft_sort_A(int *s_A, int *s_B, int max_len, t_varlen *varlen)
{
	int	i;

	if (s_A[0] < s_A[1] && s_A[0] < s_A[varlen->len_a - 1])
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
		ft_revrotate_a(s_A, *varlen);
}

void	ft_sort_BtoA(int *s_A, int *s_B, int max_len, t_varlen *varlen)
{
	int	i;

	i = 0;
	while (varlen->len_b > 1)
	{
printf(CYAN"i = %d, len_b = %d"RESET"\n", i, varlen->len_b);
		if (s_B[0] > s_B[1] && s_B[0] > s_B[varlen->len_b - 1])
			ft_push_a(s_A, s_B, max_len, varlen);
		else
		{
			if (s_B[0] < s_B[1])
				ft_swap_b(s_B, *varlen);
			else if (s_B[0] < s_B[varlen->len_b - 1])
				ft_revrotate_b(s_B, *varlen);
		}
		i++;
	}
	ft_push_a(s_A, s_B, max_len, varlen);
}


/*void	ft_code_essai(int *s_A, int *s_B, int max_len, t_varlen *varlen)
{
	int	i;
	int	j;

	i = varlen->len_a;
	while (i > 0)
	{
		if (s_A[0] < s_A[varlen->len_a] || s_A[0] > s_A[1])
		{
			ft_swap_a(s_A, *varlen);
			ft_push_b(s_A, s_B, max_len, varlen);
			if (varlen->len_b > 1)
			{
				j = varlen->len_b;
				while (j > 0)
				{
					if (s_B[0] < s_B[varlen->len_b])
						ft_revrotate_b(s_B, *varlen);
//						ft_swap_b(s_B, *varlen);
					j--;
				}
			}
		}
		i--;
	}
	return ;
*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithme_to500_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iderighe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 11:29:56 by iderighe          #+#    #+#             */
/*   Updated: 2021/11/09 10:56:11 by iderighe         ###   ########.fr       */
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
//		while (++i < varlen->len_a)
		while (i < varlen->len_a)
		{
			if (s_a[j] > s_a[i])
				index++;
			i++;
		}
		index_sa[j] = index;
		j++;
	}
i = 0;
while (i < varlen->len_a)
{
printf(YELLOW"s_a[%d] = %d "CYAN"index_sa[%d] = %d"RESET"\n", i, s_a[i], i, index_sa[i]);
i++;
}
//	ft_define_chunks(s_a, index_sa, varlen);
	ft_define_first_hold(index_sa, varlen);
	ft_define_second_hold(index_sa, varlen);
/////////////ATTENTION//////////////////////
//	ft_first_send(s_a, s_b, varlen);
	ft_fill_sort_stack_b(s_a, s_b, varlen);
	ft_loop_browse(s_a, s_b, index_sa, varlen);
	return (1);
}

int	ft_create_new_index(int *s_a, t_varlen *varlen)
{
	int	t[2];
	int	index;
	int	*index_sa;

	index_sa = malloc(sizeof(int) * (varlen->len_a));
	if (index_sa == NULL)
		return (0);
	t[1] = 0;
	while (t[1] < varlen->len_a)
	{
		t[0] = 0;
		index = 0;
		while (t[0] < varlen->len_a)
		{
			if (s_a[t[1]] > s_a[t[0]])
				index++;
			t[0]++;
		}
		index_sa[t[1]] = index;
		t[1]++;
	}
//	ft_define_chunks(s_a, index_sa, varlen);
	ft_define_first_hold(index_sa, varlen);
	ft_define_second_hold(index_sa, varlen);
	free(index_sa);
	return (1);
}

/*void	ft_define_chunks(int *s_a, int *index_sa, t_varlen *varlen)
{
	int	i;
	int	j;
	int size_chunks;
	int	sa_chunks;

	size_chunks = 0;
	if (varlen->max_len <= 100)
		size_chunks = varlen->max_len / 5;
	else if (varlen->max_len > 100)
		size_chunks = varlen->max_len / 11;
	i = 1;
	while (i < size_chunks)
	{
		j = 0;
		while (index_sa[j] < i * size_chunks)
		{
			if (index_sa[j] == i * size_chunks)
			{
				sa_chunks = s_a[j];
				ft_define_first_hold(s_a, varlen, sa_chunks);
				ft_define_second_hold(s_a, varlen, sa_chunks);
			}

			j++;
		}
		i++;
	}
//	ft_define_first_hold(index_sa, varlen);
//	ft_define_second_hold(index_sa, varlen);
}*/

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

/*void	ft_define_first_hold(int *s_a, t_varlen *varlen, int sa_chunks)
{
	int	i;
	
	i = 0;
	while (i < varlen->len_a)
	{
		if (s_a[i] < sa_chunks)
		{
			varlen-> pos_first = i;
			return ;
		}
		i++;
	}
}

void	ft_define_second_hold(int *s_a, t_varlen *varlen, int sa_chunks)
{
	int	i;
	
	i = varlen->len_a - 1;
	while (i > 0)
	{
		if (s_a[i] < sa_chunks)
		{
			varlen-> pos_second = i;
			return ;
		}
		i++;
	}
}*/

/*void	ft_first_send(int *s_a, int *s_b, t_varlen *varlen)
{
//	int	i;

//	i = 0;
	while (s_a[0] != varlen->max)
	{
		if (s_a[0] > s_b[0])
			ft_push_b(s_a, s_b, varlen);
		ft_rotate_a(s_a, varlen);
	}
	ft_push_b(s_a, s_b, varlen);
}*/

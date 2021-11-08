/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithme.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iderighe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 12:24:06 by iderighe          #+#    #+#             */
/*   Updated: 2021/08/23 13:14:31 by iderighe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_sort(int *s_A, int max_len)
{
	int	i;

	i = 0;
	while (i < max_len - 1)
	{
		if (s_A[i] > s_A[i + 1])
		{
printf(RED"KO ! You should get your code straight !"RESET"\n");
			return (1);
		}
		else
			i++;
	}
printf(GREEN"OK ! Congratulations, your algorithme worked !"RESET"\n");
	return (0);
}

void	ft_algo_2_3(int *s_A, int max_len, t_varlen varlen)
{
//	int	j;

	if (varlen.len_a == 2)
	{
		if (s_A[0] > s_A[1])
			ft_swap_a(s_A, varlen);
		else
			return ;
	}
	else
		ft_algo_3(s_A, varlen);
/*	j = 0;
printf("\nRESULTAT DE L'ALGO_2_3 :\n");
	while (j < varlen.len_a)
	{
printf(YELLOW"s_A[%d] = %d"RESET"\n", j, s_A[j]);
		j++;
	}*/
//	ft_check_sort(s_A, varlen.len_a);
	return ;
}

void	ft_algo_3(int *s_A, t_varlen varlen)
{
//	int	j;

	if (s_A[0] < s_A[1])
	{
		ft_revrotate_a(s_A, varlen);
		if (s_A[0] > s_A[1])
			ft_swap_a(s_A, varlen);
		else
			return ;
	}
	if (s_A[0] > s_A[1])
	{
		if (s_A[0] < s_A[2])
			ft_swap_a(s_A, varlen);
		else
		{
			ft_rotate_a(s_A, varlen);
			if (s_A[0] > s_A[1])
				ft_swap_a(s_A, varlen);
		}
		return ;
	}
/*	j = 0;
	printf("\nRESULTAT DE L'ALGO_3 :\n");
	while (j < varlen.len_a)
	{
printf(YELLOW"s_A[%d] = %d"RESET"\n", j, s_A[j]);
		j++;
	}*/
//	ft_check_sort(s_A, varlen.len_a);
	return ;
}

void	ft_algo_4_5(int *s_A, int *s_B, int max_len, t_varlen *varlen)
{
//	int	k;

	if (varlen->len_a == 4)
	{
		ft_push_b(s_A, s_B, max_len, varlen);
		if (!((s_A[0] < s_A[1]) && (s_A[1] < s_A[2])))
			ft_algo_3(s_A, *varlen);
		if (s_B[0] < s_A[0])
			ft_push_a(s_A, s_B, max_len, varlen);
		else if (s_B[0] > s_A[varlen->len_a - 1])
		{
			ft_push_a(s_A, s_B, max_len, varlen);
			ft_rotate_a(s_A, *varlen);
		}
		else if (s_B[0] > s_A[0] && s_B[0] < s_A[1])
		{
			ft_rotate_a(s_A, *varlen);
			ft_push_a(s_A, s_B, max_len, varlen);
			ft_revrotate_a(s_A, *varlen);
		}
		else if (s_B[0] > s_A[0] && s_B[0] > s_A[1])
		{
			ft_revrotate_a(s_A, *varlen);
			ft_push_a(s_A, s_B, max_len, varlen);
			ft_rotate_a(s_A, *varlen);
			ft_rotate_a(s_A, *varlen);
		}
		return ;
	}
	else
		ft_algo_5(s_A, s_B, max_len, varlen);
/*	k = 0;
printf("\nRESULTAT DE L'ALGO_4_5 :\n");
	while (k < varlen->len_a)
	{
printf(YELLOW"s_A[%d] = %d"RESET"\n", k, s_A[k]);
		k++;
	}*/
//	ft_check_sort(s_A, max_len);
	return ;
}

void	ft_algo_5(int *s_A, int *s_B, int max_len, t_varlen *varlen)
{
//	int	i;
//	int	j;
//	int	k;

	ft_push_b(s_A, s_B, max_len, varlen);
	ft_algo_4_5(s_A, s_B, max_len, varlen);
	if (s_B[0] < s_A[0])
	{
		ft_push_a(s_A, s_B, max_len, varlen);
	}
	else if (s_B[0] > s_A[varlen->len_a - 1])
	{
		ft_push_a(s_A, s_B, max_len, varlen);
		ft_rotate_a(s_A, *varlen);
	}
	else if (s_B[0] > s_A[0] && s_B[0] < s_A[1])
	{
		ft_rotate_a(s_A, *varlen);
		ft_push_a(s_A, s_B, max_len, varlen);
		ft_revrotate_a(s_A, *varlen);
	}
	else if (s_B[0] > s_A[0] && s_B[0] > s_A[1] && s_B[0] < s_A[2])
	{
		ft_revrotate_a(s_A, *varlen);
		ft_revrotate_a(s_A, *varlen);
		ft_push_a(s_A, s_B, max_len, varlen);
		ft_revrotate_a(s_A, *varlen);
		ft_revrotate_a(s_A, *varlen);
	}
	else if (s_B[0] > s_A[0] && s_B[0] > s_A[1] && s_B[0] > s_A[2])
	{
		ft_revrotate_a(s_A, *varlen);
		ft_push_a(s_A, s_B, max_len, varlen);
		ft_rotate_a(s_A, *varlen);
		ft_rotate_a(s_A, *varlen);
	}
/*	k = 0;
printf("\nRESULTAT DE L'ALGO_5 :\n");
	while (k < varlen->len_a)
	{
printf(YELLOW"s_A[%d] = %d"RESET"\n", k, s_A[k]);
		k++;
	}*/
//	ft_check_sort(s_A, max_len);
	return ;
}

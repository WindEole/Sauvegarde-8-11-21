/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iderighe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 10:49:56 by iderighe          #+#    #+#             */
/*   Updated: 2021/10/08 10:20:50 by iderighe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_init_sort(int *s_a, t_varlen varlen)
{
	int	i;

	i = 0;
	while (i < varlen.max_len - 1)
	{
		if (s_a[i] > s_a[i + 1])
			return (1);
		else
			i++;
	}
	return (0);
}

int	ft_check_reverse_sort(int *s_a, t_varlen *varlen)
{
	int	i;

	i = varlen->max_len - 1;
	while (i > 0)
	{
		if (s_a[i] > s_a[i - 1])
			return (0);
		else
			i--;
	}
	return (1);
}

//
//int	ft_check_sort(int *s_a, t_varlen varlen)
//{
//	int	i;
//	int	j;

//	i = 0;
//	while (i < varlen.max_len - 1)
//	{
//		if (s_a[i] > s_a[i + 1])
//		{
//			printf(RED"KO ! You should get your code straight !"RESET
//			YELLOW" nb total d'operation = %d"RESET"\n", varlen.add);
//			j = 0;
//			while (j < varlen.max_len)
//			{
//printf(RED"s_a[%d] = %d"RESET"\n", j, s_a[j]);
//				j++;
//			}
//			return (1);
//		}
//		else
//			i++;
//	}
//	printf(GREEN"OK ! Congratulations, your algorithme worked !"RESET
//	YELLOW" nb total d'operation = %d"RESET"\n", varlen.add);
//	i = 0;
//	while (i < max_len)
//	{
//printf(GREEN"s_a[%d] = %d"RESET"\n", i, s_a[i]);
//		i++;
//	}
//	return (0);
//}
//

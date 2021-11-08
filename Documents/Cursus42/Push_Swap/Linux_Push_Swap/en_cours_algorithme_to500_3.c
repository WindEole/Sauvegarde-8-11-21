/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithme_to500_3.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iderighe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 11:32:35 by iderighe          #+#    #+#             */
/*   Updated: 2021/10/16 12:20:42 by iderighe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_fill_sort_stack_b(int *s_a, int *s_b, t_varlen *varlen)
{
	int	pos_second;
	int	pos_in_b;
	int	i;
	int	j;

	pos_second = varlen->len_a - varlen->pos_second;
printf(RED"varlen->pos_first = %d s_a[F] = %d, pos_second = %d, s_a[S] = %d, varlen->len_a = %d, varlen->len_b = %d"RESET"\n", varlen->pos_first, s_a[varlen->pos_first], pos_second, s_a[varlen->pos_second], varlen->len_a, varlen->len_b);
i = 0;
while (i < varlen->len_a)
{
printf(YELLOW"s_a[%d] = %d"RESET"\n", i, s_a[i]);
i++;
}
j = 0;
while (j < varlen->len_b)
{
printf(BLUE"s_b[%d] = %d"RESET"\n", j, s_b[j]);
j++;
}
	if (varlen->pos_first < pos_second)//// ICI /////
	{
		pos_in_b = define_pos_in_b(s_a[varlen->pos_first], s_b, varlen);
printf(YELLOW"pos_in_b = %d"RESET"\n", pos_in_b);
		if (pos_in_b == 0)
			ft_loop_rotate_a(s_a, varlen, varlen->pos_first);
		else if (pos_in_b > 0)
		{
printf(GREEN"pos_in_b = %d, varlen->pos_first = %d, s_a[F] = %d, varlen->pos_second = %d, pos_second = %d, s_a[S] = %d, varlen->len_a = %d, varlen->len_b = %d"RESET"\n", pos_in_b, varlen->pos_first, s_a[varlen->pos_first], varlen->pos_second, pos_second, s_a[varlen->pos_second], varlen->len_a, varlen->len_b);
//			if (varlen->len_b <= 1)
//				ft_loop_rotate_a(s_a, varlen);
			if (varlen->pos_first == pos_in_b)
				ft_loop_rotate_ab(s_a, s_b, varlen, pos_in_b);
			if (varlen->pos_first < pos_in_b)
			{
				ft_loop_rotate_ab(s_a, s_b, varlen, varlen->pos_first);
				pos_in_b = pos_in_b - varlen->pos_first;
//				ft_loop_rotate_b(s_a, varlen, pos_in_b);
			}
			else if (varlen->pos_first > pos_in_b)
			{
				ft_loop_rotate_ab(s_a, s_b, varlen, varlen->pos_first);
				varlen->pos_first = varlen->pos_first - pos_in_b;
				ft_loop_rotate_a(s_a, varlen, varlen->pos_first);
			}
		}
//		else if (pos_in_b == 0)
//			ft_loop_rotate_a(s_a, varlen);
	}
	else if (varlen->pos_first > pos_second)/////////////////// ICI /////////
	{
		pos_in_b = define_pos_in_b(s_a[varlen->pos_second], s_b, varlen);
printf(CYAN"pos_in_b = %d"RESET"\n", pos_in_b);
		if (pos_in_b == 0)
			ft_loop_revrotate_a(s_a, varlen, pos_second);
		else if (pos_in_b > 0)
		{
			pos_in_b = varlen->len_b - pos_in_b;
printf(GREEN"pos_in_b pour rrr= %d, varlen->pos_first = %d, pos_second = %d, varlen->len_a = %d, varlen->len_b = %d"RESET"\n", pos_in_b, varlen->pos_first, pos_second, varlen->len_a, varlen->len_b);
			if (pos_second == pos_in_b)
				ft_loop_revrotate_ab(s_a, s_b, varlen, pos_second);
			if (pos_second < pos_in_b)
			{
				ft_loop_revrotate_ab(s_a, s_b, varlen, pos_second);
				pos_in_b = pos_in_b - pos_second;
				ft_loop_revrotate_b(s_b, varlen, pos_in_b);
			}
			if (pos_second > pos_in_b)
			{
				ft_loop_revrotate_ab(s_a, s_b, varlen, pos_in_b);
				pos_second = pos_second - pos_in_b;
				ft_loop_revrotate_a(s_a, varlen, pos_second);
printf(RED"ICI : pos_in_b = %d, pos_second = %d"RESET"\n", pos_in_b, pos_second);
			}
		}
	}
	else if (varlen->pos_first == pos_second)///////////////// ICI //////////
	{
		pos_in_b = define_pos_in_b(s_a[varlen->pos_second], s_b, varlen);
		if (s_a[varlen->pos_first] < s_a[varlen->pos_second])
		{
			if (pos_in_b == 0)
				ft_loop_rotate_a(s_a, varlen, varlen->pos_first);
			else if (pos_in_b > 0)
			{
printf(GREEN"pos_in_b = %d, varlen->pos_first = %d, s_a[F] = %d, varlen->pos_second = %d, pos_second = %d, s_a[S] = %d, varlen->len_a = %d, varlen->len_b = %d"RESET"\n", pos_in_b, varlen->pos_first, s_a[varlen->pos_first], varlen->pos_second, pos_second, s_a[varlen->pos_second], varlen->len_a, varlen->len_b);
//			if (varlen->len_b <= 1)
//				ft_loop_rotate_a(s_a, varlen);
				if (varlen->pos_first <= pos_in_b)
					ft_loop_rotate_ab(s_a, s_b, varlen, varlen->pos_first);
				else if (varlen->pos_first > pos_in_b)
				{
					ft_loop_rotate_ab(s_a, s_b, varlen, pos_in_b);
					varlen->pos_first = varlen->pos_first - pos_in_b;
					ft_loop_rotate_a(s_a, varlen, varlen->pos_first);
				}
			}
//		else if (pos_in_b == 0)
//			ft_loop_rotate_a(s_a, varlen);		}
//			ft_loop_rotate_a(s_a, varlen);
		}
		else if (s_a[varlen->pos_first] > s_a[varlen->pos_second])
		{
			pos_in_b = varlen->len_b - pos_in_b;
			if (pos_in_b == 0)
				ft_loop_revrotate_a(s_a, varlen, pos_second);
			else if (pos_in_b > 0)
		{
			pos_in_b = varlen->len_b - pos_in_b;
printf(GREEN"pos_in_b pour rrr= %d, varlen->pos_first = %d, pos_second = %d, varlen->len_a = %d, varlen->len_b = %d"RESET"\n", pos_in_b, varlen->pos_first, pos_second, varlen->len_a, varlen->len_b);
			if (pos_second == pos_in_b)
				ft_loop_revrotate_ab(s_a, s_b, varlen, pos_second);
			if (pos_second < pos_in_b)
			{
				ft_loop_revrotate_ab(s_a, s_b, varlen, pos_second);
				pos_in_b = pos_in_b - pos_second;
				ft_loop_revrotate_b(s_b, varlen, pos_in_b);
			}
			if (pos_second > pos_in_b)
			{
				ft_loop_revrotate_ab(s_a, s_b, varlen, pos_in_b);
				pos_second = pos_second - pos_in_b;
				ft_loop_revrotate_a(s_a, varlen, pos_second);
			}
		}
		}
//			ft_loop_revrotate_a(s_a, varlen, pos_second);
	}
	ft_sort_b(s_a, s_b, varlen);
}

int	define_pos_in_b(int xa, int *s_b, t_varlen *varlen)
{
	int	i;
	int	j;
	int	pos_in_b;
	int	pos_in_b_value;

	i = 0;
	if (xa == varlen->min)
		pos_in_b = 0;
	pos_in_b_value = varlen->min;
printf(PURPLE"On entre ici ?"RESET"\n");
	while (i < varlen->len_b)
	{
		j = 0;
		while (j < varlen->len_b)
		{
//printf(RED"xa = %d, i = %d, s_b[%d] = %d, j = %d, s_b[%d] = %d"RESET"\n", xa, i, i, s_b[i], j, j, s_b[j]);
			if (s_b[j] >= s_b[i] && s_b[j] < xa && s_b[j] > pos_in_b_value && s_b[i] < xa)
			{
				pos_in_b = j;
				pos_in_b_value = s_b[j];
printf(GREEN"pos_in_b = %d, pos_in_b_value = s_b[%d]"RESET"\n", pos_in_b, s_b[pos_in_b]);
			}
			j++;
		}
		i++;
	}
printf(RED"xa = %d, pos_in_b = %d, s_b[%d] = %d"RESET"\n", xa, pos_in_b, pos_in_b, s_b[pos_in_b]);
	return (pos_in_b);
}

void	ft_loop_rotate_a(int *s_a, t_varlen *varlen, int x)
{
	int	i;

	i = 0;
	while (i < x)
	{
		ft_rotate_a(s_a, varlen);
		i++;
	}
}

void	ft_loop_rotate_ab(int *s_a, int *s_b, t_varlen *varlen, int x)
{
	int	i;

	i = 0;
	while (i < x)
	{
		ft_rotate_ab(s_a, s_b, varlen);
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

void	ft_loop_revrotate_ab(int *s_a, int *s_b, t_varlen *varlen, int x)
{
	int	i;

	i = 0;
	while (i < x)
	{
		ft_revrotate_ab(s_a, s_b, varlen);
		i++;
	}
}

void	ft_loop_rotate_b(int *s_b, t_varlen *varlen, int x)
{
	int	i;
	i = 0;
	if (x == 0)
		return ;
	while (i < x)
	{
		ft_rotate_b(s_b, varlen);
		i++;
	}
}

void	ft_loop_revrotate_b(int *s_b, t_varlen *varlen, int x)
{
	int	i;

	i = 0;
	while (i < x)
	{
		ft_revrotate_b(s_b, varlen);
		i++;
	}
}

void	ft_sort_b(int *s_a, int *s_b, t_varlen *varlen)
{
printf(GREEN"ft_sort_b"RESET"\n");
printf(BLUE"s_a[0] = %d, s_b[0] = %d, s_b[varlen->len_b - 1] = %d"RESET"\n", s_a[0], s_b[0], s_b[varlen->len_b - 1]);
	if (s_a[0] == varlen->min)
	{
printf("ici ?\n");
		ft_push_b(s_a, s_b, varlen);
		ft_rotate_b(s_b, varlen);
	}
//	else if (varlen->len_b > 1 && s_a[0] < s_b[0]
	else if (varlen ->len_b > 1
	&& s_a[0] > s_b[varlen->len_b - 1])
		ft_insert_in_b(s_a, s_b, varlen);
	else
	{
printf("ou ici ?\n");
		ft_push_b(s_a, s_b, varlen);
		if (s_b[0] < s_b[1] && ((varlen->len_b - 1) != 0)
			&& s_b[0] > s_b[varlen->len_b - 1])
			ft_swap_b(s_b, varlen);
//		if (s_b[0] < s_b[varlen->len_b - 1])
//			ft_rotate_b(s_b, varlen);
	}
	return ;
}

void	ft_insert_in_b(int *s_a, int *s_b, t_varlen *varlen)
{
/*	int	i;
printf(CYAN"ft_insert_in_b"RESET"\n");
	i = 0;
	while (!(s_a[0] > s_b[0]))
	{
		ft_rotate_b(s_b, varlen);
		i++;
	}
	ft_push_b(s_a, s_b, varlen);
	while (i > 0)
	{
		ft_revrotate_b(s_b, varlen);
		i--;
	}
{*/
	int	i;
	int	pos_in_b;

	i = 0;
	pos_in_b = define_pos_in_b(s_a[0], s_b, varlen);
	if (pos_in_b <= (varlen->len_b / 2))
	{
		while (!(s_a[0] > s_b[0]))
		{
			ft_rotate_b(s_b, varlen);
			i++;
		}
		ft_push_b(s_a, s_b, varlen);
		while (i > 0)
		{
			ft_revrotate_b(s_b, varlen);
			i--;
		}
	}
	else if (pos_in_b > (varlen->len_b / 2))
	{
		i = 0;
		pos_in_b = varlen->len_b - pos_in_b;
		while (i < pos_in_b)
		{
			ft_revrotate_b(s_b, varlen);
			i++;
		}
		ft_push_b(s_a, s_b, varlen);
		i = i + 1;
		while (i > 0)
		{
			ft_rotate_b(s_b, varlen);
			i--;
		}
	}
}

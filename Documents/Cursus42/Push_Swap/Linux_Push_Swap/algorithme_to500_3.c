/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithme_to500_3.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iderighe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 11:32:35 by iderighe          #+#    #+#             */
/*   Updated: 2021/10/23 10:46:06 by iderighe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_fill_sort_stack_b(int *s_a, int *s_b, t_varlen *varlen)
{
	int	pos_second;
	int	pos_in_b_first;
	int	pos_in_b_second;
/*	int	i;
	int	j;
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
}*/
//printf(RED"fill_sort_stack_b"RESET"\n");
	pos_second = varlen->len_a - varlen->pos_second;
	varlen->count = 0;
	pos_in_b_first = ft_define_pos_in_b(s_a[varlen->pos_first], s_b, varlen);
	pos_in_b_second = ft_define_pos_in_b(s_a[varlen->pos_second], s_b, varlen);
//printf(YELLOW"pos_in_b_first = %d s_a[%d] = %d s_b[%d] = %d"BLUE" pos_in_b_second = %d, s_a[%d] = %d, s_b[%d] = %d"RESET"\n", pos_in_b_first, varlen->pos_first, s_a[varlen->pos_first], pos_in_b_first, s_b[pos_in_b_first], pos_in_b_second, varlen->pos_second, s_a[varlen->pos_second], pos_in_b_second, s_b[pos_in_b_second]);
/*	if (varlen->pos_first < pos_second)
		ft_loop_rotate_a(s_a, varlen);
	else if (varlen->pos_first > pos_second)
		ft_loop_revrotate_a(s_a, varlen, pos_second);
	else if (varlen->pos_first == pos_second)
	{
		if (s_a[varlen->pos_first] < s_a[varlen->pos_second])
			ft_loop_rotate_a(s_a, varlen);
		else if (s_a[varlen->pos_first] > s_a[varlen->pos_second])
			ft_loop_revrotate_a(s_a, varlen, pos_second);
	}
	ft_sort_b(s_a, s_b, varlen);*/

//printf(GREEN"pos_in_b_first + varlen->pos_first = %d, pos_in_b_second + varlen->pos_second = %d"RESET"\n", pos_in_b_first + varlen->pos_first, pos_in_b_second + varlen->pos_second);
	if (varlen->pos_first < pos_second)
	{
//printf("ici ?\n");
		if (pos_in_b_first >= varlen->pos_first && varlen->pos_first > 0)
		{
			ft_loop_rotate_ab(s_a, s_b, varlen, varlen->pos_first);
			varlen->count = varlen->pos_first;
		}
		else if (varlen->pos_first > pos_in_b_first && pos_in_b_first > 0)
		{
			ft_loop_rotate_ab(s_a, s_b, varlen, pos_in_b_first);
			varlen->pos_first = varlen->pos_first - pos_in_b_first;
			varlen->count = pos_in_b_first;
//printf(CYAN"varlen->count = %d, varlen->pos_first = %d, pos_in_b_first = %d"RESET"\n", varlen->count, varlen->pos_first, pos_in_b_first);
			ft_loop_rotate_a(s_a, varlen);
		}
		else
			ft_loop_rotate_a(s_a, varlen);
	}
	else if (varlen->pos_first > pos_second) /// on envoie pos_second vers B
	{
printf(GREEN"ici ?"RESET"\n");
		if (pos_in_b_second > (varlen->len_b / 2))
		{
printf(BLUE"ici ? pos_in_b_second = %d, varlen->len_b = %d, varlen->pos_second = %d, pos_second = %d"RESET"\n", pos_in_b_second, varlen->len_b, varlen->pos_second, pos_second);
			ft_loop_revrotate_ab(s_a, s_b, varlen, pos_second);
			varlen->count = pos_second;
		}
		else
			ft_loop_revrotate_a(s_a, varlen, pos_second);
	}
	else if (varlen->pos_first == pos_second)
	{
		if (s_a[varlen->pos_first] < s_a[varlen->pos_second])
			ft_loop_rotate_a(s_a, varlen);
		else if (s_a[varlen->pos_first] > s_a[varlen->pos_second])
			ft_loop_revrotate_a(s_a, varlen, pos_second);
	}
	ft_sort_b(s_a, s_b, varlen);
//	ft_insert_in_b(s_a, s_b, varlen);
/////////////////// ESSAI RR ET RRR /////////////////////////////////////////

/*	int	pos_second;
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
}DDDDDDEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEDDDDDD
	if (varlen->pos_first < pos_second)//// ICI /////
	{
		pos_in_b = define_pos_in_b(s_a[varlen->pos_first], s_b, varlen);
printf(YELLOW"pos_in_b = %d"RESET"\n", pos_in_b);
		if (pos_in_b == 0 || pos_in_b > (varlen->len_b / 2))
			ft_loop_rotate_a(s_a, varlen, varlen->pos_first);
		else //if (pos_in_b > 0 && pos_in_b < (varlen->len_b / 2))
		{
printf(GREEN"pos_in_b = %d, varlen->pos_first = %d, s_a[F] = %d, varlen->pos_second = %d, pos_second = %d, s_a[S] = %d, varlen->len_a = %d, varlen->len_b = %d, s_a[0] = %d"RESET"\n", pos_in_b, varlen->pos_first, s_a[varlen->pos_first], varlen->pos_second, pos_second, s_a[varlen->pos_second], varlen->len_a, varlen->len_b, s_a[0]);
//			if (pos_in_b > (varlen->len_b / 2))
//				ft_loop_rotate_a(s_a, varlen, varlen->pos_first);
//			else if (pos_in_b <= (varlen->len_b / 2))
//			{
//			if (varlen->len_b <= 1)
//				ft_loop_rotate_a(s_a, varlen);
			if (varlen->pos_first == pos_in_b)
				ft_loop_rotate_ab(s_a, s_b, varlen, pos_in_b);
			if (varlen->pos_first < pos_in_b)
			{
printf(CYAN"On entre ici ? s_a[0] = %d"RESET"\n", s_a[0]);
				ft_loop_rotate_ab(s_a, s_b, varlen, varlen->pos_first);
				pos_in_b = pos_in_b - varlen->pos_first;
printf(GREEN"s_a[0] = %d"RESET"\n", s_a[0]);
//				ft_loop_rotate_b(s_a, varlen, pos_in_b);
			}
			else if (varlen->pos_first > pos_in_b)
			{
				ft_loop_rotate_ab(s_a, s_b, varlen, varlen->pos_first);
				varlen->pos_first = varlen->pos_first - pos_in_b;
				ft_loop_rotate_a(s_a, varlen, varlen->pos_first);
			}
//			}
		}
//		else if (pos_in_b == 0)
//			ft_loop_rotate_a(s_a, varlen);
	}
///////////// ON VOIT SI CA MARCHE EN HAUT  /////////////////////////////
	else if (varlen->pos_first > pos_second)
		ft_loop_revrotate_a(s_a, varlen, pos_second);
	else if (varlen->pos_first == pos_second)
	{
		if (s_a[varlen->pos_first] < s_a[varlen->pos_second])
			ft_loop_rotate_a(s_a, varlen, varlen->pos_first);
//			ft_loop_rotate_a(s_a, varlen);
		else if (s_a[varlen->pos_first] > s_a[varlen->pos_second])
			ft_loop_revrotate_a(s_a, varlen, pos_second);
	}
	ft_sort_b(s_a, s_b, varlen);*/

//////////////// PATIENCE  /////////////////////////
/*	else if (varlen->pos_first > pos_second)/////////////////// ICI /////////
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
	ft_sort_b(s_a, s_b, varlen);*/



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

/////////////////////  FCT LOOP ///////////////////////////////////////////m
/*
void	ft_loop_rotate_a(int *s_a, t_varlen *varlen, int x)
{
	int	i;

	i = 0;
	while (i < x)
	{
		ft_rotate_a(s_a, varlen);
		i++;
	}
}*/

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
/*
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
*/
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
/*
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
*/

///////////////////////////// FIN DES FCT LOOP  //////////////////////////


void	ft_sort_b(int *s_a, int *s_b, t_varlen *varlen)
{
//printf(RED"sort_b"RESET"\n");
	if (s_a[0] == varlen->min)
	{
//printf(CYAN"sort_b On entre ici?"RESET"\n");
		ft_push_b(s_a, s_b, varlen);
		ft_rotate_b(s_b, varlen);
	}
	else if ((varlen->len_b > 1 && s_a[0] < s_b[0]
		&& s_a[0] > s_b[varlen->len_b - 1]) || varlen->count != 0)
	{
//printf(BLUE"sort_b On entre la ?"RESET"\n");
		ft_insert_in_b(s_a, s_b, varlen);
	}
	else
	{
//printf(YELLOW"sort_b Ou alors ici..."RESET"\n");
		ft_push_b(s_a, s_b, varlen);
		if (s_b[0] < s_b[1] && ((varlen->len_b - 1) != 0)
			&& s_b[0] > s_b[varlen->len_b - 1])
			ft_swap_b(s_b, varlen);
		if (s_b[0] < s_b[varlen->len_b - 1])
			ft_rotate_b(s_b, varlen);
	}
	return ;
}

void	ft_insert_in_b(int *s_a, int *s_b, t_varlen *varlen)
{
	int	i;
//	int j;
	int	pos_in_b;

	i = 0;
	pos_in_b = ft_define_pos_in_b(s_a[0], s_b, varlen);
//printf(PURPLE"insert_in_b pos_in_b = %d, i = %d"RESET"\n", pos_in_b, i);
	if (pos_in_b <= (varlen->len_b / 2))
	{
		while (!(s_a[0] > s_b[0]))
		{
			ft_rotate_b(s_b, varlen);
			i++;
		}
//printf(CYAN"insert_in_b s_a[0] = %d, s_a[1] = %d, s_a[2] = %d, s_b[last] = %d, varlen->len_a = %d"RESET"\n", s_a[0], s_a[1], s_a[2], s_b[varlen->len_b - 1], varlen->len_a);
//printf(CYAN"i = %d, s_a[0] = %d, s_b[0] = %d, varlen->count = %d"RESET"\n", i, s_a[0], s_b[0], varlen->count);
//printf(BLUE"i = %d"RESET"\n", i);
		varlen->count = varlen->count + i;
//printf(BLUE"i = %d, s_a[0] = %d, s_b[0] = %d, varlen->count = %d"RESET"\n", i, s_a[0], s_b[0], varlen->count);
		ft_push_b(s_a, s_b, varlen);
		while (varlen->count > 0)
		{
			ft_revrotate_b(s_b, varlen);
			varlen->count--;
		}
	}
	else if (pos_in_b > (varlen->len_b / 2))
	{
		i = 0;
		pos_in_b = varlen->len_b - pos_in_b;
printf(YELLOW"insert_in_b s_a[0] = %d, s_b[0] = %d, s_b[1] = %d, s_b[2] = %d, i = %d, pos_in_b = %d"RESET"\n", s_a[0], s_b[0], s_b[1], s_b[2], i, pos_in_b);
		while (i < pos_in_b)
//		while (!(s_a[0] > s_b[0]))
		{
			ft_revrotate_b(s_b, varlen);
			i++;
		}
printf(YELLOW"insert_in_b s_a[0] = %d, s_b[0] = %d, i = %d"RESET"\n", s_a[0], s_b[0], i);
		ft_push_b(s_a, s_b, varlen);
		i = i + 1 + varlen->count;
		while (i > 0)
		{
			ft_rotate_b(s_b, varlen);
			i--;
		}
	}
}

int	ft_define_pos_in_b(int xa, int *s_b, t_varlen *varlen)
{
	int	i;
	int	j;
	int	pos_in_b;
	int	pos_in_b_value;

	i = 0;
	if (xa == varlen->min)
		pos_in_b = 0;
	pos_in_b_value = varlen->min;
	while (i < varlen->len_b)
	{
		j = 0;
		while (j < varlen->len_b)
		{
			if (s_b[j] >= s_b[i] && s_b[j] < xa && s_b[j] > pos_in_b_value && s_b[i] < xa)
			{
				pos_in_b = j;
				pos_in_b_value = s_b[j];
//printf(GREEN"define_pos_in_b pos_in_b = %d, pos_in_b_value = s_b[%d]"RESET"\n", pos_in_b, s_b[pos_in_b]);
			}
			j++;
		}
		i++;
	}
//printf(RED"define_pos_in_b xa = %d, pos_in_b = %d, s_b[%d] = %d"RESET"\n", xa, pos_in_b, pos_in_b, s_b[pos_in_b]);
	return (pos_in_b);
}

int	ft_loop_push_b(int *s_a, int *s_b, t_varlen *varlen, int i)
{
	int	j;
	int	sb_last;
//	int	k;
//	int	l;

/*	j = 1;
		while (s_a[j + 1] > s_a[j] && (j + 1) < varlen->len_a && s_a[j] < s_b[varlen->len_b - 1])
		{
printf(YELLOW"s_a[0] = %d, s_a[1] = %d, s_a[2] = %d, s_a[3] = %d, s_b[last] = %d"RESET"\n", s_a[0], s_a[1], s_a[2], s_a[3], s_b[varlen->len_b - 1]);
			j++;
		}
		i = i + j;
printf(YELLOW"i = %d, j = %d"RESET"\n", i, j);
		while (j > 0)
		{
printf(GREEN"Est-ce que ca marche, ce truc ? s_a[0] = %d, s_a[1] = %d, s_a[2] = %d, len_a = %d, s_b[last] = %d"RESET"\n", s_a[0], s_a[1], s_a[2], varlen->len_a, s_b[varlen->len_b - 1]);
			ft_push_b(s_a, s_b, varlen);
			j--;
		}
printf(GREEN"i = %d"RESET"\n", i);*/
	sb_last = s_b[varlen->len_b - 1];
//printf(GREEN"sb_last = %d, s_a[0] = %d, s_b[0] = %d"RESET"\n", sb_last, s_a[0], s_b[0]);
	j = 0;
	i = i - 1;
	while (s_a[0] < sb_last && s_a[0] > s_b[0])
	{
		ft_push_b(s_a, s_b, varlen);
		sb_last = s_b[varlen->len_b];
		j++;
	}
	i = i + j;
//printf("i = %d, j = %d"RESET"\n", i, j);

/*	int	j;
printf(GREEN"loop_push s_a[0] = %d, s_b[0] = %d, s_b[last] = %d"RESET"\n", s_a[0], s_b[0], s_b[varlen->len_b - 1]);
	ft_push_b(s_a, s_b, varlen);
	j = 0;
	while (s_a[0] > s_b[0] && s_a[0] < s_b[varlen->len_b - 1])
	{
printf(GREEN"loop_push s_a[0] = %d, s_b[0] = %d, s_b[last] = %d"RESET"\n", s_a[0], s_b[0], s_b[varlen->len_b - 1]);
		ft_push_b(s_a, s_b, varlen);
		j++;
	}
printf(GREEN"i = %d, j = %d"RESET"\n", i, j);
//	j = j - 1;
	i = i + j;*/
	return (i);
}

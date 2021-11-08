/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iderighe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 10:49:56 by iderighe          #+#    #+#             */
/*   Updated: 2021/11/05 10:32:09 by iderighe         ###   ########.fr       */
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

//int	ft_check_dupl(int argc, char **argv)
int	ft_check_dupl(t_arg *arg)
{
	int	i;
	int	j;
//	int	check_dupl;
//printf(GREEN"On entre ici ? argc = %d argv[0][0] = %c"RESET"\n", argc, argv[0][0]);
	i = 0;
	if (arg->tab_argv[0][0] == '.')
		i = 1;
printf("i = %d\n", i);
	while (arg->tab_argv && i < arg->new_argc - 1)
	{
		j = i + 1;
//printf(YELLOW"i = %d, j = %d, argc = %d"RESET"\n", i, j, argc);
		while (arg->tab_argv && j < arg->new_argc)
		{
//printf(BLUE"j = %d, argc = %d"RESET"\n", j, argc);
//			check_dupl = ft_strcmp(argv[i], argv[j]);
//			if (check_dupl == 0)
			if (!(ft_strcmp(arg->tab_argv[i], arg->tab_argv[j])))
			{
				write(2, "Error\n", 6);
				return (0);
			}
			else
				j++;
		}
		i++;
	}
//printf(CYAN":qOn arrive la ? argc = %d"RESET"\n", argc);
//	if (!(ft_define_var(argc, argv)))
//	if (!(ft_define_var(arg)))
//		return (0);
//	ft_define_var(argc, argv);
	return (1);
}


int	ft_check_sort(int *s_a, t_varlen varlen)
{
	int	i;
	int	j;

	i = 0;
	while (i < varlen.max_len - 1)
	{
		if (s_a[i] > s_a[i + 1])
		{
			printf(RED"KO ! You should get your code straight !"RESET
			YELLOW" nb total d'operation = %d"RESET"\n", varlen.add);
			j = 0;
			while (j < varlen.max_len)
			{
printf(RED"s_a[%d] = %d"RESET"\n", j, s_a[j]);
				j++;
			}
			return (1);
		}
		else
			i++;
	}
	printf(GREEN"OK ! Congratulations, your algorithme worked !"RESET
	YELLOW" nb total d'operation = %d"RESET"\n", varlen.add);
	i = 0;
	while (i < varlen.max_len)
	{
printf(GREEN"s_a[%d] = %d"RESET"\n", i, s_a[i]);
		i++;
	}
	return (0);
}

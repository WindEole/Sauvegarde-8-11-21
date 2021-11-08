/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iderighe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 12:48:58 by iderighe          #+#    #+#             */
/*   Updated: 2021/11/04 15:44:27 by iderighe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//int	ft_define_var(int argc, char **argv)
//int	ft_define_var(t_arg *arg)
//{
//	int			i;
//	int			max_len_tmp;
//	t_varlen	varlen;
//printf(YELLOW"On arrive la ? argc = %d"RESET"\n", arg->new_argc);
//	i = 0;
//	max_len_tmp = arg->new_argc;
//	if (arg->tab_argv[0][0] == '.' || arg->tab_argv[0][0] == '/')
//	{
//		i = 1;
//		max_len_tmp = arg->new_argc - 1;
//		arg->new_argc = arg->new_argc - 1;
//	}
//	varlen = ft_init_varlen(max_len_tmp);
//	varlen = ft_init_varlen(arg->new_argc);
//	if (!(ft_check_minmax(argc, argv, i, &varlen)))
//	if (!(ft_check_minmax(arg, i, &varlen)))
//		return (0);
//	ft_check_minmax(argc, argv, i, &varlen);
//	return (1);
//}

//int	ft_check_minmax(int argc, char **argv, int i, t_varlen *varlen)
int	ft_check_minmax(t_arg *arg) //, t_varlen *varlen)
{
	long		*tmp;
	int			j;
	int			k;

	tmp = malloc(sizeof(long) * (arg->new_argc));
	if (tmp == NULL)
		return (0);
	j = 0;
	k = 0;
	if (arg->tab_argv[0][0] == '.' || arg->tab_argv[0][0] == '/')
		k = 1;
//	k = i;
	while (k < arg->new_argc)
	{
		tmp[j] = ft_atoi(arg->tab_argv[k]);
		if (tmp[j] > 2147483647 || tmp[j] < -2147483648)
		{
			write(2, "Error\n", 6);
			return (0);
		}
		j++;
		k++;
	}
	free(tmp);
//	if (!(ft_create_stack(arg, k, varlen)))
//		return (0);
//	ft_create_stack(argc, argv, i, varlen);
	return (1);
}

//int	ft_create_stack(int argc, char **argv, int i, t_varlen *varlen)
int	ft_create_stack(t_arg *arg, t_varlen *varlen)
{
	int			*s_a;
	int			*s_b;
	int			j;
	int			i;
//	int			init_sort;
//printf(BLUE"On arrive la ? argc = %d"RESET"\n", argc);
	s_a = malloc(sizeof(int) * (varlen->max_len));
	if (s_a == NULL)
		return (0);
	s_b = malloc (sizeof(int) * (varlen->max_len));
	if (s_b == NULL)
		return (0);
	j = 0;
	i = 0;
	if (arg->tab_argv[0][0] == '.' || arg->tab_argv[0][0] == '/')
	{
		i = 1;
		arg->new_argc = arg->new_argc + 1;
	}
	while (i < arg->new_argc) //(i < varlen->max_len) //(i < argc)
	{
		s_a[j] = ft_atoi(arg->tab_argv[i]);
printf(YELLOW"s_a[%d] = %d"RESET"\n", j, s_a[j]);
		s_b[j] = 0;
		j++;
		i++;
	}
printf(BLUE"ici ?"RESET"\n");
//	init_sort = ft_check_init_sort(s_a, *varlen);
//	if (init_sort == 0)
	if (!(ft_check_init_sort(s_a, *varlen)))
		return (0);
	ft_parsing(s_a, s_b, varlen);
	return (1);
}

int	ft_parsing(int *s_a, int *s_b, t_varlen *varlen)
{
printf(RED"On arrive la ?"RESET"\n");
	if (varlen->len_a <= 3)
		ft_algo_2_3(s_a, varlen);
	else if (varlen->len_a > 3 && varlen->len_a <= 5)
		ft_algo_4_5(s_a, s_b, varlen);
	else
		ft_algo_big_numbers(s_a, s_b, varlen);
	ft_check_sort(s_a, *varlen);
	free(s_a);
	free(s_b);
	return (1);
}

int	main(int argc, char **argv)
{
	t_arg		arg;
	int			check;
	t_varlen	varlen;

	arg.new_argc = argc;
	arg.tab_argv = argv;
	if (argc <= 1)
		return (1);
	else if (argc == 2)
		check = ft_check_uarg(&arg);
	else
		check = ft_check_narg(&arg);
	if (check == 0)
		return (1);
	if (!(ft_check_dupl(&arg)))
		return (1);
	if (arg.tab_argv[0][0] == '.' || arg.tab_argv[0][0] == '/')
		arg.new_argc = arg.new_argc - 1;
	varlen = ft_init_varlen(arg.new_argc);
	if (!(ft_check_minmax(&arg)))
		return (0);
	if (!(ft_create_stack(&arg, &varlen)))
		return (0);
	return (0);
}

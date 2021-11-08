/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iderighe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 12:48:58 by iderighe          #+#    #+#             */
/*   Updated: 2021/09/10 12:32:47 by iderighe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_varlen	ft_init_varlen(int max_len)
{
	t_varlen	varlen;

	varlen.len_a = max_len;
	varlen.len_b = 0;
	return (varlen);
}

int	ft_check_init_sort(int *s_A, int max_len)
{
	int	i;

	i = 0;
	while (i < max_len)
	{
		if (s_A[i] > s_A[i + 1])
			return (1);
		else
			i++;
	}
	return (0);
}

int	ft_check_sort(int *s_A, int max_len)
{
	int	i;
//	int	j;

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
/*	j = 0;
	while (j < max_len)
	{
printf(CYAN"s_A[%d] after sorting = %d"RESET"\n", j, s_A[j]);
		j++;
	}*/
	return (0);
}

int	ft_check_dupl(char **argv)
{
	int	i;
	int	j;
	int	check_dupl;

	i = 0;
	j = 0;
	if (argv[0][0] == '.')
		i = 1;
	while (argv[i] != '\0')
	{
		j = i + 1;
		while (argv[j] != '\0')
		{
			check_dupl = ft_strcmp(argv[i], argv[j]);
			if (check_dupl == 0)
				return (0);
			else
				j++;
		}
		i++;
	}
	return (1);
}

int	ft_check_uarg(int argc, char **argv)
{
	const char	*arg_initial;
	int			j;
	int			check_dupl;

	arg_initial = ft_strdup(argv[1]);
	j = 0;
	while (argv[1][j] != '\0')
	{
		if (argv[1][j] <= 31 || (argv[1][j] >= '!' && argv[1][j] <= '*')
			|| argv[1][j] == ',' || argv[1][j] == '.' || argv[1][j] == '/' 
			|| argv[1][j] >= ':')
		{
			printf(BLUE"Error"RESET"\n");
			return (0);
		}
		else
			j++;
	}
	argv = (char **)ft_split(arg_initial, ' ');
	j = 0;
	while (argv[j] != '\0')
		j++;
	argc = j;
	if (argc < 2 || argc > 501)
	{
		printf(RED"Error"RESET"\n");
		return (0);
	}
	check_dupl = ft_check_dupl(argv);
	if (check_dupl == 0)
	{
		printf(YELLOW"Error"RESET"\n");
		return (0);
	}
	ft_create_stacks(argc, argv);
	return (1);
}

int	ft_check_narg(int argc, char **argv)
{
	int	i;
	int	j;
	int	check_dupl;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			if (argv[i][j] <= '*' || argv[i][j]== ',' || argv[i][j] == '.' || argv[i][j] == '/'
				|| argv[i][j] >= ':')
			{
				printf(GREEN"Error"RESET"\n");
				return (0);
			}
			else
				j++;
		}
		i++;
	}
	check_dupl = ft_check_dupl(argv);
	if (check_dupl == 0)
	{
		printf(PURPLE"Error"RESET"\n");
		return (0);
	}
	else
		ft_create_stacks(argc, argv);
	return (1);
}

int	ft_create_stacks(int argc, char **argv)
{
	int			*s_A;
	int			*s_B;
	int			i;
	int			j;
	int			max_len;
	t_varlen	varlen;
	int			init_sort;

	s_A = malloc(sizeof(int) * (argc));
	if (s_A == NULL)
		return (0);
	s_B = malloc (sizeof(int) * (argc));
	if (s_B == NULL)
		return (0);
	i = 0;
	j = 0;
	max_len = argc;
	if (argv[0][0] == '.' || argv[0][0] == '/')
	{
		i = 1;
		max_len = argc - 1;
	}
printf("\nCONTENU DES STACKS A ET B\n");
	while (i < argc)
	{
		s_A[j] = ft_atoi(argv[i]);
		s_B[j] = (int)NULL;
printf(YELLOW"s_A[%d] = %d "RESET BLUE" s_B[%d] = %d"RESET "\n", j, s_A[j], j, s_B[j]);
		j++;
		i++;
	}
	varlen = ft_init_varlen(max_len);
	init_sort = ft_check_init_sort(s_A, max_len);
	if (init_sort == 0)
	{
		printf(RED"Error : arguments already sorted"RESET"\n");
		return (0);
	}
	if (varlen.len_a <= 3)
		ft_algo_2_3(s_A, varlen);
	else if(varlen.len_a > 3 && varlen.len_a<= 5)
		ft_algo_4_5(s_A, s_B, max_len, &varlen);
	else
	{
//		ft_algo_100(s_A, s_B, max_len, &varlen);
		ft_algo_big_numbers(s_A, s_B, max_len, &varlen);
//		ft_code_essai(s_A, s_B, max_len, &varlen);
//		ft_ultra_swap_a(s_A, varlen);
//		ft_ultra_rotate_a(s_A, varlen);
//		ft_rotate_b(s_B, varlen);
//		ft_rotate_ab(s_A,s_B, varlen);
//		ft_revrotate_a(s_A, varlen);
//		ft_revrotate_b(s_B, varlen);
//		ft_revrotate_ab(s_A, s_B, varlen);
//		ft_push_a(s_A, s_B, max_len, &varlen);
//		ft_push_b(s_A, s_B, max_len, &varlen);
//		ft_swap_a(s_A, varlen);
//		ft_swap_b(s_B, varlen);
//		ft_swap_ab(s_A, s_B, varlen);
	}
	ft_check_sort(s_A, max_len);
	return (1);
}

int	main(int argc, char **argv)
{
	int	i;
	int	check;

	i = 1;
/*	while (i < argc)
	{
		if (argv[i] == NULL)
		{
			printf(RED"Error"RESET"\n");
			return (0);
		}
		i++;
	}*/
	if (argc < 1)
	{
		printf(CYAN "Error"RESET"\n");
		return (0);
	}
	else if (argc == 2)
		check = ft_check_uarg(argc, argv);
	else
		check = ft_check_narg(argc, argv);
	if (check == 0)
		return (0);
	return (1);
}

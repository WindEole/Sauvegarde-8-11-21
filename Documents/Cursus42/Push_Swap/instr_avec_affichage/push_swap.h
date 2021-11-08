/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iderighe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 11:47:11 by iderighe          #+#    #+#             */
/*   Updated: 2021/08/28 15:28:29 by iderighe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <string.h>
# include <ctype.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

# define RED "\033[1;31m"
# define GREEN "\033[1;32m"
# define YELLOW "\033[1;33m"
# define BLUE "\033[1;34m"
# define PURPLE "\033[1;35m"
# define CYAN "\033[1;36m"
# define GREY "\033[1;37m"
# define RESET "\033[0m"

typedef struct s_varlen
{
	int			len_a;
	int			len_b;
	int			end_loop;
}				t_varlen;

// fonctions de push_swap.c

int				ft_create_stacks(int argc, char **argv);
int				ft_check_init_sort(int *s_A, int max_len);
void			ft_code_essai(int *s_A, int *s_B, int max_len, t_varlen *varlen);
//void			ft_ultra_rotate_a(int *s_A, t_varlen varlen);
//void			ft_ultra_swap_a(int *s_A, t_varlen varlen);
//int				ft_check_sort(int *s_A, int max_len);

// fonctions d'instr_swap.c

void			ft_swap_a(int *s_A, t_varlen varlen);
void			ft_swap_b(int *s_B, t_varlen varlen);
void			ft_swap_ab(int *s_A, int *s_B, t_varlen varlen);

// fonctions d'instr_push.c

void			ft_push_a(int *s_A, int *s_B, int max_len, t_varlen *varlen);
void			ft_push_b(int *s_A, int *s_B, int max_len, t_varlen *varlen);

// fonctions d'instr_rotate.c

void			ft_rotate_a(int *s_A, t_varlen varlen);
void			ft_rotate_b(int *s_B, t_varlen varlen);
void			ft_rotate_ab(int *s_A, int *s_B, t_varlen varlen);

// fonctions d'instr_revrotate.c

void			ft_revrotate_a(int *s_A, t_varlen varlen);
void			ft_revrotate_b(int *s_B, t_varlen varlen);
void			ft_revrotate_ab(int *s_A, int *s_B, t_varlen varlen);

// fonctions d'algorithme_to5.c

void			ft_algo_2_3(int *s_A, t_varlen varlen);
void			ft_algo_3(int *s_A, t_varlen varlen);
void			ft_algo_4_5(int *s_A, int *s_B, int max_len, t_varlen *varlen);
void			ft_algo_5(int *s_A, int *s_B, int max_len, t_varlen *varlen);

// fonctions d'algorithme_to100.c
void			ft_algo_100(int *s_A, int *s_B, int max_len, t_varlen *varlen);
int				ft_search_median_value(int *s_A, int max_len);
void			ft_fill_stack_B(int *s_A, int *s_B, int max_len, t_varlen *varlen, int pivot, int n_pivot);
void			ft_sort_A(int *s_A, int *s_B, int max_len, t_varlen *varlen);
void			ft_sort_BtoA(int *s_A, int *s_B, int max_len, t_varlen *varlen);

// fonctions d'algorithme_to500.c

int			ft_algo_big_numbers(int *s_A, int *s_B, int max_len, t_varlen *varlen);
int				ft_search_pivot_values(int *s_A, int *s_B, int max_len, t_varlen *varlen, int n_pivot, int pivot);
void			ft_sort_B(int *s_A, int *s_B, int max_len, t_varlen *varlen);


// fonctions de la Libft

int				ft_atoi(const char *s);
char			*ft_strdup(const char *s1);
char			**ft_split(const char *s, char c);
int				ft_strcmp(char *s1, char *s2);
int				ft_strlen(const char *str);

#endif

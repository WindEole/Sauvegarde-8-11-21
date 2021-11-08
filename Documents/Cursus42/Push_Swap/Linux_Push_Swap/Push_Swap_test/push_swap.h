/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_new.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iderighe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 11:47:11 by iderighe          #+#    #+#             */
/*   Updated: 2021/11/04 15:36:20 by iderighe         ###   ########.fr       */
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

typedef struct s_arg
{
	int			new_argc;
	char		**tab_argv;
}				t_arg;

typedef struct s_varlen
{
	int			len_a;
	int			len_b;
	int			add;
	int			min;
	int			max;
	int			pos_first;
	int			pos_second;
	int			max_len;
	int			count;
}				t_varlen;

// fonctions de push_swap.c (1, 2)

int				ft_parsing(int *s_a, int *s_b, t_varlen *varlen);
//int				ft_define_var(int argc, char **argv);
//int				ft_define_var(t_arg *arg);
//int				ft_c//heck_minmax(int argc, char **argv, int i, t_varlen *varlen);
int				ft_check_minmax(t_arg *arg);
//int				ft_create_stack(int argc, char **argv, int i, t_varlen *varlen);
int				ft_create_stack(t_arg *arg, t_varlen *varlen);

int				ft_check_init_sort(int *s_a, t_varlen varlen);
int				ft_check_reverse_sort(int *s_a, t_varlen *varlen);
//int				ft_check_dupl(int argc, char **argv);
int				ft_check_dupl(t_arg *arg);
int				ft_check_sort(int *s_a, t_varlen varlen);

// fonctions de arg_check.c

t_varlen		ft_init_varlen(int max_len);
//int				ft_check_uarg(int argc, char **argv);
int				ft_check_uarg(t_arg *arg);
//int				ft_check_uarg_suite(int argc, char **argv);
int				ft_check_uarg_suite(t_arg *arg);
//int				ft_check_narg(int argc, char **argv);
int				ft_check_narg(t_arg *arg);
//int				ft_check_narg_suite(int argc, char **argv);
int				ft_check_narg_suite(t_arg *arg);

// fonctions d'instr_swap_push.c

void			ft_swap_a(int *s_a, t_varlen *varlen);
void			ft_swap_b(int *s_b, t_varlen *varlen);
void			ft_swap_ab(int *s_a, int *s_b, t_varlen *varlen);
void			ft_push_a(int *s_a, int *s_b, t_varlen *varlen);
void			ft_push_b(int *s_a, int *s_b, t_varlen *varlen);

// fonctions d'instr_rotate.c

void			ft_rotate_a(int *s_a, t_varlen *varlen);
void			ft_rotate_b(int *s_b, t_varlen *varlen);
void			ft_rotate_ab(int *s_a, int *s_b, t_varlen *varlen);

// fonctions d'instr_revrotate.c

void			ft_revrotate_a(int *s_a, t_varlen *varlen);
void			ft_revrotate_b(int *s_b, t_varlen *varlen);
void			ft_revrotate_ab(int *s_a, int *s_b, t_varlen *varlen);

// fonctions d'algorithme_to5.c

void			ft_algo_2_3(int *s_a, t_varlen *varlen);
void			ft_algo_3(int *s_a, t_varlen *varlen);
void			ft_algo_4_5(int *s_a, int *s_b, t_varlen *varlen);
void			ft_algo_5(int *s_a, int *s_b, t_varlen *varlen);

// fonctions d'algorithme_to500.c (1, 2, 3)

int				ft_algo_big_numbers(int *s_a, int *s_b, t_varlen *varlen);
void			ft_define_min_max(int *s_a, t_varlen *varlen);
void			ft_loop_browse(int *s_a, int *s_b, int *index_sa, \
		t_varlen *varlen);

int				ft_create_index(int *s_a, int *s_b, t_varlen *varlen);
int				ft_create_new_index(int *s_a, t_varlen *varlen);
//void			ft_define_chunks(int *s_a, int *index_sa, t_varlen *varlen);
void			ft_define_first_hold(int *index_sa, t_varlen *varlen);
//void			ft_define_first_hold(int *s_a, t_varlen *varlen, int sa_chunks);
void			ft_define_second_hold(int *index_sa, t_varlen *varlen);
//void			ft_define_second_hold(int *s_a, t_varlen *varlen, int sa_chunks);
void			ft_first_send(int *s_a, int *s_b, t_varlen *varlen);
void			ft_median_sort(int *s_a, int *s_b, int *index_sa, t_varlen *varlen);
int				ft_define_median_a(int *s_a, int *index_sa, t_varlen *varlen);
int				ft_define_median_b(int *s_b, t_varlen *varlen);

void			ft_fill_sort_stack_b(int *s_a, int *s_b, t_varlen *varlen);
//void			ft_fill_sort_stack_bis(int *s_a, int *s_b, t_varlen *varlen);
int				ft_define_pos_in_b(int xa, int *s_b, t_varlen *varlen);
void			ft_loop_rotate_a(int *s_a, t_varlen *varlen);
//void			ft_loop_rotate_a(int *s_a, t_varlen *varlen, int x);
void			ft_loop_rotate_ab(int *s_a, int *s_b, t_varlen *varlen, int x);
void			ft_loop_revrotate_a(int *s_a, t_varlen *varlen, int pos_second);
void			ft_loop_revrotate_ab(int *s_a, int *s_b, t_varlen *varlen, int x);
void			ft_loop_rotate_b(int *s_b, t_varlen *varlen, int x);
void			ft_loop_revrotate_b(int *s_b, t_varlen *varlen, int x);
void			ft_sort_b(int *s_a, int *s_b, t_varlen *varlen);
void			ft_insert_in_b(int *s_a, int *s_b, t_varlen *varlen);
int				ft_loop_push_b(int *s_a, int *s_b, t_varlen *varlen, int i);

// fonctions de la Libft

long			ft_atoi(const char *s);
char			*ft_strdup(const char *s1);
char			**ft_split(const char *s, char c);
int				ft_strcmp(char *s1, char *s2);
int				ft_strlen(const char *str);

#endif

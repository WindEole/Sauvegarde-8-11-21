/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rballage <rballage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 14:03:57 by rballage          #+#    #+#             */
/*   Updated: 2021/09/09 13:31:32 by rballage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H
# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# define BUFF_SIZE 100
# define PID 3
# define FINISHED 2
# define LEN 1
# define COUNTER 0

typedef enum e_bool
{
	false,
	true
}				t_bool;

void			bufferise(char byte, int *index, t_bool error);
void			add_bit(char *byte, int *nth_bit, int signal);
void			clean(int *nth_bit, int *i, int *tab);
void			setlen(int signal, int *counter, int *len);
int				parse_string(int sig, int *tab);
void			handler(int sig, siginfo_t *info, void *context);
void			*ft_memset(void *b, int c, size_t len);
void			ft_putchar(char ch);
void			ft_putnbr(int n);
void			ft_putstr(char *str);

#endif

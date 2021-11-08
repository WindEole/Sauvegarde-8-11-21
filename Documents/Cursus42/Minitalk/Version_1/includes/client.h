/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rballage <rballage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 14:03:57 by rballage          #+#    #+#             */
/*   Updated: 2021/09/09 15:28:41 by iderighe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H
# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# define SLEEPTIME 1000

int				ft_atoi(const char *str);
size_t			ft_strlen(const char *str);
void			quit(char *message, int code);
int				send_bit(char byte, int *nth_bit, pid_t pid);
int				stopclean(char *byte, int *nth_bit);
int				send(pid_t pid, char *str);
int				send_len(pid_t pid, size_t len);
void			finished(int signal);

#endif

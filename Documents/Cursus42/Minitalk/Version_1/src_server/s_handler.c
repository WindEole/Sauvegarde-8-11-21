/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_handler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rballage <rballage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 15:25:01 by rballage          #+#    #+#             */
/*   Updated: 2021/09/09 13:52:58 by rballage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/server.h"

// static char	counter = 31;
// static int	len = 0;
// static char	finished = 0;
// static int	pid = 0;

void	handler(int sig, siginfo_t *info, void *context)
{
	static int	tab[4] = {31, 0, 0, 0};

	(void)context;
	if (tab[PID] != info->si_pid && tab[LEN] && tab[PID])
		parse_string(-1, tab);
	tab[PID] = info->si_pid;
	if (tab[COUNTER] >= 0 && !tab[FINISHED])
	{
		setlen(sig, &tab[COUNTER], &tab[LEN]);
		if (--(tab[COUNTER]) == -1)
		{
			tab[FINISHED] = 1;
			if (!tab[LEN])
			{
				ft_putchar('\n');
				tab[COUNTER] = 31;
				tab[FINISHED] = 0;
				kill(info->si_pid, SIGUSR1);
			}
		}
	}
	else
		parse_string(sig, tab);
}

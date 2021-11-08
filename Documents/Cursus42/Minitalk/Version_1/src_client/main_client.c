/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_client.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rballage <rballage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 15:28:40 by rballage          #+#    #+#             */
/*   Updated: 2021/09/09 12:02:43 by rballage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/client.h"

int	main(int ac, char **av)
{
	pid_t	pid;
	int		len;

	pid = 0;
	len = 0;
	if (ac == 3)
	{
		pid = (pid_t)ft_atoi(av[1]);
		if (pid <= 0 || kill(pid, 0) == -1)
			quit("ERROR - INVALID_PID\n", EXIT_FAILURE);
		else
		{
			signal(SIGUSR1, finished);
			len = send_len(pid, ft_strlen(av[2]));
			while (send(pid, av[2]))
				usleep(SLEEPTIME);
			usleep(len * SLEEPTIME);
		}
		quit("ERROR - TIMEOUT\n", EXIT_FAILURE);
	}
	else
		quit("ERROR - USAGE: ./client <SERVER_PID> <STRING>\n", EXIT_FAILURE);
	return (-1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_send_len.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rballage <rballage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 15:16:59 by rballage          #+#    #+#             */
/*   Updated: 2021/09/09 12:00:10 by rballage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/client.h"

int	send_len(pid_t pid, size_t len)
{
	int	nth_bit;

	nth_bit = 31;
	while (nth_bit >= 0)
	{
		if (len & (1 << nth_bit))
		{
			if ((kill(pid, SIGUSR1)) == -1)
				quit("ERROR - CONNECTION_LOST\n", EXIT_FAILURE);
		}
		else
			if ((kill(pid, SIGUSR2)) == -1)
				quit("ERROR - CONNECTION_LOST\n", EXIT_FAILURE);
		usleep(SLEEPTIME);
		nth_bit--;
	}
	return (len);
}

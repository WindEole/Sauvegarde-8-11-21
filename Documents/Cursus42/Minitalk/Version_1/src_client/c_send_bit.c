/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_bit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rballage <rballage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 15:15:14 by rballage          #+#    #+#             */
/*   Updated: 2021/09/08 15:19:18 by rballage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/client.h"

int	send_bit(char byte, int *nth_bit, pid_t pid)
{
	if (byte & (1 << *nth_bit))
	{
		if ((kill(pid, SIGUSR1)) == -1)
			quit("ERROR - CONNECTION_LOST\n", EXIT_FAILURE);
	}
	else
	{
		if ((kill(pid, SIGUSR2)) == -1)
			quit("ERROR - CONNECTION_LOST\n", EXIT_FAILURE);
	}
	return (1);
}

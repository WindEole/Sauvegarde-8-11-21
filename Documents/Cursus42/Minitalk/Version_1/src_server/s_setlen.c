/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_setlen.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rballage <rballage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 15:23:52 by rballage          #+#    #+#             */
/*   Updated: 2021/09/09 13:54:37 by rballage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/server.h"

void	setlen(int signal, int *counter, int *len)
{
	if (signal == SIGUSR1)
		*len |= (1 << (*counter));
	else if (signal == SIGUSR2)
		*len &= ~(1 << (*counter));
}

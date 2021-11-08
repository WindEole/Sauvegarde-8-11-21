/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_bit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rballage <rballage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 15:22:44 by rballage          #+#    #+#             */
/*   Updated: 2021/09/08 15:26:47 by rballage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/server.h"

void	add_bit(char *byte, int *nth_bit, int signal)
{
	if (signal == SIGUSR1)
		*byte |= (1 << (*nth_bit));
	else if (signal == SIGUSR2)
		*byte &= ~(1 << (*nth_bit));
	*nth_bit -= 1;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_send.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rballage <rballage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 15:16:04 by rballage          #+#    #+#             */
/*   Updated: 2021/09/09 12:01:39 by rballage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/client.h"

int	send(pid_t pid, char *str)
{
	static int	nth_bit = 7;
	static char	*bytes;

	if (!bytes)
		bytes = str;
	if (*bytes == 0)
		return (0);
	if (!send_bit(*bytes, &nth_bit, pid))
		return (stopclean(bytes, &nth_bit));
	nth_bit--;
	if (nth_bit < 0)
	{
		bytes++;
		if (*bytes)
			nth_bit = 7;
		else
			return (stopclean(bytes, &nth_bit));
	}
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_bufferise.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rballage <rballage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 15:25:58 by rballage          #+#    #+#             */
/*   Updated: 2021/09/09 12:10:15 by rballage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/server.h"

void	bufferise(char byte, int *index, t_bool error)
{
	static char	buffer[BUFF_SIZE];
	static int	buff_index = 0;

	buffer[buff_index] = byte;
	if (buff_index == BUFF_SIZE - 1 || *index == 1 || error)
	{
		if (!error)
			write(1, buffer, buff_index + 1);
		else
			ft_putchar('\n');
		buff_index = 0;
	}
	else
	{
		buff_index++;
	}
	*index -= 1;
}

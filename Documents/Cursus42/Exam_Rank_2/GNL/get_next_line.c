/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iderighe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 14:43:41 by iderighe          #+#    #+#             */
/*   Updated: 2021/05/31 15:14:23 by iderighe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(char **line)
{
	int	i;
	int	l;
	int	r;
	char	c;
	char	*tmp;

	r = 0;
	l = 1;
	if (!(*line = malloc(l)))
		return (-1);
	(*line)[0] = 0;
	while ((r = read(0, &c, 1)) && l++ && c != '\n')
	{
		if (!(tmp = malloc(l)))
		{
			free(*line);
			return (-1);
		}
		l = -1;
		while (++i < l - 2)
			tmp[i] = (*line)[i];
		tmp[i] = c;
		free(*line);
		*line = tmp;
	}
	return (r);
}

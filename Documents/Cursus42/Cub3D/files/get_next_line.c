/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogenser <ogenser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/01 12:47:27 by ogenser           #+#    #+#             */
/*   Updated: 2020/12/29 13:17:21 by ogenser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/get_next_line.h"

int		ft_assign_strs(t_list *mother, char **rest, char **line)
{
	if (line_size(*rest) > -1)
	{
		*line = ft_substr(*rest, 0, line_size(*rest));
		mother->stock = ft_substr(*rest, line_size(*rest) + 1,
		ft_strlen(*rest));
		free(*rest);
		*rest = NULL;
		*rest = ft_substr(mother->stock, 0, ft_strlen(mother->stock));
		free(mother->stock);
		mother->stock = NULL;
		return (1);
	}
	else
	{
		*line = ft_substr(*rest, 0, ft_strlen(*rest));
		free(*rest);
		*rest = NULL;
	}
	return (0);
}

int		get_next_line(int fd, char **line)
{
	t_list		mother;
	static char	*rest = NULL;

	if (fd < 0 || BUFFER_SIZE <= 0 || !line || read(fd, mother.buffer, 0) < 0)
		return (-1);
	while (line_size(rest) == -1
	&& (mother.rid = read(fd, mother.buffer, BUFFER_SIZE)) > 0)
	{
		mother.buffer[mother.rid] = '\0';
		if (!rest)
			rest = ft_substr("", 0, 0);
		rest = ft_strjoin(rest, mother.buffer);
	}
	return (ft_assign_strs(&mother, &rest, line));
}

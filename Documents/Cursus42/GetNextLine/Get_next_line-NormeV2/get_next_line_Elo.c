/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iderighe <iderighe@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 17:16:42 by iderighe          #+#    #+#             */
/*   Updated: 2021/02/06 12:43:53 by iderighe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strcut(char *str)
{
	char	*new_line;
	int		i;

	new_line = malloc(sizeof(char) * (ft_strl_n(str) + 1));
	if (new_line == NULL)
		return (NULL);
	i = 0;
	if (str)
		while (str && str[i] != '\n')
		{
			new_line[i] = str[i];
			i++;
		}
	new_line[i] = '\0';
	return (new_line);
}

char	*ft_saver(char *str)
{
	int	i;
	int	j;

	if (!str)
		return (NULL);
	i = ft_strl_n(str);
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	if (str && str[i])
		i++;
	j = 0;
	while (str && str[i])
	{
		str[j] = str[i];
		i++;
		j++;
	}
	str[j] = '\0';
	return (str);
}

int		check_n(char *str)
{
	int		i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

int		get_next_line(int fd, char **line)
{
	int			R_val;
	char		buf[BUFFER_SIZE + 1];
	static char	*str[256];
	char		*tmp;

	if (fd < 0 || BUFFER_SIZE <= 0 || !line || read(fd, buf, 0) < 0)
		return (-1);
	R_val = 1;
	while (check_n(str[fd]) == 0 && (R_val = read(fd, buf, BUFFER_SIZE)) != 0)
	{
		if (R_val == -1)
			return (-1);
		buf[R_val] = '\0';
		tmp = str[fd];
		str[fd] = ft_strjoin(tmp, buf);
		free(tmp);
	}
	*line = ft_strcut(str[fd]);
	str[fd] = ft_saver(str[fd]);
	if (R_val == 0)
		return (0);
	return (1);
}

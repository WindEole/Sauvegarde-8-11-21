/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iderighe <iderighe@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 13:31:32 by iderighe          #+#    #+#             */
/*   Updated: 2021/02/10 17:19:03 by iderighe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_check_n(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strcut(char *str)
{
	char	*cut_to_n;
	int		i;

	cut_to_n = malloc(sizeof(char) * (ft_strn(str) + 1));
	if (cut_to_n == NULL)
		return (NULL);
	i = 0;
	if (str)
	{
		while (str[i] && str[i] != '\n')
		{
			cut_to_n[i] = str[i];
			i++;
		}
	}
	cut_to_n[i] = '\0';
//	printf("voici le buf coupe au 1er retour a la ligne :\n%s\n", cut_to_n);
	return (cut_to_n);
}

char	*ft_saver(char *str)
{
	int	i;
	int	j;

	if (!str)
		return (NULL);
	i = ft_strn(str);
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

int		get_next_line(int fd, char **line)
{
	static char	*str[1024];
	int			r;
	char		buf[BUFFER_SIZE + 1];
	char		*tmp;

	if (fd < 0 || BUFFER_SIZE <= 0 || !line || read(fd, buf, 0) < 0)
		return (-1);
	r = 1;
	while (ft_check_n(str[fd]) == 0 && (r = read(fd, buf, BUFFER_SIZE)) != 0)
	{
		if (r == -1)
			return (-1);
		buf[r] = '\0';
//		printf("voici le buf : %s\n", buf);
		tmp = str[fd];
//		printf("voici le contenu de tmp : %s\n", tmp);
		str[fd] = ft_strjoin(tmp, buf);
//		printf("voici le contenu de str[fd] : %s\n", str[fd]);
		free(tmp);
	}
	*line = ft_strcut(str[fd]);
//	printf("voici le contenu de line : %s\n", *line);
	str[fd] = ft_saver(str[fd]);
//	printf("voici le contenu de str[fd] apres saver : %s\n", str[fd]);
	if (r == 0)
		return (0);
	return (1);
}

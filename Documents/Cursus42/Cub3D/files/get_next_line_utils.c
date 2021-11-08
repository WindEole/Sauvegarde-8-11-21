/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogenser <ogenser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/01 12:47:54 by ogenser           #+#    #+#             */
/*   Updated: 2021/03/10 14:48:57 by ogenser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/get_next_line.h"

char		*ft_strjoin(char *s1, char *s2)
{
	char	*dest;
	int		taille;
	int		i;
	int		j;

	i = 0;
	j = 0;
	taille = ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1;
	if (!(dest = (char *)malloc(sizeof(char) * taille)))
	{
		free(s1);
		s1 = NULL;
		return (NULL);
	}
	while (s1[j])
		dest[i++] = s1[j++];
	j = 0;
	while (s2[j])
	{
		dest[i++] = s2[j++];
	}
	dest[i] = '\0';
	free(s1);
	s1 = NULL;
	return (dest);
}

char		*ft_substr(char *s, unsigned int start, size_t len)
{
	int		i;
	char	*dest;

	i = 0;
	if (!s)
		s = "";
	if (!(dest = (char*)malloc(len + 1)))
		return (NULL);
	if (start < ft_strlen((char *)s))
		while (s[start + i] && len--)
		{
			dest[i] = s[start + i];
			i++;
		}
	dest[i] = '\0';
	return (dest);
}

int			line_size(char *s)
{
	int	i;

	if (!s)
		return (-1);
	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

size_t		ft_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

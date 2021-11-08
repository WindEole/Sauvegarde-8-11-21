/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iderighe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 15:23:21 by iderighe          #+#    #+#             */
/*   Updated: 2021/01/27 10:58:56 by iderighe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_getrows(char const *s, char c)
{
	size_t	rows;
	size_t	i;

	rows = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			rows++;
		i++;
	}
	return (rows);
}

static size_t	ft_wordlen(char const *s2, char c, size_t i)
{
	size_t	len;

	len = 0;
	while (s2[i] != c && s2[i])
	{
		len++;
		i++;
	}
	return (len);
}

static char		**ft_free(char const **tab, size_t j)
{
	size_t	i;

	i = 0;
	while (i < j)
	{
		free((void *)tab[i]);
		i++;
	}
	free(tab);
	return (0);
}

static char		**ft_filltab(char const *s, size_t rows, char c, char **tab)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	rows = ft_getrows(s, c);
	while (s[i] && j < rows)
	{
		k = 0;
		while (s[i] == c)
			i++;
		if (!(tab[j] = (char *)malloc(sizeof(char) * ft_wordlen(s, c, i) + 1)))
			return (ft_free((char const **)tab, rows));
		while (s[i] && s[i] != c)
		{
			tab[j][k] = s[i];
			k++;
			i++;
		}
		tab[j][k] = '\0';
		j++;
	}
	tab[j] = 0;
	return (tab);
}

char			**ft_split(char const *s, char c)
{
	char	**tab;
	size_t	rows;

	if (!s)
		return (0);
	rows = ft_getrows(s, c);
	tab = (char **)malloc(sizeof(char *) * (rows + 1));
	if (tab == NULL)
		return (NULL);
	return (ft_filltab(s, rows, c, tab));
}

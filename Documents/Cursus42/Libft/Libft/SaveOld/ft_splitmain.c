/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splitmain.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iderighe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 15:23:21 by iderighe          #+#    #+#             */
/*   Updated: 2021/01/30 13:44:44 by iderighe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

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

static size_t	ft_words_len(char const *s2, char c, size_t i)
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
		tab[j] = (char *)malloc(sizeof(char) * (ft_words_len(s, c, i) + 1));
		if (tab[j] == NULL)
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

/*int	main (void)
{
	char const	s[30] = "Bonjour tout le monde !";
	char		c = 'o';
	char		**str;
	int			i;

	str = ft_split(s, c);
	printf("before :%s\n", s);
	i = 0;
	while (str[i])
	{
		printf("after :%s \n", str[i]);
		i++;
	}
	return (0);
}*/

/*int		main(int argc, char **argv)
{
	char	**tab = ft_split(argv[1], argv[2][0]);
	int		i;

	i = 0;
	if (argc != 3)
		return (0);
	while (tab[i])
	{
		printf("%s\n", tab[i]);
		i++;
	}
	return (0);
}*/

#include <stdio.h>
#include <stdlib.h>
static size_t		ft_getrows(char const *s, char c);
char				**ft_split(char const *s, char c);

int					main(int argc, char *argv[])
{
	char	**strings;
	int		i;
	strings = NULL;
	if (argc == 3)
	{
		if (argv[1][0] != '\0' && argv[2][0] != '\0' && \
			argv[2][1] == '\0')
		{
			printf("wordcount = %zu\n", ft_getrows(argv[1], argv[2][0]));
			printf("ft_split('%s', '%c'):\n", argv[1], *argv[2]);
			strings = ft_split(argv[1], *argv[2]);
			i = -1;
			while (strings[++i])
				printf("[%d] == %s\n", i, strings[i]);
		}
	}
	i = 0;
	while (strings[i])
	{
		free(strings[i]);
		i++;
	}
	free(strings);
	return (0);
}

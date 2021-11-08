/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iderighe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 14:29:04 by iderighe          #+#    #+#             */
/*   Updated: 2021/10/08 16:17:04 by iderighe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atoi(const char *s)
{
	int			i;
	int			minus;
	long int	res;

	i = 0;
	minus = 1;
	res = 0;
	while (s[i] == 32 || (s[i] > 8 && s[i] < 14))
		i++;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			minus = -1 * minus;
		i++;
	}
	while (s[i] && (unsigned char)s[i] >= 48 && (unsigned char)s[i] <= 57)
	{
		res = (res * 10) + ((unsigned char)s[i] - 48);
		i++;
	}
	return ((long int)(res * minus));
}

char	*ft_strdup(const char *s1)
{
	char	*s2;
	int		i;

	s2 = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (s2 == NULL)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && (s1[i] != '\0' || s2[i] != '\0'))
		i++;
	return (s1[i] - s2[i]);
}

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogenser <ogenser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 16:54:37 by ogenser           #+#    #+#             */
/*   Updated: 2021/03/25 17:47:42 by ogenser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube3d.h"

int		getimgpixel(int x, int y, char *adress, int bits)
{
	char	*tmp;

	tmp = adress + (y * 256 + x * (bits / 8));
	return (*(unsigned int *)tmp);
}

void	ft_strcpy(char *dest, char *src, int *j)
{
	unsigned int	i;

	i = 0;
	while (src[*j] != '\0')
	{
		dest[i] = src[*j];
		i++;
		(*j)++;
	}
	dest[i] = '\0';
}

void	ft_sprcpy(char *dest, char *src, int *j)
{
	unsigned int	i;

	i = 0;
	while (src[*j + 1] != '\0')
	{
		dest[i] = src[*j];
		i++;
		(*j)++;
	}
	dest[i] = '\0';
}

int		ft_atoi(const char *str, int *i)
{
	int		minus;
	int		result;

	minus = 1;
	result = 0;
	while (str[*i] && ((str[*i] >= 9 && str[*i] <= 13)
		|| str[*i] == 32 || str[*i] >= 58))
		(*i)++;
	if (str[*i] && (str[*i] == 43 || str[*i] == 45))
	{
		if (str[*i] == 45)
			minus = -1;
		(*i)++;
	}
	while (str[*i] && (str[*i] >= '0' && str[*i] <= '9'))
	{
		result = result * 10 + (str[*i] - 48);
		(*i)++;
	}
	if (result < 0 && minus > 0)
		return (-1);
	else if (result < 0 && minus < 0 && result * minus != -2147483648)
		return (0);
	return (result * minus);
}

void	ft_colorcheck(t_mother *s, char *line)
{
	int		i;
	int		t;

	i = 0;
	t = 0;
	while (line[i] != '\0')
	{
		if (line[i] == ',')
			t++;
		if (line[i] != ',' && line[i] != 'F' && line[i] != 'C'
			&& (line[i] < '0' || line[i] >= '9') && ft_space(line[i]) == 0)
			ft_error("color", s);
		i++;
	}
	if (t > 2 || t <= 1)
		ft_error("color", s);
}

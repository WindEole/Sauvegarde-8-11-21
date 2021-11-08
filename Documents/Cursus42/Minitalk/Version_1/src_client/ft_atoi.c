/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rballage <rballage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 19:27:22 by rballage          #+#    #+#             */
/*   Updated: 2021/09/09 12:15:17 by rballage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../includes/client.h"

static int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int					sign;
	unsigned long long	n;

	sign = 1;
	n = 0;
	while ((*str <= 13 && *str >= 9) || *str == 32)
		str++;
	while ((ft_isdigit(*str) || *str == '+' || *str == '-') && *str != '\0')
	{
		if ((*str == '-' || *str == '+') && n)
			break ;
		if ((*str == '-' || *str == '+') && !(ft_isdigit(str[1])))
			return (0);
		if (*str == '-' && ft_isdigit(str[1]))
			sign = -1;
		else if (ft_isdigit(*str))
			n = n * 10 + (*str - 48);
		str++;
	}
	if (n > 9223372036854775807 && sign == -1)
		return (0);
	else if (n > 9223372036854775807 && sign == 0)
		return (-1);
	return ((int)(n * sign));
}

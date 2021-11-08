/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iderighe <iderighe@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 11:35:19 by iderighe          #+#    #+#             */
/*   Updated: 2021/03/06 11:53:08 by iderighe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	ft_minus(int n)
{
	if (n < 0)
		return (-1);
	return (1);
}

int		ft_dstlen(int n)
{
	int				dlen;
	unsigned int	nb;

	dlen = 0;
	if (n <= 0)
	{
		nb = -n;
		dlen = 1;
	}
	else
		nb = n;
	while (nb > 0)
	{
		nb = nb / 10;
		dlen++;
	}
	return (dlen);
}

char	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

char	*ft_itoa(int n)
{
	int		minus;
	int		dlen;
	char	*dst;

	minus = ft_minus(n);
	dlen = ft_dstlen(n);
	dst = (char *)malloc(sizeof(char) * (dlen + 1));
	if (dst == NULL)
		return (NULL);
	dst[dlen] = '\0';
	dlen--;
	while (dlen >= 0)
	{
		dst[dlen] = '0' + ft_abs(n % 10);
		n = n / 10;
		dlen--;
	}
	if (minus == -1)
		dst[0] = '-';
	return (dst);
}

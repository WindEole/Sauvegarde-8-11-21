/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iderighe <iderighe@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 12:32:40 by iderighe          #+#    #+#             */
/*   Updated: 2021/03/29 17:37:18 by iderighe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_dstlen_ui(unsigned long int n)
{
	int				dlen;
	unsigned int	nb;

	dlen = 0;
	if (n == 0)
		dlen = 1;
	if (n < 0)
		nb = 4294967295 - (n - 1);
	else
		nb = n;
	while (nb > 0)
	{
		nb = nb / 10;
		dlen++;
	}
	return (dlen);
}

char	ft_abs_ui(unsigned long int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

char	*ft_itoa_ui(unsigned long int n)
{
	int		dlen;
	char	*dst;

	dlen = ft_dstlen_ui(n);
	dst = (char *)malloc(sizeof(char) * (dlen + 1));
	if (dst == NULL)
		return (NULL);
	dst[dlen] = '\0';
	dlen--;
	while (dlen >= 0)
	{
		dst[dlen] = '0' + ft_abs_ui(n % 10);
		n = n / 10;
		dlen--;
	}
	return (dst);
}

int		ft_dstlen_base(unsigned int n, int size_base)
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
		nb = nb / size_base;
		dlen++;
	}
	return (dlen);
}

char	*ft_itoa_base(unsigned int n, char *base, int size_base)
{
	int		dlen;
	char	*dst;

	dlen = ft_dstlen_base(n, size_base);
	dst = (char *)malloc(sizeof(char) * (dlen + 1));
	if (dst == NULL)
		return (NULL);
	dst[dlen] = '\0';
	dlen--;
	while (dlen >= 0)
	{
		dst[dlen] = base[n % size_base];
		n = n / size_base;
		dlen--;
	}
	return (dst);
}

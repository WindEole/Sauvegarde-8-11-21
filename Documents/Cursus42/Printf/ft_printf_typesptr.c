/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_typesptr.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iderighe <iderighe@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 14:24:18 by iderighe          #+#    #+#             */
/*   Updated: 2021/03/30 12:11:50 by iderighe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_dstlen_baseptr(unsigned long long n, int size_base)
{
	int					dlen;
	unsigned long long	nb;

	dlen = 0;
	if (n == 0)
		dlen = 1;
	nb = n;
	while (nb > 0)
	{
		nb = nb / size_base;
		dlen++;
	}
	return (dlen);
}

char	*ft_itoa_baseptr(unsigned long long n, char *base, int size_base)
{
	int		dlen;
	char	*dst;

	dlen = 2 + ft_dstlen_baseptr(n, size_base);
	dst = (char *)malloc(sizeof(char) * (dlen + 1));
	if (dst == NULL)
		return (NULL);
	dst[dlen] = '\0';
	dlen--;
	while (dlen >= 2)
	{
		dst[dlen] = base[n % size_base];
		n = n / size_base;
		dlen--;
	}
	dst[1] = 'x';
	dst[0] = '0';
	return (dst);
}

int		ft_type_is_ptr(unsigned long long input, t_flags *flags)
{
	char	*str_input;
	int		add;

	add = 0;
	if (flags->dot == 0 && input == 0)
		return (add += ft_treat_width(flags->width, 0, 0));
	str_input = ft_itoa_baseptr(input, HEX_X, 16);
	add = ft_unintparse(str_input, flags);
	free(str_input);
	return (add);
}

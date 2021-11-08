/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_typesint1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iderighe <iderighe@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 16:12:36 by iderighe          #+#    #+#             */
/*   Updated: 2021/03/06 13:47:33 by iderighe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_type_is_int(int input, t_flags *flags)
{
	int		minus;
	char	*str_input;
	int		add;

	minus = 0;
	add = 0;
	if (flags->dot == 0 && input == 0)
		return (add += ft_treat_width(flags->width, 0, 0));
	if (input < 0)
	{
		input *= -1;
		minus = 1;
		if (input == -2147483648)
			minus = 0;
	}
	if (flags->zero == 1)
	{
		if (flags->dot >= 0)
			flags->zero = 0;
	}
	str_input = ft_itoa(input);
	add = ft_intparseflags(input, str_input, minus, flags);
	free(str_input);
	return (add);
}

int		ft_intparseflags(int input, char *str_input, int minus, t_flags *flags)
{
	int		add;

	add = 0;
	if (flags->width == 0 && flags->dot <= 0)
		add += ft_diminus(minus) + ft_putstr(str_input);
	if (flags->width == 0 && flags->dot > 0)
	{
		if (flags->dot < (int)ft_strlen(str_input))
			add += ft_diminus(minus) + ft_putstr(str_input);
		else
			add += ft_diminus(minus) + ft_filldotzero(str_input, *flags)
				+ ft_putstr(str_input);
	}
	if (flags->width != 0 && flags->dot <= 0)
		add = ft_widthnodot(input, str_input, minus, flags);
	if (flags->width != 0 && flags->dot > 0)
		add = ft_widthanddot(str_input, minus, flags);
	return (add);
}

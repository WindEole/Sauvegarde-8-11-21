/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_typesint3.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iderighe <iderighe@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 16:12:36 by iderighe          #+#    #+#             */
/*   Updated: 2021/03/05 17:10:49 by iderighe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_widthnodot(int input, char *str_input, int minus, t_flags *flags)
{
	int		add;

	add = 0;
	if (flags->width <= ((int)ft_strlen(str_input) + minus))
	{
		if (input == 0 && flags->dot == 0)
			add += ft_fillwidthspace(minus, str_input, *flags);
		else
			add += ft_diminus(minus) + ft_putstr(str_input);
	}
	if ((flags->width > ((int)ft_strlen(str_input) + minus))
			&& flags->minus == 1)
		add += ft_diminus(minus) + ft_putstr(str_input)
			+ ft_fillwidthspace(minus, str_input, *flags);
	else
		add += ft_widthnodot2(input, str_input, minus, flags);
	return (add);
}

int		ft_widthnodot2(int input, char *str_input, int minus, t_flags *flags)
{
	int add;

	add = 0;
	if ((flags->width > ((int)ft_strlen(str_input) + minus))
			&& flags->minus == 0)
	{
		if (flags->zero != 0)
		{
			if (input == 0 && flags->dot == 0)
				add += ft_fillwidthspace(minus, str_input, *flags);
			else
				add += ft_diminus(minus) + ft_fillwidthzero(minus,
					str_input, *flags) + ft_putstr(str_input);
		}
		else if (flags->zero == 0)
			add += ft_fillwidthspace(minus, str_input, *flags)
				+ ft_diminus(minus) + ft_putstr(str_input);
	}
	return (add);
}

int		ft_widthanddot(char *str_input, int minus, t_flags *flags)
{
	int		add;

	add = 0;
	if (flags->dot < ((int)ft_strlen(str_input) + minus))
	{
		if (flags->dot < flags->width)
			add += ft_widthanddot2(str_input, minus, flags);
		if (flags->dot >= flags->width)
			add += ft_diminus(minus) + ft_filldotzero(str_input, *flags)
				+ ft_putstr(str_input);
	}
	else if (flags->dot >= ((int)ft_strlen(str_input) + minus))
		add += ft_widthanddot2(str_input, minus, flags);
	return (add);
}

int		ft_widthanddot2(char *str_input, int minus, t_flags *flags)
{
	int		add;

	add = 0;
	if (flags->minus == 0)
		add += ft_fillwidthspacedot(minus, str_input, *flags)
			+ ft_diminus(minus) + ft_filldotzero(str_input, *flags)
			+ ft_putstr(str_input);
	else if (flags->minus == 1)
		add += ft_diminus(minus) + ft_filldotzero(str_input, *flags)
			+ ft_putstr(str_input)
			+ ft_fillwidthspace(minus, str_input, *flags);
	return (add);
}

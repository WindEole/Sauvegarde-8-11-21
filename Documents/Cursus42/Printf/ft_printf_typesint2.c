/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_typesint2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iderighe <iderighe@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 11:38:38 by iderighe          #+#    #+#             */
/*   Updated: 2021/03/31 11:39:28 by iderighe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_diminus(int minus)
{
	if (minus == 1)
	{
		ft_putchar('-');
		return (1);
	}
	return (0);
}

int		ft_fillwidthzero(int minus, char *str_input, t_flags flags)
{
	int		zero;

	zero = 0;
	while ((flags.width - ft_strlen(str_input) - minus) > 0)
	{
		zero += ft_putchar('0');
		flags.width--;
	}
	return (zero);
}

int		ft_fillwidthspace(int minus, char *str_input, t_flags flags)
{
	int		space;

	space = 0;
	if (flags.dot >= 0 && flags.dot >= (int)ft_strlen(str_input))
	{
		while ((flags.width - flags.dot - minus) > 0)
		{
			space += ft_putchar(' ');
			flags.width--;
		}
	}
	else
	{
		while ((flags.width - ft_strlen(str_input) - minus) > 0)
		{
			space += ft_putchar(' ');
			flags.width--;
		}
	}
	return (space);
}

int		ft_filldotzero(char *str_input, t_flags flags)
{
	int		zero;

	zero = 0;
	if (flags.dot > (int)ft_strlen(str_input))
	{
		while ((flags.dot - ft_strlen(str_input)) > 0)
		{
			zero += ft_putchar('0');
			flags.dot--;
		}
	}
	else if (flags.dot == (int)ft_strlen(str_input))
		return (zero);
	return (zero);
}

int		ft_fillwidthspacedot(int minus, char *str_input, t_flags flags)
{
	int		space;

	space = 0;
	if (flags.width > ((int)ft_strlen(str_input) + minus))
	{
		if (flags.dot >= ((int)ft_strlen(str_input) + minus))
		{
			while ((flags.width - flags.dot - minus) > 0)
			{
				space += ft_putchar(' ');
				flags.width--;
			}
		}
		else if (flags.dot < ((int)ft_strlen(str_input) + minus))
		{
			while (flags.width - (ft_strlen(str_input) + minus) > 0)
			{
				space += ft_putchar(' ');
				flags.width--;
			}
		}
	}
	else if (flags.width <= ((int)ft_strlen(str_input) + minus))
		return (0);
	return (space);
}

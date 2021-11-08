/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_typeschar.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iderighe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 16:12:23 by iderighe          #+#    #+#             */
/*   Updated: 2021/03/30 10:33:59 by iderighe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_type_is_percent(t_flags *flags)
{
	int	add;

	add = 0;
	if (flags->minus == 1)
		add += ft_putstrprec("%", 1);
	add += ft_treat_width(flags->width, 1, flags->zero);
	if (flags->minus == 0)
		add += ft_putstrprec("%", 1);
	return (add);
}

int		ft_type_is_c(va_list ap, t_flags *flags)
{
	int	add;

	add = 0;
	if (flags->minus == 1)
		ft_putchar(va_arg(ap, int));
	add = ft_treat_width(flags->width, 1, 0);
	if (flags->minus == 0)
		ft_putchar(va_arg(ap, int));
	return (add + 1);
}

int		ft_type_is_s(char *str, t_flags *flags)
{
	int	add;

	add = 0;
	if (!str)
		str = "(null)";
	if (flags->dot >= 0 && (size_t)flags->dot > ft_strlen(str))
		flags->dot = ft_strlen(str);
	if (flags->minus == 1)
		add += ft_partstr(str, *flags);
	if (flags->dot >= 0)
		add += ft_treat_width(flags->width, flags->dot, 0);
	else
		add += ft_treat_width(flags->width, ft_strlen(str), 0);
	if (flags->minus == 0)
		add += ft_partstr(str, *flags);
	return (add);
}

int		ft_partstr(char *str, t_flags flags)
{
	int	add;

	add = 0;
	if (flags.dot >= 0)
	{
		add += ft_treat_width(flags.dot, ft_strlen(str), 0);
		add += ft_putstrprec(str, flags.dot);
	}
	else
	{
		add += ft_putstrprec(str, ft_strlen(str));
	}
	return (add);
}

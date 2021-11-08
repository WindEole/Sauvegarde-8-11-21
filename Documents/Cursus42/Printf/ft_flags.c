/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iderighe <iderighe@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 14:49:38 by iderighe          #+#    #+#             */
/*   Updated: 2021/03/03 15:24:09 by iderighe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags		ft_init_flags(void)
{
	t_flags	flags;

	flags.dot = -1;
	flags.minus = 0;
	flags.star = 0;
	flags.zero = 0;
	flags.width = 0;
	flags.type = 0;
	return (flags);
}

int			ft_flag_dot(const char *save, int i, t_flags *flags, va_list ap)
{
	int	j;

	j = i;
	j++;
	if (save[j] == '*')
	{
		flags->dot = va_arg(ap, int);
		j++;
	}
	else
	{
		flags->dot = 0;
		while (ft_isdigit(save[j]))
			flags->dot = (flags->dot * 10) + (save[j++] - 48);
	}
	flags->zero = 0;
	return (j);
}

t_flags		ft_flag_width(va_list ap, t_flags flags)
{
	flags.star = 1;
	flags.width = va_arg(ap, int);
	if (flags.width < 0)
	{
		flags.minus = 1;
		flags.width = flags.width * -1;
	}
	return (flags);
}

t_flags		ft_flag_digit(char c, t_flags flags)
{
	if (flags.star == 1)
		flags.width = 0;
	flags.width = (flags.width * 10) + (c - 48);
	return (flags);
}

t_flags		ft_flag_minus(t_flags flags)
{
	flags.minus = 1;
	flags.zero = 0;
	return (flags);
}

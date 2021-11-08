/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_typesuix.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iderighe <iderighe@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 10:21:13 by iderighe          #+#    #+#             */
/*   Updated: 2021/03/30 10:37:43 by iderighe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_type_is_unint(unsigned int input, t_flags *flags, int a)
{
	char	*str_input;
	int		add;

	add = 0;
	input = (unsigned int)(4294967295 + 1 + input);
	if (flags->dot == 0 && input == 0)
		return (add += ft_treat_width(flags->width, 0, 0));
	if (a == 'x')
		str_input = ft_itoa_base(input, HEX_X, 16);
	if (a == 'X')
		str_input = ft_itoa_base(input, HEX_XX, 16);
	if (a == 'u')
		str_input = ft_itoa_ui(input);
	add = ft_unintparse(str_input, flags);
	free(str_input);
	return (add);
}

int		ft_unintparse(char *str_input, t_flags *flags)
{
	int		add;

	add = 0;
	if (flags->dot < 0 && flags->width != 0 && flags->zero == 1)
		add += ft_fillwidthzero_ui(str_input, *flags) + ft_putstr(str_input);
	if (flags->dot >= flags->width && flags->minus == 0)
		add += ft_filldotzero(str_input, *flags) + ft_putstr(str_input);
	if (flags->dot < flags->width && flags->minus == 0 && flags->zero == 0)
		add += ft_fillwidthspace_ui(str_input, *flags) +
			ft_filldotzero(str_input, *flags) + ft_putstr(str_input);
	if (flags->dot >= flags->width && flags->minus != 0)
		add += ft_filldotzero(str_input, *flags) + ft_putstr(str_input);
	if (flags->dot < flags->width && flags->minus != 0)
		add += ft_filldotzero(str_input, *flags) + ft_putstr(str_input) +
			ft_fillwidthspace_ui(str_input, *flags);
	return (add);
}

int		ft_fillwidthspace_ui(char *str_input, t_flags flags)
{
	int		add;

	add = 0;
	if (flags.dot >= 0)
		while (flags.width - flags.dot > 0 && flags.width >
				(int)ft_strlen(str_input))
		{
			add += ft_putchar(' ');
			flags.width--;
		}
	else if (flags.dot == -1)
		while (flags.width > (int)ft_strlen(str_input))
		{
			add += ft_putchar(' ');
			flags.width--;
		}
	return (add);
}

int		ft_fillwidthzero_ui(char *str_input, t_flags flags)
{
	int		add;

	add = 0;
	while (flags.width > (int)ft_strlen(str_input))
	{
		add += ft_putchar('0');
		flags.width--;
	}
	return (add);
}

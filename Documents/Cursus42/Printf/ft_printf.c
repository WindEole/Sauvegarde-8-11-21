/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iderighe <iderighe@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 12:15:39 by iderighe          #+#    #+#             */
/*   Updated: 2021/03/30 10:45:56 by iderighe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_exam_type(int a, t_flags *flags, va_list ap)
{
	int	add;

	add = 0;
	if (a == 'c')
		add += ft_type_is_c(ap, flags);
	else if (a == 's')
		add += ft_type_is_s(va_arg(ap, char *), flags);
	else if (a == 'p')
		add += ft_type_is_ptr(va_arg(ap, unsigned long long), flags);
	else if (a == 'd' || a == 'i')
		add += ft_type_is_int(va_arg(ap, int), flags);
	else if (a == 'u' || a == 'x' || a == 'X')
		add += ft_type_is_unint(va_arg(ap, unsigned int), flags, a);
	else if (a == '%')
		add += ft_type_is_percent(flags);
	return (add);
}

int		ft_exam_flags(const char *save, int i, t_flags *flags, va_list ap)
{
	while (save[i])
	{
		if (!ft_isdigit(save[i]) && !ft_isatype(save[i]) &&
			!ft_isaflag(save[i]))
			break ;
		if (save[i] == '0' && flags->width == 0 && flags->minus == 0)
			flags->zero = 1;
		if (save[i] == '.')
			i = ft_flag_dot(save, i, flags, ap);
		if (save[i] == '-')
			*flags = ft_flag_minus(*flags);
		if (save[i] == '*')
			*flags = ft_flag_width(ap, *flags);
		if (ft_isdigit(save[i]))
			*flags = ft_flag_digit(save[i], *flags);
		if (ft_isatype(save[i]))
		{
			flags->type = save[i];
			break ;
		}
		i++;
	}
	return (i);
}

int		ft_exam_save(const char *save, va_list ap)
{
	int		add;
	int		i;
	t_flags	flags;

	i = 0;
	add = 0;
	while (save[i] != '\0')
	{
		flags = ft_init_flags();
		if (!save[i])
			break ;
		if (save[i] == '%' && save[i + 1])
		{
			i = ft_exam_flags(save, ++i, &flags, ap);
			if (ft_isatype(save[i]))
				add += ft_exam_type(save[i], &flags, ap);
			else if (save[i])
				add += ft_putchar(save[i]);
		}
		else if (save[i] != '%')
			add += ft_putchar(save[i]);
		i++;
	}
	return (add);
}

int		ft_printf(const char *input, ...)
{
	const char	*save;
	va_list		ap;
	int			add;

	save = ft_strdup(input);
	add = 0;
	va_start(ap, input);
	add += ft_exam_save(save, ap);
	va_end(ap);
	free((char *)save);
	return (add);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfisa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iderighe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/05 15:19:25 by iderighe          #+#    #+#             */
/*   Updated: 2021/06/05 17:07:55 by iderighe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags		ft_init_flags(void)
{
	t_flags	flags;

	flags.dot = -1;
	flags.width = 0;
	flags.type = 0;
	return (flags);
}

int			ft_isatype(int a)
{
	return ((a == 's') || (a == 'd') || (a == 'x'));
}

int			ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int			ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

size_t		ft_strlen(const char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int			ft_putstr(char *str)
{
	int		add;
	int		i;

	add = 0;
	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
		add++;
	}
	return (add);
}

void	ft_putnbr(int nb)
{
	long int	i;
	int			a;

	i = nb;
	if (i < 0)
	{
		ft_putchar('-');
		i = i * -1;
	}
	if (i >= 0)
	{
		a = i % 10 + 48;
		i = i / 10;
		if (i > 0)
		{
			ft_putnbr(i);
		}
		ft_putchar(a);
	}
}

char		*ft_strdup(const char *s1)
{
	char	*s2;
	int		i;

	s2 = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (s2 == NULL)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

int			ft_flag_dot(const char *save, int i, t_flags *flags, va_list ap)
{
	int	j;

	j = i;
	j++;
	flags->dot = 0;
	while (ft_isdigit(save[j]))
		flags->dot = (flags->dot * 10) + (save[j++] - 48);
	return (j);
}

int			ft_type_is_s(char *str, t_flags *flags)
{
	int	add;

	add = 0;
	if (!str)
		str = "(null)";
	if (flags->dot >= 0 && (size_t)flags->dot > ft_strlen(str))
		flags->dot = ft_strlen(str);
	if (flags->dot >= 0)
		add += ft_treat_width(flags->width, flags->dot);
	else
		add += ft_treat_width(flags->width, ft_strlen(str));
	return (add);
}

int			ft_treat_width(int width, int swrite)
{
	int add;

	add = 0;
	while (width - swrite > 0)
	{
		ft_putchar(' ');
		width -= 1;
		add++;
	}
	return (add);
}

int			ft_exam_type(int a, t_flags *flags, va_list ap)
{
	int	add;

	add = 0;
	else if (a == 's')
		add += ft_type_is_s(va_arg(ap, char *), flags);
	else if (a == 'd')
		add += ft_type_is_int(va_arg(ap, int), flags);
	else if (a == 'x')
		add += ft_type_is_unint(va_arg(ap, unsigned int), flags, a);
	return (add);
}

int			ft_exam_flags(const char *save, int i, t_flags *flags, va_list ap)
{
	while (save[i])
	{
		if (!ft_isdigit(save[i]) && !ft_isatype(save[i]) &&
			(save[i] != '.'))
			break ;
		if (save[i] == '.')
			i = ft_flag_dot(save, i, flags, ap);
		if (ft_isdigit(save[i]))
			flags.width = (flags.width * 10) + (c - 48)
		if (ft_isatype(save[i]))
		{
			flags->type = save[i];
			break ;
		}
		i++;
	}
	return (i);
}

int			ft_exam_save(const char *save, va_list ap)
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

int			ft_printf(const char *input, ...)
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

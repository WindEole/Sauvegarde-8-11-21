/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_negative.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iderighe <iderighe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 14:52:30 by iderighe          #+#    #+#             */
/*   Updated: 2021/08/10 15:17:51 by iderighe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//void	ft_putchar(char c)
//{
//	write(1, &c, 1);
//}

void	ft_is_negative(int n)
{
	if (n >= 0)
	{
		ft_putchar('P');
	}
	else
	{
		ft_putchar('N');
	}
}

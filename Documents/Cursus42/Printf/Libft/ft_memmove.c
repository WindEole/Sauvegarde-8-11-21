/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iderighe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 15:02:34 by iderighe          #+#    #+#             */
/*   Updated: 2021/01/20 11:18:09 by iderighe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	*s;
	char	*d;

	s = (char *)src;
	d = (char *)dst;
	i = 0;
	if (!src && !dst)
		return (NULL);
	if (d > s)
		while (len > 0)
		{
			d[len - 1] = s[len - 1];
			len--;
		}
	else
		while (i < len)
		{
			d[i] = s[i];
			i++;
		}
	return (dst);
}

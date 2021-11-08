/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rballage <rballage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 19:32:36 by rballage          #+#    #+#             */
/*   Updated: 2021/09/09 12:01:57 by rballage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/client.h"

size_t	ft_strlen(const char *str)
{
	const char	*j;

	j = str;
	while (*str)
		str++;
	return ((size_t)(str - j));
}

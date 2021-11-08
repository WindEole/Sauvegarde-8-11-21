/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finished.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rballage <rballage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 15:17:18 by rballage          #+#    #+#             */
/*   Updated: 2021/09/08 15:19:01 by rballage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/client.h"

void	finished(int signal)
{
	(void)signal;
	quit("SUCCESS - DATA_RECEIVED\n", EXIT_SUCCESS);
}

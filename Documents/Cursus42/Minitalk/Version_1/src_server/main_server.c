/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_server.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rballage <rballage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 15:29:50 by rballage          #+#    #+#             */
/*   Updated: 2021/09/09 12:09:14 by rballage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/server.h"

int	main(void)
{
	struct sigaction	info;

	ft_memset(&info, 0, sizeof(info));
	info.sa_sigaction = &handler;
	info.sa_flags = SA_RESTART | SA_SIGINFO;
	sigemptyset(&info.sa_mask);
	ft_putstr("PID: ");
	ft_putnbr(getpid());
	ft_putchar('\n');
	sigaction(SIGUSR1, &info, NULL);
	sigaction(SIGUSR2, &info, NULL);
	while (1)
		;
	return (0);
}

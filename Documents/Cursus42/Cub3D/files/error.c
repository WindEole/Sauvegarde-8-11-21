/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogenser <ogenser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 12:00:34 by ogenser           #+#    #+#             */
/*   Updated: 2021/03/27 14:23:39 by ogenser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube3d.h"

void	ft_errorsuite(char *error)
{
	if (ft_strcmp(error, "directory") == 0)
		ft_putstr("Error:\nfile is a directory\n");
	else if (ft_strcmp(error, "open") == 0)
		ft_putstr("Error:\nopen\n");
	else if (ft_strcmp(error, "close") == 0)
		ft_putstr("Error:\nclose\n");
	else if (ft_strcmp(error, "arguments") == 0)
		ft_putstr("Error\ninvalid arguments\n");
	else if (ft_strcmp(error, "open") == 0)
		ft_putstr("Error:\nUnknown error");
	else if (ft_strcmp(error, "screensize") == 0)
		ft_putstr("Error:\nscreensize\n");
	else if (ft_strcmp(error, "char") == 0)
		ft_putstr("Error:\nwrong char in map\n");
	else if (ft_strcmp(error, "duplicate") == 0)
		ft_putstr("Error:\nsomething in config is duplicated\n");
	else if (ft_strcmp(error, "config") == 0)
		ft_putstr("Error:\nsomething in config file is broken\n");
	else if (ft_strcmp(error, "missing") == 0)
		ft_putstr("Error:\nsomething in config is missing\n");
	else if (ft_strcmp(error, "map open") == 0)
		ft_putstr("Error:\nmap is open\n");
}

int		ft_error(char *error, t_mother *s)
{
	ft_errorsuite(error);
	if (ft_strcmp(error, "color resolution") == 0)
		ft_putstr("Error:\ncolor does not exist\n");
	else if (ft_strcmp(error, "color") == 0)
		ft_putstr("Error:\ncolor problem\n");
	else if (ft_strcmp(error, "resolution too large") == 0)
		ft_putstr("Error:\nresolution too large\n");
	else if (ft_strcmp(error, "wrong char in file") == 0)
		ft_putstr("Error:\nwrong char in file\n");
	else if (ft_strcmp(error, "res") == 0)
		ft_putstr("Error:\nresolution\n");
	else if (ft_strcmp(error, "res is low") == 0)
		ft_putstr("Error:\nresolution is very low\n");
	else if (ft_strcmp(error, "xpm") == 0)
		ft_putstr("Error:\ntexture not .xpm, check end of line\n");
	else if (ft_strcmp(error, "multiplayer") == 0)
		ft_putstr("Error:\nmultiple player detected\n");
	else if (ft_strcmp(error, "no player") == 0)
		ft_putstr("Error:\nno player detected\n");
	else if (ft_strcmp(error, "malloc") == 0)
		ft_putstr("Error:\nmalloc\n");
	ft_esc(s);
	exit(0);
	return (0);
}

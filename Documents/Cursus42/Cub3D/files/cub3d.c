/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogenser <ogenser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 17:14:04 by ogenser           #+#    #+#             */
/*   Updated: 2021/03/25 21:08:24 by ogenser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube3d.h"

void	ft_rotate(t_mother *s, int side)
{
	double	tmpdirx;
	double	tmpplanex;

	tmpdirx = s->img.dirx;
	tmpplanex = s->ray.planex;
	if (side == 'r')
	{
		s->img.dirx = s->img.dirx * cos(-RSPEED) - s->img.diry * sin(-RSPEED);
		s->img.diry = tmpdirx * sin(-RSPEED) + s->img.diry * cos(-RSPEED);
		s->ray.planex = s->ray.planex * cos(-RSPEED)
			- s->ray.planey * sin(-RSPEED);
		s->ray.planey = tmpplanex * sin(-RSPEED) + s->ray.planey * cos(-RSPEED);
	}
	if (side == 'l')
	{
		s->img.dirx = s->img.dirx * cos(RSPEED) - s->img.diry * sin(RSPEED);
		s->img.diry = tmpdirx * sin(RSPEED) + s->img.diry * cos(RSPEED);
		s->ray.planex = s->ray.planex * cos(RSPEED)
			- s->ray.planey * sin(RSPEED);
		s->ray.planey = tmpplanex * sin(RSPEED) + s->ray.planey * cos(RSPEED);
	}
	raycaster(s);
}

void	ft_checkdirectory(int fd, char *mapfile, t_mother *s)
{
	fd = 0;
	if ((fd = open(mapfile, O_DIRECTORY)) != -1)
		ft_error("directory", s);
}

int		key_hook(int keycode, t_mother *s)
{
	if (keycode == 65362 || keycode == 119)
		ft_deplacements('w', s);
	else if (keycode == 65364 || keycode == 115)
		ft_deplacements('s', s);
	else if (keycode == 97)
		ft_deplacements('a', s);
	else if (keycode == 100)
		ft_deplacements('d', s);
	else if (keycode == 65363)
		ft_rotate(s, 'r');
	else if (keycode == 65361)
		ft_rotate(s, 'l');
	else if (keycode == 113 || keycode == 65307)
		ft_esc(s);
	return (1);
}

int		main(int ac, char **av)
{
	(void)av;
	if (ac == 2 && argcheck(av[1], 1))
		structinit(av[1], 0);
	else if (ac == 3 && argcheck(av[1], 1) && argcheck(av[2], 2))
		structinit(av[1], 1);
	else
		ft_putstr("Error\ninvalid arguments\n");
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogenser <ogenser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 15:45:13 by ogenser           #+#    #+#             */
/*   Updated: 2021/04/02 17:22:28 by ogenser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube3d.h"

void	ft_esc(t_mother *s)
{
	int		i;

	i = s->map.mapstart - 1;
	if (s->tex.no != NULL && s->tex.so != NULL && s->tex.ea != NULL &&
				s->tex.we != NULL && s->tex.s != NULL)
		while (++i < s->map.linenb)
			free(s->map.map[i]);
	if (s->spr.y)
		free(s->spr.y);
	s->spr.y = NULL;
	if (s->spr.x)
		free(s->spr.x);
	s->spr.x = NULL;
	if (s->img.ptrimg)
		mlx_destroy_image(s->win.ptrmlx, s->img.ptrimg);
	s->img.ptrimg = NULL;
	ft_bye(s);
	ft_echap(s);
	exit(0);
}

void	ft_movew(t_mother *s)
{
	int		minwalldist;

	minwalldist = 2;
	if (s->map.map[(int)(s->ply.px + s->img.dirx * MSPEED)]
		[(int)s->ply.py] == '0')
		s->ply.px += s->img.dirx * MSPEED / minwalldist;
	if (s->map.map[(int)s->ply.px]
		[(int)(s->ply.py + s->img.diry * MSPEED)] == '0')
		s->ply.py += s->img.diry * MSPEED / minwalldist;
}

void	ft_moves(t_mother *s)
{
	int		minwalldist;

	minwalldist = 2;
	if (s->map.map[(int)(s->ply.px - s->img.dirx * MSPEED)]
		[(int)s->ply.py] == '0')
		s->ply.px -= s->img.dirx * MSPEED / minwalldist;
	if (s->map.map[(int)s->ply.px]
		[(int)(s->ply.py - (s->img.diry * MSPEED))] == '0')
		s->ply.py -= s->img.diry * MSPEED / minwalldist;
}

void	ft_movea(t_mother *s)
{
	int		minwalldist;

	minwalldist = 2;
	if (s->map.map[(int)(s->ply.px - s->img.diry * MSPEED)]
		[(int)s->ply.py] == '0')
		s->ply.px -= s->img.diry * MSPEED / minwalldist;
	if (s->map.map[(int)s->ply.px]
		[(int)(s->ply.py + s->img.dirx * MSPEED)] == '0')
		s->ply.py += s->img.dirx * MSPEED / minwalldist;
}

void	ft_deplacements(int key, t_mother *s)
{
	int minwalldist;

	minwalldist = 2;
	if (key == 'w')
		ft_movew(s);
	if (key == 's')
		ft_moves(s);
	if (key == 'd')
	{
		if (s->map.map[(int)(s->ply.px + s->img.diry * MSPEED)]
			[(int)s->ply.py] == '0')
			s->ply.px += s->img.diry * MSPEED / minwalldist;
		if (s->map.map[(int)s->ply.px]
			[(int)(s->ply.py - s->img.dirx * MSPEED)] == '0')
			s->ply.py -= s->img.raydirx * MSPEED / minwalldist;
	}
	if (key == 'a')
		ft_movea(s);
	raycaster(s);
}

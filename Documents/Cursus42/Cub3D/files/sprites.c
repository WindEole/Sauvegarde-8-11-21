/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogenser <ogenser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 14:16:42 by ogenser           #+#    #+#             */
/*   Updated: 2021/04/02 17:36:41 by ogenser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube3d.h"

void	ft_parsesprites(t_mother *s)
{
	int		i;
	int		j;
	int		tmp;
	double	tmpxy;

	i = 0;
	ft_parsespriteinit(s);
	while (i < s->spr.nbr - 1)
	{
		j = -1;
		while (++j < s->spr.nbr - 1)
			if (s->spr.sprdist[j] < s->spr.sprdist[j + 1])
			{
				tmp = s->spr.sprdist[j];
				s->spr.sprdist[j] = s->spr.sprdist[j + 1];
				s->spr.sprdist[j + 1] = tmp;
				tmpxy = s->spr.x[j];
				s->spr.x[j] = s->spr.x[j + 1];
				s->spr.x[j + 1] = tmpxy;
				tmpxy = s->spr.y[j];
				s->spr.y[j] = s->spr.y[j + 1];
				s->spr.y[j + 1] = tmpxy;
			}
		i++;
	}
}

void	ft_sprcalcul(t_mother *s)
{
	s->spr.invdet = 1.0
		/ (s->ray.planex * s->img.diry - s->img.dirx * s->ray.planey);
	s->spr.zx = s->spr.invdet
		* (s->img.diry * s->spr.sprx - s->img.dirx * s->spr.spry);
	s->spr.zy = s->spr.invdet
		* (-s->ray.planey * s->spr.sprx + s->ray.planex * s->spr.spry);
	s->spr.spritesx = (int)((s->win.winwidth / 2)
		* (1 + s->spr.zx / s->spr.zy));
	s->spr.sprheight = (int)(s->win.winheight / s->spr.zy);
	s->spr.drawsy = -s->spr.sprheight / 2 + s->win.winheight / 2;
	if (s->spr.drawsy < 0)
		s->spr.drawsy = 0;
	s->spr.drawey = s->spr.sprheight / 2 + s->win.winheight / 2;
	if (s->spr.drawey >= s->win.winheight)
		s->spr.drawey = s->win.winheight - 1;
	s->spr.sprwidth = (int)(s->win.winheight / s->spr.zy);
	s->spr.drawsx = -s->spr.sprwidth / 2 + s->spr.spritesx;
	if (s->spr.drawsx < 0)
		s->spr.drawsx = 0;
	s->spr.drawex = s->spr.sprwidth / 2 + s->spr.spritesx;
	if (s->spr.drawex >= s->win.winwidth)
		s->spr.drawex = s->win.winwidth - 1;
	s->spr.stripe = s->spr.drawsx;
}

void	ft_sprdrawinit(t_mother *s)
{
	s->spr.texx = (int)(256 *
		(s->spr.stripe - (-s->spr.sprwidth / 2 + s->spr.spritesx))
		* s->spr.width / s->spr.sprwidth) / 256;
	s->spr.k = s->spr.drawsy;
	if (s->spr.zy > 0 && s->spr.stripe >= 0
		&& s->spr.stripe < s->win.winwidth
		&& s->spr.zy < s->spr.distbuffer[s->spr.stripe])
		while (s->spr.k < s->spr.drawey)
			ft_sprdraw(s);
	s->spr.stripe++;
}

void	ft_sprites(t_mother *s)
{
	int i;

	s->spr.stripe = 0;
	ft_sprassign(s);
	ft_parsesprites(s);
	i = 0;
	while (i < s->spr.nbr)
	{
		s->spr.sprx = s->spr.x[i] - s->ply.px + 0.5;
		s->spr.spry = s->spr.y[i] - s->ply.py + 0.5;
		ft_sprcalcul(s);
		while (s->spr.stripe < s->spr.drawex)
			ft_sprdrawinit(s);
		i++;
	}
	if (s->spr.distbuffer)
		free(s->spr.distbuffer);
	s->spr.distbuffer = NULL;
	if (s->spr.sprdist)
		free(s->spr.sprdist);
	if (s->spr.sprorder)
		free(s->spr.sprorder);
	if (s->tex.ptr)
		mlx_destroy_image(s->win.ptrmlx, s->tex.ptr);
}

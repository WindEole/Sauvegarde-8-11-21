/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structinit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogenser <ogenser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 21:00:15 by ogenser           #+#    #+#             */
/*   Updated: 2021/03/25 21:06:29 by ogenser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube3d.h"

void	structinitmapply(t_mother *s, char *mapfile)
{
	s->map.map = NULL;
	s->map.mapstart = -1;
	s->map.linenb = 0;
	s->map.linesize = 0;
	s->map.colnb = 0;
	s->map.maplinesize = 0;
	s->map.errormap = -1;
	s->ply.px = 1;
	s->ply.py = 1;
	s->ply.rotation = 0;
	s->ray.rayi = 0;
	s->ray.hit = 0;
	s->img.camerax = 0;
	s->ray.planex = 0;
	s->ray.planey = 0;
	mapcheck(mapfile, s);
}

void	structinitimg(t_mother *s, char *mapfile)
{
	s->img.dirx = 0;
	s->img.diry = 0;
	s->img.ptrimg = NULL;
	s->img.adress = NULL;
	s->img.raydirx = 0;
	s->img.raydiry = 0;
	s->img.sidedistx = 0;
	s->img.sidedisty = 0;
	s->img.stepx = 0;
	s->img.stepy = 0;
	s->img.deltadistx = 0;
	s->img.deltadisty = 0;
	s->img.perpwalldist = 0;
	s->img.side = 0;
	s->img.lineheight = 0;
	s->img.mapx = 0;
	s->img.mapy = 0;
	s->img.drawstart = 0;
	s->img.drawend = 0;
	s->img.color = 0;
	structinitmapply(s, mapfile);
}

void	structinittex(t_mother *s, char *mapfile)
{
	s->tex.tex = NULL;
	s->tex.no = NULL;
	s->tex.so = NULL;
	s->tex.s = NULL;
	s->tex.ea = NULL;
	s->tex.we = NULL;
	s->tex.height = 0;
	s->tex.width = 0;
	s->tex.endian = 0;
	s->tex.ptr = NULL;
	s->tex.adress = NULL;
	s->tex.bits = 0;
	s->tex.linesize = 0;
	s->tex.y = 0;
	s->tex.color = 0;
	s->tex.wallhit = 0;
	s->tex.texx = 0;
	s->tex.texy = 0;
	s->tex.step = 0;
	s->tex.position = 0;
	s->tex.c = 0;
	s->tex.f = 0;
	structinitimg(s, mapfile);
}

void	structinitspr2(t_mother *s, char *mapfile)
{
	s->spr.color = 0;
	s->spr.adress = NULL;
	s->spr.sprx = 0;
	s->spr.spry = 0;
	s->spr.texy = 0;
	s->spr.d = 0;
	s->spr.invdet = 0;
	s->spr.zx = 0;
	s->spr.zy = 0;
	s->spr.spritesx = 0;
	s->spr.sprheight = 0;
	s->spr.drawsy = 0;
	s->spr.drawey = 0;
	s->spr.sprwidth = 0;
	s->spr.drawsx = 0;
	s->spr.drawex = 0;
	s->spr.stripe = 0;
	s->spr.texx = 0;
	s->spr.k = 0;
	s->spr.nbr = 0;
	s->spr.distbuffer = NULL;
	structinittex(s, mapfile);
}

void	structinitspr(t_mother *s, char *mapfile)
{
	t_raycast	ray;
	t_image		img;
	t_textures	tex;
	t_sprites	spr;

	tex.c = 0;
	img.side = 0;
	spr.k = 0;
	ray.hit = 0;
	s->tex = tex;
	s->img = img;
	s->spr = spr;
	s->ray = ray;
	s->spr.stex = 0;
	s->spr.x = NULL;
	s->spr.y = NULL;
	s->spr.tex = NULL;
	s->spr.sprdist = NULL;
	s->spr.sprorder = NULL;
	s->spr.height = 0;
	s->spr.width = 0;
	s->spr.endian = 0;
	s->spr.bits = 0;
	s->spr.linesize = 0;
	structinitspr2(s, mapfile);
}

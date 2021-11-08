/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogenser <ogenser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 00:06:07 by ogenser           #+#    #+#             */
/*   Updated: 2021/04/02 18:20:44 by ogenser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H

# include "../minilibx-linux/mlx.h"
# include "get_next_line.h"
# include <unistd.h>
# include <math.h>
# include <stdio.h>

# define WHITE 16777215
# define BLUE 255
# define RED 16711680
# define GREEN 0x0000FF00
# define YELLOW 0xFFFF00
# define RSPEED 0.1
# define MSPEED 0.3

typedef struct	s_window
{
	int				y;
	void			*ptr;
	void			*ptrmlx;
	int				winwidth;
	int				winheight;
	char			*title;
}				t_window;

typedef struct	s_map
{
	int				mapstart;
	int				linesize;
	int				maplinesize;
	int				linenb;
	int				colnb;
	int				save;
	int				errormap;
	char			**map;
}				t_map;

typedef struct	s_player
{
	double			px;
	double			py;
	int				rotation;
}				t_player;

typedef struct	s_image
{
	void			*ptrimg;
	void			*adress;
	int				bits;
	int				linesize;
	double			camerax;
	double			dirx;
	double			diry;
	double			raydirx;
	double			raydiry;
	double			sidedistx;
	double			sidedisty;
	int				stepx;
	int				stepy;
	double			deltadistx;
	double			deltadisty;
	double			perpwalldist;
	int				side;
	int				drawstart;
	int				drawend;
	int				lineheight;
	int				mapx;
	int				mapy;
	unsigned int	color;
}				t_image;

typedef struct	s_raycast
{
	int				rayi;
	int				hit;
	double			planex;
	double			planey;
}				t_raycast;

typedef struct	s_textures
{
	char			*no;
	char			*so;
	char			*ea;
	char			*we;
	char			*s;
	unsigned int	f;
	unsigned int	c;
	unsigned int	*tex;
	int				height;
	int				width;
	int				endian;
	void			*ptr;
	char			*adress;
	int				bits;
	int				linesize;
	int				y;
	int				color;
	int				texx;
	int				texy;
	double			wallhit;
	double			step;
	double			position;
}				t_textures;

typedef struct	s_sprites
{
	int				*sprorder;
	int				*sprdist;
	unsigned int	*stex;
	char			*tex;
	double			*x;
	double			*y;
	int				nbr;
	double			*distbuffer;
	int				height;
	int				width;
	int				endian;
	int				bits;
	int				linesize;
	int				color;
	char			*adress;
	float			sprx;
	float			spry;
	int				texy;
	int				d;

	double			invdet;
	double			zx;
	double			zy;
	int				spritesx;
	int				sprheight;

	int				drawsy;
	int				drawey;
	int				sprwidth;
	int				drawsx;
	int				drawex;
	int				stripe;
	int				texx;
	int				k;
}				t_sprites;

typedef struct	s_mother
{
	t_map			map;
	t_image			img;
	t_player		ply;
	t_window		win;
	t_raycast		ray;
	t_textures		tex;
	t_sprites		spr;
}				t_mother;

void			structinit(char *mapfile, int save);
int				argcheck(char *av, int cas);
void			ft_putstr(char *s);
void			mapcheck(char *mapfile, t_mother *s);
int				ft_error(char *error, t_mother *s);
int				ft_strcmp(char *s1, char *s2);
void			ft_minimap(t_mother s);
int				ft_strcmp(char *s1, char *s2);
void			ft_deplacements(int key, t_mother *s);
void			ft_esc(t_mother *s);
void			raycaster(t_mother *s);
void			verticalline(int drawstart, int drawend, int color,
					t_mother *s);
void			ft_floor(t_mother *s, int drawend);
void			ft_ceiling(t_mother *s, int drawstart);
int				key_hook(int keycode, t_mother *s);
void			ray(t_mother *s);
void			ft_textures(t_mother *s);
void			ftmlxpixel(t_mother *s, int x, int y, int color);
int				getimgpixel(int x, int y, char *adress, int bits);
void			verticalline2(t_mother *s, unsigned int *texture);
void			ft_save(t_mother *s);
void			ft_sprites(t_mother *s);
void			ft_getmapargs(t_mother *s, char *line);
int				ft_atoi(const char *str, int *i);
void			ft_rotate(t_mother *s, int side);
int				ft_space(char str);
void			ft_parsesprites(t_mother *s);
void			ft_missing(t_mother *s);
void			floodinit(t_mother *s);
int				ft_mapparse(t_mother *s, char *mapfile);
void			ft_mapclose(t_mother *s);
void			ft_ismapopen(t_mother *s);
int				parseline(char *line, t_mother *s, int nbline);
void			ft_strcpy(char *dest, char *src, int *j);
void			ft_sprcpy(char *dest, char *src, int *j);
void			ft_color(t_mother *s, char *line, char c);
void			ft_colorcheck(t_mother *s, char *line);
int				ft_screensize(t_mother *s, char *line);
void			ft_parsespriteinit(t_mother *s);
void			ft_sprassign(t_mother *s);
void			ft_sprdraw(t_mother *s);
void			ft_checkdirectory(int fd, char *mapfile, t_mother *s);
void			structinitspr(t_mother *s, char *mapfile);
void			structinitspr2(t_mother *s, char *mapfile);
void			structinittex(t_mother *s, char *mapfile);
void			structinitimg(t_mother *s, char *mapfile);
void			structinitmapply(t_mother *s, char *mapfile);
int				ft_isamap(t_mother *s);
int				ft_screenresize(t_mother *s);
void			ft_checkassign(t_mother *s);
int				getimgpixel1(t_mother *s, int x, int y, char *adress);
int				looper(t_mother *s);
int				ft_screenresize(t_mother *s);
int				ft_exit(t_mother *s);
void			ft_distbuf(t_mother *s);
void			ft_missing(t_mother *s);
void			ft_bye(t_mother *s);
void			ft_echap(t_mother *s);
void			plyparse(t_mother *s, int i, int j);
void			ft_mapimalloc(t_mother *s, int i, char *line);
int				ft_mapfill(t_mother *s, char *line, int i);
void			raycastfree(t_mother *s);

#endif

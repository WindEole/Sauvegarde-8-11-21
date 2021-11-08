/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseutils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogenser <ogenser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 10:39:48 by ogenser           #+#    #+#             */
/*   Updated: 2021/04/02 17:39:26 by ogenser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube3d.h"

void	ft_remp(t_mother *s, char c, char *line)
{
	int		j;

	j = 3;
	if (c == 'N')
	{
		if (!(s->tex.no = (char *)malloc(sizeof(char) * ft_strlen(line) - 2)))
			ft_error("malloc", s);
		ft_strcpy(s->tex.no, line, &j);
	}
	if (c == 'S')
	{
		if (!(s->tex.so = (char *)malloc(sizeof(char) * ft_strlen(line) - 2)))
			ft_error("malloc", s);
		ft_strcpy(s->tex.so, line, &j);
	}
	if (c == 'W')
	{
		if (!(s->tex.we = (char *)malloc(sizeof(char) * ft_strlen(line) - 2)))
			ft_error("malloc", s);
		ft_strcpy(s->tex.we, line, &j);
	}
}

void	ft_remplissage(t_mother *s, char c, char *line)
{
	int		j;
	int		i;

	j = 3;
	i = ft_strlen(line);
	if (line[i - 1] != 'm' || line[i - 2] != 'p'
		|| line[i - 3] != 'x' || line[i - 4] != '.')
		ft_error("xpm", s);
	ft_remp(s, c, line);
	if (c == 'E')
	{
		if (!(s->tex.ea = (char *)malloc(sizeof(char) * ft_strlen(line) - 2)))
			ft_error("malloc", s);
		ft_strcpy(s->tex.ea, line, &j);
	}
	j--;
	if (c == 'P')
	{
		if (!(s->tex.s = (char *)malloc(sizeof(char) * ft_strlen(line) - 1)))
			ft_error("malloc", s);
		ft_strcpy(s->tex.s, line, &j);
	}
}

void	argduplicate(t_mother *s, char linei, char lineione)
{
	if (linei == 'N' && s->tex.no != NULL)
		ft_error("duplicate", s);
	if ((linei == 'R' && lineione == ' ')
		&& (s->win.winheight != 0 || s->win.winwidth != 0))
		ft_error("duplicate", s);
	if ((linei == 'S' && lineione == 'O') && s->tex.so != NULL)
		ft_error("duplicate", s);
	if ((linei == 'S' && lineione == ' ') && s->tex.s != NULL)
		ft_error("duplicate", s);
	if (linei == 'E' && s->tex.ea != NULL)
		ft_error("duplicate", s);
	if (linei == 'W' && s->tex.we != NULL)
		ft_error("duplicate", s);
	if (linei == 'C' && s->tex.c != 0)
		ft_error("duplicate", s);
	if (linei == 'F' && s->tex.f != 0)
		ft_error("duplicate", s);
}

void	ft_getcolorargs(t_mother *s, char linei, char lineione, char *line)
{
	if (linei == 'S' && lineione == ' ' && s->tex.s == NULL)
		ft_remplissage(s, 'P', line);
	if (linei == 'F' && lineione == ' ' && s->tex.f == 0)
		ft_color(s, line, 'F');
	if (linei == 'C' && lineione == ' ' && s->tex.c == 0)
		ft_color(s, line, 'C');
}

void	ft_getmapargs(t_mother *s, char *line)
{
	int		i;

	i = 0;
	while (i < s->map.linesize && ft_space(line[i]) == 1)
		i++;
	if (line[i] != '\0')
		argduplicate(s, line[i], line[i + 1]);
	if (line[i] == 'R' && line[i + 1] == ' '
		&& (s->win.winheight == 0 || s->win.winwidth == 0))
		ft_screensize(s, line);
	if (line[i] == 'N' && line[i + 1] == 'O'
		&& line[i + 2] == ' ' && s->tex.no == NULL)
		ft_remplissage(s, 'N', line);
	if (line[i] == 'S' && line[i + 1] == 'O'
		&& line[i + 2] == ' ' && s->tex.so == NULL)
		ft_remplissage(s, 'S', line);
	if (line[i] == 'W' && line[i + 1] == 'E'
		&& line[i + 2] == ' ' && s->tex.we == NULL)
		ft_remplissage(s, 'W', line);
	if (line[i] == 'E' && line[i + 1] == 'A'
		&& line[i + 2] == ' ' && s->tex.ea == NULL)
		ft_remplissage(s, 'E', line);
	if (line[i] != '\0')
		ft_getcolorargs(s, line[i], line[i + 1], line);
}

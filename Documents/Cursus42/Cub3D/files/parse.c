/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogenser <ogenser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 13:41:21 by ogenser           #+#    #+#             */
/*   Updated: 2021/04/02 17:28:59 by ogenser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube3d.h"

void	ft_linetooshort(t_mother *s)
{
	int		i;
	int		j;

	i = s->map.mapstart;
	while (i < s->map.linenb)
	{
		j = 0;
		while (j < s->map.linesize - 1 && s->map.map[i][j] != '\0')
		{
			if ((s->map.map[i][j] == '0' ||
				s->map.map[i][j] == '2') &&
				s->map.map[i][j + 1] == '\0' && j < s->map.linesize)
				ft_error("map open", s);
			j++;
		}
		i++;
	}
}

void	ft_assymetrie(t_mother *s)
{
	int		i;
	int		actualline;
	int		nextline;
	int		previousline;

	actualline = 0;
	nextline = 0;
	previousline = 0;
	i = s->map.mapstart;
	nextline = ft_strlen(s->map.map[i + 1]);
	while (i < s->map.linenb && nextline != 0)
	{
		actualline = ft_strlen(s->map.map[i]);
		if (i < s->map.linenb - 1)
			nextline = ft_strlen(s->map.map[i + 1]);
		previousline = ft_strlen(s->map.map[i - 1]);
		if (s->map.map[i][actualline - 2] != '1' && ((nextline <
		actualline - 1) || (previousline < actualline - 1)))
			ft_error("map open", s);
		if (s->map.map[i][actualline - 1] != '1'
			&& (nextline == actualline || actualline == previousline))
			ft_error("map open", s);
		i++;
	}
	ft_linetooshort(s);
}

void	mapcheckcall(t_mother *s, char *mapfile)
{
	if (!(s->spr.y = malloc(sizeof(double *) * s->spr.nbr)))
		ft_error("malloc", s);
	if (!(s->spr.x = malloc(sizeof(double *) * s->spr.nbr)))
		ft_error("malloc", s);
	s->spr.nbr = 0;
	ft_mapparse(s, mapfile);
	ft_missing(s);
	floodinit(s);
	ft_assymetrie(s);
	s->win.ptrmlx = mlx_init();
	ft_screenresize(s);
	if (s->map.save != 1)
		s->win.ptr = mlx_new_window(s->win.ptrmlx,
			s->win.winwidth, s->win.winheight, s->win.title);
	ft_sprassign(s);
	raycaster(s);
}

void	mapcheckinfo(t_mother *s, char *line)
{
	int		j;

	s->map.linenb++;
	if ((size_t)s->map.linesize < ft_strlen(line))
		s->map.linesize = ft_strlen(line);
	if ((size_t)s->map.maplinesize < ft_strlen(line)
		&& (line[0] == '1' || line[1] == '1' || line[3] == '1'))
		s->map.maplinesize = ft_strlen(line);
	if (line[0] == '1' && s->map.mapstart == -1)
		s->map.mapstart = s->map.linenb - 1;
	if (line[0] == '1')
		s->map.errormap++;
	j = 0;
	while (line[j])
	{
		if (line[j] == '2')
			s->spr.nbr++;
		j++;
	}
}

void	mapcheck(char *mapfile, t_mother *s)
{
	int		fd;
	char	*line;
	int		ret;

	fd = 0;
	ft_checkdirectory(fd, mapfile, s);
	if (!(fd = open(mapfile, O_RDONLY)) || (fd == -1))
		ft_error("open", s);
	ret = 1;
	while (ret > 0)
	{
		ret = get_next_line(fd, &line);
		mapcheckinfo(s, line);
		free(line);
	}
	if (s->map.errormap < 2)
		ft_error("missing", s);
	if (!(s->map.map = malloc(sizeof(char *) * s->map.linenb + 2)))
		ft_error("malloc", s);
	if (close(fd) == -1)
		ft_error("close", s);
	mapcheckcall(s, mapfile);
}

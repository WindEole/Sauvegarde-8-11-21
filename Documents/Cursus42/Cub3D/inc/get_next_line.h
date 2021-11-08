/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogenser <ogenser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/01 12:47:40 by ogenser           #+#    #+#             */
/*   Updated: 2021/02/18 16:41:29 by ogenser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <stdio.h>

# define BUFFER_SIZE 1

typedef	struct	s_list
{
	char	*stock;
	int		rid;
	char	buffer[BUFFER_SIZE + 1];
}				t_list;

int				get_next_line(int fd, char **line);
char			*ft_substr(char *s, unsigned int start, size_t len);
char			*ft_strjoin(char *s1, char *s2);
int				line_size(char *s);
int				ft_assign_strs(t_list *mother, char **rest, char **line);
size_t			ft_strlen(const char *s);

#endif

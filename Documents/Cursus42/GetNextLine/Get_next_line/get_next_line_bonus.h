/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iderighe <iderighe@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 17:22:51 by iderighe          #+#    #+#             */
/*   Updated: 2021/06/04 14:40:10 by iderighe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

int		get_next_line(int fd, char **line);
int		ft_check_n(char *str);
char	*ft_saver(char *str);
char	*ft_strcut(char *str);
int		ft_strlen(char *s);
int		ft_strn(char *s);
char	*ft_strjoin(char *s1, char *s2);

#endif

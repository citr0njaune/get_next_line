/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chphan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 14:51:09 by chphan            #+#    #+#             */
/*   Updated: 2024/12/19 14:51:12 by chphan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdio.h>
# include <stdlib.h>
# include <stddef.h>
# include <string.h>
# include <unistd.h>
# include <stddef.h>

size_t	ft_strlen(const char *str);
int		im_detected(char *stash);
char	*ft_strjoin(char *s1, char *s2);

char	*read_file(int fd, char *stash);
char	*get_save(char *stash);
char	*get_lineuh(char *stash);
char	*get_next_line(int fd);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

#endif

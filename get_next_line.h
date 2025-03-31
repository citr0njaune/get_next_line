/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chphan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 16:49:56 by chphan            #+#    #+#             */
/*   Updated: 2024/12/12 16:49:59 by chphan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

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

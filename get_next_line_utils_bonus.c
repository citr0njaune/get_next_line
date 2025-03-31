/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chphan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 14:51:28 by chphan            #+#    #+#             */
/*   Updated: 2024/12/19 14:51:31 by chphan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

int	im_detected(char *stash)
{
	int	i;

	i = 0;
	if (!stash)
		return (0);
	while (stash[i])
	{
		if (stash[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	char	*final;
	int		stot_len;

	i = 0;
	if (!s1)
	{
		s1 = malloc(sizeof(char));
		s1[0] = '\0';
	}
	stot_len = ft_strlen(s1) + ft_strlen(s2) + 1;
	final = malloc(stot_len * sizeof(char));
	if (!final || !s1 || !s2)
		return (0);
	while (i != (ft_strlen(s1) + ft_strlen(s2)))
	{
		if (i < ft_strlen(s1))
			final[i] = s1[i];
		else
			final[i] = s2[i - ft_strlen(s1)];
		i++;
	}
	free(s1);
	final[i] = '\0';
	return (final);
}

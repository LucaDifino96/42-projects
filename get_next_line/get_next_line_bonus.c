/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldifino <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 12:51:30 by ldifino           #+#    #+#             */
/*   Updated: 2023/04/14 14:20:49 by ldifino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_read(int fd, char *str)
{
	char	*ptr;
	int		i;

	ptr = (char *)malloc(BUFFER_SIZE + 1);
	if (!ptr)
		return (0);
	i = 1;
	while (!ft_strchr(str) && i != 0)
	{
		i = read(fd, ptr, BUFFER_SIZE);
		if (i == -1)
		{
			free(ptr);
			return (str);
		}
		ptr[i] = '\0';
		str = ft_strjoin(str, ptr);
	}
	free(ptr);
	if (str[0] == '\0')
	{
		free(str);
		return (0);
	}
	return (str);
}

char	*get_next_line(int fd)
{
	char static	*ptr[4096];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	ptr[fd] = ft_read(fd, ptr[fd]);
	if (!ptr[fd])
		return (0);
	line = ft_write(ptr[fd]);
	ptr[fd] = ft_reset(ptr[fd]);
	return (line);
}

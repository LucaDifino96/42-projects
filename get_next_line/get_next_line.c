/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldifino <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 18:03:09 by ldifino           #+#    #+#             */
/*   Updated: 2023/04/12 19:46:41 by ldifino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>

size_t	*ft_read(int fd, char *str)
{
	char	*ptr;
	int		i;

	ptr = malloc(BUFFER_SIZE + 1);
	if (!ptr)
		return (NULL);
	i = 1;
	while (!ft_strchr(str, '\n') && i != 0)
	{
		i = read(fd, &str, BUFFER_SIZE);
		if (i == -1)
		{
			free(ptr);
			return (NULL);
		}
		ptr[i] = '\0';
		str = ft_strjoin(str, ptr);
	}
	free(ptr);
	return (str);
}

char	*get_next_line(int fd)
{
	char static	*ptr;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	ptr = ft_read(fd, ptr);
	if (!ptr)
		return (NULL);
	line = ft_write(ptr);
	ptr = ft_res(ptr);
	return (line);
}

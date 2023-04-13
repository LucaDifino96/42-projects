/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldifino <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 12:51:24 by ldifino           #+#    #+#             */
/*   Updated: 2023/04/13 21:09:23 by ldifino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == ('\n'))
			return (&s[i]);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*ptr;

	i = 0;
	if (!s1)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	ptr = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!ptr)
		return (0);
	while (s1[i++] != 0)
		ptr[i] = s1[i];
	j = 0;
	while (s2[j] != 0)
		ptr[i++] = s2[j++];
	ptr[i] = '\0';
	free(s1);
	return (ptr);
}

char	*ft_write(char *str)
{
	char	*mal;
	int		i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	mal = (char *)malloc(sizeof(char) * (i + 2));
	if (!mal)
		return (0);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		mal[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		mal[i] = str[i];
		i++;
	}
	mal[i] = '\0';
	return (mal);
}

char	*ft_reset(char *str)
{
	char	*mal;
	int		i;
	int		j;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	mal = (char *)malloc(sizeof(char *) * ((ft_strlen(str) - i) + 1));
	if (!mal)
		return (NULL);
	i++;
	j = 0;
	while (str[i])
		mal[j++] = str[i++];
	mal[j] = '\0';
	free(str);
	return (mal);
}

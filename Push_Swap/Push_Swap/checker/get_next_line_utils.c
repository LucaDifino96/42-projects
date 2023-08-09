/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldifino <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 14:27:59 by ldifino           #+#    #+#             */
/*   Updated: 2023/04/14 12:34:10 by ldifino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker/checker.h"

size_t	strlen1(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*strchr1(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
	{
		if (s[i] == ('\n'))
			return (&s[i]);
		i++;
	}
	return (0);
}

char	*strjoin1(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*ptr;

	if (!s1)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (0);
	ptr = (char *)malloc((strlen1(s1) + strlen1(s2) + 1) * sizeof(char));
	if (!ptr)
		return (0);
	i = -1;
	while (s1[++i] != 0)
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
		return (0);
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
	mal = (char *)malloc(sizeof(char *) * (strlen1(str) - i + 1));
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

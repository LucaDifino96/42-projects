/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldifino <ldifino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 16:34:26 by ldifino           #+#    #+#             */
/*   Updated: 2023/07/15 14:09:53 by ldifino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*ptr;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	ptr = malloc((ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (!ptr)
		return (0);
	while (s1[i] != 0)
	{
		ptr[i] = *(s1 + i);
		i++;
	}
	j = 0;
	while (s2[j] != 0)
	{
		ptr[i] = *(s2 + j);
		j++;
		i++;
	}
	free((void *)s1);
	ptr[i] = '\0';
	return (ptr);
}

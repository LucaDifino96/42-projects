/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldifino <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 18:14:52 by ldifino           #+#    #+#             */
/*   Updated: 2023/04/06 15:33:41 by ldifino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*mal;

	mal = (t_list *)malloc(sizeof(t_list));
	if (!mal)
		return (NULL);
	mal->content = content;
	mal->next = NULL;
	return (mal);
}

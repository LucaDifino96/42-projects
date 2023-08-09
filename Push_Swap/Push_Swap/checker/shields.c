/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shield.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldifino <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 16:53:29 by ldifino           #+#    #+#             */
/*   Updated: 2023/07/05 16:53:32 by ldifino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker/checker.h"

t_listlink	*move_on_first(t_listlink *stack)
{
	while (stack->index != 1)
		stack = stack->next;
	return (stack);
}

void	error(void)
{
	ft_printf("Error");
	exit(1);
}

void	free1(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
}

void	delete_list(t_listlink *stack_a)
{
	t_listlink	*tmp;

	while (stack_a->index != 1)
	{
		tmp = stack_a;
		stack_a = stack_a->next;
		free(tmp);
	}
	free(stack_a);
}

void	error2(char **helper, t_listlink *stack_a, int flag)
{
	if (flag == 1)
	{
		(void)stack_a;
		free1(helper);
	}
	else
	{
		delete_list(stack_a);
		free1(helper);
	}
	ft_printf("Error");
	exit(1);
}

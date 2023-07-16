/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shield.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldifino <ldifino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 15:06:26 by ldifino           #+#    #+#             */
/*   Updated: 2023/07/16 14:59:15 by ldifino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	error1(char **helper, t_listlink *stack_a, int flag)
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

void	finalfree(t_listlink **stack_a, t_listlink **stack_b)
{
	*stack_a = move_on_first(*stack_a);
	delete_list((*stack_a)->next);
	*stack_b = move_on_first(*stack_b);
	if ((*stack_b)->next == NULL)
		free(*stack_b);
	else
		delete_list((*stack_b)->next);
	exit (1);
}

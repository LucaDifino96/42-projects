/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shield02.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldifino <ldifino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 14:59:01 by ldifino           #+#    #+#             */
/*   Updated: 2023/07/16 14:59:19 by ldifino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_listlink	*move_on_first(t_listlink *stack)
{
	while (stack->index != 1)
		stack = stack->next;
	return (stack);
}

void	print_nodes(t_listlink *stack, int j)
{
	while (stack->index != j)
	{
		printf("content : %d\nindex : %d\n", stack->content, stack->index);
		stack = stack->next;
	}
	if (stack->next == NULL)
		printf("stack é vuoto\n");
	else
	{
		printf("content : %d\nindex : %d\n", stack->content, stack->index);
	}
}

void	check_order(t_listlink **stack_a, t_listlink **stack_b)
{
	while ((*stack_a)->index != move_on_first(*stack_a)->before->index)
	{
		if ((*stack_a)->content > (*stack_a)->next->content)
			return ;
		*stack_a = (*stack_a)->next;
	}
	finalfree(stack_a, stack_b);
}

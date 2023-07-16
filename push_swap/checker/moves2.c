/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldifino <ldifino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 16:52:26 by ldifino           #+#    #+#             */
/*   Updated: 2023/07/16 15:00:27 by ldifino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker/checker.h"

void	sa1(t_listlink *stack_a)
{
	int	tmp1;

	tmp1 = 0;
	if (stack_a)
	{
		while (stack_a->index != 1)
			stack_a = stack_a->next;
		tmp1 = stack_a->content;
		stack_a->content = stack_a->next->content;
		stack_a->next->content = tmp1;
	}
}

void	sb1(t_listlink *stack_b)
{
	int	tmp1;

	tmp1 = 0;
	if (stack_b)
	{
		while (stack_b->index != 1)
			stack_b = stack_b->next;
		tmp1 = stack_b->content;
		stack_b->content = stack_b->next->content;
		stack_b->next->content = tmp1;
	}
}

void	ss1(t_listlink *stack_a, t_listlink *stack_b)
{
	if (stack_a || stack_b)
	{
		sa1(stack_a);
		sb1(stack_b);
	}
}

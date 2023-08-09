/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldifino <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 16:51:49 by ldifino           #+#    #+#             */
/*   Updated: 2023/07/05 16:51:52 by ldifino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker/checker.h"

void	check_duplicates(t_listlink *stack_a, int ac)
{
	int	*seen;
	int	i;
	int	j;

	i = 1;
	j = 0;
	seen = (int *)malloc((ac - 1) * sizeof(int));
	while (i < ac)
	{
		seen[i++ - 1] = stack_a->content;
		stack_a = stack_a->next;
	}
	i = 0;
	while (i < ac - 1)
	{
		j = i;
		while (j < ac - 2)
		{
			if (seen[i] == seen[j + 1])
				error();
			j++;
		}
		i++;
	}
	free(seen);
}

void	check_int(char **helper, t_listlink *stack_a, int flag)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (helper[i])
	{
		j = 0;
		while (helper[i][j])
		{
			if (helper[i][j] != '-' && helper[i][j] != '+')
				if (helper[i][j] < 48 || helper[i][j] > 57)
					error2(helper, stack_a, flag);
			j++;
		}
		i++;
	}
}

void	create_stack_a2(t_listlink **stack_a, char **av,
	t_create *utils, int ac)
{
	free1(utils->helper);
	utils->index = utils->j;
	while (utils->i < ac)
	{
		utils->helper = ft_split(av[utils->i++], ' ');
		check_int(utils->helper, *stack_a, 2);
		utils->j = 0;
		while (utils->helper[utils->j])
		{
			utils->tmp = ft_lstnew(ft_atoi(utils->helper[utils->j]),
					utils->index + 1);
			ft_lstadd_back(stack_a, utils->tmp);
			utils->j++;
			utils->index++;
		}
		free1(utils->helper);
	}
	(*stack_a)->before = ft_lstlast(*stack_a);
	ft_lstlast(*stack_a)->next = *stack_a;
}

t_listlink	*create_stack_a(char **av, int ac)
{
	t_listlink	*stack_a;
	t_create	utils;

	utils.i = 0;
	utils.j = 0;
	utils.index = 0;
	utils.helper = ft_split(av[utils.i++], ' ');
	check_int(utils.helper, NULL, 1);
	stack_a = ft_lstnew(ft_atoi(utils.helper[utils.j]), utils.j + 1);
	utils.j++;
	while (utils.helper[utils.j])
	{
		utils.tmp = ft_lstnew(ft_atoi(utils.helper[utils.j]), utils.j + 1);
		ft_lstadd_back(&stack_a, utils.tmp);
		utils.j++;
	}
	create_stack_a2(&stack_a, av, &utils, ac);
	return (stack_a);
}

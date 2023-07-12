#include "push_swap.h"
#include <stdio.h>

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
					error1(helper, stack_a, flag);
			j++;
		}
		i++;
	}
}

void	create_stack_a2(t_listlink **stack_a, char **av, t_create *utils, int ac)
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

int	main(int ac, char **av)
{
	t_listlink	*stack_a;
	t_listlink	*stack_b;

	if (ac == 1)
		return (1);
	stack_a = create_stack_a(av + 1, ac - 1);
	ac = stack_a->before->index + 1;
	check_duplicates(stack_a, ac);
	stack_b = ft_lstnew(90, 1);
	stack_b->before = NULL;
	stack_b->next = NULL;
	stack_a = move_on_first(stack_a);
	check_order(&stack_a, &stack_b);
	if (ac - 1 == 2)
		checker2(stack_a);
	else if (ac - 1 <= 4)
		checker3(stack_a, stack_b);
	else
		checker10(stack_a, stack_b);
	finalfree(&stack_a, &stack_b);
	return (0);
}
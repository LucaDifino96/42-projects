/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldifino <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 15:37:52 by ldifino           #+#    #+#             */
/*   Updated: 2023/06/30 15:37:56 by ldifino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include "../libft/libft.h"
# include "../push_swap.h"
# include <stddef.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

/*typedef struct s_create
{
	char		**helper;
	int			i;
	int			j;
	int			index;
	t_listlink	*tmp;
}	t_create;*/

size_t	strlen1(char *str);
char	*strchr1(char *s);
char	*strjoin1(char *s1, char *s2);
char	*ft_write(char *str);
char	*ft_reset(char *str);
char	*ft_read(int fd, char *str);
char	*get_next_line(int fd);
void		error(void);
t_listlink	*move_on_first(t_listlink *stack);
void		free1(char **split);
void		delete_list(t_listlink *stack_a);
void		error2(char **helper, t_listlink *stack_a, int flag);
void		sa1(t_listlink *stack_a);
void		sb1(t_listlink *stack_b);
void		ss1(t_listlink *stack_a, t_listlink *stack_b);
void		pa1(t_listlink *stack_a, t_listlink *stack_b);
void		pb1(t_listlink *stack_a, t_listlink *stack_b);
void		ra1(t_listlink *stack_a);
void		rb1(t_listlink *stack_b);
void		rr1(t_listlink *stack_a, t_listlink *stack_b);
void		rra1(t_listlink *stack_a);
void		rrb1(t_listlink *stack_b);
void		rrr1(t_listlink *stack_a, t_listlink *stack_b);
void		check_duplicates(t_listlink *stack_a, int ac);
void		check_int(char **helper, t_listlink *stack_a, int flag);
void		create_stack_a2(t_listlink **stack_a, char **argv, t_create *utils, int argc);
t_listlink	*create_stack_a(char **av, int ac);
void	check_moves2(t_listlink *stack_a, t_listlink *stack_b, char **tmp);
void	check_moves(t_listlink *stack_a, t_listlink *stack_b, char **tmp);
void	error2(char **helper, t_listlink *stack_a, int flag);
#endif

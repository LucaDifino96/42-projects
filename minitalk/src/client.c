/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldifino <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 14:48:17 by ldifino           #+#    #+#             */
/*   Updated: 2023/05/08 14:48:21 by ldifino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_transfer(int pid, char b)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if ((b & (1 << bit)) != 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		bit++;
		usleep(500);
	}
}

void	check_msg(int signal)
{
	if (signal == SIGUSR2)
	{
		ft_printf("Messaggio ricevuto!\n");
	}
}

static int	check_argument(int argc, char **argv)
{
	int	pid;

	if (argc != 3)
		return (ft_printf("ERROR: numero di argomenti errati.\n"));
	pid = ft_atoi(argv[1]);
	if (kill(pid, 0) == -1)
		return (ft_printf("404 Server non trovato.\n", argv[1]));
	return (pid);
}

int	main(int argc, char **argv)
{
	int		pid;
	size_t	i;


	pid = check_argument(argc, argv);
	signal(SIGUSR2, check_msg);
	i = 0;
	while (argv[2][i]) 
	{
		ft_transfer(pid, argv[2][i]);
        i++;
    }
	ft_transfer(pid, '\0');
	return (0);
}

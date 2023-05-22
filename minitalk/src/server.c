/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldifino <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 14:49:04 by ldifino           #+#    #+#             */
/*   Updated: 2023/05/08 14:49:08 by ldifino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_signal(int sig, siginfo_t *info, void *context)
{
	static int	bit;
	static int	ptr;

	(void)context;
	if (sig == SIGUSR1)
		ptr |= (0x01 << bit);
	bit++;	
	if (bit == 8)
	{
		if (ptr == 0)
			kill(info->si_pid, SIGUSR2);
		ft_printf("%c", ptr);
		bit = 0;
		ptr = 0;
	}
}

int	main(void)
{
	int	pid;
	struct sigaction	str;

	pid = getpid();
	if (pid == -1)
		ft_printf("Error\n");
	str.sa_flags = SA_SIGINFO;
	ft_printf("PID: %d\n", pid);
	str.sa_sigaction = ft_signal;
	sigaction(SIGUSR1, &str, NULL);
	sigaction(SIGUSR2, &str, NULL);
	while (1)
		pause ();
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilel-hla <ilel-hla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 19:28:59 by ilel-hla          #+#    #+#             */
/*   Updated: 2025/02/10 15:28:48 by ilel-hla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	signal_handler(int signal, siginfo_t *info, void *context)
{
	static unsigned char	c = 0;
	static int				bit = 0;
	static int				pid = 0;

	(void)context;
	if (pid == 0)
		pid = info->si_pid;
	if (pid != info->si_pid)
	{
		ft_putchar('\n');
		pid = info->si_pid;
		bit = 0;
		c = 0;
	}
	if (signal == SIGUSR2)
		c |= (1 << bit);
	bit++;
	if (bit == 8)
	{
		ft_putchar(c);
		bit = 0;
		c = 0;
	}
}

int	main(int ac, char **av)
{
	struct sigaction	sa;

	(void)av;
	if (ac != 1)
	{
		write(2, "\033[0;31m ❌ Usage: ./server ❌ \033[0m\n", 37);
		exit(1);
	}
	write(1, "\033[0;33m SERVER PID : \033[0m", 26);
	ft_putnbr(getpid());
	write(1, "\n", 1);
	sa.sa_sigaction = signal_handler;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}

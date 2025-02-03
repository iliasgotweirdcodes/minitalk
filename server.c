/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilel-hla <ilel-hla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:27:33 by ilel-hla          #+#    #+#             */
/*   Updated: 2025/02/03 22:52:53 by ilel-hla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	read_byte(int sign, siginfo_t *info, void *context)
{
	static char	c = 0;
	static int	bit = 128;
	static int	current_client = 0;

	(void)context;
	if (current_client == 0)
		current_client = info->si_pid;
	if (current_client != info->si_pid)
	{
		write(1, "\n", 1);
		current_client = info->si_pid;
		c = 0;
		bit = 128;
	}
	if (sign == SIGUSR2)
		c += bit;
	bit /= 2;
	if (bit == 0)
	{
		write(1, &c, 1);
		c = 0;
		bit = 128;
	}
}

int	main(int ac, char **av)
{
	struct sigaction	sa;
	int					pid;

	 (void)av;
	if (ac != 1)
	{
		write(2, "\033[0;31m ❌ Error too many arguments ❌\033[0m\n", 46);
		return (1);
	}
	sa.sa_sigaction = read_byte;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	pid = getpid();
	write(1, "\033[0;33mSERVER PID : \033[0m", 26);
	ft_putnbr(pid);
	write(1, "\n", 1);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}

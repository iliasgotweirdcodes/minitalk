/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilel-hla <ilel-hla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 21:06:40 by ilel-hla          #+#    #+#             */
/*   Updated: 2025/02/10 15:23:22 by ilel-hla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

int	g_server_pid;

void	send_byte(int pid, char c)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if (c & (1 << bit))
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(100);
		usleep(100);
		usleep(100);
		bit++;
	}
}

void	signal_handler(int signum, siginfo_t *info, void *context)
{
	(void)signum;
	(void)context;
	if (g_server_pid != info->si_pid)
		return ;
	else
	{
		write(1, "\033[0;32m ✔ Signal received successfully ✔ \033[0m\n", 51);
		exit(0);
	}
}

void	get_pid(char **av)
{
	int	i;

	g_server_pid = ft_atoi(av[1]);
	if (g_server_pid != -1 && g_server_pid > 0 && kill(g_server_pid, 0) == 0)
	{
		i = 0;
		while (av[2][i])
		{
			send_byte(g_server_pid, av[2][i]);
			i++;
		}
		send_byte(g_server_pid, '\0');
		write(1, "\033[0;32m ✔ Signal is sent successfully ✔ \033[0m\n", 50);
	}
}

int	main(int ac, char **av)
{
	struct sigaction	sa;

	if (ac != 3 || av[1][0] == '\0' || av[2][0] == '\0')
	{
		write(2, "\033[0;31m ❌ Usage: ./client PID message ❌ \033[0m\n", 50);
		exit (1);
	}
	get_pid(av);
	if (g_server_pid == -1 || g_server_pid <= 0 || kill(g_server_pid, 0) != 0)
	{
		write(2, "\033[0;31m ❌ Invalid PID ❌ \033[0m\n", 34);
		exit (1);
	}
	sa.sa_sigaction = signal_handler;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}

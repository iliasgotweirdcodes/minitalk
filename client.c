/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilel-hla <ilel-hla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 19:28:57 by ilel-hla          #+#    #+#             */
/*   Updated: 2025/02/10 15:21:33 by ilel-hla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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
		bit++;
	}
}

int	main(int ac, char **av)
{
	int	pid;
	int	i;

	if (ac != 3 || av[1][0] == '\0' || av[2][0] == '\0')
	{
		write(2, "\033[0;31m ❌ Usage: ./client PID message ❌ \033[0m\n", 50);
		exit (1);
	}
	pid = ft_atoi(av[1]);
	if (pid != -1 && pid > 0 && kill(pid, 0) == 0)
	{
		i = 0;
		while (av[2][i])
		{
			send_byte(pid, av[2][i]);
			i++;
		}
		send_byte(pid, '\0');
	}
	else
	{
		write(2, "\033[0;31m ❌ Invalid PID ❌ \033[0m\n", 34);
		exit (1);
	}
	return (0);
}

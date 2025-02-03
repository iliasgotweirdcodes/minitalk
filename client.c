/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilel-hla <ilel-hla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:07:53 by ilel-hla          #+#    #+#             */
/*   Updated: 2025/02/03 22:55:12 by ilel-hla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_byte(int pid, char c)
{
	int	i;

	i = 128;
	while (i > 0)
	{
		if (c >= i)
		{
			kill(pid, SIGUSR2);
			c -= i;
		}
		else
			kill(pid, SIGUSR1);
		i /= 2;
		usleep(100);
		usleep(100);
	}
}
void	sent(void)
{
	write(1, "\033[0;32m ✔ Signal is sent successfully ✔ \033[0m\n", 50);
	return ;
}

	void error(void)
{
	write(2, "\033[0;31m ❌ Error Invalid parameters or invalid PID ❌ \033[0m\n", 62);
	return;
}

int	main(int ac, char **av)
{
	int	pid;
	int	i;

	i = 0;
	if (3 == ac && ft_atoi(av[1]) != -1
		&& ft_atoi(av[1]) >= 0 && (kill(ft_atoi(av[1]), 0) == 0))
	{
		pid = ft_atoi(av[1]);
		while (av[2][i] != '\0')
		{
			send_byte(pid, av[2][i]);
			i++;
		}
		sent();
	}
	else
		error();
	return (0);
}

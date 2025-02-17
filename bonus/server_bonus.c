/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilel-hla <ilel-hla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 21:09:25 by ilel-hla          #+#    #+#             */
/*   Updated: 2025/02/17 16:31:29 by ilel-hla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk_bonus.h"

int	whatsthesize(unsigned char c)
{
	if (c < 0b10000000)
		return (1);
	else if ((c & 0b11100000) == 0b11000000)
		return (2);
	else if ((c & 0b11110000) == 0b11100000)
		return (3);
	else if ((c & 0b11111000) == 0b11110000)
		return (4);
	else
		return (0);
}

void	notify_message_completion(t_client *client)
{
	if (client->current_char == '\0')
	{
		write(1, "\n", 1);
		usleep(300);
		usleep(300);
		if (kill(client->pid, SIGUSR2))
			write (2, "\033[0;31m ❌ Error: Signal not sent ❌ \033[0m\n", 45);
		set_client(client);
	}
}

void	handle_unicode(t_client *client)
{
	if (client->unicode_index == 0)
		client->unicode_size = whatsthesize(client->current_char);
	client->unicode_buffer[client->unicode_index++] = client->current_char;
	if (client->unicode_size == client->unicode_index)
	{
		client->unicode_buffer[client->unicode_index] = '\0';
		write(1, client->unicode_buffer, client->unicode_size);
		ft_bzero(client->unicode_buffer, 8);
		client->unicode_size = 0;
		client->unicode_index = 0;
	}
}

void	signal_handler(int signal, siginfo_t *info, void *context)
{
	static t_client	client;

	(void)context;
	if (client.pid != 0 && (client.pid != info->si_pid))
		set_client(&client);
	if (client.pid == 0)
		client.pid = info->si_pid;
	if (signal == SIGUSR2)
		client.current_char |= (1 << client.current_bit);
	client.current_bit++;
	if (client.current_bit == 8)
	{
		handle_unicode(&client);
		notify_message_completion(&client);
		client.current_bit = 0;
		client.current_char = 0;
	}
}

int	main(int ac, char **av)
{
	struct sigaction	sa;

	(void)av;
	if (ac != 1)
	{
		write(2, "\033[0;31m ❌ Usage: ./server ❌ \033[0m\n", 38);
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilel-hla <ilel-hla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 21:06:08 by ilel-hla          #+#    #+#             */
/*   Updated: 2025/02/10 15:27:54 by ilel-hla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include <signal.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_client
{
	int				pid;
	char			current_char;
	int				current_bit;
	unsigned char	unicode_buffer[8];
	int				unicode_size;
	int				unicode_index;
}	t_client;

int		ft_atoi(const char *str);
void	ft_putnbr(int nbr);
void	ft_putchar(char c);
void	ft_bzero(void *s, size_t n);
void	set_client(t_client *client);

#endif

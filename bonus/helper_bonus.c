/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilel-hla <ilel-hla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 18:14:18 by ilel-hla          #+#    #+#             */
/*   Updated: 2025/02/17 16:31:23 by ilel-hla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk_bonus.h"

void	set_client(t_client *client)
{
	client->pid = 0;
	client->current_char = 0;
	client->current_bit = 0;
	client->unicode_size = 0;
	client->unicode_index = 0;
	ft_bzero(client->unicode_buffer, 8);
}

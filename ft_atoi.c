/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilel-hla <ilel-hla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 17:19:05 by ilel-hla          #+#    #+#             */
/*   Updated: 2025/02/03 17:46:45 by ilel-hla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(const char *str)
{
    int                    i;
    int                    signe;
    long                res;

    i = 0;
    signe = 1;
    res = 0;
    while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || \
            str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
        i++;
    if (str[i] == '-' || str[i] == '+')
    {
        if (str[i++] == '-')
            signe = signe * -1;
    }
    while (str[i] >= '0' && str[i] <= '9')
    {
        res = res * 10 + (str[i++] - 48);
    }
    if ((signe == 1 && res > 2147483647)
        || (signe == -1 && res > 2147483648))
        return (-1);
    if (str[i] != '\0')
        return (-1);
    return (res * signe);
}

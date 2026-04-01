/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkamil-h <tkamil-h@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 13:42:19 by tkamil-h          #+#    #+#             */
/*   Updated: 2026/04/01 12:25:08 by tkamil-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long    ft_atol(const char *str)
{
    long    result;
    int     sign;
    int     i;

    result = 0;
    sign = 1;
    i = 0;
    if (str[i] == '-' || str[i] == '+')
    {
        if (str[i] == '-')
            sign = -1;
        i++;
    }
    while (str[i])
    {
        if (result > (LONG_MAX - (str[i] - '0')) / 10)
            return (sign == 1 ? LONG_MAX : LONG_MIN);
        result = result * 10 + (str[i] - '0');
        i++;
    }
    return (result * sign);
}
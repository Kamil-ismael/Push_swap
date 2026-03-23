/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkamil-h <tkamil-h@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 11:38:51 by tkamil-h          #+#    #+#             */
/*   Updated: 2026/03/23 11:38:52 by tkamil-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_node
{
    int             value;
    int             index;
    struct s_node   *next;
    struct s_node   *prev;
}   t_node;

typedef struct s_info
{
    t_node  *stack_a;
    t_node  *stack_b;
    int     size_a;
    int     size_b;
    int     op_total;
    int     op_sa;
    double  disorder;
}   t_info;

#endif

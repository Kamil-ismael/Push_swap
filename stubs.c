/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stubs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkamil-h <tkamil-h@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 14:14:10 by tkamil-h          #+#    #+#             */
/*   Updated: 2026/04/02 14:14:16 by tkamil-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_adaptive(t_info *info)
{
	info->disorder = compute_disorder(info);
	if (info->size_a <= 3)
		sort_simple(info);
	else if (info->size_a <= 10)
		sort_simple(info);
	else if (info->size_a <= 100)
		sort_medium(info);
	else
		sort_complex(info);
}
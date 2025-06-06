/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mourdani <mourdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 07:55:42 by mourdani          #+#    #+#             */
/*   Updated: 2021/11/10 11:21:25 by mourdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

void	sort_others(t_stack *a, t_stack *b, t_chunk chunk)
{
	int		max_i;

	max_i = a->max_i;
	send_smallest_biggest(a, b);
	sort_stacks(a, b, chunk, max_i);
	send_b_to_a(a, b);
}

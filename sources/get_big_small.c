/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_big_small.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mourdani <mourdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 11:17:37 by mourdani          #+#    #+#             */
/*   Updated: 2021/11/10 11:17:40 by mourdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

void	get_smallest(t_stack *a)
{
	int	i;

	i = 0;
	while (a->stack[i] != a->sorted[0])
		i++;
	rotate_a_ntimes(a, find_nrotates(i, a->max_i));
}

void	get_biggest(t_stack *a)
{
	int	i;

	i = 0;
	while (a->stack[i] != a->sorted[a->max_i + 1])
		i++;
	rotate_a_ntimes(a, find_nrotates(i, a->max_i));
}

void	send_smallest_biggest(t_stack *a, t_stack *b)
{
	get_smallest(a);
	push_a(a, b);
	get_biggest(a);
	push_a(a, b);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mourdani <mourdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 11:18:50 by mourdani          #+#    #+#             */
/*   Updated: 2021/11/10 11:18:51 by mourdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

int	find_pos(t_stack *a, t_stack *b, int n)
{
	int	i;

	i = 0;
	while (i <= b->max_i)
	{
		if (a->stack[n] > b->stack[i] && a->stack[n] < b->stack[i + 1])
			return (i);
		i++;
	}
	return (i);
}

void	find_pos_closest_in_b(t_stack *a, t_stack *b, t_chunk chunk, int j)
{
	int	n_a;
	int	n_b;
	int	hold_first;
	int	hold_second;
	int	closest;

	hold_first = scan_from_top(a, chunk, j);
	hold_second = scan_from_bottom(a, chunk, j);
	closest = find_closest(a, hold_first, hold_second);
	n_a = find_nrotates(closest, a->max_i);
	n_b = find_nrotates(find_pos(a, b, closest), b->max_i);
	arrange_stacks(a, b, n_a, n_b);
}

void	sort_stacks(t_stack *a, t_stack *b, t_chunk chunk, int max_i)
{
	int	i;
	int	j;

	j = -1;
	while (j++ < chunk.number && b->max_i < max_i)
	{
		i = -1;
		while (i++ <= chunk.max_i && b->max_i < max_i)
		{
			find_pos_closest_in_b(a, b, chunk, j);
			push_a(a, b);
		}
	}
}

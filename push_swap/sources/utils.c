/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mourdani <mourdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 06:37:46 by mourdani          #+#    #+#             */
/*   Updated: 2021/11/09 14:30:02 by ymehdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

void	free_a_b(t_stack *a, t_stack *b)
{
	free(a->stack);
	free(a->sorted);
	free(b->stack);
}

void	free_all(t_stack *a, t_stack *b, t_chunk *chunk)
{
	int		j;

	j = 0;
	while (j < chunk->number)
	{
		free(chunk->chunks[j]);
		j++;
	}
	free(chunk->chunks);
	free(a->stack);
	free(a->sorted);
	free(b->stack);
}

void	send_b_to_a(t_stack *a, t_stack *b)
{
	int	i;

	i = 0;
	while (b->stack[i] != a->sorted[b->max_i])
		i++;
	rotate_b_ntimes(b, find_nrotates(i, b->max_i));
	i = b->max_i;
	while (i-- >= 0)
		push_b(b, a);
}

int	find_closest(t_stack *a, int hold_first, int hold_second)
{
	int	n_first;
	int	n_second;
	int	closest;

	n_first = find_nrotates(hold_first, a->max_i);
	n_second = find_nrotates(hold_second, a->max_i);
	closest = hold_first;
	if ((n_first * n_first) > (n_second * n_second))
		closest = hold_second;
	return (closest);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_h_first_sec.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mourdani <mourdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 11:18:45 by mourdani          #+#    #+#             */
/*   Updated: 2022/01/25 18:04:04 by mourdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

int	scan_from_top(t_stack *a, t_chunk chunk, int chunk_number)
{
	int	i;

	i = a->max_i;
	while (i >= 0)
	{
		if (check_chunk(chunk.chunks[chunk_number],
				chunk.max_i, a->stack[i]) == 1)
			return (i);
		i--;
	}
	return (0);
}

int	scan_from_bottom(t_stack *a, t_chunk chunk, int chunk_number)
{
	int	i;

	i = 0;
	while (i <= a->max_i)
	{
		if (check_chunk(chunk.chunks[chunk_number],
				chunk.max_i, a->stack[i]) == 1)
			return (i);
		i++;
	}
	return (0);
}

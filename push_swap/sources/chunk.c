/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mourdani <mourdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 13:59:29 by mourdani          #+#    #+#             */
/*   Updated: 2022/01/25 18:03:39 by mourdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

void	init_chunks(t_stack a, t_chunk *chunk)
{
	int	s;
	int	i;
	int	j;

	j = 0;
	s = 0;
	while (j < chunk->number)
	{
		i = 0;
		while (i <= (chunk->max_i))
		{
			chunk->chunks[j][i] = a.sorted[s];
			i++;
			s++;
		}
		j++;
	}
}

void	init_chunk(t_chunk *chunk, t_stack a)
{
	if (a.max_i >= 499)
	{
		chunk->number = 11;
		chunk->max_i = a.max_i / chunk->number;
	}
	else if (a.max_i >= 5)
	{
		chunk->number = 5;
		chunk->max_i = a.max_i / chunk->number;
	}
	else if (a.max_i < 5)
	{
		chunk->number = 0;
		chunk->max_i = a.max_i;
	}
}

int	malloc_chunks(t_stack *a, t_stack *b, t_chunk *chunk)
{
	int	j;

	j = 0;
	init_chunk(chunk, *a);
	chunk->chunks = (int **)malloc(sizeof(int *) * chunk->number);
	if (!(chunk->chunks))
	{
		free_a_b(a, b);
		return (0);
	}
	while (j < chunk->number)
	{
		chunk->chunks[j] = (int *)malloc(sizeof(int) * (chunk->max_i + 1));
		if (!(chunk->chunks[j]))
		{
			free_all(a, b, chunk);
			return (0);
		}
		j++;
	}
	init_chunks(*a, chunk);
	return (1);
}

int	check_chunk(int *chunk, int chunk_max, int x)
{
	int	i;

	i = 0;
	while (i <= chunk_max)
	{
		if (x == chunk[i])
			return (1);
		i++;
	}
	return (0);
}

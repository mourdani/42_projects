/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mourdani <mourdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 11:18:59 by mourdani          #+#    #+#             */
/*   Updated: 2021/11/10 11:19:55 by mourdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

void	init_a_b(t_stack a, t_stack b, char **argv)
{
	int	i;
	int	j;
	int	*temp;

	i = 0;
	j = a.max_i + 1;
	while (j > 0)
		a.stack[i++] = ft_atoi(argv[j--]);
	i = 0;
	while (i <= a.max_i)
	{
		b.stack[i] = 0;
		i++;
	}
	a.max_i = --i;
	temp = (int *)malloc(sizeof(int) * (a.max_i + 1));
	if (!temp)
		return ;
	ft_memcpy(temp, a.stack, (a.max_i + 1) * sizeof(int));
	ft_memcpy(a.sorted, quicksort
		(temp, 0, a.max_i), (a.max_i + 1) * sizeof(int));
	free(temp);
}

int	malloc_a_b(t_stack *a, t_stack *b, int argc)
{
	a->stack = (int *)malloc(sizeof(int) * argc - 1);
	if (!a->stack)
		return (0);
	a->sorted = (int *)malloc(sizeof(int) * argc - 1);
	if (!a->sorted)
	{
		free(a->stack);
		return (0);
	}
	b->stack = (int *)malloc(sizeof(int) * argc - 1);
	if (!b->stack)
	{
		free(a->stack);
		free(a->sorted);
		return (0);
	}
	a->max_i = argc - 2;
	b->max_i = -1;
	return (1);
}

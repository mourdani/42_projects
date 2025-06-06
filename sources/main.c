/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mourdani <mourdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 00:59:50 by mourdani          #+#    #+#             */
/*   Updated: 2021/11/13 11:18:04 by mourdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

void	sort(t_stack *a, t_stack *b, t_chunk chunk)
{
	if (a->max_i == 1)
		sort_two(a);
	else if (a->max_i == 2)
		sort_three(a);
	else if (a->max_i == 3)
		sort_four(a, b);
	else if (a->max_i == 4)
		sort_five(a, b);
	else
		sort_others(a, b, chunk);
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	t_chunk	chunk;

	if (check_alpha(argc, argv) || argc == 1 || argc == 2)
		return (0);
	if (!(malloc_a_b(&a, &b, argc)))
	{
		ft_puterr("Memory alloc failed for 'a' or 'b'\n");
		return (0);
	}
	init_a_b(a, b, argv);
	if (!(malloc_chunks(&a, &b, &chunk)))
	{
		ft_puterr("Memory alloc failed for 'chunks'\n");
		return (0);
	}
	if (check_duplicate(a) == 1 || check_sorted(a) == 1)
	{
		free_all(&a, &b, &chunk);
		return (0);
	}
	sort(&a, &b, chunk);
	free_all(&a, &b, &chunk);
	return (0);
}

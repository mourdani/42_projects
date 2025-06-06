/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrange_a_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mourdani <mourdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 11:17:45 by mourdani          #+#    #+#             */
/*   Updated: 2021/11/10 11:17:46 by mourdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

void	arrange_stacks(t_stack *a, t_stack *b, int n_a, int n_b)
{
	if (n_a > 0 && n_b > 0)
		rotatea_b(a, b, n_a, n_b);
	else if (n_a < 0 && n_b < 0)
		rrotatea_b(a, b, n_a, n_b);
	else
	{
		rotate_a_ntimes(a, n_a);
		rotate_b_ntimes(b, n_b);
	}
}

int	check_elig(t_stack *b, t_stack *a, int i)
{
	if (i == a->sorted[0] || i == a->sorted[b->max_i])
		return (1);
	else
		return (0);
}

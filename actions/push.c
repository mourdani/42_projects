/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mourdani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 15:41:17 by mourdani          #+#    #+#             */
/*   Updated: 2021/11/05 05:35:26 by mourdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

void	push_a(t_stack *a, t_stack *b)
{
	b->max_i += 1;
	b->stack[b->max_i] = a->stack[a->max_i];
	a->stack[a->max_i] = 0;
	a->max_i -= 1;
	ft_putstr("pb\n");
}

void	push_b(t_stack *a, t_stack *b)
{
	b->max_i += 1;
	b->stack[b->max_i] = a->stack[a->max_i];
	a->stack[a->max_i] = 0;
	a->max_i -= 1;
	ft_putstr("pa\n");
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_a.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mourdani <mourdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 11:14:04 by mourdani          #+#    #+#             */
/*   Updated: 2021/11/10 11:14:06 by mourdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

void	rotate_a(t_stack *s)
{
	int	i;
	int	temp;

	i = s->max_i;
	temp = s->stack[s->max_i];
	while (i > 0)
	{
		s->stack[i] = s->stack[i - 1];
		i--;
	}
	s->stack[0] = temp;
	ft_putstr("ra\n");
}

void	rrotate_a(t_stack *s)
{
	int	i;
	int	temp;

	i = 0;
	temp = s->stack[0];
	while (i < s->max_i)
	{
		s->stack[i] = s->stack[i + 1];
		i++;
	}
	s->stack[s->max_i] = temp;
	ft_putstr("rra\n");
}

int	rotate_a_ntimes(t_stack *stack, int n)
{
	while (n-- > 0)
		rotate_a(stack);
	while (n++ < -1)
		rrotate_a(stack);
	return (n);
}

void	rotatea_b(t_stack *a, t_stack *b, int n_a, int n_b)
{
	while (n_a > 0 && n_b > 0)
	{
		rr(a, b);
		n_a--;
		n_b--;
	}
	rotate_a_ntimes(a, n_a);
	rotate_b_ntimes(b, n_b);
}

void	rrotatea_b(t_stack *a, t_stack *b, int n_a, int n_b)
{
	while (n_a < -1 && n_b < -1)
	{
		rrr(a, b);
		n_a++;
		n_b++;
	}
	rotate_a_ntimes(a, n_a);
	rotate_b_ntimes(b, n_b);
}

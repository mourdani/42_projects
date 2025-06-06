/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mourdani <mourdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 15:41:09 by mourdani          #+#    #+#             */
/*   Updated: 2021/11/09 14:03:55 by ymehdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

void	rotate(t_stack *s)
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
}

void	rr(t_stack *a, t_stack *b)
{
	rotate(a);
	rotate(b);
	ft_putstr("rr\n");
}

void	rrotate(t_stack *s)
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
}

void	rrr(t_stack *a, t_stack *b)
{
	rrotate(a);
	rrotate(b);
	ft_putstr("rrr\n");
}

int	find_nrotates(int n, int max_i)
{
	int	i;

	i = 0;
	if (n == max_i)
		return (0);
	if (n == 0)
		return (-1);
	if (n >= (max_i / 2))
	{
		while (n++ < max_i)
			i++;
		return (i);
	}
	else if (n <= (max_i / 2))
	{
		while (n-- >= 0)
			i--;
		return (i);
	}
	return (i);
}

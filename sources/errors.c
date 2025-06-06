/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mourdani <mourdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 11:17:51 by mourdani          #+#    #+#             */
/*   Updated: 2022/01/25 18:05:06 by mourdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

int	ft_atoi_err(const char *str)
{
	int		i;
	long	num;
	int		sign;

	if (!*str)
		return (1);
	i = 0;
	num = 0;
	sign = 1;
	while (*(str + i) == '\n' || *(str + i) == '\t' || *(str + i) == '\r'
		|| *(str + i) == '\v' || *(str + i) == '\f' || *(str + i) == ' ')
		i++;
	if (*(str + i) == '-')
		sign = -1;
	if (*(str + i) == '-' || *(str + i) == '+')
		i++;
	while (*(str + i))
	{
		if (!(*(str + i) >= '0' && *(str + i) <= '9'))
			return (1);
		num = num * 10 + (*(str + i++) - '0');
	}
	if ((num * sign) > 2147483647 || (num * sign) < -2147483648)
		return (1);
	return (0);
}

int	check_duplicate(t_stack a)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (j <= a.max_i)
	{
		i = 0;
		while (i <= a.max_i)
		{
			if (a.stack[i] == a.stack[j] && i != j)
			{
				ft_puterr("Error\n");
				return (1);
			}
			i++;
		}
		j++;
	}
	return (0);
}

int	check_alpha(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i <= argc - 1)
	{
		if (ft_atoi_err(argv[i]) == 1)
		{
			ft_puterr("Error\n");
			return (1);
		}
		i++;
	}
	return (0);
}

int	check_sorted(t_stack a)
{
	int	i;
	int	j;

	i = 0;
	j = a.max_i;
	while (i <= a.max_i)
	{
		if (a.stack[i] != a.sorted[j])
		{
			return (0);
		}
		i++;
		j--;
	}
	return (1);
}

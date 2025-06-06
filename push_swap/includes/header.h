/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmechety <rmechety@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 12:52:24 by rmechety          #+#    #+#             */
/*   Updated: 2021/11/13 11:42:44 by mourdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <stdlib.h>
# include <unistd.h>

typedef struct t_stack{
	int	*stack;
	int	max_i;
	int	*sorted;
}t_stack;

typedef struct t_chunk{
	int	**chunks;
	int	max_i;
	int	number;
}t_chunk;
/* -------------------------------------------------------------------------- */
/*                      FILE = header/get_h_first_sec.c                       */
/* -------------------------------------------------------------------------- */
int		scan_from_top(t_stack *a, t_chunk chunk, int chunk_number);
int		scan_from_bottom(t_stack *a, t_chunk chunk, int chunk_number);
/* -------------------------------------------------------------------------- */
/*                            FILE = header/test.c                            */
/* -------------------------------------------------------------------------- */
void	print_stacks(t_stack *a, t_stack *b);
void	priprint_stack(int *stack, int max_i);
int		pritest(t_stack *a, t_stack *b);
/* -------------------------------------------------------------------------- */
/*                            FILE = header/swap.c                            */
/* -------------------------------------------------------------------------- */
void	swap(t_stack *a);
void	swap_b(t_stack *a);
/* -------------------------------------------------------------------------- */
/*                      FILE = header/get_h_first_sec.c                       */
/* -------------------------------------------------------------------------- */
/* -------------------------------------------------------------------------- */
/*                        FILE = src/get_h_first_sec.c                        */
/* -------------------------------------------------------------------------- */
int		scan_from_top(t_stack *a, t_chunk chunk, int chunk_number);
int		scan_from_bottom(t_stack *a, t_chunk chunk, int chunk_number);

/* -------------------------------------------------------------------------- */
/*                             FILE = src/sort.c                              */
/* -------------------------------------------------------------------------- */
int		find_pos(t_stack *a, t_stack *b, int n);
void	find_pos_closest_in_b(t_stack *a, t_stack *b, t_chunk chunk, int j);
void	sort_stacks(t_stack *a, t_stack *b, t_chunk chunk, int max_i);

/* -------------------------------------------------------------------------- */
/*                             FILE = src/swap.c                              */
/* -------------------------------------------------------------------------- */
void	swap(t_stack *a);
void	swap_b(t_stack *a);

/* -------------------------------------------------------------------------- */
/*                             FILE = src/init.c                              */
/* -------------------------------------------------------------------------- */
void	init_a_b(t_stack a, t_stack b, char **argv);
int		malloc_a_b(t_stack *a, t_stack *b, int argc);
/* -------------------------------------------------------------------------- */
/*                             FILE = src/utils.c                             */
/* -------------------------------------------------------------------------- */
void	free_a_b(t_stack *a, t_stack *b);
void	free_all(t_stack *a, t_stack *b, t_chunk *chunk);
void	send_b_to_a(t_stack *a, t_stack *b);
int		find_closest(t_stack *a, int hold_first, int hold_second);

/* -------------------------------------------------------------------------- */
/*                          FILE = src/sort_others.c                          */
/* -------------------------------------------------------------------------- */
void	sort_others(t_stack *a, t_stack *b, t_chunk chunk);

/* -------------------------------------------------------------------------- */
/*                             FILE = src/push.c                              */
/* -------------------------------------------------------------------------- */
void	push_a(t_stack *a, t_stack *b);
void	push_b(t_stack *a, t_stack *b);

/* -------------------------------------------------------------------------- */
/*                             FILE = src/main.c                              */
/* -------------------------------------------------------------------------- */
void	sort(t_stack *a, t_stack *b, t_chunk chunk);
int		main(int argc, char **argv);

/* -------------------------------------------------------------------------- */
/*                            FILE = src/errors.c                             */
/* -------------------------------------------------------------------------- */
int		ft_atoi_err(const char *str);
int		check_duplicate(t_stack a);
int		check_alpha(int argc, char **argv);
int		check_sorted(t_stack a);

/* -------------------------------------------------------------------------- */
/*                          FILE = src/arrange_a_b.c                          */
/* -------------------------------------------------------------------------- */
void	arrange_stacks(t_stack *a, t_stack *b, int n_a, int n_b);
int		check_elig(t_stack *b, t_stack *a, int i);

/* -------------------------------------------------------------------------- */
/*                            FILE = src/rotate.c                             */
/* -------------------------------------------------------------------------- */
void	rotate(t_stack *s);
void	rr(t_stack *a, t_stack *b);
void	rrotate(t_stack *s);
void	rrr(t_stack *a, t_stack *b);
int		find_nrotates(int n, int max_i);

/* -------------------------------------------------------------------------- */
/*                           FILE = src/rotate_b.c                            */
/* -------------------------------------------------------------------------- */
void	rotate_b(t_stack *s);
void	rrotate_b(t_stack *s);
int		rotate_b_ntimes(t_stack *stack, int n);

/* -------------------------------------------------------------------------- */
/*                           FILE = src/sort_five.c                           */
/* -------------------------------------------------------------------------- */
void	sort_three(t_stack *a);
void	sort_four(t_stack *a, t_stack *b);
void	sort_five(t_stack *a, t_stack *b);
void	sort_two(t_stack *a);

/* -------------------------------------------------------------------------- */
/*                         FILE = src/get_big_small.c                         */
/* -------------------------------------------------------------------------- */
void	get_smallest(t_stack *a);
void	get_biggest(t_stack *a);
void	send_smallest_biggest(t_stack *a, t_stack *b);

/* -------------------------------------------------------------------------- */
/*                           FILE = src/rotate_a.c                            */
/* -------------------------------------------------------------------------- */
void	rotate_a(t_stack *s);
void	rrotate_a(t_stack *s);
int		rotate_a_ntimes(t_stack *stack, int n);
void	rotatea_b(t_stack *a, t_stack *b, int n_a, int n_b);
void	rrotatea_b(t_stack *a, t_stack *b, int n_a, int n_b);

/* -------------------------------------------------------------------------- */
/*                             FILE = src/chunk.c                             */
/* -------------------------------------------------------------------------- */
void	init_chunks(t_stack a, t_chunk *chunk);
void	init_chunk(t_chunk *chunk, t_stack a);
int		malloc_chunks(t_stack *a, t_stack *b, t_chunk *chunk);
int		check_chunk(int *chunk, int chunk_max, int x);

/* -------------------------------------------------------------------------- */
/*                          FILE = src/libft_utils.c                          */
/* -------------------------------------------------------------------------- */
void	*ft_memcpy(void *dst, const void *src, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	ft_putstr(char const *s);
void	ft_puterr(char const *s);
int		ft_atoi(const char *str);

/* -------------------------------------------------------------------------- */
/*                           FILE = src/quicksort.c                           */
/* -------------------------------------------------------------------------- */
void	quickswap(int *i, int *j);
int		partition(int *stack, int low, int high);
int		*quicksort(int *stack, int low, int high);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mourdani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 15:05:58 by mourdani          #+#    #+#             */
/*   Updated: 2022/12/28 15:06:00 by mourdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_TPP
# define ITER_TPP

template < typename T, std::size_t N>
void	iter(T (&array)[N], unsigned int len, void (*function)(T const &)) {
	if (!array)
  		return;
	if (N < len)
		throw std::out_of_range("length out of range.");
	unsigned int i = 0;
	while (i < len)
		function(array[i++]);

	return;
}

template< typename T >
void print(const T &x) {
	std::cout << x << std::endl;
	return;
}

#endif
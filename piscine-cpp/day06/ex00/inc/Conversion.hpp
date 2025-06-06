/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Conversion.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mourdani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 01:18:03 by mourdani          #+#    #+#             */
/*   Updated: 2022/12/25 01:18:04 by mourdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  CONVERSION_H
# define CONVERSION_H

#include <string>
#include <string>
#include <iomanip>
#include <limits.h>
#include <iostream>

class Conversion {

public:
	Conversion();
	Conversion(Conversion const &cpy);
	virtual ~Conversion();

	Conversion		&operator=(Conversion const &cpy);

	std::string	find_type(std::string literal) const;
	void	print(char c) const;
	void	print(int i) const;
	void	print(float f) const;
	void	print(double d) const;
};

#endif

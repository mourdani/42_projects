/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mourdani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 13:59:31 by mourdani          #+#    #+#             */
/*   Updated: 2022/10/27 19:34:05 by mourdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef HARL_HPP
# define HARL_HPP

#include <string>
#include <iostream>

class Harl 
{
	public:
		Harl();
		~Harl();
		void complain( std::string level );

	private:
		void _debug( void );
		void _info( void );
		void _warning( void );
		void _error( void );
};

#endif

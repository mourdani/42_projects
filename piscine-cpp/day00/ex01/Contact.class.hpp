/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mourdani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 19:31:58 by mourdani          #+#    #+#             */
/*   Updated: 2022/09/29 02:02:29 by mourdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef CONTACT_CLASS_HPP
#define CONTACT_CLASS_HPP

#include "phonebook.hpp"
// Attributes of a contact
class Contact
{
	private:
		std::string _first;
		std::string _last;
		std::string _nick;
		std::string _secret;
		int _number;

	public:
		int index;
		int set;
		std::string getFirst(void);
		std::string getLast(void);
		std::string getNick(void);
		std::string getSecret(void);
		int getNumber(void);

		// Function to add a contact 
		int add();
};
#endif 

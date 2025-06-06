/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mourdani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 17:14:57 by mourdani          #+#    #+#             */
/*   Updated: 2022/09/29 02:03:06 by mourdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include <cctype>
#include <limits>
#include "Contact.class.hpp"
#include "Phonebook.class.hpp"

#define SLIM_LINE "_____________________________________________"
#define BOLD_LINE "==============================================="
#define COLUMNS "|__________|__________|__________|__________|"

int check_empty(std::string str, int mode);
std::string	ptrunk(std::string str);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mourdani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 02:39:59 by mourdani          #+#    #+#             */
/*   Updated: 2022/12/22 02:43:42 by mourdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ShrubberyCreationForm.hpp"
#include <fstream>
#include <cstring>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : Form("Shrubbery Creation", 145, 137), target(target)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : Form(other), target(other.target)
{
}
/*
ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	 Form::operator=(other);
	 target = other.target;
	 return *this;
}
*/
void ShrubberyCreationForm::execute(const Bureaucrat& executor) const
{
	 (void)executor;
	 char file_name[100] = "";
	 strcat(file_name, target.c_str());
	 strcat(file_name, "_shrubbery");
	 std::ofstream out(file_name);
	 out << "    o" << std::endl;
	 out << "   /|\\ " << std::endl;
	 out << "  / | \\ " << std::endl;
	 out << " /  |  \\ " << std::endl;
	 out << "/   |   \\" << std::endl;
	 out << "---------" << std::endl;
	 out << "   |||	    -" << std::endl;
	 out << "   |||	    -" << std::endl;
}

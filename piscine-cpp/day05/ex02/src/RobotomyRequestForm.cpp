/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mourdani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 02:41:52 by mourdani          #+#    #+#             */
/*   Updated: 2022/12/22 02:44:21 by mourdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
       	: Form::Form("Robotomy Request", 72, 45), target(target)
{
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
	: Form(other), target(other.target)
{
}
/*
RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	 Form::operator=(other);
	 target = other.target;
	 return *this;
}
*/
void RobotomyRequestForm::execute(const Bureaucrat& executor) const
{
	(void)executor;
	std::cout << "Drilling noises" << std::endl;

	std::srand((unsigned int)time(NULL));
	if ((rand() % 2) != 0)
		std::cout << target << " has been robotomized successfully" << std::endl;
	else
		std::cout << "Robotomy failed" << std::endl;
}


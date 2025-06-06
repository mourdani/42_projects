/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mourdani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 21:26:29 by mourdani          #+#    #+#             */
/*   Updated: 2022/12/22 01:08:39 by mourdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Form.hpp"

// Constructor
Form::Form(std::string name, int sign_grade, int exec_grade)
	:_name(name) , _signed(false), _sign_grade(sign_grade), _exec_grade(exec_grade) {
	if (sign_grade < 1 || exec_grade < 1)
		throw Form::GradeTooHighException();
	if (sign_grade > 150 || exec_grade > 150)
		throw Form::GradeTooLowException();
}

std::string Form::getName() const {
	return _name;
}

bool Form::getSigned() const {
	return _signed;
}

int Form::getSignGrade() const {
	return _sign_grade;
}

int Form::getExecGrade() const {
	return _exec_grade;
}

void	Form::beSigned(Bureaucrat bureaucrat) {
	if (bureaucrat.getGrade() > this->_sign_grade) {
		std::cout<< bureaucrat.getName() << " couldn't sign " << this->getName() << " because : ";
		throw Form::GradeTooLowException();
	}
	else
	{
		this->_signed = true;
		std::cout << bureaucrat.getName() << " SIGNED " << this->getName() << std::endl;
	}
}


std::ostream & operator<<(std::ostream & out, const Form & form) {
	out	<< "Form 		: " << form.getName() << std::endl
		<< "Signed	  	: "	<< (form.getSigned() ? "yes" : "no") << std::endl
		<< "Grade to sign	: "	<< form.getSignGrade()	<< std::endl
		<< "Grade to execute: "	<< form.getExecGrade()	<< std::endl;
	return out;
}

void Form::execute(const Bureaucrat& executor) const
{
	if (!this->_signed)
		throw Form::NotSigned();

	if (executor.getGrade() > this->getExecGrade())
		throw Form::GradeTooLowException();
}

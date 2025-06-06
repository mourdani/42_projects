/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mourdani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 19:35:39 by mourdani          #+#    #+#             */
/*   Updated: 2022/12/22 00:40:03 by mourdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"

// Constructor
Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name) {
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		this->_grade = grade;
}

// Getters 
std::string 	Bureaucrat::getName() const {return this->_name;}
int		Bureaucrat::getGrade() const {return this->_grade;}

// Setter
void		Bureaucrat::setGrade(int grade) {
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	else
		this->_grade = grade;
}

// Incrementation functions
void Bureaucrat::incrementGrade() {
	this->_grade -=1;
	if (this->_grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (this->_grade > 150)
		throw Bureaucrat::GradeTooLowException();
}
void Bureaucrat::decrementGrade() {
	this->_grade +=1;
	if (this->_grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (this->_grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

void Bureaucrat::signForm(Form &form) {
	if (this->_grade > form.getSignGrade())
		throw Form::GradeTooLowException();
	else
	try
	{
		form.beSigned(*this);
	}
	catch(const std::exception& e)
	{
		std::cerr	<< this->_name
					<< " cannot sign "
					<< form.getName()
					<< " because "
					<< e.what()
					<< std::endl;
		return ;
	}
}

void Bureaucrat::executeForm(const Form& form)
{

	try
	{
			form.execute(*this);
			std::cout << this->_name << " executed " << form.getName() << std::endl;

	}
	catch (const std::exception& e)
	{
		std::cout << this->_name << " could not execute " << form.getName() << ": " << e.what() << std::endl;
	}
}

// Overloaded operator << 
std::ostream &operator<< (std::ostream &out, const Bureaucrat &bureaucrat) {
	out << "Bureaucrat " << bureaucrat.getName() << ", grade : " << bureaucrat.getGrade();
	return out;
}


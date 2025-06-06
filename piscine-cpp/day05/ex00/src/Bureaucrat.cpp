/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mourdani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 19:35:39 by mourdani          #+#    #+#             */
/*   Updated: 2022/12/21 21:17:54 by mourdani         ###   ########.fr       */
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

// Overloaded operator << 
std::ostream &operator<< (std::ostream &out, const Bureaucrat &bureaucrat) {
	out << "Bureaucrat " << bureaucrat.getName() << ", grade : " << bureaucrat.getGrade();
	return out;
}

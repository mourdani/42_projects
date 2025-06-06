/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mourdani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 18:26:14 by mourdani          #+#    #+#             */
/*   Updated: 2022/12/21 23:52:23 by mourdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include <stdexcept>
#include "Form.hpp" 

class Form;

class Bureaucrat {
	public :

		// Constructor
		Bureaucrat(std::string name, int grade);

		// Exception Classes
		class GradeTooHighException : public std::exception {
			public :
				const char* what() const throw() {
					return "Grade too High !!";
				};

		
		};
		class GradeTooLowException  : public std::exception {
			public :
				const char* what() const throw() {
					return "Grade too Low !!";
				};
		
		};

		// Getters
		std::string 	getName() const;
		int 		getGrade() const;

		// Setters
		void		setGrade(int grade);

		// Incrementing functions
		void incrementGrade();
		void decrementGrade();

		void signForm(Form &form);
		void executeForm(const Form& form);

	protected :
		std::string const	_name;
		int			_grade;	
};

// Operator overload <<
std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat);


#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mourdani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 21:26:39 by mourdani          #+#    #+#             */
/*   Updated: 2022/12/22 00:50:48 by mourdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include <string>
#include <ostream>
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
	private :
		const std::string	_name;
		bool		_signed;
		const int		_sign_grade;
		const int		_exec_grade;

	public :
		Form(std::string name, int sign_grade, int exec_grade);
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
		class NotSigned  : public std::exception {
			public :
				const char* what() const throw() {
					return "Form not signed!!";
				};
		
		};
		std::string getName() const;
		bool getSigned() const;
		int getSignGrade() const;
		int getExecGrade() const;

		void	beSigned(Bureaucrat bureaucrat);

		virtual void execute(const Bureaucrat& executor) const = 0;
};

std::ostream & operator<<(std::ostream & os, const Form & form);

#endif

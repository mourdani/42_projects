/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mourdani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 18:25:52 by mourdani          #+#    #+#             */
/*   Updated: 2022/12/22 00:53:09 by mourdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Form.hpp"
#include "../inc/Bureaucrat.hpp"

int main()
{
	try
    {
		Form form1("form1", 1, 3);
		std::cout << form1 << std::endl;

		Form form2("form2", 1, 1);
		std::cout << form2 << std::endl;

		Bureaucrat bureaucrat1("bureaucrat1", 1);
		std::cout << bureaucrat1 << std::endl;

		Bureaucrat bureaucrat2("bureaucrat2", 50);
		std::cout << bureaucrat2 << std::endl;
		

		bureaucrat1.signForm(form1);
		//form2.beSigned(bureaucrat1);
		std::cout << form2 << std::endl;
	}
	catch (Form::GradeTooLowException& e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (Form::GradeTooHighException& e)
	{
		std::cout << e.what() << std::endl;
	}
	
	return 0;
}

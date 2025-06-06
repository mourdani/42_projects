/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mourdani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 18:25:52 by mourdani          #+#    #+#             */
/*   Updated: 2022/12/21 21:24:15 by mourdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"

int main()
{
	// Try block to catch any exceptions thrown during the following code execution
	try
	{
		Bureaucrat b("John", 149);
		std::cout << b << std::endl;


		b.decrementGrade();
		std::cout << b << std::endl;
		
		b.incrementGrade();
		std::cout << b << std::endl;
		
		b.decrementGrade();
		std::cout << b << std::endl;
		
		b.decrementGrade();
		std::cout << b << std::endl;
	}
	
	// catch (Bureaucrat::GradeTooLowException& e)
	// {
	// 	std::cout << e.what() << std::endl;
	// }
	// catch (Bureaucrat::GradeTooHighException& e)
	// {
	// 	std::cout << e.what() << std::endl;
	// }
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	
	return 0;
}


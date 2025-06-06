/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mourdani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 18:25:52 by mourdani          #+#    #+#             */
/*   Updated: 2022/12/22 01:11:28 by mourdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Form.hpp"
#include "../inc/Bureaucrat.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/PresidentialPardonForm.hpp"
#include "../inc/ShrubberyCreationForm.hpp"


int main(void)
{	try {


        PresidentialPardonForm form("presidenche");
        ShrubberyCreationForm form2("tree");
        RobotomyRequestForm form3("sol");
        
        std::cout << "\n\n--------- SIGN AND EXECUTE TEST ---------\n\n" << std::endl;
        
        Bureaucrat	poto("poto", 1);
           
        poto.executeForm(form);
        poto.executeForm(form2);
        poto.executeForm(form3);
        
        poto.signForm(form);
        poto.signForm(form3);
        poto.signForm(form2);

        std::cout << form << std::endl;
        std::cout << form2 << std::endl;
        std::cout << form3 << std::endl;

        poto.executeForm(form);
        poto.executeForm(form3);
        poto.executeForm(form2);

        std::cout << poto << std::endl;
    }

	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	

	return (0);
}

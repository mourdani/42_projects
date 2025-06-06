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
#include "../inc/Intern.hpp"


int main()
{
    Intern someRandomIntern;

    Form* rrf;
    rrf = someRandomIntern.makeForm("robotomy request", "Bender");
    Bureaucrat bob("Bob", 1);
    bob.signForm(*rrf);
    bob.executeForm(*rrf);
    delete rrf;

    Form* scf;
    scf = someRandomIntern.makeForm("shrubbery creation", "Garden");
    Bureaucrat alice("Alice", 1);
    alice.signForm(*scf);
    alice.executeForm(*scf);
    delete scf;

    Form* ppf;
    ppf = someRandomIntern.makeForm("presidential pardon", "Prisoner");
    Bureaucrat charlie("Charlie", 1);
    charlie.signForm(*ppf);
    charlie.executeForm(*ppf);
    delete ppf;

    return 0;
}
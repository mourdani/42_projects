#include "../inc/Intern.hpp"

Intern::Intern() {}
Intern::~Intern() {}

Form *Intern::_createPresidentialForm(std::string target)
{
	return (new PresidentialPardonForm(target));
}

Form *Intern::_createRobotomyForm(std::string target)
{
	return (new RobotomyRequestForm(target));
}

Form *Intern::_createShrubberyForm(std::string target)
{
	return (new ShrubberyCreationForm(target));
}

Form* Intern::makeForm(const std::string& formName, const std::string& target)
{
std::string namesArray[3] = {
    "shrubbery creation",
    "robotomy request",
    "presidential pardon"
    };
	
	Form	*(Intern::*createForm[3])(std::string target) = {
        	&Intern::_createShrubberyForm,
			&Intern::_createRobotomyForm,
			&Intern::_createPresidentialForm
    };
	
	for(int i = 0; i < 3; i++)
	{
		if (formName == namesArray[i])
		{
			std::cout << "Intern creates " << formName << std::endl;
			return ((this->*createForm[i])(target));
		}
	}
	std::cout << formName << " is not a valid form." << std::endl;
	return (NULL);
}
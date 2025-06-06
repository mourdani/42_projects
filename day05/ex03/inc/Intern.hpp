#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/ShrubberyCreationForm.hpp"
#include "../inc/PresidentialPardonForm.hpp"

class Intern
{
    private:
	    Form	*_createPresidentialForm(std::string target);
	    Form	*_createRobotomyForm(std::string target);
	    Form	*_createShrubberyForm(std::string target);

    public:
        Intern();
       virtual ~Intern();

        Form* makeForm(const std::string& formName, const std::string& target);
};
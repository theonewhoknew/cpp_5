#include "../inc/Intern.hpp"
#include "../inc/PresidentialPardonForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/ShrubberyCreationForm.hpp"

Intern::Intern()
{	

}

Intern::~Intern()
{

}

AForm *Intern::makeForm(const std::string &form, const std::string &target)
{	
	    return 
			(form == "robotomy request") ? createRobotomy(form, target) :
			(form == "presidential pardon") ? createPresidential(form, target) :
			(form == "shrubbery creation") ? createShrubbery(form, target) :
			creationError();
}

AForm *Intern::createRobotomy(const std::string &form, const std::string &target)
{
	std::cout << "Intern creates " << form << std::endl;
	return (new RobotomyRequestForm(target));
}

AForm *Intern::createPresidential(const std::string &form, const std::string &target)
{
	std::cout << "Intern creates " << form << std::endl;
	return (new PresidentialPardonForm(target));
}

AForm *Intern::createShrubbery(const std::string &form, const std::string &target)
{
	std::cout << "Intern creates " << form << std::endl;
	return (new ShrubberyCreationForm(target));
}

AForm *Intern::creationError()
{
	std::cout << "Intern couldn't create form!" << std::endl;
	return (NULL);
}
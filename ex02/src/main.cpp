#include "../inc/AForm.hpp"
#include "../inc/Bureaucrat.hpp"
#include "../inc/ShrubberyCreationForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/PresidentialPardonForm.hpp"

int main(void)
{
	ShrubberyCreationForm A20("home");

	Bureaucrat John("John", 40);

	John.signForm(A20);
	John.executeForm(A20);

	std::cout << A20 << std::endl;

	RobotomyRequestForm C54("John");

	John.signForm(C54);
	John.executeForm(C54);

	std::cout << C54 << std::endl;

	PresidentialPardonForm Z89("John");

	John.signForm(Z89);
	John.executeForm(Z89);
	
}
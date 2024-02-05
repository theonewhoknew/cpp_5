#include "../inc/AForm.hpp"
#include "../inc/Bureaucrat.hpp"
#include "../inc/ShrubberyCreationForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/PresidentialPardonForm.hpp"

int main(void)
{
	ShrubberyCreationForm A20("home");
	ShrubberyCreationForm A22("great");

	Bureaucrat John("John", 40);

	John.executeForm(A20);
	John.signForm(A20);
	John.executeForm(A20);

	John.signForm(A22);
	John.executeForm(A22);

	std::cout << A20 << std::endl;

	Bureaucrat Paul("Paul", 150);

	Paul.signForm(A20);

	RobotomyRequestForm C54("John");

	John.signForm(C54);
	John.executeForm(C54);

	std::cout << C54 << std::endl;

	PresidentialPardonForm Z89("John");

	John.signForm(Z89);
	John.executeForm(Z89);
	
}
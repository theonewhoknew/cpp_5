#include "../inc/AForm.hpp"
#include "../inc/Bureaucrat.hpp"
#include "../inc/ShrubberyCreationForm.hpp"

int main(void)
{
	ShrubberyCreationForm A20("home");

	Bureaucrat John("John", 40);

	John.signForm(A20);
	John.executeForm(A20);

}
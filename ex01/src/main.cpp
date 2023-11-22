#include "../inc/Bureaucrat.hpp"

int	main()
{
	try
	{
		Bureaucrat *a = new Bureaucrat("anon", 150);
		Bureaucrat b("dani", 45);
		std::cout << *a << std::endl << b << std::endl;
	}
	catch(const Bureaucrat::GradeTooLowException& e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		Bureaucrat b(0);
	}
	catch(const Bureaucrat::GradeTooHighException& e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		Bureaucrat b(1);
		b.incrementGrade();
	}
	catch(const Bureaucrat::GradeTooHighException& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
}

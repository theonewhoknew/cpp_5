#include "../inc/Bureaucrat.hpp"

int	main()
{
		// CONSTRUCTING BAD GRADE //
	std::cout << std::endl;
	std::cout << "CONSTRUCTING INVALID GRADE" << std::endl;
	try
	{
		Bureaucrat John("John", -49);
	}
	catch (std::exception &e)
	{
		std::cout << e.what();
	}
	std::cout << std::endl << std::endl;
	try
	{
		Bureaucrat John("John", 256);
	}
	catch (std::exception &e)
	{
		std::cout << e.what();
	}
	std::cout << std::endl << std::endl;
	std::cout << std::endl;

	/*INCREMENT - DECREMENT*/

	std::cout << "INCREMENT - DECREMENT" << std::endl;
	Bureaucrat Paul("Paul", 1);
	try
	{
		Paul.decrementGrade();
	}
	catch (std::exception &e)
	{
		std::cout << e.what();
	}
	std::cout << Paul << std::endl;
	try
	{
		Paul.incrementGrade();
	}
	catch (std::exception &e)
	{
		std::cout << e.what();
	}
	std::cout << Paul;
	std::cout << std::endl << std::endl;

	/*INCREMENT EXCEPTION*/

	std::cout << std::endl;

	try
	{
		Paul.incrementGrade();
	}
	catch (std::exception &e)
	{
		std::cout << e.what();
	}
	std::cout << std::endl << std::endl;

	Paul.setGrade(150);
	try
	{
		Paul.decrementGrade();
	}
	catch (std::exception &e)
	{
		std::cout << e.what();
	}
	std::cout << std::endl << std::endl;


	std::cout << "Insertion operator test" << std::endl;
	std::cout << std::endl << std::endl;

	std::cout << Paul << std::endl;

	return (0);
}

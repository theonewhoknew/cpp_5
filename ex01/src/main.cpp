#include "../inc/Bureaucrat.hpp"
#include "../inc/Form.hpp"

int	main()
{
		// Constructors
	std::cout << std::endl;
	std::cout << "CONSTRUCTORS:" << std::endl;
	// Create a Form with grades too low
	try
	{
		Form	c("C46", 489, 1435);
	}
	catch (std::exception &e)
	{
		std::cout << "Constructor failure: " << e.what() << std::endl; //the grade is too low
	}

	try
	{
		Form	c("C46", 20, 151);
	}
	catch (std::exception &e)
	{
		std::cout << "Constructor failure: " << e.what() << std::endl; //the grade is too low
	}

	// Create a grade with grades too high
	try
	{
		Form	c("D143", -583, -800);
	}
	catch (std::exception &e)
	{
		std::cout << "Constructor failure: " << e.what() << std::endl; //the grade is too high
	}
	try
	{
		Form	c("D143", 0, 1);
	}
	catch (std::exception &e)
	{
		std::cout << "Constructor failure: " << e.what() << std::endl; //the grade is too high
	}
	std::cout << std::endl << std::endl;

	Bureaucrat	bob("Bob", 1);
	Bureaucrat	bill("Bill", 132);

	Bureaucrat & bob_ref = bob;
	Bureaucrat & bill_ref = bill;

	Form		a("A13", 4, 6);
	Form		b("B97", 146, 135);
	// Sign forms
	std::cout << std::endl;
	std::cout << "SIGN:" << std::endl;

	// Sign OK
	std::cout << "SIGN OK:" << std::endl;
	bob_ref.signForm(a);
	std::cout << a << std::endl;
	a.setSigned(false);
	std::cout << std::endl << std::endl;

	// Sign KO
	std::cout << "SIGN KO:" << std::endl;
	bill_ref.signForm(a);
	std::cout << a << std::endl;
	std::cout << std::endl << std::endl;

	// Sign OK
	std::cout << "SIGN OK:" << std::endl;
	bob.signForm(b);
	std::cout << b << std::endl;
	b.setSigned(false);
	std::cout << std::endl << std::endl;
	
	// Sign OK
	std::cout << "SIGN OK:" << std::endl;
	bill.signForm(b);
	std::cout << b << std::endl;
	std::cout << std::endl << std::endl;

	return (0);
}

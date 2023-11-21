#include "../inc/Bureaucrat.hpp"

int	main()
{
	try
	{
		Bureaucrat a(151);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}
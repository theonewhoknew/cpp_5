#include "../inc/Bureaucrat.hpp"
#include "../inc/Form.hpp"

int	main()
{
		Bureaucrat *a = new Bureaucrat("anon", 150);
		Bureaucrat Dani("Dani", 55);
		Form c("License 20B", 50, 20);
		std::cout << *a << std::endl << Dani << std::endl;
		std::cout << c << std::endl;
		Dani.signForm(c);
}

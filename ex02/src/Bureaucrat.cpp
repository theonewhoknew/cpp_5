#include "../inc/Bureaucrat.hpp"
#include "../inc/AForm.hpp"
#include "../inc/ShrubberyCreationForm.hpp"

Bureaucrat::Bureaucrat(): _name("default"), _grade(150)
{	

}

Bureaucrat::Bureaucrat(int grade): _name("default")
{	
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade = grade;
}

Bureaucrat::Bureaucrat(std::string name, int grade): _name(name)
{	
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat &copy) : _name(copy.getName()), _grade(copy.getGrade())
{	

}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &copy)
{	
	this->_grade = copy.getGrade();
	return (*this);
}

Bureaucrat::~Bureaucrat()
{

}

std::string Bureaucrat::getName() const
{
	return (this->_name);
}

int	Bureaucrat::getGrade() const
{
	return (this->_grade);
}

void	Bureaucrat::setGrade(const int new_grade)
{
	this->_grade = new_grade;
}

void	Bureaucrat::incrementGrade()
{	
	if (this->_grade - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	this->_grade--;
}

void	Bureaucrat::decrementGrade()
{	
	if (this->_grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade++;
}

void	Bureaucrat::signForm(AForm &form)
{	
	try
	{
		form.beSigned(*this);
		std::cout << this->getName() << " signed " << form.getName() << std::endl;
	}
	catch(const Bureaucrat::GradeTooLowException& e)
	{
		std::cout << this->getName() << " couldn't sign " <<form.getName() << " because of " << e.what() << std::endl;
	}

}

void	Bureaucrat::executeForm(AForm const &form)
{	
	try
	{
		form.execute(*this);
		std::cout << this->getName() << " executed " << form.getName() << std::endl;
	}
	catch(const Bureaucrat::GradeTooLowException& e)
	{
		std::cout << this->getName() << " couldn't execute " <<form.getName() << " because of " << e.what() << std::endl;
	}
	catch(const AForm::FormNotSignedException& e)
	{
		std::cout << this->getName() << " couldn't execute " <<form.getName() << " because of " << e.what() << std::endl;
	}

}

const char *Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return ("Bureaucrat: Grade too high");
};

const char *Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return ("Bureaucrat: Grade too low");
};

std::ostream & operator<<(std::ostream & o, const Bureaucrat &reference)
{
	o << reference.getName() << ", bureaucrat grade " << reference.getGrade() << ".";
	return (o);
}

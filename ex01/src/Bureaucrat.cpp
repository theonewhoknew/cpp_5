#include "../inc/Bureaucrat.hpp"

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

Bureaucrat::Bureaucrat(Bureaucrat &copy)
{	
	this->_grade = copy.getGrade();
	this->_name = copy.getName();
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

const char *Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return ("Grade too high");
};

const char *Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return ("Grade too low");
};

std::ostream & operator<<(std::ostream & o, const Bureaucrat &reference)
{
	o << reference.getName() << ", bureaucrat grade " << reference.getGrade() << ".";
	return (o);
}

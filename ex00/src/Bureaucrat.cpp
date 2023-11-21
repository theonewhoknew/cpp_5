#include "../inc/Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): _name("default"), _grade(150)
{	

}

Bureaucrat::Bureaucrat(int grade)
{
	this->_grade = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat &copy)
{	
	this->_grade = copy.getGrade();
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
	this->_grade--;
}

void	Bureaucrat::decrementGrade()
{
	this->_grade++;
}

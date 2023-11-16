#include "../inc/Bureaucrat.hpp"

Bureaucrat::Bureaucrat(int grade)
{
	this->_grade = grade;
}

Bureaucrat::~Bureaucrat() throw()
{
}

std::string Bureaucrat::getName()
{
	return (this->_name);
}

int	Bureaucrat::getGrade()
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
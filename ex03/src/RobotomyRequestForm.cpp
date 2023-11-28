#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/Bureaucrat.hpp"
#include <iostream>
#include <fstream>
#include <unistd.h>
#include <stdlib.h>

RobotomyRequestForm::RobotomyRequestForm() : AForm("Robotomy Request Form", 72, 45)
{	

}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm("Robotomy Request Form", 72, 45), _target(target)
{

}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm &copy) : AForm("Robotomy Request Form", 72, 45), _target(copy._target)
{	

}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &instance)
{
	this->setSigned(instance.getSigned());
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{

}

std::string RobotomyRequestForm::getTarget() const
{
	return (this->_target);
}

void	RobotomyRequestForm::beSigned(const Bureaucrat &signer)
{
	if (signer.getGrade() <= this->getSignGrade())
		this->setSigned(true);
	else
		throw Bureaucrat::GradeTooLowException();
}

void	RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
	if(!this->getSigned())
		throw RobotomyRequestForm::FormNotSignedException();
	else if (executor.getGrade() <= this->getExecGrade())
		robotomize(this->getTarget());
	else
		throw Bureaucrat::GradeTooLowException();
}

void	robotomize(const std::string &target)
{
	srand(time(NULL));
	std::cout << "Bzzzz BzzzzBzzzzBzzzz Bzzzz BzzzzBzzzz" << std::endl;
	sleep(1);
	std::cout << "Bzzzz BzzzzBzzzzBzzzz Bzzzz BzzzzBzzzz" << std::endl;
	sleep(1);
	std::cout << "Bzzzz BzzzzBzzzzBzzzz Bzzzz BzzzzBzzzz " << std::endl;
	sleep(1);
	if (rand() % 2)
		std::cout << target << "was robotomized succesfully!" << std::endl;
	else
		std::cout << "Ooops, something went wrong and " << target << " is still human!" << std::endl;
}

std::ostream & operator<<(std::ostream & o, const RobotomyRequestForm &reference)
{
	o << "Form " << reference.getName() << ", ";
	if (reference.getSigned())
		o << "IS ";
	else
		o << "IS NOT ";
	o << "signed. Grade required to sign is " << reference.getSignGrade() << ". Grade required to execute is "
	<< reference.getExecGrade() << ". ";
	o << "The form asks to robotomize " << reference.getTarget() << ".";
	return (o);
}

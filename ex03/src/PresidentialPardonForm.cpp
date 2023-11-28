#include "../inc/PresidentialPardonForm.hpp"
#include "../inc/Bureaucrat.hpp"
#include <iostream>
#include <fstream>

PresidentialPardonForm::PresidentialPardonForm() : AForm("Presidential Pardon Form", 25, 5)
{	

}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : AForm("Presidential Pardon Form", 25, 5), _target(target)
{

}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm &copy) : AForm("Presidential Pardon Form", 25, 5), _target(copy._target)
{	

}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &instance)
{
	this->setSigned(instance.getSigned());
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{

}

std::string PresidentialPardonForm::getTarget() const
{
	return (this->_target);
}

void	PresidentialPardonForm::beSigned(const Bureaucrat &signer)
{
	if (signer.getGrade() <= this->getSignGrade())
		this->setSigned(true);
	else
		throw Bureaucrat::GradeTooLowException();
}

void	PresidentialPardonForm::execute(const Bureaucrat &executor) const
{
	if(!this->getSigned())
		throw PresidentialPardonForm::FormNotSignedException();
	else if (executor.getGrade() <= this->getExecGrade())
		std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox!" << std::endl;
	else
		throw Bureaucrat::GradeTooLowException();
}

std::ostream & operator<<(std::ostream & o, const PresidentialPardonForm &reference)
{
	o << "Form " << reference.getName() << ", ";
	if (reference.getSigned())
		o << "IS ";
	else
		o << "IS NOT ";
	o << "signed. Grade required to sign is " << reference.getSignGrade() << ". Grade required to execute is "
	<< reference.getExecGrade() << ". ";
	o << "The form asks Zaphod Beeblebrox to pardon " << reference.getTarget();
	return (o);
}

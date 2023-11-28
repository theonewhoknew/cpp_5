#include "../inc/AForm.hpp"
#include "../inc/Bureaucrat.hpp"

AForm::AForm(): _name("default"), _signed(false), _sign_grade(150), _exec_grade(150)
{	

}

AForm::AForm(const std::string name, const int sign, const int exec) : _name(name), _signed(false), _sign_grade(sign), _exec_grade(exec)
{
	if (this->getSignGrade() < 1 || this->getExecGrade() < 1)
		throw AForm::GradeTooHighException();
	else if (this->getSignGrade() > 150 || this->getExecGrade() > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(AForm &copy) : _name(copy.getName()), _signed(copy.getSigned()), _sign_grade(copy.getSignGrade()), _exec_grade(copy.getExecGrade()) 
{	

}

AForm& AForm::operator=(const AForm &instance)
{
	_signed = instance.getSigned();
	return (*this);
}

AForm::~AForm()
{

}

std::string AForm::getName() const
{
	return (this->_name);
}

bool AForm::getSigned() const
{
	return (this->_signed);
}

int AForm::getSignGrade() const
{
	return (this->_sign_grade);
}

int AForm::getExecGrade() const
{
	return (this->_exec_grade);
}

void AForm::setSigned(bool state)
{
	this->_signed = state;
}

const char *AForm::Exception::what(void) const throw()
{
	return ("AForm Exception.");
};

const char *AForm::FormNotSignedException::what(void) const throw()
{
	return ("Form is not signed!");
};

const char *AForm::GradeTooHighException::what(void) const throw()
{
	return ("Grade too high!");
};

const char *AForm::GradeTooLowException::what(void) const throw()
{
	return ("Grade too low!");
};

std::ostream & operator<<(std::ostream & o, const AForm &reference)
{
	o << "Form " << reference.getName() << ", ";
	if (reference.getSigned())
		o << "IS ";
	else
		o << "IS NOT ";
	o << "signed. Grade required to sign is " << reference.getSignGrade() << ". Grade required to execute is "
	<< reference.getExecGrade() << ". ";
	return (o);
}

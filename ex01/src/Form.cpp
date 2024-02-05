#include "../inc/Form.hpp"
#include "../inc/Bureaucrat.hpp"

Form::Form(): _name("default"), _signed(false), _sign_grade(150), _exec_grade(150)
{	

}

Form::Form(const std::string name, const int sign, const int exec) : _name(name), _signed(false), _sign_grade(sign), _exec_grade(exec)
{
	if (this->getSignGrade() < 1 || this->getExecGrade() < 1)
		throw Form::GradeTooHighException();
	else if (this->getSignGrade() > 150 || this->getExecGrade() > 150)
		throw Form::GradeTooLowException();
}

Form::Form(Form &copy) : _name(copy.getName()), _signed(copy.getSigned()), _sign_grade(copy.getSignGrade()), _exec_grade(copy.getExecGrade()) 
{	

}

Form& Form::operator=(const Form &instance)
{
	_signed = instance.getSigned();
	return (*this);
}

Form::~Form()
{

}

std::string Form::getName() const
{
	return (this->_name);
}

bool Form::getSigned() const
{
	return (this->_signed);
}

int Form::getSignGrade() const
{
	return (this->_sign_grade);
}

int Form::getExecGrade() const
{
	return (this->_exec_grade);
}

void Form::setSigned(bool state)
{
	this->_signed = state;
}

const char *Form::GradeTooHighException::what(void) const throw()
{
	return ("Grade too high!");
};

const char *Form::GradeTooLowException::what(void) const throw()
{
	return ("Grade too low!");
};

std::ostream & operator<<(std::ostream & o, const Form &reference)
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

void	Form::beSigned(const Bureaucrat &signer)
{
	if (signer.getGrade() <= this->getSignGrade())
		this->setSigned(true);
	else
		throw Bureaucrat::GradeTooLowException();
}
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
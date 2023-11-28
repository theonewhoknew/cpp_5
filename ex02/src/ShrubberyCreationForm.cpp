#include "../inc/ShrubberyCreationForm.hpp"
#include "../inc/Bureaucrat.hpp"
#include <iostream>
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Shrubbery Creation Form", 145, 137)
{	

}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("Shrubbery Creation Form", 145, 137), _target(target)
{

}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm &copy) : AForm("Shrubbery Creation Form", 145, 137), _target(copy._target)
{	

}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &instance)
{
	this->setSigned(instance.getSigned());
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{

}

std::string ShrubberyCreationForm::getTarget() const
{
	return (this->_target);
}

void	ShrubberyCreationForm::beSigned(const Bureaucrat &signer)
{
	if (signer.getGrade() <= this->getSignGrade())
		this->setSigned(true);
	else
		throw Bureaucrat::GradeTooLowException();
}

void	ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
	if(!this->getSigned())
		throw ShrubberyCreationForm::FormNotSignedException();
	else if (executor.getGrade() <= this->getExecGrade())
	{	
		std::string str(this->getTarget() + "_shrubbery");
		std::ofstream file(str.c_str());
		if (file.is_open())
			drawTree(file);
		file.close();
	}
	else
		throw Bureaucrat::GradeTooLowException();
}

void drawTree(std::ofstream &file) 
{
    for (int i = 1; i <= 10; ++i) 
	{
        for (int j = 0; j < 10 - i; ++j)
            file << ' ';
        for (int k = 0; k < 2 * i - 1; ++k)
            file << '*';
        file << '\n';
    }
    for (int i = 0; i < 10 - 1; ++i)
        file << ' ';
    file << "|\n";
}


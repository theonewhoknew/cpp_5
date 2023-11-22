#include "../inc/Form.hpp"

Form::Form(): _name("default"), _signed(false), _sign(150), _exec(150)
{	

}

Form::Form(const std::string name, const int sign, const int exec) : _name(name), _signed(false), _sign(sign), _exec(exec)
{

}

Form::Form(Form &copy)
{	
	this->_name = copy.getName();
}

Form& Form::operator=(const Form &copy)
{	
	this->_grade = copy.getGrade();
	return (*this);
}

std::string Form::getName() const
{
	return (this->_name);
}

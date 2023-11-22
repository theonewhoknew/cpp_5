#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <exception>

class Form
{
private:
	const std::string	_name;
	bool				_signed;
	const	int			_sign;
	const	int			_exec;

public:
	Form();
	Form(const std::string name, const int sign, const int exec);
	Form(Form &copy);
	Form& operator=(const Form &copy);
	~Form();
	std::string	getName(void) const;
	bool		getSigned(void);
	int			getSignGrade(void) const;
	int			getExecGrade(void) const;
	class		GradeTooHighException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};
	class		GradeTooLowException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};

};

std::ostream & operator<<(std::ostream &o, const Form &reference);

#endif

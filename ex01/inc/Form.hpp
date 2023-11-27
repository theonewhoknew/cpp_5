#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <exception>

class Bureaucrat;

class Form
{
private:
	const std::string	_name;
	bool				_signed;
	const	int			_sign_grade;
	const	int			_exec_grade;

public:
	Form();
	Form(const std::string name, const int sign, const int exec);
	Form(Form &copy);
	Form& operator=(const Form &instance);
	~Form();
	std::string	getName(void) const;
	bool		getSigned(void) const;
	int			getSignGrade(void) const;
	int			getExecGrade(void) const;
	void		setSigned(bool state);
	void		beSigned(const Bureaucrat &signer);
	class Exception : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};
	class		GradeTooHighException : public Form::Exception
	{
		public:
			virtual const char *what() const throw();
	};
	class		GradeTooLowException : public Form::Exception
	{
		public:
			virtual const char *what() const throw();
	};
};

std::ostream & operator<<(std::ostream &o, const Form &reference);

#endif

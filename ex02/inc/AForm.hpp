#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <exception>

class Bureaucrat;

class AForm
{
private:
	const std::string	_name;
	bool				_signed;
	const	int			_sign_grade;
	const	int			_exec_grade;

public:
	AForm();
	AForm(const std::string name, const int sign, const int exec);
	AForm(AForm &copy);
	AForm& operator=(const AForm &instance);
	~AForm();
	
	std::string	getName(void) const;
	bool		getSigned(void) const;
	int			getSignGrade(void) const;
	int			getExecGrade(void) const;
	
	void		setSigned(bool state);

	virtual void		beSigned(const Bureaucrat &signer) = 0;
	virtual void		execute(const Bureaucrat &executor) const = 0;

	class		FormNotSignedException : public std::exception
	{
		public:
			const char *what() const throw();
	};
	class		GradeTooHighException : public std::exception
	{
		public:
			 const char *what() const throw();
	};
	class		GradeTooLowException : public std::exception
	{
		public:
			 const char *what() const throw();
	};
};

std::ostream & operator<<(std::ostream &o, const AForm &reference);

#endif

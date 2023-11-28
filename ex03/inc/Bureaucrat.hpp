#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <exception>
# include "AForm.hpp"

class Bureaucrat
{
private:
	const std::string	_name;
	int					_grade;

public:
	Bureaucrat();
	Bureaucrat(int grade);
	Bureaucrat(std::string name, int grade);
	Bureaucrat(Bureaucrat &copy);
	Bureaucrat& operator=(const Bureaucrat &copy);
	~Bureaucrat();
	
	std::string	getName(void) const;
	int			getGrade(void) const;
	void		setGrade(const int new_grade);
	
	void		incrementGrade(void);
	void		decrementGrade(void);
	
	void		signForm(AForm &form);
	void		executeForm(AForm const &form);
	
	
	class Exception : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};
	class		GradeTooHighException : public Bureaucrat::Exception
	{
		public:
			virtual const char *what() const throw();
	};
	class		GradeTooLowException : public Bureaucrat::Exception
	{
		public:
			virtual const char *what() const throw();
	};
};

std::ostream & operator<<(std::ostream &o, const Bureaucrat &reference);

#endif

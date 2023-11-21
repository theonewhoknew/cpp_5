#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <exception>

class Bureaucrat
{
private:
	const std::string	_name;
	int					_grade;

public:
	Bureaucrat();
	Bureaucrat(int grade);
	Bureaucrat(Bureaucrat &copy);
	Bureaucrat& operator=(const Bureaucrat &copy);
	~Bureaucrat();
	std::string	getName(void) const;
	int			getGrade(void) const;
	void		incrementGrade(void);
	void		decrementGrade(void);
	class		GradeTooHighException : public std::exception
	{

	};
	class		GradeTooLowException : public std::exception
	{

	};
};

#endif

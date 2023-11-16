#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <exception>

class Bureaucrat: public std::exception
{
private:
	const std::string	_name;
	int					_grade;

public:
	Bureaucrat(int grade);
	virtual ~Bureaucrat()_NOEXCEPT;
	std::string	getName(void);
	int			getGrade(void);
	void		incrementGrade(void);
	void		decrementGrade(void);
};

#endif

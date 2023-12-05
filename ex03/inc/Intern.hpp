#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include "AForm.hpp"

class Bureaucrat;

class Intern
{

public:
	Intern();
	Intern(Intern &copy);
	Intern& operator=(const Intern &instance);
	~Intern();

	AForm	*makeForm(const std::string &form, const std::string &target);

	AForm	*createRobotomy(const std::string &form, const std::string &target);
	AForm	*createPresidential(const std::string &form, const std::string &target);
	AForm	*createShrubbery(const std::string &form, const std::string &target);
	AForm	*creationError();
};

#endif
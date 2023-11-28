#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <iostream>
# include <exception>
# include "AForm.hpp"

class Bureaucrat;

class RobotomyRequestForm : public AForm
{

private:

	const std::string _target;

public:
	RobotomyRequestForm();
	RobotomyRequestForm(const std::string &target);
	RobotomyRequestForm(RobotomyRequestForm &copy);
	RobotomyRequestForm& operator=(const RobotomyRequestForm &instance);
	~RobotomyRequestForm();

	std::string getTarget() const;

	void		beSigned(const Bureaucrat &signer);
	void		execute(const Bureaucrat &executor) const;

};

void		robotomize(const std::string &target);

std::ostream & operator<<(std::ostream &o, const RobotomyRequestForm &reference);

#endif
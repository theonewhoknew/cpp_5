#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <iostream>
# include <exception>
# include "AForm.hpp"

class Bureaucrat;

class PresidentialPardonForm : public AForm
{

private:

	const std::string _target;

public:
	PresidentialPardonForm();
	PresidentialPardonForm(const std::string &target);
	PresidentialPardonForm(PresidentialPardonForm &copy);
	PresidentialPardonForm& operator=(const PresidentialPardonForm &instance);
	~PresidentialPardonForm();

	std::string getTarget() const;

	void		beSigned(const Bureaucrat &signer);
	void		execute(const Bureaucrat &executor) const;

};

std::ostream & operator<<(std::ostream &o, const PresidentialPardonForm &reference);

#endif
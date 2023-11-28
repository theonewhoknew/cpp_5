#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <iostream>
# include <exception>
# include "AForm.hpp"

class Bureaucrat;

class ShrubberyCreationForm : public AForm
{

private:

	const std::string _target;

public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(const std::string &target);
	ShrubberyCreationForm(ShrubberyCreationForm &copy);
	ShrubberyCreationForm& operator=(const ShrubberyCreationForm &instance);
	~ShrubberyCreationForm();

	std::string getTarget() const;

	void		beSigned(const Bureaucrat &signer);
	void		execute(const Bureaucrat &executor) const;

};


std::ostream & operator<<(std::ostream &o, const AForm &reference);

void	drawTree(std::ofstream &file);

#endif
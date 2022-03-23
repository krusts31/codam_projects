#include "Intern.hpp"

Intern::Intern()
{
	return ;
}

Intern::~Intern()
{
	return ;
}

Intern & Intern::operator=(Intern const & src)
{
	(void) src;
	return *this;
}

Intern::Intern(Intern const & src)
{
	*this = src;
}

Form	*Intern::robotomyRequest(std::string const & name, std::string const & target) const
{
	std::cout << "Internn creates " << name << std::endl;
	return (new RobotomyRequestForm(target));
}

Form	*Intern::shrubberyCreation(std::string const & name, std::string const & target) const
{
	std::cout << "Internn creates " << name << std::endl;
	return (new ShrubberyCreationForm(target));
}

Form	*Intern::presidentialPardon(std::string const & name, std::string const & target) const
{
	std::cout << "Internn creates " << name << std::endl;
	return (new PresidentialPardonForm(target));
}

Form	*Intern::makeForm(std::string const & name, std::string const & target) const
{
	int	act;

	Form *(Intern:: *actions[3])(std::string const & name, std::string const & target) const =
	{
		&Intern::robotomyRequest,
		&Intern::shrubberyCreation,
		&Intern::presidentialPardon
	};
	
	act = ("robotomy request" == name) ? 0 :
		("shrubbery creation" == name) ? 1 :
		("presidential pardon" == name) ? 2
		: throw "Invalid Form.";
	return ((this->*actions[act])(name, target));
}

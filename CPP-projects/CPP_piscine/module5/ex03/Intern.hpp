#ifndef Intern_CLASS_H
# define Intern_CLASS_H
# include "Form.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "PresidentialPardonForm.hpp"
# include <string>
class Intern
{
public:
//construcotrs
	Intern();
	~Intern();
	Intern(Intern const & src);
//operator overloads
	Intern & operator=(Intern const & src);
//member functions
	Form	*makeForm(std::string const & name, std::string const & target) const;
	Form	*robotomyRequest(std::string const & name, std::string const & target) const;
	Form	*shrubberyCreation(std::string const & name, std::string const & target) const;
	Form	*presidentialPardon(std::string const & name, std::string const & target) const;
};
#endif

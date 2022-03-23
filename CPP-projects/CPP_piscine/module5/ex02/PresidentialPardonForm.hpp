#ifndef PresidentialPardonForm_CLASS_H
# define PresidentialPardonForm_CLASS_H
# include "Form.hpp"
class PresidentialPardonForm : public Form
{
public:

/*
**	Construcotrs
*/

	PresidentialPardonForm(std::string target);
	virtual ~PresidentialPardonForm();
	PresidentialPardonForm(PresidentialPardonForm const & src);

/*
**	Getters
*/

	std::string	getTarget(void)			const;

/*
**	Member functions
*/

	void	execute(Bureaucrat const &executor)	const;

/*
**	operatr overloads
*/

	PresidentialPardonForm & operator=(PresidentialPardonForm const & src);
private:
	PresidentialPardonForm();	//default constructor

/*
**	Varibles
*/
	std::string	_target;	
};

std::ostream	&operator<<(std::ostream &out, PresidentialPardonForm const &form);

#endif

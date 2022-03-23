#ifndef ShrubberyCreationForm_CLASS_H
# define ShrubberyCreationForm_CLASS_H
# include "Form.hpp"

class ShrubberyCreationForm : public Form
{
public:

/*
**	Construcotrs
*/

	ShrubberyCreationForm(std::string target);
	virtual ~ShrubberyCreationForm();
	ShrubberyCreationForm(ShrubberyCreationForm const & src);

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

	ShrubberyCreationForm & operator=(ShrubberyCreationForm const & src);

private:
	ShrubberyCreationForm();	//default constructor

/*
**	Varibles
*/
	std::string	_target;	
};

std::ostream	&operator<<(std::ostream &out, ShrubberyCreationForm const &form);

#endif


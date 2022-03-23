#ifndef RobotomyRequestForm_CLASS_H
# define RobotomyRequestForm_CLASS_H
# include "Form.hpp"

class RobotomyRequestForm : public Form
{
public:

/*
**	Construcotrs
*/

	RobotomyRequestForm(std::string target);
	virtual ~RobotomyRequestForm();
	RobotomyRequestForm(RobotomyRequestForm const & src);

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

	RobotomyRequestForm & operator=(RobotomyRequestForm const & src);

private:
	RobotomyRequestForm();	//default constructor

/*
**	Varibles
*/
	std::string	_target;	
};

std::ostream	&operator<<(std::ostream &out, RobotomyRequestForm const &form);

#endif


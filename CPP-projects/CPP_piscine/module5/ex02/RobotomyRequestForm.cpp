#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <stdlib.h>
/*
**	Constructors
*/

RobotomyRequestForm::RobotomyRequestForm(std::string target)
: Form("RobotomyRequestForm", 72, 45)
{
	this->_target = target;
	return ;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	return ;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &src)
: Form("RobotomyRequestForm", 72, 45), _target(src._target)
{
}

RobotomyRequestForm & RobotomyRequestForm::operator=(RobotomyRequestForm const & src)
{
	(void) src;
	return (*this);
}

std::string	RobotomyRequestForm::getTarget()			const
{
	return (this->_target);
}

void	RobotomyRequestForm::execute(Bureaucrat const &executor)	const
{
	int	randNr = rand() % 2;	
	if (getSigned() == false)
	{
		throw Form::NotSignedException();
	}
	if (getGExecute() <= executor.getGrade())
	{
		throw Form::GradeTooHighException();
	}
	else
	{
		std::cout << "Drill Drill!!" << std::endl;
		if (randNr == 1)
		{
			std::cout << "<" << getTarget() << "> has been robotomized " 
		<< "successfully." << std::endl;
		}
		else
		{
			std::cout << "<" << getTarget() << "> failed to been robotomized" 
		<< std::endl;
		}
	}
}

std::ostream &operator<<(std::ostream &out, RobotomyRequestForm const &form)
{
	std::string	status = "unsigned";

	if (form.getSigned())
		status = "signed";
	out << "Form <" << form.getName() << "> is <" << status << 
	"> Grade to signe <" << form.getGWrite() << "> and Grade to execute <"
	<< form.getGExecute() << ">" << std::endl;
	return (out);
}

#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
/*
**	Constructors
*/

PresidentialPardonForm::PresidentialPardonForm(std::string target)
: Form("PresidentialPardonForm", 25, 5)
{
	this->_target = target;
	return ;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	return ;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &src)
: Form("PresidentialPardonForm", 25, 5), _target(src._target)
{
}

PresidentialPardonForm & PresidentialPardonForm::operator=(PresidentialPardonForm const & src)
{
	(void)src;
	return (*this);
}


std::string	PresidentialPardonForm::getTarget()			const
{
	return (this->_target);
}

void	PresidentialPardonForm::execute(Bureaucrat const &executor)	const
{
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
		std::cout << "<" << getTarget() << "> is pardoned by <"
	<< getName() << ">" << std::endl;
	}
}

std::ostream &operator<<(std::ostream &out, PresidentialPardonForm const &form)
{
	std::string	status = "unsigned";

	if (form.getSigned())
		status = "signed";
	out << "Form <" << form.getName() << "> is <" << status << 
	"> Grade to signe <" << form.getGWrite() << "> and Grade to execute <"
	<< form.getGExecute() << ">" << std::endl;
	return (out);
}

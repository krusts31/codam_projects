#include "Form.hpp"
#include "Bureaucrat.hpp"
/*
**	Constructors
*/

Form::Form(std::string const &name, int const GWrite, int const GExecute) :
_name(name), _GWrite(GWrite), _GExecute(GExecute)
{
	if (GWrite > 150 || GExecute > 150)
		throw Form::GradeTooLowException();
	else if (GWrite < 1 || GExecute < 1)
		throw Form::GradeTooHighException();
	this->_signed = false;
	return ;
}

Form::~Form()
{
	return ;
}

Form::Form(Form const & src) :
_name(src.getName()), _GWrite(src.getGWrite()), _GExecute(src.getGExecute())
{
	*this = src;
}


/*
**	Exceptions
*/

const char	*Form::GradeTooHighException::what() const throw()
{
	return "FormException: Grade too High";
}

const char	*Form::GradeTooLowException::what() const throw()
{
	return "FormException: Grade too Low";
}

const char	*Form::NotSignedException::what() const throw()
{
	return "FormException: Form is not signed";
}

Form::GradeTooHighException::GradeTooHighException(void) {}
Form::GradeTooHighException::~GradeTooHighException(void) throw() {}
Form::GradeTooHighException::GradeTooHighException(GradeTooHighException const &src)
{
	*this = src;
}

Form::GradeTooHighException	&Form::GradeTooHighException::operator=(Form::GradeTooHighException const &rhs)
{
	std::exception::operator=(rhs);
	return (*this);
}
Form::GradeTooLowException::GradeTooLowException(void) {}
Form::GradeTooLowException::~GradeTooLowException(void) throw() {}
Form::GradeTooLowException::GradeTooLowException(GradeTooLowException const &src)
{
	*this = src;
}
Form::GradeTooLowException	&Form::GradeTooLowException::operator=(Form::GradeTooLowException const &rhs)
{
	std::exception::operator=(rhs);
	return (*this);
}

Form::NotSignedException::NotSignedException(void) {}
Form::NotSignedException::~NotSignedException(void) throw() {}
Form::NotSignedException::NotSignedException(NotSignedException const &src)
{
	*this = src;
}

Form::NotSignedException	&Form::NotSignedException::operator=(Form::NotSignedException const &rhs)
{
	std::exception::operator=(rhs);
	return (*this);
}

/*
**	Member funtions
*/

void	Form::beSigned(Bureaucrat const &beuro)
{
	if (beuro.getGrade() <= getGWrite())
	{
		this->_signed = true;
	}
	else
		throw Form::GradeTooHighException();
}

/*
**	Getters
*/

std::string 		Form::getName()	const
{
	return (this->_name);
}

int			Form::getGWrite()	const
{
	return (this->_GWrite);
}

int			Form::getGExecute()	const
{
	return (this->_GExecute);
}

bool			Form::getSigned()	const
{
	return (this->_signed);
}

/*
**	operator overloads
*/

Form & Form::operator=(Form const & src)
{
	if (this != &src)
	{
		this->_signed = src._signed;
	}
	return (*this);
}

std::ostream &operator<<(std::ostream &out, Form const &form)
{
	std::string	status = "unsigned";

	if (form.getSigned())
		status = "signed";
	out << "Form <" << form.getName() << "> is <" << status << 
	"> Grade to signe <" << form.getGWrite() << "> and Grade to execute <"
	<< form.getGExecute() << ">" << std::endl;
	return (out);
}

#include "Bureaucrat.hpp"

/*
**	Construcots
*/

Bureaucrat::Bureaucrat(std::string const & name, int grade) :
_name(name)
{
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else
		this->_grade = grade;
	return ;
}

Bureaucrat::~Bureaucrat()
{
	return ;
}

Bureaucrat::Bureaucrat(Bureaucrat const & src) :
_name(src.getName())
{
	*this = src;
}

/*
**	End of Construcotrs
*/


/*
**	Exceptions
*/


const char	*Bureaucrat::GradeTooHighException::what() const throw()
{
	return "BureaucratException: Grade too High";
}

const char	*Bureaucrat::GradeTooLowException::what() const throw()
{
	return "BureaucratException: Grade too Low";
}

Bureaucrat::GradeTooLowException::GradeTooLowException(void) {}
Bureaucrat::GradeTooLowException::~GradeTooLowException(void) throw(){}
Bureaucrat::GradeTooLowException::GradeTooLowException(GradeTooLowException const &src)
{
	*this = src;
}

Bureaucrat::GradeTooLowException	&Bureaucrat::GradeTooLowException::operator=(Bureaucrat::GradeTooLowException const &src)
{
	std::exception::operator=(src);
	return (*this);
}


Bureaucrat::GradeTooHighException::GradeTooHighException(void) {}
Bureaucrat::GradeTooHighException::~GradeTooHighException(void) throw(){}
Bureaucrat::GradeTooHighException::GradeTooHighException(GradeTooHighException const &src)
{
	*this = src;
}

Bureaucrat::GradeTooHighException	&Bureaucrat::GradeTooHighException::operator=(Bureaucrat::GradeTooHighException const &rhs)
{
	std::exception::operator=(rhs);
	return (*this);
}

/*
**	End of Exceptions
*/


/*
**	Member functions
*/


void	Bureaucrat::gradeUp()
{
	if (getGrade() == 1)
		throw Bureaucrat::GradeTooHighException();
	else
		this->_grade--;	
}

void	Bureaucrat::gradeDown()
{
	if (getGrade() == 150)
		throw Bureaucrat::GradeTooLowException();
	else
		this->_grade++;	
}


void	Bureaucrat::executeForm(Form const & form) const
{
	try
	{
		form.execute(*this);
		std::cout << "<" << getName() << "> executes <" 
			<< form.getName() << ">" << std::endl;
	}
	catch (std::exception const &e)
	{
		std::cout << getName() << " can not execute " << form.getName() \
			<< " becuase " << e.what() << std::endl;
	}
}

void	Bureaucrat::signeForm(Form &form)
{
	try 
	{
		form.beSigned(*this);
		std::cout << getName() << " signs " << form.getName() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << getName() << " can not signe " << form.getName() \
			<< " becuase " << e.what() << std::endl;
	}
}

/*
**	End of member functions
*/


/*
**	Getters
*/


int		Bureaucrat::getGrade() const
{
	return (this->_grade);
}

std::string	Bureaucrat::getName() const
{
	return (this->_name);
}


/*
**	End of Getters
*/


/*
**	Operator Overloads
*/


Bureaucrat & Bureaucrat::operator=(Bureaucrat const & src)
{
	if (this != &src)
		this->_grade = src.getGrade();
	return (*this);
}

std::ostream &operator<<(std::ostream &out, Bureaucrat const &beura)
{
	out << "<" << beura.getName() << ">, bureaucrat grade <" << beura.getGrade() << ">"; 
	return (out);
}

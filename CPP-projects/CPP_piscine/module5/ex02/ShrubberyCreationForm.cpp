#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

/*
**	Constructors
*/

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
: Form("ShrubberyCreationForm", 25, 5)
{
	this->_target = target;
	return ;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &src)
: Form("ShrubberyCreationForm", 25, 5), _target(src._target)
{
}

ShrubberyCreationForm & ShrubberyCreationForm::operator=(ShrubberyCreationForm const & src)
{
	(void)src;
	return (*this);
}

std::string	ShrubberyCreationForm::getTarget()			const
{
	return (this->_target);
}

void	ShrubberyCreationForm::execute(Bureaucrat const &executor)	const
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
		std::ofstream	os((this->_target + "_shrubbery").c_str());
		if (os)
		{
			os << "                     .o00o" << std::endl
			<< "                   o000000oo" << std::endl
			<< "                  00000000000o" << std::endl
			<< "                 00000000000000" << std::endl
			<< "              oooooo  00000000  o88o" << std::endl
			<< "           ooOOOOOOOoo  ```''  888888" << std::endl
			<< "         OOOOOOOOOOOO'.qQQQQq. `8888'" << std::endl
			<< "        oOOOOOOOOOO'.QQQQQQQQQQ/.88'" << std::endl
			<< "        OOOOOOOOOO'.QQQQQQQQQQ/ /q" << std::endl
			<< "         OOOOOOOOO QQQQQQQQQQ/ /QQ" << std::endl
			<< "           OOOOOOOOO `QQQQQQ/ /QQ'" << std::endl
			<< "             OO:F_P:O `QQQ/  /Q'" << std::endl
			<< "                \\\\. \\ |  // |" << std::endl
			<< "                d\\ \\\\\\|_////" << std::endl
			<< "                qP| \\\\ _' `|Ob" << std::endl
			<< "                   \\  / \\  \\Op" << std::endl
			<< "                   |  | O| |" << std::endl
			<< "           _       /\\. \\_/ /\\" << std::endl
			<< "            `---__/|_\\\\   //|  __" << std::endl
			<< "                  `-'  `-'`-'-'" << std::endl;
		}
		os.close();
	}
}

std::ostream &operator<<(std::ostream &out, ShrubberyCreationForm const &form)
{
	std::string	status = "unsigned";

	if (form.getSigned())
		status = "signed";
	out << "Form <" << form.getName() << "> is <" << status << 
	"> Grade to signe <" << form.getGWrite() << "> and Grade to execute <"
	<< form.getGExecute() << ">" << std::endl;
	return (out);
}


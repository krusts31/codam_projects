#ifndef Form_CLASS_H
# define Form_CLASS_H
# include <string>
# include <iostream>
# include <stdexcept>

class Bureaucrat;

class Form
{
public:
/*
**	Construcotrs
*/
	Form(std::string const &name, int const GWrite, int const GExecute);
	~Form();
	Form(Form const & src);

/*
**	Operator overloads
*/

	Form & operator=(Form const & src);

/*
**	Exceptions
*/

class	GradeTooLowException : public std::exception
{
	public:
		const char *what() const throw();
		GradeTooLowException(void);
		~GradeTooLowException(void) throw();
		GradeTooLowException(GradeTooLowException const &src);
		GradeTooLowException	&operator=(GradeTooLowException const &rhs);
};

class	GradeTooHighException : public std::exception
{
	public:
		const char *what() const throw();
		GradeTooHighException(void);
		~GradeTooHighException(void) throw();
		GradeTooHighException(GradeTooHighException const &src);
		GradeTooHighException	&operator=(GradeTooHighException const &rhs);
};

/*
**	Member functions
*/
	void		beSigned(Bureaucrat const &beuro);
/*
**	Getters
*/
	std::string	getName(void)		const;
	bool		getSigned(void)		const;
	int 		getGWrite(void)		const;
	int 		getGExecute(void)	const;


private:
	Form(); // default construcotr
/*
**	Varibles
*/
	std::string const	_name;
	bool			_signed;
	int const		_GWrite;
	int const		_GExecute;
};

std::ostream &operator<<(std::ostream &out, Form const &form);

#endif
